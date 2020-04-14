#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*hello_message)(const char*);

bool init_libaray(){
    void *hdl = dlopen("./libHello.so", RTLD_LAZY);
    if (NULL == hdl)
    {
        return false;
    }
    hello_message = (void(*)(const char *))dlsym(hdl, "print");
    if(NULL == hello_message){
         return false;
    }
   return true;

}
int main()
{
   if(init_libaray())
        hello_message("Ariel");
    else
    {
        printf("Library was not loaded \n");
    }
        
    return 0;
}

