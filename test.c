#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "uthread.h"

void wrapper(void *arg1, void *arg2) {
    int *arg = (int *)arg1;
    *arg = 100;
    printf(1, "Exiting thread\n");
    exit();
}

int main() {
    int a = 0;
    printf(1, "Creating thread\n");
    int tid = thread_create(wrapper, (void *)&a, 0);
    if(tid == -1){
        printf(1, "Error: thread_create failed\n");
        exit();
    }
    tid = thread_join();
    if(tid == -1){
        printf(1, "Error: thread_join failed\n");
        exit();
    }
    if(a != 100){
        printf(1, "Error: thread function failed\n");
    } else {
        printf(1, "Thread function succeeded\n");
    }
    printf(1, "Exiting main thread\n");
    exit();
}