## Laboratory work II

Данная лабораторная работа посвещена изучению утилит для разработки проектов

## Tasks

- [x] 1. Ознакомиться со ссылками учебного материала
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```bash
$ export GITHUB_USERNAME=Aksiniya # создание переменной GITHUB_USERNAME, которая наследуется в дочерние проессы
$ export GIST_TOKEN=<тут токен> # аналогично со строкой выше, переменная GIST_TOKEN
$ alias edit=vim # замена вызова команды vim на edit (typedef)
```

```bash
$ npm install -g gistup # установка gistup. Флаг -g указывает на то, что установка идет не в текущую директорию, а в основную папку для хранения пакетов
```

```bash
$ cat > ~/.gistup.json <<EOF 
{
"token": "${GIST_TOKEN}"
}
EOF
# добавление строки "token": "${GIST_TOKEN}" в конец файла по адресу ~/.gistup.json (конкатенация)
```

```bash
$ cd ~
$ mkdir -p workspace/labs/projects/ #создание директории projects. Флаг -p указывает на то, что при необходимости создаются дочерние директории. При существовании такой директории вывод об ошибке игнорируется
$ mkdir -p workspace/labs/tasks/ # аналогично со строкой выше
$ mkdir -p workspace/labs/reports/
```

## Report

```bash
$ cd ~/workspace/labs/ # выбор директории по адресу
$ export LAB_NUMBER=02 # добавление переменной LAB_NUMBER, наследуемой в дочерие процессы
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER} # скачивание директории из GitHub в директории tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER} # создание директории
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md # копирование файла README.md из tasks/lab${LAB_NUMBER}/ в reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER} # выбор директории
$ edit REPORT.md # редактирование файла с помощью vim
$ gistup -m "lab${LAB_NUMBER}" # выгрузка
```

## Links

### Unix commands

- [ar](https://en.wikipedia.org/wiki/Ar_(Unix))
- [cat](https://en.wikipedia.org/wiki/Cat_(Unix))
- [cd](https://en.wikipedia.org/wiki/Cd_(command))
- [cp](https://en.wikipedia.org/wiki/Cp_(Unix))
- [cut](https://en.wikipedia.org/wiki/Cut_(Unix))
- [echo](https://en.wikipedia.org/wiki/Echo_(command))
- [env](https://en.wikipedia.org/wiki/Env_(shell))
- [ex](https://en.wikipedia.org/wiki/Ex_(editor))
- [file](https://en.wikipedia.org/wiki/File_(command))
- [find](https://en.wikipedia.org/wiki/Find)
- [ls](https://en.wikipedia.org/wiki/Ls)
- [man](https://en.wikipedia.org/wiki/Man_page)
- [mkdir](https://en.wikipedia.org/wiki/Mkdir)
- [mv](https://en.wikipedia.org/wiki/Mv)
- [nm](https://en.wikipedia.org/wiki/Nm_(Unix))
- [ps](https://en.wikipedia.org/wiki/Ps_(Unix))
- [pwd](https://en.wikipedia.org/wiki/Pwd)
- [rm](https://en.wikipedia.org/wiki/Rm_(Unix))
- [sed](https://en.wikipedia.org/wiki/Sed)
- [touch](https://en.wikipedia.org/wiki/Touch_(Unix))

### Package Managers

- [apt](http://help.ubuntu.ru/wiki/apt) | [dnf](https://en.wikipedia.org/wiki/DNF_(software)) | [yum](https://fedoraproject.org/wiki/Yum/ru)
- [brew](https://brew.sh) | [linuxbrew](http://linuxbrew.sh)
- [npm](https://docs.npmjs.com)

### Software

- [curl](https://www.gitbook.com/book/bagder/everything-curl/details)
- [wget](https://www.gnu.org/software/wget/manual/wget.pdf)
- [clang](https://clang.llvm.org)
- [g++](https://gcc.gnu.org/onlinedocs/gcc-4.0.2/gcc/G_002b_002b-and-GCC.html)
- [make](https://en.wikipedia.org/wiki/Make_(software))
- [open](https://developer.apple.com/legacy/library/documentation/Darwin/Reference/ManPages/man1/open.1.html)
- [openssl](https://www.openssl.org)
- [nano](https://www.nano-editor.org)
- [tree](https://linux.die.net/man/1/tree)
- [vim](http://www.vim.org)

```
Copyright (c) 2017 Братья Вершинины
```
