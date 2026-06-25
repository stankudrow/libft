# libft

The first project of the School 42.

Linted according to the `norminette` v3.3.51 rules (at the time of writing which was a long time ago)... **not anymore**.

## Table of Contents

- [Overview](#overview)
- [Libft in C](#libft-in-c)
- [Libft in Rust](#libft-in-rust)
- [References](#references)
  - [C](#c)
  - [Rust](#rust)
  - [C++](#c++)

### Overview

This project was done in C during my learning at the School 42 (School 21). Now it is located in the [c](./c) directory.

### Libft in C

I reorganised the original code and placed it in the [c](./c) directory. To build the project, use `make` or `make bonus` which will create a static "libft.a" library. During my time at School 42, I checked the correctness of the library using the following testing programs (**attention**, these programs are written by people, so rely on them cautiously):

- [libft-unit-test](https://github.com/alelievr/libft-unit-test) (contributed a while back)
- [libftTester](https://github.com/Tripouille/libftTester) (contributed some time ago)
- [libft-war-machine](https://github.com/ska42/libft-war-machine)

It is normal (!) if some of your functions are flagged as unprotected, you don't need to be scared of opinionated "boom" messages (or maybe you have to according to the School 42 latest subject).

Later on, I got into my head that that I need (for some inexplicable reason) to learn how to write unit tests in C and this project seems to me like the perfect place to start. I picked [Check](https://libcheck.github.io/check/) framework because it is:

- installable via `sudo apt install check` (see the [Installing Check](https://libcheck.github.io/check/web/install.html) section for more details);
- simple enough and has some documentation and even tutorials: [basic](https://libcheck.github.io/check/doc/check_html/check_3.html) and [advanced](https://libcheck.github.io/check/doc/check_html/check_4.html#Advanced-Features) + not so-long [API reference](https://libcheck.github.io/check/doc/doxygen/html/check_8h.html);
- recommended or even required (?) at School 21.

So, if you are a student or an "intern" at School 21 or 42, you might want to use the "Check" framework in your C projects. Tests are available in the [c/tests](./c/tests) directory. The tests are not written following best practices, please don’t expect idiomatic or well‑structured code. **Disclaimer**: I had and have no eagerness to provide full coverage for this project in C, only functions or data structures of interest that was enough **for me** to master "Check" to some basic level.

### Libft in Rust

Libft is a library, and I wanted to learn how to build a proper Rust crate—something I could publish and reuse in other projects. This seemed like a good first challenge.

- `cargo new --lib %my-fancy-lib%` - creates a library project/directory with ***%my-fancy-lib%*** name;
- `cargo fmt` - format the code;
- `cargo clippy` - built-in linter;
- `cargo build` - build/compile the project;
- `cargo test` - run tests.

### References

#### C

Some of my other 42cursus projects in C:
- [get-next-line](https://github.com/stankudrow/get_next_line)
- [ft_printf](https://github.com/stankudrow/ft_printf)

Resources on C programming language:
- [CodeVault playlist](https://www.youtube.com/@CodeVault/playlists) - must watch, practically all videos.

#### Rust

- [The Cargo Book][cargo_book_ref] - Cargo is the Rust package manager: dependencies, package compilation, building, uploading to [crates.io package registry](https://crates.io/) etc.

#### C++

No way, thanx. The reason why I won't learn C++ and practice it on the libft -> have fun (or any other emotions) watching [this video](https://www.youtube.com/watch?v=7fGB-hjc2Gc).


[cargo_book_ref]: https://doc.rust-lang.org/cargo/index.html
