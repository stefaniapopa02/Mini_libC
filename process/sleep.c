#include "../include/time.h"

unsigned int sleep(unsigned int seconds){
    struct timespec rqtp;
    struct timespec rmtp;

    rqtp.tv_sec = seconds;
    rqtp.tv_nsec = 0;

    int ret =  nanosleep((const struct timespec*) &rqtp, &rmtp);
    return (unsigned int) ret;

}