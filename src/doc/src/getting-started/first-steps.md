# First Steps with Cask

This section provides a quick sense for the `cask` command line tool. We
demonstrate its ability to generate a new [***package***][def-package] for us,
its ability to compile the [***barrel***][def-barrel] within the package, and
its ability to run the resulting program.

To start a new package with Cask, use `cask new`:

```console
$ cask new hello_world
```

Cask defaults to `--bin` to make a binary program. To make a library, we
would pass `--lib`, instead.

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
[package]
name = "hello_world"
version = "0.1.0"
standard = "20"

[dependencies]
```

This is called a [***manifest***][def-manifest], and it contains all of the
metadata that Cask needs to compile your package.

Here’s what’s in `src/main.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World!\n";
}
```

Cask generated a “hello world” program for us, otherwise known as a
[***binary barrel***][def-barrel]. Let’s compile it:

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

[def-barrel]:     ../appendix/glossary.md#barrel     '"barrel" (glossary entry)'
[def-manifest]:  ../appendix/glossary.md#manifest  '"manifest" (glossary entry)'
[def-package]:   ../appendix/glossary.md#package   '"package" (glossary entry)'
