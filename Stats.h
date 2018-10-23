#ifndef _STATS_H_
#define _STATS_H_

using namespace std;
#include <iostream>

class Stats{

	public:

	//count = size of array
	static double average(const int a[], int count);
	static int largest(const int a[], int count);
	static int sum(const int a[], int count);

};

#endif