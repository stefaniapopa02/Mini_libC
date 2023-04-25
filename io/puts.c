#include <internal/io.h>
#include <string.h>


int puts(const char* str){
    long ret;

    ret = write(1, (const char*) str, strlen(str)); 
    if(ret < 0){
        return -1;
    }


    ret = write(1, "\n", 1);
    if(ret < 0){
        return -1;
    }

    return 1;

}