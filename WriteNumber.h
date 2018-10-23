/**
 *  A class to write ints and doubles to an arbitrary file as a complete line.
 *  A string writer is included as a gift.
 */

#ifndef _WRITENUMBERS_H_
#define _WRITENUMBERS_H_

using namespace std;
#include <iostream>
#include <fstream>

class WriteNumber
{   private:
        ofstream out;

    public:
        /*
          Constructor to initialise the output stream and create the output file if it doesn't exist.
          @param filename - a c-string like "fred.txt"
          Program exits with an error message if it cannot create the file.
        */
        WriteNumber(const char *filename);

        /*
          function to write an int to a file, followed by an end of line.
          @param n - integer to write
        */
        void writeInt(int n);

        /*
          function to write a double to a file, followed by an end of line.
          @param d - double to write
        */
        void writeDouble(double d);

        /*
          Writes a C-string to a file, no end of line.
          @param s - c style string to write.
        */
        void writeString(const char *s);

        /*
          function to close the file, thus ensuring it is stable on disk,
        */
       void close();
};

#endif
