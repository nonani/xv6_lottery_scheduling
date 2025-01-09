#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "uthread.h"

int thread_create(void (*fcn)(void *, void *), void *arg1, void *arg2) {
    void *stack = malloc(4096); // Allocate 4KB for user stack
    if (stack == 0)
        return -1;

    int tid = clone(fcn, arg1, arg2, stack);
    if (tid == -1) {
        free(stack);
    }
    return tid;
}

int thread_join(void) {
    void *stack;
    int tid = join(&stack);
    if (tid != -1) {
        free(stack);
    }
    return tid;
}