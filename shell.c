#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>

#define MAX_LEN_LINE    100
#define LEN_HOSTNAME    30
int main(void)
{
    char command[MAX_LEN_LINE];
    char *args[] = {command,NULL, NULL};
    int ret, status;
    pid_t pid, cpid;
    while (true) {
        char *s;
        int len;
	char hostname[LEN_HOSTNAME+1];
        printf("\033[1;33m MyShell $ \033[0m");
        s = fgets(command, MAX_LEN_LINE, stdin);
	
	printf("%c[1;32m", 27);
        printf("입력받은 command 값 : %s" , command);
	printf("%c[0m", 27);
        
	if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }
        len = strlen(command);
	printf("%c[1;35m", 27);
        printf("len : %d\n", len);
        printf("%c[0m",27);
       	if (command[len - 1] == '\n') {
            command[len - 1] = '\0'; 
        } 
	/* exit 구현 */
        if (!strcmp(command,"exit")){
           return -1;
        }
        /* exit 구현*/
                                  
        
	/*hostname과  username 구현 */	
	gethostname(hostname, LEN_HOSTNAME);
	printf("%c[1;31m",27);
        if (!strcmp(command,"hostname")){
		printf("host name is %s\n", hostname);
                continue;
	}
        
	if (!strcmp(command, "username")){
		printf("user name is %s\n", getpwuid(getuid())->pw_name);
		continue;
	}
        printf("%c[0m",27);   
        /*hostname , username 구현 */
        
	/* fork */ 	
        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "fork failed\n");
                exit(1);
        } 
        
	
	
	if (pid != 0) {  /* parent */
            cpid = waitpid(pid, &status, 0);
             if (cpid != pid) {
                fprintf(stderr, "waitpid failed\n");        
                              }
                printf("%c[1;34m",27);
	        printf("Child process terminated\n");
             if (WIFEXITED(status)) {
                printf("%c[0;33m",27);
	        printf("Exit status is %d\n", WEXITSTATUS(status)); 
	        printf("%c[0m", 27);
                                    }
                     	}        /* parent 닫음괄호 */
        
	
	
	else {  /* child */
	     	
	     /*ls 구현 */	
             if (!strcmp(command,"ls")){
	     strcpy(command, "/bin/ls");
	     }

	     /* cwd 구현 */
             if (!strcmp(command,"cwd")){
	     strcpy(command,"/bin/pwd");
     	     } 
	     
	     /* ls -l 구현 */
             if (!strcmp(command,"ls -l")) {
             args[0]="/bin/ls";
	     args[1]="-l";
	     }             
	     ret = execve(args[0], args, NULL);
           
	     if (ret < 0){ 
             printf("%c[1;33m",27);
             fprintf(stderr, "execve failed\n");
	     printf("%c[0m", 27);   
             return 1;           
    	     }
           }  /* child 닫음 괄호 */
    } 
              return 0;
	      }
