/*
 *  VehicleLog.cpp
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

#include "VehicleLog.h"


VehicleLog::VehicleLog()
{
    // Nothing to do here

} // END default constructor for VehicleLog class
     
VehicleLog::~VehicleLog()
{
    // deallocates all dynamically allocated memory

    for (int i = 0; i < vehicles.size(); i++ )
    {
        delete ( vehicles.at(i) );
    } 

    vehicles.clear();

} // END destructor for VehicleLog class

int VehicleLog::getTotalPassengerCapacity() const
{
    int totalPassengerCapacity = 0;

    for ( unsigned long i = 0; i < vehicles.size(); i++ )
    {
        Passenger *ptr= dynamic_cast<Passenger*>(vehicles.at(i));

        if ( ptr )
        {
            totalPassengerCapacity += ptr->getCapacity();
        }
    }

    return totalPassengerCapacity;
   
} // END VehicleLog::getTotalPassengerCapacity member function for VehicleLog class

double VehicleLog::getTotalCargoCapacity() const
{
    double totalCargoCapacity = 0;

    for ( unsigned long i = 0; i < vehicles.size(); i++ )
    {
        Cargo *ptr= dynamic_cast<Cargo*>(vehicles.at(i));

        if ( ptr )
        {
            totalCargoCapacity += ptr->getCapacity();
        }
    }

    return totalCargoCapacity;  
 
} // END VehicleLog::getTotalCargoCapacity member function for VehicleLog class
     
void VehicleLog::print( ostream& os ) const
{
    // print method of VehicleLog class

    std::string errOutStream = "ERROR: in VehicleLog class print member function\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }  

    for ( unsigned long i = 0; i < vehicles.size(); i++ )
    { 
        vehicles.at(i)->print();
    }

} // END VehicleLog::print member function for VehicleLog class

void VehicleLog::read( string fileName )
{
    // read method of VehicleLog class
    // pointer of valid objects shall be appended to the end of the VehicleLog's vector

    char vType = '?';
    bool answer = true;
    Vehicle *addMe = NULL;
    string throwaway;

    std::ifstream inFile;

    inFile.open(fileName.c_str());

    std::string errInStream = "ERROR: in VehicleLog class read member function\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";

    if (!inFile)
    {
        throw std::invalid_argument(errInStream);
    }

    try
    {
        vType = inFile.peek();

        if ( vType != TYPE_CODES[0] && vType != TYPE_CODES[1] && vType != TYPE_CODES[2] )
        {
            throw bad_vehicle_code("ERROR: Vehicle code not valid!\n");
        }

        switch (vType)
        {
            case 'i':
            addMe = new Individual;
            break;
 
            case 'p':
            addMe = new Passenger;
            break;
 
            case 'c':
            addMe = new Cargo;
            break;
        }

        addMe->read(inFile);
    }

    catch (bad_vehicle_code bvc)
    {   
        cout << "ERROR: caught bad vehicle code exepction";
        cout << " in Vehicle Log class read member function\n";
        cout << bvc.what() << endl;
        getline(inFile, throwaway);
        answer = false;
    }
    catch (too_many_passengers tmp)
    {   
        cout << "ERROR: caught too many passengers exepction";
        cout << " in Vehicle Log class read member function\n";
        cout << tmp.what() << endl;
        getline(inFile, throwaway);
        answer = false;
    }
    catch (too_much_cargo tmc)
    {   
        cout << "ERROR: caught too much cargo exepction";
        cout << " in Vehicle Log class read member function\n";
        cout << tmc.what() << endl;
        getline(inFile, throwaway);
        answer = false;
    }
    catch (invalid_argument &e)
    {
        cout << "ERROR: caught invalid argument exception";
        cout << " in VehicleLog class read member function\n";
        cout << e.what() << endl;
        getline(inFile, throwaway);
        answer = false;
    }
    catch (logic_error le)
    {
        cout << "ERROR: ";
        cout << "caught logic_error exception in VehicleLog class read member function\n";
        cout << le.what() << endl;
        getline(inFile, throwaway);
        answer = false;
    }
    catch (...)
    {   
        cout << "ERROR: unknown exception caught";
        cout << " in VehicleLog class read member function\n";
        answer = false;
    }
    
    while ( inFile )
    {
        if ( answer )
        {
            vehicles.push_back(addMe);
        }
 
        answer = true;
 
        try
        {
            vType = inFile.peek();

            if ( vType != TYPE_CODES[0] && vType != TYPE_CODES[1] && vType != TYPE_CODES[2] )
            {
                throw bad_vehicle_code("ERROR: Vehicle code not valid!\n");
            }

            switch (vType)
            {
                case 'i':
                addMe = new Individual;
                break;
 
                case 'p':
                addMe = new Passenger;
                break;
 
                case 'c':
                addMe = new Cargo;
                break;
            }

            addMe->read(inFile);
        }

        catch (bad_vehicle_code bvc)
        {   
            cout << "ERROR: caught bad vehicle code exepction";
            cout << " in Vehicle Log class read member function\n";
            cout << bvc.what() << endl;
            getline(inFile, throwaway);
            answer = false;
        }
        catch (too_many_passengers tmp)
        {   
            cout << "ERROR: caught too many passengers exepction";
            cout << " in Vehicle Log class read member function\n";
            cout << tmp.what() << endl;
            getline(inFile, throwaway);
            answer = false;
        }
        catch (too_much_cargo tmc)
        {   
            cout << "ERROR: caught too much cargo exepction";
            cout << " in Vehicle Log class read member function\n";
            cout << tmc.what() << endl;
            getline(inFile, throwaway);
            answer = false;
        }
        catch (invalid_argument &e)
        {
            cout << "ERROR: caught invalid argument exception";
            cout << " in VehicleLog class read member function\n";
            cout << e.what() << endl;
            getline(inFile, throwaway);
            answer = false;
        }
        catch (logic_error le)
        {
            cout << "ERROR: ";
            cout << "caught logic_error exception in VehicleLog class read member function\n";
            cout << le.what() << endl;
            getline(inFile, throwaway);
            answer = false;
        }
        catch (...)
        {   
            cout << "ERROR: unknown exception caught";
            cout << " in VehicleLog class read member function\n";
           answer = false;
        }
    }          

    inFile.close();

} // END VehicleLog::read member function for VehicleLog class
     
unsigned long VehicleLog::size() const
{
    return vehicles.size();

} // END VehicleLog::size member function for VehicleLog class
    
Vehicle& VehicleLog::at(unsigned long ndx)
{
    return *vehicles.at(ndx);

} // END VehicleLog::at member function for VehicleLog class
     