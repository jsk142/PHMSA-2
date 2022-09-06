/*
 *  main.cpp
 *
 *  COSC 052 Fall 2019
 *  Project #2
 *
 *  Due on: OCT 10, 2019
 *  Author: jsk142
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */

#include "main.h"


int main(int argc, const char * argv[])
{
    string inputFileName = "";
    char inputFormat = '?';

    // Check if argc is less than 2
    if ( argc < 2)
    {
       string errMsg = "Not enough command line arguments, ";
       errMsg += "please pass the complete path and name\n";
       errMsg += "with character that is the code for the file format\n";
       errMsg += "processing cannot continue... goodbye.\n";

       throw invalid_argument(errMsg);
    }

    // Get full path and file name for the input data file
    inputFileName = argv[1];
  
    try
    {
        // Instantiate VehicleLog object
        VehicleLog log;
     
        // Read vehicles from the input data file 
        log.read(inputFileName);

        // Prints all valid objects
        log.print();
        cout << endl << endl;
        cout << "Total records on the vector: " << log.size() << endl;
        cout << "   Total passenger capacity: " << log.getTotalPassengerCapacity() << endl;
        cout << "       Total cargo capacity: " << log.getTotalCargoCapacity() << endl << endl;
    }

    catch (std::invalid_argument &e)
    { 
        cout << "ERROR: ";
        cout << "caught invalid_argument exception in function main\n";
        cout << e.what() << endl;
     
    }
    catch (logic_error le)
    {
        cout << "ERROR: ";
        cout << "caught logic_error exception in function main\n";
        cout << le.what() << endl;

    }
    catch (...)
    {
        cout << "ERROR: unknown exception caught in function main \n";
    }
   
    return 0;  

} // END function main