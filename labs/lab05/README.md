[![Build Status](https://travis-ci.org/Aksiniya/lab05.svg?branch=master)](https://travis-ci.org/Aksiniya/lab05)
## Laboratory work V

Данная лабораторная работа посвещена изучению систем непрерывной интеграции на примере сервиса **Travis CI**

```ShellSession
$ open https://travis-ci.org
```

## Tasks

- [x] 1. Авторизоваться на сервисе **Travis CI** с использованием **GitHub** аккаунта
- [x] 2. Создать публичный репозиторий с названием **lab05** на сервисе **GitHub**
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Включить интеграцию сервиса **Travis CI** с созданным репозиторием
- [x] 5. Получить токен для **Travis CLI** с правами **repo** и **user**
- [x] 6. Получить фрагмент вставки значка сервиса **Travis CI** в формате **Markdown**
- [x] 7. Установить [**Travis CLI**](https://github.com/travis-ci/travis.rb#installation)
- [x] 8. Выполнить инструкцию учебного материала
- [x] 9. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя> # adding variable
$ export GITHUB_TOKEN=<полученный_токен> # adding variable
```
Cloning repo from github lab 04 to dir lab05 and connect with remote repo
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab04 lab05
$ cd lab05
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab05
```
Create .travis.yml anf concatenate text to the end of .travis.yml
```ShellSession
$ cat > .travis.yml <<EOF
language: cpp
EOF
```
Concatenate text to the end of .travis.yml
```ShellSession
$ cat >> .travis.yml <<EOF

script:
- cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
- cmake --build _build
- cmake --build _build --target install
EOF
```
Concatenate text to the end of .travis.yml
```ShellSession
$ cat >> .travis.yml <<EOF

addons:
  apt:
    sources:
      - george-edison55-precise-backports
    packages:
      - cmake
      - cmake-data
EOF
```
login in travis with github (for github token help) 
```ShellSession
$ travis login --github-token ${GITHUB_TOKEN}
```
but I login throw github acc with login and password, because have some problems with this command

```ShellSession
$ travis lint # check .travis.yml for possible issues, deprecations and so on
```

```ShellSession
$ ex -sc '1i|<фрагмент_вставки_значка>' -cx README.md #adding string to begining of README.md
```
Adding files to tracked on git and push on github
```ShellSession
$ git add .travis.yml 
$ git add README.md
$ git commit -m"added CI"
$ git push origin master
```

```ShellSession
$ travis lint # check .travis.yml for possible issues, deprecations and so on
$ travis accounts # displays accounts and their subscription status
$ travis sync # triggers a new sync with GitHub
$ travis repos # list of my repos
$ travis enable # enables a project
$ travis whatsup # lists most recent builds
$ travis branches # most recent build for each branch
$ travis history # project history
$ travis show # showing project
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=05
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Travis Client](https://github.com/travis-ci/travis.rb)
- [AppVeyour](https://www.appveyor.com/)
- [GitLab CI](https://about.gitlab.com/gitlab-ci/)

```
Copyright (c) 2017 Братья Вершинины
```
