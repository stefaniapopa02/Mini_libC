#include "../include/time.h"
#include "../include/internal/syscall.h"

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp){

    long ret = syscall(__NR_nanosleep, rqtp, rmtp);
    return (int) ret;
}