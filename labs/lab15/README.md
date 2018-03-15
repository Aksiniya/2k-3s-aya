## Laboratory work XV

Данная лабораторная работа посвещена изучению инструментов статического и динамического анализа кода
```ShellSession
$ open http://cppcheck.sourceforge.net
```

## Tasks

- [x] 1. Ознакомиться со ссылками учебного материала
- [x] 2. Используя **cpplint** провести анализ проекта на **C++**
- [x] 3. Используя **Cppcheck** провести анализ проекта на **C++**
- [x] 4. Используя **OCLint** провести анализ проекта на **C++**
- [x] 5. Используя **Valgrind** провести анализ проекта на **C++**
- [x] 6. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Output
Пример выполнения на этапе 0102 домашнего задания Stack.
```
$ cpplint main.cpp 
main.cpp:0:  No copyright message found.  You should have a line: "Copyright [year] <Copyright Owner>"  [legal/copyright] [5]
main.cpp:3:  Do not use namespace using-directives.  Use using-declarations instead.  [build/namespaces] [5]
main.cpp:10:  Missing space before {  [whitespace/braces] [5]
main.cpp:17:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
main.cpp:17:  Should have a space between // and comment  [whitespace/comments] [4]
main.cpp:22:  Missing space before {  [whitespace/braces] [5]
main.cpp:23:  Missing space before {  [whitespace/braces] [5]
main.cpp:29:  At least two spaces is best between code and comments  [whitespace/comments] [2]
main.cpp:31:  Missing space before {  [whitespace/braces] [5]
main.cpp:36:  Missing space before {  [whitespace/braces] [5]
main.cpp:44:  Missing space before {  [whitespace/braces] [5]
main.cpp:45:  Missing space before {  [whitespace/braces] [5]
main.cpp:53:  Missing space before {  [whitespace/braces] [5]
main.cpp:58:  Missing space before {  [whitespace/braces] [5]
main.cpp:63:  Missing space before {  [whitespace/braces] [5]
main.cpp:65:  At least two spaces is best between code and comments  [whitespace/comments] [2]
main.cpp:66:  Lines should be <= 80 characters long  [whitespace/line_length] [2]
main.cpp:66:  At least two spaces is best between code and comments  [whitespace/comments] [2]
main.cpp:66:  Missing space before {  [whitespace/braces] [5]
main.cpp:70:  At least two spaces is best between code and comments  [whitespace/comments] [2]
main.cpp:70:  Missing space before {  [whitespace/braces] [5]
Done processing main.cpp
Total errors found: 21
```

```
$ cppcheck main.cpp 
Checking main.cpp ...
```

```
$ valgrind ./a.out 
==31462== Memcheck, a memory error detector
==31462== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31462== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31462== Command: ./a.out
==31462== 
--31462-- run: /usr/bin/dsymutil "./a.out"
warning: no debug symbols in executable (-arch x86_64)
Latest element in IntStack is: 3
Ошибка при удалении элемента: стек пуст
hello
==31462== Invalid write of size 4
==31462==    at 0x100001852: Stack<int>::push(int const&) (in ./a.out)
==31462==    by 0x10000137D: OverwriteIntStack() (in ./a.out)
==31462==    by 0x100000E10: main (in ./a.out)
==31462==  Address 0x100a7d728 is 0 bytes after a block of size 24 alloc'd
==31462==    at 0x10000C681: malloc (in /usr/local/Cellar/valgrind/3.13.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==31462==    by 0x1000517DD: operator new(unsigned long) (in /usr/lib/libc++.1.dylib)
==31462==    by 0x100001D0B: Stack<int>::reinitializeMemory() (in ./a.out)
==31462==    by 0x10000183F: Stack<int>::push(int const&) (in ./a.out)
==31462==    by 0x10000137D: OverwriteIntStack() (in ./a.out)
==31462==    by 0x100000E10: main (in ./a.out)
==31462== 
==31462== Invalid read of size 4
==31462==    at 0x100001952: Stack<int>::pop() (in ./a.out)
==31462==    by 0x10000146B: OverwriteIntStack() (in ./a.out)
==31462==    by 0x100000E10: main (in ./a.out)
==31462==  Address 0x100a7d72c is 4 bytes after a block of size 24 alloc'd
==31462==    at 0x10000C681: malloc (in /usr/local/Cellar/valgrind/3.13.0/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==31462==    by 0x1000517DD: operator new(unsigned long) (in /usr/lib/libc++.1.dylib)
==31462==    by 0x100001D0B: Stack<int>::reinitializeMemory() (in ./a.out)
==31462==    by 0x10000183F: Stack<int>::push(int const&) (in ./a.out)
==31462==    by 0x10000137D: OverwriteIntStack() (in ./a.out)
==31462==    by 0x100000E10: main (in ./a.out)
==31462== 
8 7 6 5 4 3 2 1 
15
10
==31462== 
==31462== HEAP SUMMARY:
==31462==     in use at exit: 26,617 bytes in 197 blocks
==31462==   total heap usage: 274 allocs, 77 frees, 32,851 bytes allocated
==31462== 
==31462== LEAK SUMMARY:
==31462==    definitely lost: 0 bytes in 0 blocks
==31462==    indirectly lost: 0 bytes in 0 blocks
==31462==      possibly lost: 2,064 bytes in 1 blocks
==31462==    still reachable: 4,384 bytes in 3 blocks
==31462==         suppressed: 20,169 bytes in 193 blocks
==31462== Rerun with --leak-check=full to see details of leaked memory
==31462== 
==31462== For counts of detected and suppressed errors, rerun with: -v
==31462== ERROR SUMMARY: 4 errors from 2 contexts (suppressed: 0 from 0)
```

```
$ oclint main.cpp 
Error while trying to load a compilation database:
Could not auto-detect compilation database for file "main.cpp"
No compilation database found in /Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack) or any parent directory
json-compilation-database: Error while opening JSON database: No such file or directory
Running without flags.

Compiler Errors:
(please be aware that these errors will prevent OCLint from analyzing this source code)

/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/Stack.h:14:33: expected member name or ';' after declaration specifiers
/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/Stack.h:14:28: expected '('
/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/Stack.h:14:32: expected ';' after expression
/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/main.cpp:15:18: no member named 'pop' in 'Stack<unsigned long>'
/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/main.cpp:18:18: no member named 'pop' in 'Stack<unsigned long>'
/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/main.cpp:37:19: no matching constructor for initialization of 'Stack<size_t>' (aka 'Stack<unsigned long>')
/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/main.cpp:65:20: no matching constructor for initialization of 'Stack<int>'

Compiler Warnings:

/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/Stack.h:11:19: in-class initialization of non-static data member is a C++11 extension
/Users/macbook/workspace/homework/hw0102(Stack)/hw01(Stack)/Stack.h:14:29: expression result unused


OCLint Report

Summary: TotalFiles=0 FilesWithViolations=0 P1=0 P2=0 P3=0 


[OCLint (http://oclint.org) v0.13]
```
## Links

- [Google C++ Style Guide](https://github.com/cpplint/cpplint)
- [Cppcheck Manual](http://cppcheck.sourceforge.net/manual.pdf)
- [Valgrind Quick Start Guide](http://valgrind.org/docs/manual/index.html)
- [OCLint Tutorial](http://docs.oclint.org/en/stable/intro/tutorial.html)

```
Copyright (c) 2017 Братья Вершинины
```
