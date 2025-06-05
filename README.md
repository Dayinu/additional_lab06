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

```
