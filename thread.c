#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_NUM 10

pthread_mutex_t lock;
pthread_cond_t cond;

int counter=1;

void* printodd(void* arg){
    while(counter<=MAX_NUM){
        pthread_mutex_lock(&lock);
        if(counter%2==1){
            printf("odd thread:%d",counter);
            counter++;
            pthread_cond_signal(&cond);
        }
        
        else{
            pthread_cond_wait(&cond,&lock);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}


void* printeven(void* arg){
    while(counter<=MAX_NUM){
        if(counter%2==0){
            printf("even thread: %d",counter);
            counter++;
            pthread_cond_signal(&cond);
        }
        else{
            pthread_cond_wait(&cond,&lock);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(){
    pthread_t thread1,thread2;
    
    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);
    
    
    
    pthread_create(&thread1,NULL,printodd,NULL);
    pthread_create(&thread2,NULL,printeven,NULL);
    
    
    pthread_join(thread1);
    pthread_join(thread2);
    
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    
    return 0;
}
