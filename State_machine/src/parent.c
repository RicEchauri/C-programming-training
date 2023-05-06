
#include "coin_state_machine.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main (int argc, char* argv[])
{
    
    int id = fork();
    int child_pid;

    if (id == 0)
    {
        child_pid = (int)getpid();
        printf("Child %d\n", (int)getpid());
        //child process
        execl("main", NULL);

    }
    else if(id == 1)
    {
        //Parent process
        //printf("parent process\n");
        if (getchar() == 'r')
        {
            kill(child_pid, SIGKILL);
        }
        while(1)
        {
            usleep(1);
        }
    }
    else
    {
        //Error case
        fprintf(stderr,"Error: Fail in fork");
        return -1;
    }
    
    return 0;
}