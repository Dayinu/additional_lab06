## Дополнительное задание к 6 Лабораторной

**Студентки группы ИУ8-22**

**Ивановой Влады**

```sh
$ git clone --depth 1 --filter=blob:none --no-checkout https://github.com/embeddedmz/16-Games.git
Cloning into '16-Games'...
remote: Enumerating objects: 34, done.
remote: Counting objects: 100% (34/34), done.
remote: Compressing objects: 100% (32/32), done.
remote: Total 34 (delta 0), reused 31 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (34/34), 5.00 KiB | 2.50 MiB/s, done.

$ cd 16-Games 

$ git sparse-checkout init --cone

$ git sparse-checkout set "03 - Arkanoid"

$ git checkout master
remote: Enumerating objects: 2, done.
remote: Counting objects: 100% (2/2), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 2 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (2/2), 1.73 KiB | 1.73 MiB/s, done.
Already on 'master'
Your branch is up to date with 'origin/master'.

$ rm -rf .git
                                                                             
$ git init
hint: Using 'master' as the name for the initial branch. This default branch name                                                                         
hint: is subject to change. To configure the initial branch name to use in all                                                                            
hint: of your new repositories, which will suppress this warning, call:
hint:
hint:   git config --global init.defaultBranch <name>
hint:
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint:
hint:   git branch -m <name>
Initialized empty Git repository in /home/linux/add_lab06/16-Games/.git/

┌──(linux㉿kali)-[~/add_lab06/16-Games]
└─$ git add .        
                                                                             
┌──(linux㉿kali)-[~/add_lab06/16-Games]
└─$ git commit -m "Initial commit"      
[master (root-commit) 548801f] Initial commit
 3 files changed, 206 insertions(+)
 create mode 100644 CMakeLists.txt
 create mode 100644 README.md
 create mode 100644 main.cpp
                                                                             
┌──(linux㉿kali)-[~/add_lab06/16-Games]
└─$ git branch main  
                                                                             
┌──(linux㉿kali)-[~/add_lab06/16-Games]
└─$ git push -u origin main
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (5/5), done.
Writing objects: 100% (5/5), 2.40 KiB | 491.00 KiB/s, done.
Total 5 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:Dayinu/additional_lab06.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.

$ mkdir -p .github/workflows

$ cat > .github/workflows/ci.yml << 'EOF'
name: Windows Build

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build-windows:
    name: Build for Windows
    runs-on: windows-latest

    steps:
    - name: Checkout code
      uses: actions/checkout@v4

    - name: Setup SFML dependencies
      run: |
        choco install mingw -y --version 12.2.0
        choco install cmake -y --installargs 'ADD_CMAKE_TO_PATH=System'

    - name: Configure CMake
      shell: cmd
      run: |
        cmake -S . -B build -G "MinGW Makefiles"

    - name: Build project
      shell: cmd
      run: |
        cmake --build build --config Release

    - name: Verify artifacts
      shell: cmd
      run: |
        dir build\Release
        if exist build\Release\arkanoid.exe (exit 0) else (exit 1)
EOF

$ git add .                                                                
                                                                             
 git commit -m "Step 2"        
[main 1311801] Step 2
 11 files changed, 110 insertions(+), 80 deletions(-)
 create mode 100644 .github/workflows/ci.yml
 create mode 100644 images/background.jpg
 create mode 100644 images/ball.png
 create mode 100644 images/block01.png
 create mode 100644 images/block02.png
 create mode 100644 images/block03.png
 create mode 100644 images/block04.png
 create mode 100644 images/block05.png
 create mode 100644 images/paddle.png

$ git push origin main
Enumerating objects: 19, done.
Counting objects: 100% (19/19), done.
Delta compression using up to 2 threads
Compressing objects: 100% (14/14), done.
Writing objects: 100% (16/16), 21.09 KiB | 1.51 MiB/s, done.
Total 16 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:Dayinu/additional_lab06.git
   548801f..1311801  main -> main

```
