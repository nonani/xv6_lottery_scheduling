#ifndef UTHREAD_H
#define UTHREAD_H

int thread_create(void (*fcn)(void *, void *), void *arg1, void *arg2);
int thread_join(void);

#endif // UTHREAD_H