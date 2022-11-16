#include "csapp.h"
sem_t mutex;
int cnt = 0;
void *thread(void *vargp);

int main() {
    Sem_init(&mutex, 0, 1);
    pthread_t tid_1, tid_2;
    int a = 1;
    int b = 2;
    Pthread_create(&tid_1, NULL, thread, &a);
    Pthread_create(&tid_2, NULL, thread, &b);
    
    Pthread_join(tid_1, NULL);
    Pthread_join(tid_2, NULL);
    return 0;
}

void *thread(void *vargp) {
    int *t = (int *) vargp;
    while (1) {
        P(&mutex);
        cnt++;
        printf("Message from the thread %d, now thw cnt is %d.\n", *t, cnt);
        V(&mutex);
    }
    return NULL;
}
