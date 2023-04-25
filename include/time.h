#ifndef __TIME_H__
#define __TIME_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

typedef int time_t;

struct timespec{
        time_t tv_sec;
        long tv_nsec;
};

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);
unsigned int sleep(unsigned int seconds);


#ifdef __cplusplus
}
#endif

#endif