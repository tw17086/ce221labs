#ifndef _READARRAY_H_
#define _READARRAY_H_

using namespace std;
#include <iostream>
#include <fstream>

class ReadArray
{ public:
    ReadArray(const char* filename);
    int array[100];
    int count;
    void inputArray();
  private:
    ifstream f;
};

#endif