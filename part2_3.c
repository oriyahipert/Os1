#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(){
    __pid_t pid = fork();

    if(pid == 0){
        chdir("/");
        setsid();
        printf("stating my daemon \n");

        close(stdout);
        close(stdin);
        close(stderr);

        openlog("myDeamon" , LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "daemon started");
        usleep(3000000);
        syslog(LOG_NOTICE, "doing some work....");
        usleep(3000000);
        syslog(LOG_NOTICE, "daemon finished");
    }
    else
    {
        printf("daemon PID %d\n", pid);
    }
    return 0;
}