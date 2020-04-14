//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void print (const char *text){

    int i;
    for(i=0; i<20; i++){
        printf("Hello from %s/n", text);
        usleep(10000000) ;
    }
}

int main(){
    __pid_t pid = fork();
    if(pid == 0){
        __pid_t pid = fork();
        if (pid == 0)
    {
        print("grandfather");
    }
    else
    {
        print("child");
    }
 }
else
{
    print("parent");
}
return 0;

}