/*************************************************************************
    > File Name: mutexlock.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年09月06日 星期日 10时31分43秒
 ************************************************************************/
#ifndef _MUTEX_LOCK_H_
#define _MUTEX_LOCK_H_
#include<iostream>
#include<stdio.h>
#include<pthread.h>
using namespace std;

class MutexLock
{
	public:
		MutexLock()
		{
			pthread_mutex_init(&mutex, NULL);
		}

		~MutexLock()
		{
			pthread_mutex_destroy(&mutex);
		}

		void lock()
		{
			pthread_mutex_lock(&mutex);
		}

		void trylock()
		{
			pthread_mutex_trylock(&mutex);
		}
		void unlock()
		{
			pthread_mutex_unlock(&mutex);
		}
		
		pthread_mutex_t* getMutex()
		{
			return &mutex;
		}
	private:
		pthread_mutex_t mutex;
};

class MutexLockGuard
{
	public:
		explicit MutexLockGuard(MutexLock& mutex) : m_mutex(mutex)
		{
			m_mutex.lock();
		}

		~MutexLockGuard()
		{
			m_mutex.unlock();
		}
	private:
		MutexLock& m_mutex;
};
#endif
