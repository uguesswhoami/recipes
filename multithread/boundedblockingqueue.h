/*************************************************************************
    > File Name: boundedblockingqueue.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年09月06日 星期日 15时28分42秒
 ************************************************************************/
#ifndef _BOUNGED_BLOCKING_QUEUE_H_
#define _BOUNDED_BLOCKING_QUEUE_H_
#include<iostream>
#include<stdio.h>
#include<pthread.h>
#include"condition.h"
#include"mutexlock.h"
#include<boost/circular_buffer.hpp>

using namespace std;
template<class T>
class BoundedBlockingQueue
{
	public:
		BoundedBlockingQueue(int size) : m_mutexlock(),
								 m_notempty(m_mutexlock),
								 m_notfull(m_mutexlock),
								 queue(size)
		{

		}
		~BoundedBlockingQueue()
		{

		}

		void put(const T& value)
		{
			MutexLockGuard lock(m_mutexlock);
			while(queue.full())
			{
				m_notfull.wait();
			}
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
			m_notfull.notify();
			return front;
		}
	private:
		MutexLock m_mutexlock;
		Condition m_notempty;
		Condition m_notfull;
		boost::circular_buffer<T> queue;
};
#endif
