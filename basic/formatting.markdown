---
title: clang-format
category: basic
layout: main
---

The goal of this exercise is to learn how to
use [`clang-format`](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
to format your code automatically and uniformly.

Consider [hello.cpp]({{site.exercises_repo}}/hands-on/basic/hello.cpp):

    [student@esc ~]$ cd esc18/hands-on/basic
    [student@esc basic]$ cat hello.cpp
    #include <iostream>
    int main(int argc, char*argv[]){std::cout<<"Hello, ";...
    [student@esc basic]$ clang-format hello.cpp
    #include <iostream>
    int main(int argc, char *argv[]) {
      std::cout << "Hello, ";
      if (argc > 1)
        std::cout << argv[1];
    ...

Not perfect, but not bad either.

Note in particular how the `*` in `char *argv` is attached to the argument.
Instead we want it attached to the type as in `char* argv`.

    [student@esc basic]$ clang-format -style="{PointerAlignment: Left}" hello.cpp
    #include <iostream>
    int main(int argc, char* argv[]) {
      std::cout << "Hello, ";
      if (argc > 1)
        std::cout << argv[1];
    ...

Much better. We can save our settings in a configuration file, starting from a
dump of the default settings.

    [student@esc basic]$ clang-format -dump-config -style="{PointerAlignment: Left}" > .clang-format
    [student@esc basic]$ clang-format hello.cpp
    #include <iostream>
    int main(int argc, char* argv[]) {
      std::cout << "Hello, ";
      if (argc > 1)
        std::cout << argv[1];
    ...


If we use the same `.clang-format` for all our projects, it can also be saved in
${HOME}.

To format a file _in place_ use the `-i` option.

    [student@esc basic]$ clang-format -i hello.cc
    [student@esc basic]$ cat hello.cc
    #include <iostream>
    int main(int argc, char* argv[]) {
      std::cout << "Hello, ";
      if (argc > 1)
        std::cout << argv[1];
    ...
