#include "csapp.h"
sem_t s1, s2;
void *thread1(void *vargp);
void *thread2(void *vargp);
int x, y, z;

int main() {
    Sem_init(&s1, 0, 0);
    Sem_init(&s2, 0, 0);

    pthread_t tid_1, tid_2;
    Pthread_create(&tid_1, NULL, thread1, NULL);
    Pthread_create(&tid_2, NULL, thread2, NULL);

    Pthread_join(tid_2, NULL);
    Pthread_join(tid_1, NULL);
    printf("x: %d, y: %d, z: %d\n", x, y, z);
    return 0;
}

void *thread1(void *vargp) {
    y = 1;
    y = y + 3;
    V(&s1);
    z = y + 1;
    P(&s2);
    y = z + y;
    return NULL;
}

void *thread2(void *vargo) {
    x = 1;
    x = x + 5;
    P(&s1);
    x = x + y;
    V(&s2);
    z = z + x;
    return NULL;
}
