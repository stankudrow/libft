# libft

The first project of the School 42.

Linted according to the `norminette` v3.3.51 rules (at the time of writing long time ago).

## Table of Contents

- [Overview](#overview)
  - [Third-party libft test programs](#third-party-libft-test-programs)
  - [Unit Testing in C](#unit-testing-in-c)

### Overview

This project was done in C during my learning at the School 42 (School 21). Now it is located in the [c](./c) directory. To build the project, use `make` or `make bonus` to include linked list data structure and functions and assumed to be a default build.

#### Third-party libft test programs

**Attention**: test-programs are written by people, so rely on them cautiously.

* [libft-unit-test](https://github.com/alelievr/libft-unit-test)

* [libftTester](https://github.com/Tripouille/libftTester)

* [libft-war-machine](https://github.com/ska42/libft-war-machine)

It is normal (!) if some of your functions are not protected according to some test.

#### Unit Testing in C

After some "research", I picked up two C unit-test frameworks:

* [Criterion](https://criterion.readthedocs.io/en/master/index.html) - seems to be mature and well-maintained.
* [Check](hhttps://libcheck.github.io/check/) - this one is (or was) used at School 21 + it .

The "Check" framework is a natural choice for this project:

- Can be installed via `sudo apt install check` (see the [Installing Check](https://libcheck.github.io/check/web/install.html) section for more details);
- Advised by the School 21 C project subjects, do, if you are a student or an "intern" at School 21, you might want to use the "Check" framework for unit testing your libft functions.
