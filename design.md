# Shelley design

## Introduction

Shelley is a simple experiment to see if the author could make a Unix-like
shell.

Even through it is experimental a good design with a good set of requirements
is still needed to make a foundation that could be built on. This document
aims to be that set of requirement and design to make a good and stable
foundation.

### About this document

Note that this document is not a straight-up design document, instead it's
more of a list of things that needs to be done, as well as a roadmap.

# Requirements

It has not yet been decided if the shell should be POSIX compatible, or use
its own style and syntax (like [C Shell](https://en.wikipedia.org/wiki/C_shell)
or [Fish](https://fishshell.com)).

# Design

# Use-cases

1. A user should be able to enter a line of input
2. A user should be able to execute commands
3. A user should be able to pass arguments to commands
4. A string in double- or single-quotes (`"` and `'`) should be a single
   argument
5. Certain special characters, like space outside of quoted strings, should
   be able to escaped
6. Variable expansion should not happen in single-quoted strings
7. Multiple commands should possible to write on a single line, separating
   them with semicolon
8. Comments should be introduced with the `#` character, and last to the
   end of the line

# Milestones

None of the milestones will have a fixed release-date.

### 0.1.0

Very basic shell.

Will be able to

* Read a single line of input from user
* Simple tokenization of the input into command and arguments
* Create a new process to execute the command

Will not have:

* Redirection.
* Piping
* History
* Aliases
* Scripting
* Any built-in commands
* Variables, both environment and local
* Separate multiple commands using semicolon

### 0.2.0

Adding support for built-in commands

Initial list of commands:

* `cd`

### 0.3.0

Advanced tokenization of the input line:

* Handling quoted strings
* Add support to handlke single-quoted (`'`) strings differently from
  double-quoted (`"`) strings.
* Comments using `#` that lasts to the end of the line

### 0.4.0

Add sub-shells

Includes the possibility to run "embedded" commands

### 0.5.0

Adding history

### 0.6.0

Adding piping

### 0.7.0

Adding redirection

### 0.8.0

Adding variables:

* Environment
* Local
* Global (but not in the environment)

### 0.9.0

Prompting

* "Left" prompt
* "Right" prompt
* "Title" prompt

### 0.10.0

Adding scripting:

* Selection
  - `if`
  - `switch`
* Loops
  - `for`
  - `while`
* Functions
* Command sequencing
  - Separating commands with semicolon
  - Conditional sequencing with `AND` and `OR` operators

### 0.11.0

Adding aliases

May be skipped in favor of functions.

### 1.0.0

Job control

# Implementation details
