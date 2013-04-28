BrainDead
=========

About
-----

BrainDead is an interpreter for the BrainFuck programming language, written in C, that can be run in interactive or non-interactive mode.

Documentation
-------------

### Usage

    braindead [OPTIONS] [TARGET]

By default, enters the interactive mode and interprets brainfuck code from stdin.  
Type `x`, `X`, `q` or `Q` to exit the interactive mode.

If `TARGET` is specified, interprets it as a brainfuck code file and displays the result on the standard output.

### Code samples

Here's the brainfuck code to use to print "Hello World!":

    ++++++++++
    [>+++>+++++++>++++++++>++++++++++>+++++++++++<<<<<-]
    >>++.>>+.+++++++..>+.<<<<++.>>+++++++.>>.+++.<.--------.<<<+.

Here's the brainfuck code to use to create a 'cat' like command:
     
    ,[.,],[.,]

### Examples

Entering into interactive mode:

    braindead

Running a brainfuck script:

    braindead path/to/file

Running a brainfuck script by reading characters by characters, allocating only 2 stack cells at a time, and displaying debug informations:

    braindead -drm 1 2 path/to/file

Running a brainfuck script with input from a file instead of stdin:

    braindead path/to/file < path/to/input/file

### Available command line arguments:

    -h,    boolean,    --help
    Displays help about the command

    -v,    boolean,    --version
    Displays the version number

    -l,    boolean,    --license
    Displays the license text

    -m,    integer,    --malloc
    Allocates <X> stack cells at a time (default is 85)

    -r,    integer,    --read
    Read <X> bytes from input file at a time (default is 1024)

    -d,    boolean,    --debug
    Debug mode - Displays every operation

    -b,    boolean,    --enable-breakpoints
    Enables the use of '@' symbols in the brainfuck code for breakpoints

    -s,    boolean,    --enable-stack-debug
    Enables the use of '$' symbols in the brainfuck code for stack debugging

    -z,    boolean,    --enable-stack-reset
    Enables the use of '%' symbols in the brainfuck code for stack reset

License
-------

BrainDead is released under the terms of the Boost Software License - Version 1.0.

Repository Infos
----------------

    Owner:			Jean-David Gadina - XS-Labs
    Web:			www.xs-labs.com
    Blog:			www.noxeos.com
    Twitter:		@macmade
    GitHub:			github.com/macmade
    LinkedIn:		ch.linkedin.com/in/macmade/
    StackOverflow:	stackoverflow.com/users/182676/macmade