//Group Project
#include <iostream>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Tickets
    {
        private:

            string ticketNumber;
            string apt;
            string name;
            string date;
            string phone;
            string priority;
            string issue;
            string notes;
            string ticketStatus;

        public:
            Tickets();
            ~Tickets();
            string getTicketNumber() { return ticketNumber;}
            void setTicketNumber(string x) {ticketNumber = x; }
            string getApt() { return apt; }
            void setApt(string val) { apt = val; }
            string getName() { return name; }
            void setName(string val) { name = val; }
            string getDate() { return date; }
            void setDate(string x) { date = x; }
            string getPhone() { return phone; }
            void setPhone(string val) { phone = val; }
            string getIssue() { return issue; }
            void setIssue(string val) { issue = val; }
            string getNotes() { return notes; }
            void setNotes(string val) { notes = val; }
            string getPriority() { return priority; }
            void setPriority(string val) { priority = val; }
            string getTicketStatus() { return ticketStatus; }
            void setTicketStatus(string val) { ticketStatus = val; }
    };

void displayHeader(vector<Tickets>&);
void mainMenu(vector<Tickets>&);
void newTicket(vector<Tickets>&);
void viewTicket(){cout << "View a ticket.\n";}
void openTicket(){cout << "View an open ticket\n";}
void closeTickets(){cout << "View a closed ticket\n";}
void displayTickets(){cout << "Display the ticket\n";}
string todaysDate();
void openMaintLog(vector<Tickets>&);
void populateVector (vector<Tickets>&);

int main ()
    {

        vector<Tickets> TicketLog;
        populateVector(TicketLog);
        displayHeader(TicketLog);
        mainMenu(TicketLog);
        return 0;
    }


void mainMenu(vector<Tickets>& TicketLog)
    {
        cout << "1: New Ticket\n";
        cout << "2: View Ticket\n";
        cout << "3: Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1)
            newTicket(TicketLog);
        else if (choice == 2)
            viewTicket();
        else if (choice == 3)
        {
            openMaintLog(TicketLog);
            exit(0);
        }

    }

/**************************************************************************
Constructor
**************************************************************************/
Tickets::Tickets()
    {

    }

/**************************************************************************
Destructor
**************************************************************************/
Tickets::~Tickets()
    {
        //destruct
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

                getline(maintFile, temp, ',');
                TicketLog[index].setTicketStatus(temp);  //status

                getline(maintFile, temp, ',');
                TicketLog[index].setTicketNumber(temp); //ticket number

                getline(maintFile, temp, ',');
                TicketLog[index].setDate(temp);         //date

                getline(maintFile, temp, ',');
                TicketLog[index].setApt(temp);          //apt number

                getline(maintFile, temp, ',');
                TicketLog[index].setName(temp);         //name

                getline(maintFile, temp, ',');
                TicketLog[index].setPhone(temp);        //phone

                getline(maintFile, temp, ',');
                TicketLog[index].setPriority(temp);     //priority

                getline(maintFile, temp, ',');
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
                    maintSaveFile << TicketLog[index].getTicketStatus() << ",";
                    maintSaveFile << TicketLog[index].getTicketNumber() << ",";
                    maintSaveFile << TicketLog[index].getDate() << ",";
                    maintSaveFile << TicketLog[index].getApt() << ",";
                    maintSaveFile << TicketLog[index].getName() << ",";
                    maintSaveFile << TicketLog[index].getPhone() << ",";
                    maintSaveFile << TicketLog[index].getPriority() << ",";
                    maintSaveFile << TicketLog[index].getIssue() << ",";
                    maintSaveFile << TicketLog[index].getNotes() << "\n\n";
                    index++;
                }
            }
        maintSaveFile.close();      //close that file!!
    }
