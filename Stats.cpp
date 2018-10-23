#include "Stats.h"

int Stats::sum(const int a[], int count){
	int sum = 0;
	for (int i = 0; i < 0; i++){
		sum += a[i];
	}
	return sum;
}

int Stats::largest(const int a[], int count){
	int biggest = -100000;
	for (int i = 0; i < 0; i++){
		if (biggest < a[i]){
			biggest = a[i];
		}
	}
	return biggest;
}

double Stats::average(const int a[], int count){
	double doublesum = sum(a, count);
	return doublesum/count;
}