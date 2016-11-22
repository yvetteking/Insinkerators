#ifndef DALE_H_INCLUDED
#define DALE_H_INCLUDED

#include <iostream>     //for cin, cout
#include <sstream>      //for stringstream
#include <fstream>      //for ifstream, ofstream
#include <vector>       //for vector
#include <iomanip>      //for setw()

using namespace std;

#include "Tickets.h"
#include "Yvette.h"
#include "Lazaro.h"
#include "Brittany.h"

const int NUM_OF_EMPLOYEES = 2; //change the num of employees here

void newTicket(vector<Tickets>&);
void displayHeader(vector<Tickets>&);
void openMaintLog(vector<Tickets>&);
void populateVector (vector<Tickets>&);
void mainMenu(vector<Tickets>&);
string todaysDate();
void createWorkforce(vector<Tickets>&);

/**************************************************************************
Programmer: Dale Ming

The createWorkforce function simply creates two Employee struct objects
and assigns the object a name and employee number. The function the prompts
the user for the names of the workers and asks if the input is correct. If
the info is correct the displayHeader function is called and if the input
is incorrect, the createWorkforce is called.

The input will be string names and a char y/n.

The output will be maintenance workforce inf and prompting for correctness,
the function will return nothing.

                ****************************************************
                ****************************************************
                **                                                **
                ** This functions output and input need work!     **
                ** There is no error checking or input validation!**
                **                                                **
                ****************************************************
                ****************************************************

**************************************************************************/
void createWorkforce(vector<Tickets>& TicketLog)
    {
        Employee* empPool;
        empPool = new Employee[NUM_OF_EMPLOYEES];       //dynsmcally allocates an array of struct pointers

        cout << "The number of workers is currently set at " << NUM_OF_EMPLOYEES
             << ". \nPlease contact the admin to adjust the number of employees.\n";
        for (int index = 0; index < NUM_OF_EMPLOYEES; index++)
            {
                cout << "Please key in the name of the maintenance worker number " << index +1 << ": ";
                getline(cin, empPool[index].employeeName);           //sets employeeName directly
                empPool[index].setEmployeeNumber(index + 1);    //sets employeeNumber thru the set function
            }
        int flag = 1;
        while (flag == 1)
            {
                cout << "\n\nToday's workforce is: \n";
                cin.ignore(0);
                for (int index = 0; index < NUM_OF_EMPLOYEES; index++)
                    {
                        cout << "\t\t" << empPool[index].employeeNumber << ":  "
                             << empPool[index].getEmployeeName() << endl;
                    }
                cout << "Is this correct? (y/n)\n";

                char response;
                cin >> response;

                if (response == 'y')
                    {
                        displayHeader(TicketLog);
                        mainMenu(TicketLog);
                        flag = 2;
                        break;
                    }

                else if (response == 'n')
                    {
                        cin.ignore();
                        createWorkforce(TicketLog);
                        flag = 1;
                    }
            }
    }

/**************************************************************************
Programmer: Dale Ming

This is basically a stub function that demonstrates the calling of the
todaysDate() function. The function creates a new Tickets object and adds
it to the Tickets object vector. Then the function displays a statement
that a new object had been create and reports the new date.
**************************************************************************/
void newTicket(vector<Tickets>& TicketLog)
    {
        Tickets workTicket;
        TicketLog.push_back(workTicket);

        /******************************************************************
        The size of the vector returned by TicketLog.size() seems to always
        be 1 higher than the actual number of tickets, so I decrement it in
        order to place information in the correct vector[index] position.
        *******************************************************************/
        int newObjectPosition = TicketLog.size() - 1;
        string temp = ",\n";
        TicketLog[newObjectPosition].setDate(todaysDate());
        cout << "Ticket object for " << TicketLog[newObjectPosition].getDate()
             << " is created.\n\n";
        //TicketLog[newObjectPosition].setNotes(temp);
        displayHeader(TicketLog);
        mainMenu(TicketLog);
    }

/**************************************************************************
Programmer: Dale Ming

The displayHeader function is called by main() and accepts a reference to
the vector of class Tickets objects. The function uses a while loop to
output the return values of selected Tickets class member functions to the
console to represent the list of pending maintenance tickets.

The function requires no user input, all input id from the vector, and all
output is to the console.
**************************************************************************/
void displayHeader(vector<Tickets>& TicketLog)
    {
        int size = TicketLog.size();
        int index = 0;

        while(index < size)
            {
                cout << right << setw(10)
                     << TicketLog[index].getTicketNumber() << "  "
                     << TicketLog[index].getDate() << "  "
                     << TicketLog[index].getApt() << "  " << left << setw(10)
                     << TicketLog[index].getIssue() << "  "
                     << TicketLog[index].getNotes() << endl;
                 index++;
            }
    }

