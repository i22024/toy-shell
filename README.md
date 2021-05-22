# toy-shell
# Project-1-Make-Your-Own-Shell-20171563-

I did this assignment in WSL2 environment of Window10.

# toy-shell




###################### exit 


        if (!strcmp(command,"exit")){
        return -1;
        }
        
By adding this code,
After comparing the command received through the strcmp function with "exit", a function has been added to exit the shell when exit is entered in the command. 


###################### hostname


        gethostname(hostname, LEN_HOSTNAME);
        printf("%c[1;31m",27);
        if (!strcmp(command,"hostname")){
                printf("host name is %s\n", hostname);
                 continue;
        }
        
The 'hostname' is received through'gethostname' and copied to the 'hostname' variable, and the 'command' and 'hostname' are compared using 'strcmp'. When'hostname' is input, the 'hostname' value is printed, and the 'while' statement can be exited with 'continue'

###################### username


         if (!strcmp(command, "username")){
         printf("user name is %s\n", getpwuid(getuid())->pw_name);
         continue;
         }
        
When it is determined that the input'command' and'username' are the same, I implemented so that my username can be received and printed through'getpwuid(getuid())->pw_name'.
And I implemented it so that we can exit the loop through continue. 


###################### ls 

By adding, 

     if (!strcmp(command,"ls")){
             strcpy(command, "/bin/ls");
             }
             
When 'ls' is entered in the 'command',  '/bin/ls' is copied to the 'command' using 'strcpy', and the files of the current directory are printed.

###################### ls -l 


     if (!strcmp(command,"ls -l")) {
             args[0]="/bin/ls";
             args[1]="-l";
             }

Refer to slide 11 of Lecture 13 process management. 
By substituting'/bin/ls' in args[0] and ls option'-l' in args[1], the file information such as the files existing in the directory and access rights of the directory is displayed. . 


###################### color 


    printf("%c[1;35m", 27); 
    printf("%c[1;33m",27); 
    printf("%c[1;31m",27);

Using like these codes, I implemented a function to color the shell. 

###################### cwd 

    if (!strcmp(command,"cwd")){
             strcpy(command,"/bin/pwd");
             }
                      
When the command cwd is entered, "/bin/pwd" is copied to the "command" so that the current working directory can be executed and printed. 



