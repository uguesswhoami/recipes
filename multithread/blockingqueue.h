/*************************************************************************
    > File Name: blockingqueue.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年09月06日 星期日 12时43分22秒
 ************************************************************************/
#ifndef _BLOCKING_QUEUE_H_
#define _BLOCKING_QUEUE_H_

#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<deque>
#include"mutexlock.h"
#include"condition.h"
using namespace std;

template<class T>
class BlockingQueue
{
	public:
		BlockingQueue() : m_mutexlock(),
						  m_notempty(m_mutexlock),
						  queue()
		{
			
		}
		~BlockingQueue()
		{

		}

		void put(const T& value)
		{
			MutexLockGuard lock(m_mutexlock);
			queue.push_back(value);
			m_notempty.notify();
		}

		T take()
		{
			MutexLockGuard lock(m_mutexlock);
			while(queue.empty())
			{
				m_notempty.wait();
			}
			T front = queue.front();
			queue.pop_front();
			return front;
		}
	private:
		MutexLock m_mutexlock;
		Condition m_notempty;
		std::deque<T> queue;		
};
#endif
