## Laboratory work III

Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

```bash
$ open https://git-scm.com
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab03** и с лиценцией **MIT**
- [x] 2. Ознакомиться со ссылками учебного материала
- [x] 3. Выполнить инструкцию учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=Aksiniya
$ export GITHUB_EMAIL=a_strelina@inbox.ru
$ alias edit=vim
```

```ShellSession
$ mkdir lab03 && cd lab03
$ git init # создание основы Git-репозитория
$ git config --global user.name ${GITHUB_USERNAME} # установка(настройка) глобальных параметрвов. Флаг --global указывает на постоянство параметров.
$ git config --global user.email ${GITHUB_EMAIL}
$ git config -e --global # открыть файл, где хранятся глобальные параметры
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03 # создание удаленного репозитория 
$ git pull origin master # получение данных с ветки мастер удаленного репозитория на локальный
$ touch README.md # создать файл README.md в текущей директории
$ git status # статус git на данный момент
$ git add README.md # добавление файла README.md в отслеживаемые
$ git commit -m"added README.md" #коммит
$ git push origin master # отправка изменений из локального репозитория в удаленный
```

Добавить на сервисе **GitHub** в репозитории **lab03** файл **.gitignore**
со следующем содержимом:

```ShellSession
*build*/
*install*/
*.swp
```

```ShellSession
$ git pull origin master
$ git log # выводит список коммитов созданных в данном репозитории в обратном хронологическом порядке
```

```ShellSession
$ mkdir sources
$ mkdir include
$ mkdir examples
$ cat > sources/print.cpp <<EOF # создание директории sources, файла print.cpp и добавление в print.cpp строк ниже:
#include <print.hpp>

void print(const std::string& text, std::ostream& out) {
  out << text;
}

void print(const std::string& text, std::ofstream& out) {
  out << text;
}
EOF
```

```ShellSession
$ cat > include/print.hpp <<EOF #аналогично комментарию выше
#include <string>
#include <fstream>
#include <iostream>

void print(const std::string& text, std::ostream& out = std::cout);
void print(const std::string& text, std::ofstream& out);
EOF
```

```ShellSession
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv) {
  print("hello");
}
EOF
```

```ShellSession
$ cat > examples/example2.cpp <<EOF
#include <fstream>
#include <print.hpp>

int main(int argc, char** argv) {
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```

```ShellSession
$ edit README.md
```

```ShellSession
$ git status
$ git add . # добавление в отслеживаемые всех файлов в данной директории
$ git commit -m"added sources"
$ git push origin master # выгрузка
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=03
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [GitHub](https://github.com)
- [Bitbucket](https://bitbucket.org)
- [Gitlab](https://about.gitlab.com)
- [LearnGitBranching](http://learngitbranching.js.org/)

```
Copyright (c) 2017 Братья Вершинины
```

