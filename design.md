# Shelley design

## Introduction

Shelley is a simple experiment to see if the author could make a Unix-like
shell.

Even through it is experimental a good design with a good set of requirements
is still needed to make a foundation that could be built on. This document
aims to be that set of requirement and design to make a good and stable
foundation.

# Requirements

It has not yet been decided if the shell should be POSIX compatible, or use
its own style and syntax (like [C Shell](https://en.wikipedia.org/wiki/C_shell)
or [Fish](https://fishshell.com)).

# Design

# Use-cases

# Milestones

None of the milestones will have a fixed release-date.

### 0.1.0

Very basic shell.

Will be able to

* Read a single line of input from user
* Tokenize the input into command and arguments
* Create a new process to execute the command
* Built-in `cd` command

Will not have:

* Redirection.
* Piping
* History
* Aliases
* Scripting
* Any built-in commands (except `cd`)
* Variables, both environment and local

### 0.2.0

Adding history

### 0.3.0

Adding piping

### 0.4.0

Adding redirection

### 0.5.0

Adding aliases

May be skipped in favor of functions.

### 0.6.0

Adding more usefull built-in commands

### 0.7.0

Adding variables:

* Environment
* Local
* Global (but not in the environment)

### 1.0.0

Adding scripting:

* Selection
  - `if`
  - `switch`
* Loops
  - `for`
  - `while`
* Functions

# Implementation details
