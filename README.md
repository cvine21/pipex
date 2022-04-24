<div id="header" align="center">
  <h1>
    Pipex
  </h1>
</div>

### Table of contents
1. [About pipex](#about-pipex)
2. [How to run](#how-to-run)
    - [Mandatory part](#mandatory-part)
    - [Bonus part](#bonus-part)

## About pipex
This project demonstates how pipes work in UNIX.

Conceptually, a pipe is a connection between two processes, such that the standard output from one process becomes the standard input of the other process. In UNIX Operating System, Pipes are useful for communication between related processes(inter-process communication)

## How to run
1. Clone this repo and go to the cloned directoty
``` sh
$> git clone https://github.com/cvine21/pipex.git
$> cd pipex/
```
### Mandatory part
This part handles only a single pipe.

Create an executable file:
``` sh
$> cd pipex && make
```
Program will be executed as follows:
``` sh
$> ./pipex file1 cmd1 cmd2 file2
```
It must take 4 arguments:
- file1 and file2 are filenames.
- cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:
``` sh
$> < file1 cmd1 | cmd2 > file2
```
For example:
``` sh
$> ./pipex infile "ls-l" "wc-l" outfile
```
Should behave like: `< infile ls -l | wc -l > outfile`
``` sh
$> ./pipex infile "grep a1" "wc -w" outfile
```
Should behave like: `< infile grep a1 | wc -w > outfile`

### Bonus part
Bonus part handles multiple pipes and supports « and » redirections and heredoc.

Create an executable file:
``` sh
$> cd pipex_bonus && make
```
For example:
``` sh
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Should behave like: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

To use `heredoc` the first parameter must be "here_doc":
``` sh
$> ./pipex here_doc LIMITER cmd cmd1 file
```
Should behave like: `cmd << LIMITER | cmd1 >> file`
