name: CMake Build
on: [push, pull_request]
jobs:
  build:
    runs-on: windows-latest
    steps:
    - uses: actions/checkout@v4
    
    - name: Install dependencies
      run: |
        choco install mingw -y --version 12.2.0
        choco install cmake -y --installargs 'ADD_CMAKE_TO_PATH=System'
        
        if (-not (Test-Path C:/SFML-2.5.1)) {
            Invoke-WebRequest "https://github.com/SFML/SFML/releases/download/2.5.1/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit.zip" -OutFile "sfml.zip"
            Expand-Archive sfml.zip -DestinationPath C:/
        }
        echo "C:\SFML-2.5.1\bin" >> $env:GITHUB_PATH
    
    - name: Configure CMake
      run: cmake -S . -B build -G "MinGW Makefiles" -DSFML_DIR="C:/SFML-2.5.1/lib/cmake/SFML"
        
    - name: Build
      run: cmake --build build --config Release --parallel
        
    - name: Copy essential DLLs
      run: |
        $dlls = "libgcc_s_seh-1.dll", "libstdc++-6.dll", "libwinpthread-1.dll"
        Copy-Item "C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\bin\*" -Include $dlls -Destination build
        Copy-Item "C:/SFML-2.5.1/bin/*.dll" -Destination build/
        
    - name: Install OpenAL
      run: |
        Invoke-WebRequest "https://github.com/kcat/openal-soft/releases/download/1.23.1/openal-soft-1.23.1-bin.zip" -OutFile "openal.zip"
        Expand-Archive openal.zip -DestinationPath openal_tmp
        $dll = Get-ChildItem openal_tmp -Recurse -Filter "soft_oal.dll" | Select-Object -First 1
        Copy-Item $dll.FullName -Destination "build/openal32.dll"
        Remove-Item openal.zip, openal_tmp -Recurse
        
    - name: Verify dependencies
      run: |
        cd build
        Write-Host "DLLs:"
        Get-ChildItem *.dll
        Write-Host "Executable:"
        Get-ChildItem arkanoid.exe
        
    - name: Copy resources
      run: |
        Copy-Item images -Destination build/images -Recurse -Force
        Write-Host "Copied resources:"
        Get-ChildItem build/images/*
        
    - name: Check dependencies
      run: |
        choco install -y visualstudio2022-workload-vctools
        cd build
        dumpbin /dependents arkanoid.exe
        
    - name: Run executable
      run: |
        cd build
        # Проверка наличия файлов
        Write-Host "Build contents:"
        Get-ChildItem -Recurse
        Write-Host "Resources:"
        Get-ChildItem images/*
        
        # Запуск с обработкой ошибок
        $ErrorActionPreference = "Stop"
        try {
            .\arkanoid.exe 2>&1 | Tee-Object -FilePath output.log
        } catch {
            Write-Error "Execution failed: $_"
            exit 1
        }
        
        # Всегда показывать лог
        if (Test-Path output.log) {
            Get-Content output.log
        } else {
            Write-Warning "Log file not found"
        }
        
        # Проверка кода возврата
        if ($LASTEXITCODE -ne 0) {
            exit $LASTEXITCODE
        }
