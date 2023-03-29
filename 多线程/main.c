#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
long led0 = 0b0001;
long led1 = 0b1000;
void *thread1(void *arg)
{
    int i = 3;
    for (;;)
    {
        if (i == 3)
        {
            while (i >= 0)
            {
                printf("%ld ", led0);
                fflush(stdout);
                sleep(1);
                led0 = led0 << 1;
                i--;
            }
        }
        led0 = led0 >> 1;
        i += 1;
        if (i == 0)
        {
            while (i < 4)
            {
                printf("%ld ", led0);
                fflush(stdout);
                sleep(1);
                led0 = led0 >> 1;
                i++;
            }
        }
        i = 3;
        led0 = 0b001;
        fflush(stdout);
    }
}
void *thread2(void *arg)
{
    int i = 4;
    for (;;)
    {
        if (i == 4)
        {
            while (i < 8)
            {
                printf("%ld ", led1);
                // printf("%d",i);
                fflush(stdout);
                sleep(1);
                i++;
                if (i < 8)
                    led1 = led1 >> 1;
            }
        }
        i -= 1;
        if (i == 7)
        {
            while (i >= 4)
            {
                printf("%ld ", led1);
                fflush(stdout);
                sleep(1);
                led1 = led1 << 1;
                i--;
            }
        }
        i = 4;
        led1 = 0b1000;
        fflush(stdout);
    }
}
int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1,NULL,thread1,NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2, NULL);
    return 0;
}
