#include "ReadArray.h"
#include "Stats.h"
#include "WriteNumber.h"
using namespace std;
#include <iostream>

int main(int argc, char *argv[]){
	const char* infile;
	const char* outfile;

	if (argc < 3) {
		infile = "Data.dat";
		outfile = "outputfile.dat";
		cout << "Too few arguments, using default files" << endl;
	} else if (argc == 3) {
		infile = argv[1];
		outfile = argv[2];
	} else {
		cout << "Too many arguments";
		return 1;
	}

	ReadArray ra(infile);
	ra.inputArray();

	WriteNumber wn(outfile);

	wn.writeString("The sum is ");
	wn.writeInt(Stats::sum(ra.array, ra.count));

	wn.writeString("The largest is ");
	wn.writeInt(Stats::largest(ra.array, ra.count));

	wn.writeString("The average is ");
	wn.writeDouble(Stats::average(ra.array, ra.count));

	cout << "The sum is " << Stats::sum(ra.array, ra.count)
	<< ". The largest is " << Stats::largest(ra.array, ra.count)
	<< ". The average is " << Stats::average(ra.array, ra.count);

	return 0;
}