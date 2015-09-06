/*************************************************************************
    > File Name: multithreadtest.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年09月06日 星期日 10时53分16秒
 ************************************************************************/

#include<iostream>
#include<pthread.h>
#include"mutexlock.h"
#include"condition.h"
//#include"blockingqueue.h"
#include"boundedblockingqueue.h"
using namespace std;
MutexLock g_mutex;
BoundedBlockingQueue<int> bq(20);
//BlockingQueue<int> bq;
int global_var = 0;
void* thread1(void *)
{
	for(int i = 0; i < 100; i++)
	{
		{
		printf("this is thread1 produce product\n");
			bq.put(i);
		//	MutexLockGuard lock(g_mutex);
		//	global_var++;
		//	sleep(1);
		}
	//	printf("this is thread1,i = %d\n",global_var);
//		sleep(1);
	}
	return NULL;
}

void* thread2(void *)
{
	for(int i = 0; i < 109; i++)
	//while(true)
	{
		{
		//	MutexLockGuard lock(g_mutex);
		//	global_var++;
		}
		printf("this is thread2,product is %d\n ",bq.take());
	//	printf("this is thread2,i = %d\n",global_var);
	}
	return NULL;
}
int main()
{
	pthread_t tid1, tid2;
//	pthread_create(&tid1, NULL, thread1,NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}