/**************************************************************************
Programmer: Dale Ming

populateVector is called by main() and executes to populate a vector of
class Tickets objects. The function accepts a reference to the vector of
Tickets objects and names it "TicketLog". The function opens the
TicketLog.txt file where it extracts the saved ticket information. Each
field is separated by a comma that I use as a delimiter to trigger the end
of the field. As each instance of the object is created the member variables
are populated with the necessary information.

The function does not require any user input and the output is to the vector
of class Tickets objects.
**************************************************************************/
void populateVector (vector<Tickets>& TicketLog)
    {
        ifstream maintFile("TicketLog.txt", ios::in);//ifstream object
        //ifstream maintFile("TicketLogSave.txt", ios::in);
        if (!maintFile)
            cout << "Error opening file!";
        string temp;

        for (int index = 0; !(maintFile.eof()); index++)
            {
        /******************************************************************
        The next 2 lines of code creates a new instance of the class
        Tickets object and pushes back the size of the TicketLog vector to
        allocate enough space for the object.
        ******************************************************************/
                Tickets workTicket;
                TicketLog.push_back(workTicket);

                getline(maintFile, temp, '~');
                TicketLog[index].setTicketStatus(temp);  //status

                getline(maintFile, temp, '~');
                TicketLog[index].setTicketNumber(temp); //ticket number

                getline(maintFile, temp, '~');
                TicketLog[index].setDate(temp);         //date

                getline(maintFile, temp, '~');
                TicketLog[index].setApt(temp);          //apt number

                getline(maintFile, temp, '~');
                TicketLog[index].setName(temp);         //name

                getline(maintFile, temp, '~');
                TicketLog[index].setPhone(temp);        //phone

                getline(maintFile, temp, '~');
                TicketLog[index].setPriority(temp);     //priority

                getline(maintFile, temp, '~');
                TicketLog[index].setIssue(temp);        //issue

                getline(maintFile, temp, '\n');
                TicketLog[index].setNotes(temp);        //notes
            }
            maintFile.close();  //close that file!!
    }


/**************************************************************************
Programmer: Dale Ming

todaysDate is a public member function of the Tickets class, it will return
the current date for new tickets. It could also be used for getting the
date if we want to attach a date to the closing of a ticker.
setDate is a function that returns the date as a string. The
struct tm is a <ctime> structure that has members for each
component of the date and time. timeMarker is a pointer for
the current time calculated by <ctime>'s function localtime( )
which accepts the address of the value returned by time(0). A
struct pointer object is created to point at the return values
of several of tm's functions Each one is then passed to a
stringstream object and converted to a string.
**************************************************************************/
string todaysDate()
    {
        //time() returns the number of seconds since 1-1-70
        time_t currentTime = time(0);
        //localtime returns the local time using current time as
        //a reference
        struct tm* timeMarker = localtime( & currentTime );
        //string object to hold the date
        stringstream dateStream;
        //pass each part of the date to a stream object separated
        //by a "/"
        dateStream << (timeMarker->tm_mon + 1)
                   << "/" << timeMarker->tm_mday << "/"
                   <<(timeMarker->tm_year + 1900);
        //convert the stringstream object into a string object
        string date = dateStream.str();
        return date;
    }

/**************************************************************************
Programmer: Dale Ming

openMaintLog is called when the exit item is selected on the main menu and
executes before the program closes. It opens the TicketLog.txt and
repopulates it with the contents of the Tickets vector. The function
accepts a reference to the vector of class Tickets objects and names it
TicketLog (I keep the name of the vector consistent for ease of reading)
indexes thru each of the Tickets class member "get" functions and saves
their return value to the file followed by a comma.

No input from the user is required and the output will be to a file, not
to the console.
**************************************************************************/
void openMaintLog(vector<Tickets>& TicketLog)
    {
        ofstream maintSaveFile("TicketLogSave.txt", ios::out);  //ofstream object
        if (!maintSaveFile)
            cout << "Error opening file!";
        else
            {

            int size = TicketLog.size();
            int index = 0;
            while(index < size)
                {               // "," is my delimiter to separate the fields
                    maintSaveFile << TicketLog[index].getTicketStatus() << "~";
                    maintSaveFile << TicketLog[index].getTicketNumber() << "~";
                    maintSaveFile << TicketLog[index].getDate() << "~";
                    maintSaveFile << TicketLog[index].getApt() << "~";
                    maintSaveFile << TicketLog[index].getName() << "~";
                    maintSaveFile << TicketLog[index].getPhone() << "~";
                    maintSaveFile << TicketLog[index].getPriority() << "~";
                    maintSaveFile << TicketLog[index].getIssue() << "~";
                    maintSaveFile << TicketLog[index].getNotes() << "\n\n";
                    index++;
                }
            }
        maintSaveFile.close();      //close that file!!
    }



#endif // DALE_H_INCLUDED
