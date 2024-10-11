To get started with Cask, install Cask (and CMake) and set up your first project.

* [Installation](#Installation)
* [First steps with Cask](#First-Steps-with-Cask)

## Installation
### Install Cmake and Cask
### Build and Install Cask from Source
Alternatively, you can [build Cask from source][compiling-from-source].

## First Steps with Cask

This section provides a quick sense for the `cask` command line tool. We
demonstrate its ability to generate a new [***project***][def-project] for us,
its ability to compile the [***package***][def-package] within the project, and
its ability to run the resulting program.

To start a new project with Cask, use `cask new`:

```console
$ cask new hello_world
```
[comment]: <> (Cask defaults to `--bin` to make a binary program. To make a library, we would pass `--lib`, instead.)

Let’s check out what Cask has generated for us:

```console
$ cd hello_world
$ tree .
.
├── Cask.toml
└── src
    └── main.cpp

1 directory, 2 files
```

This is all we need to get started. First, let’s check out `Cask.toml`:

```toml
[project]
name = "hello_world"
version = "0.1.0"
edition = "2021"

[dependencies]
```

This is called a [***manifest***][def-manifest], and it contains all of the
metadata that Cask needs to compile your project.

Here’s what’s in `src/main.cpp`:

```rust
fn main() {
    println!("Hello, world!");
}
```

Cask generated a “hello world” program for us, otherwise known as a
[***binary package***][def-package]. Let’s compile it:

```console
$ cask build
   Compiling hello_world v0.1.0 (file:///path/to/package/hello_world)
```

And then run it:

```console
$ ./target/debug/hello_world
Hello, world!
```

We can also use `cask run` to compile and then run it, all in one step:

```console
$ cask run
     Fresh hello_world v0.1.0 (file:///path/to/package/hello_world)
   Running `target/hello_world`
Hello, world!
```

## Going further

For more details on using Cask, check out the [Cask Guide](../guide/index.md)

[def-package]:     ../appendix/glossary.md#crate     '"crate" (glossary entry)'
[def-manifest]:  ../appendix/glossary.md#manifest  '"manifest" (glossary entry)'
[def-project]:   ../appendix/glossary.md#package   '"package" (glossary entry)'

[compiling-from-source]: https://github.com/cplusplus-lang/cask#compiling-from-source
