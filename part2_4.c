#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include <sched.h>
#include<unistd.h>
char child_stack [10000+1];

void print (char *text){
    int i;
    for(i=0; i<20; i++){
        printf("Hello from %s/n", text);
        usleep(1000000) ;
    }
}

int Myclone(void* input){
    char * args[]= {"./part2_2",NULL};
    execvp(args[0],args);
}

int Mydaemon(){
    char * args[]= {"./part2_3",NULL};
    execvp(args[0],args);
}

int main(){
    pid_t pid = fork();
    printf("PID is: %d ",pid);
    if(pid == 0) {  
        char* args[2] = {"./part2_1",NULL};
        int result = clone(Myclone,child_stack+10000, CLONE_PARENT,0);
        execvp(args[0],args);
    }

    else{
    pid_t pid2 = fork();
        if(pid2==0) {
           Mydaemon();
        }  
              print("father");
    }
    return 0;
}
