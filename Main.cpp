#include "ReadArray.h"
#include "Stats.h"
#include "WriteNumber.h"
using namespace std;
#include <iostream>

int main(){
	ReadArray ra("Data.dat");
	ra.inputArray();

	WriteNumber wn("outputfile.dat");

	wn.writeString("The sum is ");
	wn.writeInt(Stats::sum(ra.array, ra.count));

	wn.writeString("The largest is ");
	wn.writeInt(Stats::largest(ra.array, ra.count));

	wn.writeString("The average is ");
	wn.writeDouble(Stats::average(ra.array, ra.count));


	return 0;
}