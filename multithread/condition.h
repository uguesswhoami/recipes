/*************************************************************************
    > File Name: condition.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年09月06日 星期日 11时37分58秒
 ************************************************************************/
#ifndef _CONDITION_H_
#define _CONDITION_H_

#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include"mutexlock.h"
using namespace std;
class Condition
{
	public:
	explicit Condition(MutexLock&  mutexlock) : m_mutexlock(mutexlock)
		{
			pthread_cond_init(&m_cond, NULL);
		}

		~Condition()
		{
			pthread_cond_destroy(&m_cond);
		}
		
		void wait()
		{
			pthread_cond_wait(&m_cond, m_mutexlock.getMutex());
		}

		void notify()
		{
			pthread_cond_signal(&m_cond);
		}

		void broadcast()
		{
			pthread_cond_broadcast(&m_cond);
		}
	private:
		MutexLock&  m_mutexlock;
		pthread_cond_t m_cond;
};
#endif
