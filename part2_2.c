#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE 10000
#define CYCLES 10000
char child_stack[STACK_SIZE+1];

void print (const char *text){
    int i;
    for(i=0; i<CYCLES; i++){
        printf("Hello from %s\n", text);
        usleep(1000000);
    }
}
int child(){
    print("child_thread");
}

int child2(){
    print("child2");
}

int main(){
    int result = clone(child, child_stack+STACK_SIZE,CLONE_PARENT,0);
    int result2 = clone(child2 , child_stack+STACK_SIZE , CLONE_PARENT,0);
  //  printf("clone result = %d\n" , result);
    print("parent");
    return 0;
}