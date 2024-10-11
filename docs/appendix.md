# Appendix

## Glossary

## Package

A Rust *crate* is either a library or an executable program, referred to as
either a *library crate* or a *binary crate*, respectively.

Every [target](#target) defined for a Cargo [package](#package) is a *crate*.

Loosely, the term *crate* may refer to either the source code of the target or
to the compiled artifact that the target produces. It may also refer to a
compressed package fetched from a [registry](#registry).

The source code for a given crate may be subdivided into [*modules*](#module).

## Project

A *package* is a collection of source files and a `Cargo.toml`
[*manifest*](#manifest) file which describes the package. A package has a name
and version which is used for specifying dependencies between packages.

A package contains multiple [*targets*](#target), each of which is a
[*crate*](#crate). The `Cargo.toml` file describes the type of the crates
(binary or library) within the package, along with some metadata about each
one --- how each is to be built, what their direct dependencies are, etc., as
described throughout this book.

The *package root* is the directory where the package's `Cargo.toml` manifest
is located. (Compare with [*workspace root*](#workspace).)

The [*package ID specification*][pkgid-spec], or *SPEC*, is a string used to
uniquely reference a specific version of a package from a specific source.

Small to medium sized Rust projects will only need a single package, though it
is common for them to have multiple crates.

Larger projects may involve multiple packages, in which case Cargo
[*workspaces*](#workspace) can be used to manage common dependencies and other
related metadata between the packages.
