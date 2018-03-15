## Laboratory work IV

Данная лабораторная работа посвещена изучению систем автоматизации сборки проекта на примере **CMake**

```ShellSession
#go to https://cmake.org/ website
$ open https://cmake.org/
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab04** на сервисе **GitHub**
- [x] 2. Ознакомиться со ссылками учебного материала
- [x] 3. Выполнить инструкцию учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя>
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab03.git lab04 #clone git repository from https://github.com/${GITHUB_USERNAME}/lab03.git to lab04 directory
$ cd lab04 # change rep
$ git remote remove origin #remove(delete) old origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab04.git # add new origin
```

```ShellSession
$ g++ -I./include -std=c++11 -c sources/print.cpp # flag -I./ point to header files. Compile by c++11 standart, way to execute file
$ ls print.o #list print.o
$ ar rvs print.a print.o # archieve print.o in print.a
$ file print.a # show type of print.a
$ g++ -I./include -std=c++11 -c examples/example1.cpp # Compile example1 file by c++11 standart 
$ ls example1.o # list example.o
$ g++ example1.o print.a -o example1
$ ./example1 && echo # change example1 and output
```

```ShellSession
$ g++ -I./include -std=c++11 -c examples/example2.cpp # Compile example2 file by c++11 standart 
$ ls example2.o # list example2.o
$ g++ example2.o print.a -o example2
$ ./example2 #cd dir
$ cat log.txt && echo # output log.txt
```
delete example1.o example2.o print.o print.a example1 example2 log.txt:
```ShellSession
$ rm -rf example1.o example2.o print.o 
$ rm -rf print.a 
$ rm -rf example1 example2
$ rm -rf log.txt
```

```ShellSession
# create CMakeLists.txt and add text: (set proj)
$ cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.0)
project(print)
EOF
```

```ShellSession
# seting variable in CMakeLists.txt
$ cat >> CMakeLists.txt <<EOF
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
EOF
```

```ShellSession
#add library, target=print, flag=STATIC, exeFile=print.cpp
$ cat >> CMakeLists.txt <<EOF
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```

```ShellSession
#list (include) of dirs for finding headers
$ cat >> CMakeLists.txt <<EOF
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```

```ShellSession
$ cmake -H. -B_build #build project with "rubbish_target_file"=_build
$ cmake --build _build # building and linking project
```

```ShellSession
#add example1.cpp and example2.cpp as exe files
$ cat >> CMakeLists.txt <<EOF

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
```

```ShellSession
#add example1 and example2 to print library
$ cat >> CMakeLists.txt <<EOF

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
```

```ShellSession
$ cmake --build _build # building proj and writing them to /lab04/_build
$ cmake --build _build --target print #building print as a target
$ cmake --build _build --target example1 #buildig example1 only (without example2)
$ cmake --build _build --target example2 # building exaple2
```

```ShellSession
$ ls -la _build/libprint.ab # list libprint.ab
$ _build/example1 && echo # building and then print example1
hello # result 
$ _build/example2 # building example2
$ cat log.txt && echo # open log.txt and print (output)
hello
```

```ShellSession
$ git clone https://github.com/tp-labs/lab04 tmp # git clone to tmp dir
$ mv -f tmp/CMakeLists.txt . # move tmp/CMakeLists.txt .
$ rm -rf tmp # delete tmp dir
```

```ShellSession
$ cat CMakeLists.txt
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install #building project with "rubbish_file" _build and with special flag/variable DCMAKE
$ cmake --build _build --target install #building througt all targets 
$ tree _install #creating tree _install
```

```ShellSession
$ git add CMakeLists.txt # adding CMakeLists.txt to git
$ git commit -m"added CMakeLists.txt" # commit
$ git push origin master # forward to git
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=04
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [Autotools](http://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)
- [CMake](https://cgold.readthedocs.io/en/latest/index.html)

```
Copyright (c) 2017 Братья Вершинины
```
