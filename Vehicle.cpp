/*
 *  Vehicle.cpp
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

#include "Vehicle.h"


Vehicle::Vehicle()
{
    setID(DEFAULT_ID);
    setName(DEFAULT_NAME);
    setInspectionDate(Date(MIN_YYYY, MIN_MM, MIN_DD));
    setStatus(DEFAULT_STATUS);

} // END default constructor for Vehicle class 	

Vehicle::Vehicle( string id, string n, Date d, char s )
{
    setID(id);
    setName(n);
    setInspectionDate(d);
    setStatus(s);

} // END constructor with parameters for Vehicle class

Vehicle::~Vehicle()
{
    // Nothing to do here

} // END destructor for Vehicle class

string Vehicle::getID() const
{
    return id;

} // END Vehcile::getID member function for Vehicle class

string Vehicle::getName() const
{
    return name;

} // END Vehicle::getName member function for Vehicle class

Date Vehicle::getInspectionDate() const
{
    return inspectionDate;

} // END Vehicle::getInspectionDate member function for Vehicle class

char Vehicle::getStatus() const
{
    return status;

} // END Vehicle::getStatus member function for Vehicle class
     
void Vehicle::setID( string id )
{
    // function to validate ID for Vehicle class

    bool idOK = true;

    if ( id.size() != ID_REQUIRED_LENGTH )
    {
        idOK = false;
    }

    if ( id.at(0) != TYPE_CODES[0] && id.at(0) != TYPE_CODES[1] && id.at(0) != TYPE_CODES[2] )
    {
        idOK = false;
    }

    for ( unsigned long i = 0; i < id.length(); i++ )
    {
        if ( !isalnum(id.at(i)) )
        {
            idOK = false;
        }
    }

    if ( !idOK )
    {
        string errID = "ERROR: in Vehicle class setID member function\n";
        errID += "id is invalid\n";
        invalid_argument e(errID);
        throw e;
    }

    this->id = id;

} // END Vehicle::setID member function for Vehicle class

void Vehicle::setName( string name )
{
    this->name = name;

} // END Vehicle::setName member function for Vehicle class

void Vehicle::setInspectionDate( Date iDate )
{
    inspectionDate.setDate(iDate);

} // END Vehicle::setInspectionDate member function for Vehicle class

void Vehicle::setStatus( char status )
{
    // function to validate status for Vehicle class

    bool statusOK = true;
   
    if ( status != STATUS_CODES[0] && status != STATUS_CODES[1] && status != STATUS_CODES[2] )
    {
        statusOK = false;
    }

    if ( !statusOK )
    {
        string errStatus = "ERROR: in Vehicle class setStatus member function\n";
        errStatus += "status is invalid\n";
        invalid_argument e(errStatus);
        throw e;
    }

    this->status = status;

} // END Vehicle::setStatus member function for Vehicle class
     
void Vehicle::print( ostream& os ) const
{
    // print method of the print class

    string errOutStream = "ERROR: in Vehicle class print member function\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if ( !os )
    {
        throw invalid_argument(errOutStream);
    }
    
    os << endl;
    os << "     Vehicle ID:   " << id << endl;
    os << "     Make/Model:   " << name << endl;
    os << "Last Inspection:   " << inspectionDate << endl;
    os << " Current Status:   ";

    if ( status == STATUS_CODES[0] )
    {
        os << "In Maintenance" << endl;
    }
    
    if ( status == STATUS_CODES[1] )
    {
        os << "In Service" << endl;
    }
 
    if ( status == STATUS_CODES[2] )
    {
        os << "Available" << endl;
    } 

} // END Vehicle::print member function for Vehicle class

void Vehicle::read( istream& is )
{
    // read method of the base class

    string vID;
    string vName;
    Date vInspectionDate;
    char vStatus;

    string errInStream = "ERROR: in Vehicle class read member function\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";

    if ( !is )
    {
        throw invalid_argument(errInStream);
    }
  
    try
    {
        bool streamFailed = false;

        is >> vID;
        if (!is) { streamFailed = true; }

        vName = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }

        is >> vInspectionDate;
        if (!is) { streamFailed = true; }

        is >> vStatus;      
        if (!is) { streamFailed = true; }
  
        if ( streamFailed )
        {
            string errInStream = "WARNING: in Vehicle class read member function\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "Vehicle object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }

        setID(vID);
        setName(vName);
        setInspectionDate(vInspectionDate);
        setStatus(vStatus);

    }

    catch (std::runtime_error &e)
    {
        cout << "WARNING: ";
        cout << "caught runtime_error exception in Vehicle class read member function\n";
        cout << e.what() << endl;
        // allow processing to continue, do not re-throw
    }
    catch (invalid_argument &e)
    {
        cout << "ERROR: ";
        cout << "caught invalid_argument exception in Vehicle class read member function\n";
        cout << e.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (logic_error le)
    {
        cout << "ERROR: ";
        cout << "caught logic_error exception in Vehicle class read member function\n";
        cout << le.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (...)
    {
        cout << "ERROR: unknown exception caught in Vehicle class read member function\n";
        throw;
    }

} // END Vehicle::read member function for Vehicle class

Individual::Individual() : Vehicle()
{
} // END default constructor for Individual class

Individual::Individual ( string id, string name, Date inspectionDate, char status )
          : Vehicle ( id, name, inspectionDate, status )
{
} // END constructor with parameters for Individual class

Passenger::Passenger ( unsigned short c ) : Vehicle()
{
    setCapacity(c);

} // END default constructor for Passenger class

Passenger::Passenger ( string id, string n, Date d, char s, unsigned short capacity ) 
         : Vehicle ( id, n, d, s )
{
    setCapacity(capacity);

} // END constructor with parameters for Passenger class

unsigned short Passenger::getCapacity() const
{
    return capacity;

} // END Passenger::getCapacity member function for Passenger class

void Passenger::print ( ostream& os ) const
{
    // function to print vehicle records for Passenger class

    string errOutStream = "ERROR: in Passenger class print member function\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if ( !os )
    {
        throw invalid_argument(errOutStream);
    }

    // call the print method of the base class
    Vehicle::print( os );
 
    os << "Max. Passengers:   " << capacity << endl;

} // END Passenger::print member function for Passenger class

void Passenger::read ( istream& is )
{
    // function to read vehicle records for Passenger class

    unsigned short c;

    string errInStream = "ERROR: in Passenger class read member function\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";

    if ( !is )
    {
        throw invalid_argument(errInStream);
    }

    try
    {
        bool streamFailed = false;

        // call the read method of the base class
        Vehicle::read( is );
        if (!is) { streamFailed = true; }

        is >> c;
        if (!is) { streamFailed = true; }
    

        if ( streamFailed )
        {
            string errInStream = "WARNING: in Passenger class read member function\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "Passenger object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }

        setCapacity(c);
    }

    catch (std::runtime_error &e)
    {
        cout << "WARNING: ";
        cout << "caught runtime_error exception in Passenger class read member function\n";
        cout << e.what() << endl;
        // allow processing to continue, do not re-throw
    }
    catch (too_many_passengers tmp)
    {
        cout << "ERROR: ";
        cout << "caught too many passengers exception in Passenger class read member function\n";
        cout <<  tmp.what() << endl; 
        throw;
    }
    catch (invalid_argument &e)
    {
        cout << "ERROR: ";
        cout << "caught invalid_argument exception in Passenger class read member function\n";
        cout << e.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (logic_error le)
    {
        cout << "ERROR: ";
        cout << "caught logic_error exception in Passenger class read member function\n";
        cout << le.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (...)
    {
        cout << "ERROR: unknown exception caught in Passenger class read member function\n";
        throw;
    }

} // END Passenger::read member function for Passenger class 

void Passenger::setCapacity ( unsigned short cap )
{
    // function to validate capacity for Passenger class

    bool capacityOK = true;

    if ( cap < MIN_PASSENGER_CAPACITY || cap > MAX_PASSENGER_CAPACITY )
    {
        capacityOK = false;
    }

    if ( !capacityOK )
    { 
        throw too_many_passengers("ERROR: Maximum passenger transport capacity reached!\n");
    }

    capacity = cap;

} // END Passenger::setCapacity member function for Passenger class

Cargo::Cargo ( double c ) : Vehicle ()
{
    setCapacity(c);

} // END default constructor for Cargo class

Cargo::Cargo ( string id, string n, Date d, char s, double capacity )
    : Vehicle ( id, n, d, s )
{
    setCapacity(capacity);

} // END constructor with parameters for Cargo class

double Cargo::getCapacity() const
{
    return capacity;

} // END Cargo::getCapacity member function for Cargo class

void Cargo::print ( ostream& os ) const
{
    // function to print vehicle records for Cargo class

    string errOutStream = "ERROR: in Cargo class print member function\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if ( !os )
    {
        throw invalid_argument(errOutStream);
    }

    // call the print method of the base class
    Vehicle::print( os );
 
    os << "   Max. Payload:   " << capacity << " tons" << endl;

} // END Cargo::print member function for Cargo class

void Cargo::read ( istream& is )
{
   // function to read vehicle records for Cargo class

    double c;

    string errInStream = "ERROR: in Cargo class read member function\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";

    if ( !is )
    {
        throw invalid_argument(errInStream);
    }

    try
    {
        bool streamFailed = false;

        // call the read method of the base class
        Vehicle::read( is );
        if (!is) { streamFailed = true; }

        is >> c;
        if (!is) { streamFailed = true; }

        if ( streamFailed )
        {
            string errInStream = "WARNING: in Cargo class read member function\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "Cargo object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }
  
        setCapacity(c);
    }

    catch (std::runtime_error &e)
    {
        cout << "WARNING: ";
        cout << "caught runtime_error exception in Cargo class read member function";
        cout << e.what() << endl;
        // allow processing to continue, do not re-throw
    }
    catch (too_much_cargo tmc)
    {
        cout << "ERROR: ";
        cout << "caught too many passengers exception in Cargo class read member function\n";
        cout <<  tmc.what() << endl; 
        throw;
    }
    catch (invalid_argument &e)
    {
        cout << "ERROR: ";
        cout << "caught invalid_argument exception in Cargo class read member function\n";
        cout << e.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (logic_error le)
    {
        cout << "ERROR: ";
        cout << "caught logic_error exception in Cargo class read member function\n";
        cout << le.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (...)
    {
        cout << "ERROR: unknown exception caught in Cargo class read member function\n";
        throw;
    }

} // END Cargo::read member function for Cargo class

void Cargo::setCapacity ( double cap )
{
    // function to validate capacity for Cargo class

    bool capacityOK = true;

    if ( cap < MIN_CARGO_CAPACITY || cap > MAX_CARGO_CAPACITY )
    {
        capacityOK = false;
    }

    if ( !capacityOK )
    {
        throw too_much_cargo("ERROR: Maximum payload hauling capacity reached!\n");
    }
 
    capacity = cap;

} // END Cargo::setCapacity member function for Cargo class