#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

int mine = 1000;
pthread_mutex_t	mutex;

void *didding_mine(void* arg)
{
    
    int id=*(int *) arg;
    while(1){
        sleep(rand()%10);
		pthread_mutex_lock(&mutex);

        if(mine<0||mine==0)
        {
		    pthread_mutex_unlock(&mutex);
            pthread_exit(NULL);
        }
        else
        {
            mine-=50;
            printf("mine = %d, id =%d\n", mine, id);
        }
		pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}

int main(int argc, char **argv)
{
    int working = 4, result, id;
    pthread_t threads[working];
    for(int i=0;i<working;i++)
    {
        id=i;
        result=pthread_create(&threads[i],NULL, didding_mine,&id);
        if (result != 0) {
			perror("Creating the first thread");
			return EXIT_FAILURE;
		}	
        else {
			//pthread_detach(threads[i]);
		}
    }
    for(int i=0;i<working;i++)
    {
    pthread_join(threads[i], NULL);
    }
}
