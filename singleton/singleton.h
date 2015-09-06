/*************************************************************************
    > File Name: singleton.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年09月06日 星期日 09时47分40秒
 ************************************************************************/
#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include<iostream>
#include<pthread.h>
#include<stdio.h>
using namespace std;

template<class T>
class Singleton
{
	public:
		static T& getInstance()
		{
			pthread_once(&ponce, &Singleton::init);
			return *instance;
		}
		static void init()
		{
			instance = new T();
		}
	private:
		Singleton(){}
		~Singleton(){}
	private:
		static T *instance;
		static pthread_once_t ponce;
};

template<class T>
pthread_once_t Singleton<T>::ponce = PTHREAD_ONCE_INIT;

template<class T>
T* Singleton<T>::instance = NULL;
#endif
