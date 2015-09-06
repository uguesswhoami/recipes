/*************************************************************************
    > File Name: singletontest.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2015年09月06日 星期日 10时02分57秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include"singleton.h"

using namespace std;

class Singletontest
{
	public:
	void print()
	{
		printf("this is singleton test.\n");
	}
};

int main()
{
	Singleton<Singletontest>::getInstance().print();
	return 0;
}
