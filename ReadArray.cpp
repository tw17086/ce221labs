#include "ReadArray.h"
#include <cstdlib>
#include <fstream>

ReadArray::ReadArray(const char* filename){
	int array[100];
    int count;
    f.open(filename);
    if (!f) {
			cout << "could not open " << filename << endl;
			exit(1);
	}
}

void ReadArray::inputArray(){
	int n;  // temp to read into
	count = 0;
	bool reading = true;  // loop control
	while (reading)  // loop until we run out of file.
	{   f >> n;
	    if (!f.eof())     //  test to see if we've gone past the end of the file
	    {
	    	array[count++] = n;
	    	cout << n << endl;
	    }
	    else // done - terminate the loop, and close the file.
	    {
			reading = false;
	        f.close();  // dont forget to do this!
        }
	}
}
