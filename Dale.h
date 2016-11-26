#ifndef DALE_H_INCLUDED
#define DALE_H_INCLUDED

#include <iostream>     //for cin, cout
#include <sstream>      //for stringstream
#include <fstream>      //for ifstream, ofstream
#include <vector>       //for vector
#include <iomanip>      //for setw()

using namespace std;

const int NUM_OF_EMPLOYEES = 2;
const int NUM_OF_LINES = 25;

void newTicket(vector<Tickets>&, vector<Tickets>&);
void displayHeader(vector<Tickets>&);
void openMaintLog(vector<Tickets>&, vector<Tickets>&);
void populateVector (vector<Tickets>&, vector<Tickets>&);
void mainMenu(vector<Tickets>&, vector<Tickets>&);
string todaysDate();
void createWorkforce(vector<Tickets>&, vector<Tickets>&);
void clearScreen(const int);
void adjustScreen(int);
void pauseScreen();

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
                                        ** This functions input and output need work!     **
                                        ** There is no error checking or input validation!**
                                        **                                                **
                                        ****************************************************
                                        ****************************************************

**************************************************************************/
void createWorkforce(vector<Tickets>& openTicketLog, vector<Tickets>& closedTicketLog)
    {
        cin.ignore(1);
        Employee* empPool;
        empPool = new Employee[NUM_OF_EMPLOYEES];       //dynamically allocates an array of struct pointers

        cout << "\t\tThe number of workers is currently set at " << NUM_OF_EMPLOYEES
             << ". \n\t\tPlease contact the admin to adjust the number of employees.\n";

        for (int index = 0; index < NUM_OF_EMPLOYEES; index++)
            {
                clearScreen(NUM_OF_LINES);
                cout << "\t    Please key in the name of the maintenance worker number " << index +1 << ": ";
                adjustScreen(12);
                cout << "\t\t\t\t\t";
                getline(cin, empPool[index].employeeName);           //sets employeeName directly
                empPool[index].setEmployeeNumber(index + 1);    //sets employeeNumber thru the set function
            }
        int flag = 1;
        while (flag == 1)
            {
                clearScreen(NUM_OF_LINES);
                cout << "\n\n\t\t\tToday's workforce is: \n";
                cin.ignore(0);
                for (int index = 0; index < NUM_OF_EMPLOYEES; index++)
                    {
                        cout << "\t\t\t\t\t" << empPool[index].employeeNumber << ":  "
                             << empPool[index].getEmployeeName() << endl;
                    }
                cout << "\t\t\tIs this correct? (y/n)\n";
                adjustScreen(10);
                cout << "\t\t\t\t\t";
                char response;
                cin >> response;

                if (response == 'y')
                    {
                        clearScreen(NUM_OF_LINES);
                        displayHeader(openTicketLog);
                        mainMenu(openTicketLog, closedTicketLog);
                        flag = 2;
                        break;
                    }

                else if (response == 'n')
                    {
                        cin.ignore();
                        clearScreen(NUM_OF_LINES);
                        createWorkforce(openTicketLog, closedTicketLog);
                        flag = 1;
                    }
            }
    }

/**************************************************************************

Programmer: Dale Ming

This is basically a stub function that demonstrates the calling of the
todaysDate() function. The function creates a new Tickets object and adds
it to the Tickets object vector. T

**************************************************************************/

                                /******************************************************************
                                *******************************************************************
                                **                                                               **
                                ** This function should be deleted and replaced by the programmer**
                                ** taking on new ticket input.                                   **
                                **
                                *******************************************************************
                                ******************************************************************/

void newTicket(vector<Tickets>& openTicketLog, vector<Tickets>& closedTicketLog)
    {
        Tickets workTicket;
        openTicketLog.push_back(workTicket);

        /******************************************************************
        The size of the vector returned by openTicketLog.size() seems to always
        be 1 higher than the actual number of tickets, so I decrement it in
        order to place information in the correct vector[index] position.
        *******************************************************************/
        int newObjectPosition = openTicketLog.size() - 1;
        openTicketLog[newObjectPosition].setDate(todaysDate());
        displayHeader(openTicketLog);
        mainMenu(openTicketLog, closedTicketLog);
    }

