# 🖱 42Paris Project | minishell

## Objectives

The goal of this project is to make a "little" shell.  
We take bash for reference to manage comportements.  
We have to make the following built-ins:  
- **echo** with option -n  
- **cd** with only a relative or absolute path  
- **pwd** with no options  
- **export** with no options  
- **unset** with no options  
- **env** with no options or arguments  
- **exit** with no options  

Manage the following redirections:  
- **<** should redirect input.  
- **>** should redirect output.  
- **<<** should be given a delimiter, then read the input until a line containing the  
- delimiter is seen. However, it doesn’t have to update the history!  
- **>>** should redirect output in append mode.  

Implement **pipes**: in our project you can only open pipes at the limit of opened file descriptors (1024 per process on Linux), if you open more pipes an undefined behavior happend.

Handle **environment variables**.  
Handle **ctrl-C**, **ctrl-D** and **ctrl-\\** which should behave like in bash.  
In interactive mode:  
- CTRL-C displays a new prompt on a new line.  
- CTRL-D exits the shell.  
- CTRL-\ does nothing.  

## Usage

`make` to compile the program.  
`clean` to clean objects files.  
`fclean` to clean objects files and program file.  

**Execute**: `./minishell`

## Help

[CodeVault](https://www.youtube.com/CodeVault) were usefull to understand pipes:  
https://www.youtube.com/watch?v=cex9XrZCU14  
https://www.youtube.com/watch?v=Mqb2dVRe0uo

## Colaborator

[Xavier Le-baux](https://github.com/Xavier-LB "Xavier Le-baux")
