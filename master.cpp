//Group Project
//Test change for github
//New branch and pull request
#include <iostream>
#include <cstring>
#include "Brittany.h"
#include "Dale.h"
#include "Lazaro.h"
#include "Yvette.h"

using namespace std;

class Tickets
    {
        private:
            int apt;
            string name;
            int date;
            int phone;
            int ticketNumber;
            bool priority;
            string issue;
            //unique_pointer for the employee
            string notes;
            bool ticketStatus;
        public:
            //get/sets for each variable
            //sort function for date, priority, apt #

    };


using namespace std;
void displayHeader(){cout << "header\n\n\n";}
void mainMenu();
void newTicket(){cout << "Create a new ticket\n";}
void viewTicket(){cout << "View a ticket.\n";}
void openTicket(){cout << "View an open ticket\n";}
void closeTickets(){cout << "View an open ticket\n";}
void displayTickets(){cout << "Display the ticket\n";}


int main ()
    {
        displayHeader();
        mainMenu();

        return 0;
    }


void mainMenu(){cout << "1: New Ticket\n";
                cout << "2: View Ticket\n";
                cout << "3: Exit\n";
                int choice;
                cin >> choice;
                if (choice == 1)
                    newTicket();
                else if (choice == 2)
                    viewTicket();
                else if (choice == 3)
                    exit(0);
                }

