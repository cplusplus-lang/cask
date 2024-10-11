# Appendix

## Glossary

## Index

The *index* is the searchable list of [*packages*](#package) in a
[*registry*](#registry).

## Package

A Cask *package* is either a library or an executable program, referred to as
either a *library package* or a *binary package*, respectively.

Every [target](#target) defined for a Cask [project](#project) is a *package*.

Loosely, the term *package* may refer to either the source code of the target or
to the compiled artifact that the target produces. It may also refer to a
compressed project fetched from a [registry](#registry).

The source code for a given package may be subdivided into [*modules*](#module).

## Project

A *project* is a collection of source files and a `Cask.toml`
[*manifest*](#manifest) file which describes the project. A project has a name
and version which is used for specifying dependencies between projects.

A project contains multiple [*targets*](#target), each of which is a
[*package*](#package). The `Cask.toml` file describes the type of the packages
(binary or library) within the project, along with some metadata about each
one --- how each is to be built, what their direct dependencies are, etc., as
described throughout this book.

The *project root* is the directory where the project's `Cask.toml` manifest
is located. (Compare with [*workspace root*](#workspace).)

The [*project ID specification*][pkgid-spec], or *SPEC*, is a string used to
uniquely reference a specific version of a project from a specific source.

Small to medium sized Rust projects will only need a single project, though it
is common for them to have multiple packages.

Larger projects may involve multiple projects, in which case Cask
[*workspaces*](#workspace) can be used to manage common dependencies and other
related metadata between the projects.

## Registry

A *registry* is a service that contains a collection of downloadable
[*packages*](#package) that can be installed or used as dependencies for a
[*project*](#project). The default registry in the Cask ecosystem is
`TBD`. The registry has an [*index*](#index) which
contains a list of all packages, and tells Cask how to download the packages that
are needed.

## Target

The meaning of the term *target* depends on the context:

- **Cask Target** --- Cask [*projects*](#project) consist of *targets* which
  correspond to [*artifacts*](#artifact) that will be produced. Packages can
  have library, binary, example, test, and benchmark targets. The
  [list of targets][targets] are configured in the `Cask.toml`
  [*manifest*](#manifest), often inferred automatically by the [directory
  layout] of the source files.
- **Target Directory** --- Cask places all built artifacts and intermediate
  files in the *target* directory. By default this is a directory named
  `target` at the [*workspace*](#workspace) root, or the project root if not
  using a workspace.
  [comment]: <> (The directory may be changed with the `--target-dir` command-line option, the `CARGO_TARGET_DIR` [environment variable], or the `build.target-dir` [config option].)
- **Target Architecture** --- The OS and machine architecture for the built
  artifacts are typically referred to as a *target*.
- **Target Triple** --- A triple is a specific format for specifying a target
  architecture. Triples may be referred to as a *target triple* which is the
  architecture for the artifact produced, and the *host triple* which is the
  architecture that the compiler is running on. The target triple can be
  specified with the `--target` command-line option or the `build.target`
  [config option]. The general format of the triple is
  `<arch><sub>-<vendor>-<sys>-<abi>` where:

  - `arch` = The base CPU architecture, for example `x86_64`, `i686`, `arm`,
    `thumb`, `mips`, etc.
  - `sub` = The CPU sub-architecture, for example `arm` has `v7`, `v7s`,
    `v5te`, etc.
  - `vendor` = The vendor, for example `unknown`, `apple`, `pc`, `nvidia`, etc.
  - `sys` = The system name, for example `linux`, `windows`, `darwin`, etc.
    `none` is typically used for bare-metal without an OS.
  - `abi` = The ABI, for example `gnu`, `android`, `eabi`, etc.

  Some parameters may be omitted. Run `rustc --print target-list` for a list of
  supported targets.
