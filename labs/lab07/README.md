[![Build Status](https://travis-ci.org/Aksiniya/lab07.svg?branch=master)](https://travis-ci.org/Aksiniya/lab07)

## Laboratory work VII

Данная лабораторная работа посвещена изучению систем документирования исходного кода на примере **Doxygen**

```ShellSession
$ open https://www.stack.nl/~dimitri/doxygen/manual/index.html
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab07** на сервисе **GitHub**
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=Aksiniya # value GITHUB_USERNAME
$ alias edit=vim # "rename" command vim to edit
```
git init:
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab06 lab07
$ cd lab07
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab07
```

```ShellSession
$ mkdir docs #  create dir
$ doxygen -g docs/doxygen.conf # create configuration file docs/doxygen.conf
$ cat docs/doxygen.conf # open file
```

edit the configuration file - make project name(print), example path (examples), etc.
```ShellSession
$ sed -i '' 's/\(PROJECT_NAME.*=\).*$/\1 print/g' docs/doxygen.conf
$ sed -i '' 's/\(EXAMPLE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf
$ sed -i '' 's/\(INCLUDE_PATH.*=\).*$/\1 examples/g' docs/doxygen.conf
$ sed -i '' 's/\(INPUT *=\).*$/\1 README.md include/g' docs/doxygen.conf
$ sed -i '' 's/\(USE_MDFILE_AS_MAINPAGE.*=\).*$/\1 README.md/g' docs/doxygen.conf
$ sed -i '' 's/\(OUTPUT_DIRECTORY.*=\).*$/\1 docs/g' docs/doxygen.conf
```
rename lab06 to lab07 in README.md
```ShellSession
$ sed -i '' 's/lab06/lab07/g' README.md
```

```ShellSession
# документируем функции print 
$ edit include/print.hpp
```

```ShellSession
$ git add . # add all files to git
$ git commit -m"added doxygen.conf" # commit
$ git push origin master # push to git
```
make repo lab07 enable to travis
```ShellSession
$ travis login --auto
$ travis enable
```

```
$ doxygen docs/doxygen.conf # generate the documentation for project
$ ls | grep "[^docs]" | xargs rm -rf
$ mv docs/html/* . && rm -rf docs
$ git checkout -b gh-pages # create new branch gh-pages
$ git add .  # adding all files to git
$ git commit -m"added documentation" # commit
$ git push origin gh-pages # push gh-pages to git
$ git checkout master # change branch
```
Make screenshot, send it to gdrive(load with google acc), send it to rusdevops@gmail.com, open https://drive.google.com/open?id=${SCREENSHOT_ID}
```ShellSession
$ mkdir artifacts && cd artifacts
$ screencapture -T 10 screenshot.jpg # или png
<Command>-T
$ open https://${GITHUB_USERNAME}.github.io/lab07/print_8hpp_source.html
$ gdrive upload screenshot.jpg # или png
$ SCREENSHOT_ID=`gdrive list | grep screenshot | awk '{ print $1; }'`
$ gdrive share ${SCREENSHOT_ID} --role reader --type user --email rusdevops@gmail.com
$ echo https://drive.google.com/open?id=${SCREENSHOT_ID}
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=07
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [HTML](https://ru.wikipedia.org/wiki/HTML)
- [LAΤΕΧ](https://ru.wikipedia.org/wiki/LaTeX)
- [man](https://ru.wikipedia.org/wiki/Man_(%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D0%B0_Unix))
- [CHM](https://ru.wikipedia.org/wiki/HTMLHelp)
- [PostScript](https://ru.wikipedia.org/wiki/PostScript)

```
Copyright (c) 2017 Братья Вершинины
```
