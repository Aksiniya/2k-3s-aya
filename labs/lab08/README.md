[![Build Status](https://travis-ci.org/Aksiniya/lab08.svg?branch=master)](https://travis-ci.org/Aksiniya/lab08)

## Laboratory work VIII

Данная лабораторная работа посвещена изучению средств пакетирования на примере **CPack**

```ShellSession
$ open https://cmake.org/Wiki/CMake:CPackPackageGenerators
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab08** на сервисе **GitHub**
- [x] 2. Выполнить инструкцию учебного материала
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=Aksiniya # set value GITHUB_USERNAME
$ export GITHUB_EMAIL=a_strelina@inbox.ru  # set value GITHUB_EMAIL
$ alias edit=vim # substitution command vim by command edit
$ alias gsed=sed # for *-nix system substitution command sed by command gsed
```

instalation GitHub parameters
```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab07 lab08
$ cd lab08
$ git remote remove origin
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab08
```

add strings after string "project(print)" in CMakeLists.txt
```ShellSession
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_STRING "v${PRINT_VERSION}")
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION \
\${PRINT_VERSION_MAJOR}.\${PRINT_VERSION_MINOR}.\${PRINT_VERSION_PATCH}.\${PRINT_VERSION_TWEAK})
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_TWEAK 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\
set(PRINT_VERSION_PATCH 0)
' CMakeLists.txt
$ gsed -i '/project(print)/a\ 
set(PRINT_VERSION_MINOR 1)
' CMakeLists.txt
$ gsed -i '/project(print)/a\ 
set(PRINT_VERSION_MAJOR 0)
' CMakeLists.txt
```

```ShellSession
$ touch DESCRIPTION && edit DESCRIPTION # create file DESCRIPTION and edit this file
$ touch ChangeLog.md # create ChangeLog.md file
# set data, and add text to ChangeLog.md
$ DATE=`date` cat > ChangeLog.md <<EOF
* ${DATE} ${GITHUB_USERNAME} <${GITHUB_EMAIL}> 0.1.0.0
- Initial RPM release
EOF
```

set iclude
```ShellSession
$ cat > CPackConfig.cmake <<EOF
include(InstallRequiredSystemLibraries)
EOF
```

setting up settings for CPack
-contact info
-version _.x.x.x - major
-version x._.x.x - minor
-version x.x._.x - patch
-version x.x.x._ - tweak
-way to description
-set summary description
```ShellSession
$ cat >> CPackConfig.cmake <<EOF
set(CPACK_PACKAGE_CONTACT ${GITHUB_EMAIL}) 
set(CPACK_PACKAGE_VERSION_MAJOR \${PRINT_VERSION_MAJOR}) 
set(CPACK_PACKAGE_VERSION_MINOR \${PRINT_VERSION_MINOR}) 
set(CPACK_PACKAGE_VERSION_PATCH \${PRINT_VERSION_PATCH}) 
set(CPACK_PACKAGE_VERSION_TWEAK \${PRINT_VERSION_TWEAK}) 
set(CPACK_PACKAGE_VERSION \${PRINT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE \${CMAKE_CURRENT_SOURCE_DIR}/DESCRIPTION) 
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "static c++ library for printing") 
EOF
```
set up settings for CPack (resource file settings)
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RESOURCE_FILE_LICENSE \${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README \${CMAKE_CURRENT_SOURCE_DIR}/README.md)
EOF
```
set up settings for CPack (Settings for package) - name, license, group, url etc.
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_RPM_PACKAGE_NAME "print-devel")
set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_RPM_PACKAGE_GROUP "print")
set(CPACK_RPM_PACKAGE_URL "https://github.com/${GITHUB_USERNAME}/lab07")
set(CPACK_RPM_CHANGELOG_FILE \${CMAKE_CURRENT_SOURCE_DIR}/ChangeLog.md)
set(CPACK_RPM_PACKAGE_RELEASE 1)
EOF
```

metainfo
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

set(CPACK_DEBIAN_PACKAGE_NAME "libprint-dev")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://${GITHUB_USERNAME}.github.io/lab07")
set(CPACK_DEBIAN_PACKAGE_PREDEPENDS "cmake >= 3.0")
set(CPACK_DEBIAN_PACKAGE_RELEASE 1)
EOF
```

iclude CPack in CPackConfig.cmake
```ShellSession
$ cat >> CPackConfig.cmake <<EOF

include(CPack)
EOF
```

iclude CPackConfig.cmake in CMakeLists.txt
```ShellSession
$ cat >> CMakeLists.txt <<EOF

include(CPackConfig.cmake)
EOF 
```

substitution lab07 in lab08 in README
```ShellSession
$ gsed -i 's/lab07/lab08/g' README.md
```

git set 
```ShellSession
$ git add .
$ git commit -m"added cpack config"
$ git push origin master
```

make travis enable (lab08)
```ShellSession
$ travis login --auto
$ travis enable
```

building proj
```ShellSession
$ cmake -H. -B_build
$ cmake --build _build
$ cd _build
$ cpack -G "TGZ" # algotithm compression zip - create package print-0.1.0.0-Darwin.tar.gz
$ cpack -G "DragNDrop" # algorithm compression zip - create package .dmg
$ cd ..
```

build by target (TGZ flag)
```ShellSession
$ cmake -H. -B_build -DCPACK_GENERATOR="TGZ"
$ cmake --build _build --target package
```

```ShellSession
$ mkdir artifacts
$ mv _build/*.tar.gz artifacts # move
$ tree artifacts
```

## Report

```ShellSession
$ cd ~/workspace/labs/
$ export LAB_NUMBER=08
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Links

- [DMG](https://cmake.org/cmake/help/latest/module/CPackDMG.html)
- [DEB](https://cmake.org/cmake/help/latest/module/CPackDeb.html)
- [RPM](https://cmake.org/cmake/help/latest/module/CPackRPM.html)
- [NSIS](https://cmake.org/cmake/help/latest/module/CPackNSIS.html)

```
Copyright (c) 2017 Братья Вершинины
```
