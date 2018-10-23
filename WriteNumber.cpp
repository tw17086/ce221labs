/**
 *  This is the implementation of the WriteNumber class.
 */

#include "WriteNumber.h"

// need cstdlib header for declaration of exit function
// will work in some compilers without this
#include <cstdlib>

/**
 * implementation of WriteNumber Constructor.
 * Its function is to open the file and associate it with the stream. It is opened for writing, as "out" is an ofstream.
 * @param filename - c style string.
 * Exits after perorting an error if it cannot open the file.
 */
WriteNumber::WriteNumber(const char *filename)
{   out.open(filename);  // will create the file if it does not exist, or overwrite it if it does exist
                         // could fail if file or folder have insufficient access permission
    if (!out)
    {   cout << "cannot make " << filename << endl;
        exit(1);
    }
}

/**
 *  Implementation of writeInt.
 */
void WriteNumber::writeInt(int n)
{   out << n << endl;
}

/**
 * Implementation of writeDouble.
 */
void WriteNumber:: writeDouble(double d)
{   out << d << endl;
}

/**
 * Implementation of writeString.
 */
void WriteNumber:: writeString(const char *s)
{   out << s;
}

/**
 *  Implementation of close.
*/
void WriteNumber:: close()
{   out.close();
}