/**************************************************************************

Programmer: Dale Ming

The displayHeader function is called by main() and accepts a reference to
the vector of class Tickets objects. The function uses a while loop to
output the return values of selected Tickets class member functions to the
console to represent the list of pending maintenance tickets.

The function requires no user input, all input is from the vector, and
output is to the console.

**************************************************************************/
void displayHeader(vector<Tickets>& openTicketLog)
    {
        int size = openTicketLog.size();
        int index = 0;
        int numOfLines = openTicketLog.size();
        adjustScreen(12 - numOfLines);
        while(index < size)
            {
                if (openTicketLog[index].getTicketStatus() == "Open")
                    {
                        cout << right << setw(10)
                             << openTicketLog[index].getTicketNumber() << "  "
                             << openTicketLog[index].getDate() << "  "
                             << openTicketLog[index].getApt() << "  " << left << setw(10)
                             << openTicketLog[index].getIssue() << "  "
                             << openTicketLog[index].getNotes() << endl;
                        ++index;
                    }
                else ++index;
            }
            adjustScreen(3);
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

The function does not require any user input and there is no console output.

**************************************************************************/
void populateVector (vector<Tickets>& openTicketLog, vector<Tickets>& closedTicketLog)
    {
        ifstream maintFile("TicketLog.txt", ios::in);//ifstream object
        if (!maintFile)
            cout << "Error opening file!";
        string temp;

        for (int index = 0; !(maintFile.eof()); index++)
            {
        /******************************************************************
        The next 2 lines of code creates a new instance of the class
        Tickets object and pushes back the size of the openTicketLog vector to
        allocate enough space for the object.
        ******************************************************************/
                Tickets openWorkTicket;
                openTicketLog.push_back(openWorkTicket);

                Tickets closedWorkTicket;
                closedTicketLog.push_back(closedWorkTicket);

                getline(maintFile, temp, '~');

                if (temp == "Open")
                    {
                        openTicketLog[index].setTicketStatus(temp);  //status

                        getline(maintFile, temp, '~');
                        openTicketLog[index].setTicketNumber(temp); //ticket number

                        getline(maintFile, temp, '~');
                        openTicketLog[index].setDate(temp);         //date

                        getline(maintFile, temp, '~');
                        openTicketLog[index].setApt(temp);          //apt number

                        getline(maintFile, temp, '~');
                        openTicketLog[index].setName(temp);         //name

                        getline(maintFile, temp, '~');
                        openTicketLog[index].setPhone(temp);        //phone

                        getline(maintFile, temp, '~');
                        openTicketLog[index].setPriority(temp);     //priority

                        getline(maintFile, temp, '~');
                        openTicketLog[index].setIssue(temp);        //issue

                        getline(maintFile, temp, '\n');
                        openTicketLog[index].setNotes(temp);        //notes
                    }
                else if (temp == "Closed")
                    {
                        closedTicketLog[index].setTicketStatus(temp);  //status

                        getline(maintFile, temp, '~');
                        closedTicketLog[index].setTicketNumber(temp); //ticket number

                        getline(maintFile, temp, '~');
                        closedTicketLog[index].setDate(temp);         //date

                        getline(maintFile, temp, '~');
                        closedTicketLog[index].setApt(temp);          //apt number

                        getline(maintFile, temp, '~');
                        closedTicketLog[index].setName(temp);         //name

                        getline(maintFile, temp, '~');
                        closedTicketLog[index].setPhone(temp);        //phone

                        getline(maintFile, temp, '~');
                        closedTicketLog[index].setPriority(temp);     //priority

                        getline(maintFile, temp, '~');
                        closedTicketLog[index].setIssue(temp);        //issue

                        getline(maintFile, temp, '\n');
                        closedTicketLog[index].setNotes(temp);        //notes
                    }

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

There is no user input and there is no console output. The function returns
the date as a string data type (format nn/nn/nnnn).

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
void openMaintLog(vector<Tickets>& openTicketLog, vector<Tickets>& closedTicketLog)
    {
        clearScreen(NUM_OF_LINES);
        cout << "\t\t\t\tSaving files...";
        adjustScreen(14);
        pauseScreen();
        clearScreen(NUM_OF_LINES);
        ofstream maintSaveFile("TicketLogSave.txt", ios::out);  //ofstream object
        if (!maintSaveFile)
            cout << "Error opening file!";
        else
            {

            int size = openTicketLog.size();
            int index = 0;
            while(index < size)
                {               // "~" is my delimiter to separate the fields
                    maintSaveFile << openTicketLog[index].getTicketStatus() << "~";
                    maintSaveFile << openTicketLog[index].getTicketNumber() << "~";
                    maintSaveFile << openTicketLog[index].getDate() << "~";
                    maintSaveFile << openTicketLog[index].getApt() << "~";
                    maintSaveFile << openTicketLog[index].getName() << "~";
                    maintSaveFile << openTicketLog[index].getPhone() << "~";
                    maintSaveFile << openTicketLog[index].getPriority() << "~";
                    maintSaveFile << openTicketLog[index].getIssue() << "~";
                    maintSaveFile << openTicketLog[index].getNotes() << "\n\n";
                    index++;
                }
            }
        maintSaveFile.close();      //close that file!!
    }

/**************************************************************************

Programmer: Dale Ming

clearScreen adds lines to the console effectively clearing the output
console window. The number of lines is set by a global const. The function
loops thru a for loop adding new lines to the screen.

There is no user input and the console output is empty lines.

**************************************************************************/
void clearScreen(const int NUM_OF_LINES)
    {
        for(int index = 0; index < NUM_OF_LINES; index++) cout << "\n";
    }


/**************************************************************************

Programmer: Dale Ming

adjustScreen is almost identical to clearScreen except the programmer
passes an int as a parameter to set the condition of the for loop.

There is no user input and the console output is empty lines.

**************************************************************************/
void adjustScreen(int lines)
    {
        for (int index = 0; index < lines; index++) cout << "\n";
    }

/**************************************************************************

Programmer: Dale Ming

pauseScreen uses clock() to get a starting point for measuring time.
clock_t is a data type capable if representing clock "ticks" or .001
seconds.

There is no user input or console output.

**************************************************************************/
void pauseScreen()
    {
        const int waitTime = 2; // change the value of this variable to change the pause time
        clock_t start_time = clock();// sets the start time
        clock_t end_time = waitTime * 1000 + start_time;// sets the duration
        while(clock() != end_time); //starts a loop that ends after 2000 ticks or 2 seconds
    }






#endif // DALE_H_INCLUDED













