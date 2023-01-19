#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0){
        fprintf(stderr, "Fork failed");
        return 1;
    }
    else if (pid == 0){
        printf("pid in child: %d \n", pid);
        printf("get pid in child %d \n", getpid());
        printf("get ppid in child %d \n", getppid());
        wait(NULL);
        execlp("/bin/ls", "ls", NULL);
        printf("alpha\n"); fflush(NULL);
    }
    else{
        printf("pid in parent: %d \n", pid);
        printf("get pid in parent %d \n", getpid());
        printf("get ppid in parent %d \n", getppid());
        wait(NULL); //wait until all child process is done
        printf("beta\n"); fflush(NULL);
    }
    return 0;
}