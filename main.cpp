//Group Project
#include <cstdlib> // for exit()

using namespace std;

#include "Tickets.h"
#include "Dale.h"
#include "Yvette.h"
#include "Lazaro.h"
#include "Brittany.h"

int main ()
    {

        vector<Tickets> openTicketLog;
        vector<Tickets> closedTicketLog;
        populateVector(openTicketLog, closedTicketLog);
        displayHeader(openTicketLog);
        mainMenu(openTicketLog, closedTicketLog);
        return 0;
    }

void mainMenu(vector<Tickets>& openTicketLog, vector<Tickets>& closedTicketLog)
    {

        cout << "\t\t\t\t1: New Ticket\n";
        cout << "\t\t\t\t2: View Ticket\n";
        cout << "\t\t\t\t3: Workforce Menu\n";
        cout << "\t\t\t\t4: Exit\n";
        adjustScreen(5);
        cout << "\t\t\t\t\t";
        int choice;
        cin >> choice;
        if (choice == 1)
            {
                clearScreen(NUM_OF_LINES);
                newTicket(openTicketLog, closedTicketLog);
            }
        else if (choice == 2)
            {
                clearScreen(NUM_OF_LINES);
                viewTicket();
                closedTickets(closedTicketLog);
            }
        else if (choice == 3)
            {
                clearScreen(NUM_OF_LINES);
                createWorkforce(openTicketLog, closedTicketLog);
            }
        else if (choice == 4)
            {
                clearScreen(NUM_OF_LINES);
                openMaintLog(openTicketLog, closedTicketLog);
                exit(0);
            }
    }








