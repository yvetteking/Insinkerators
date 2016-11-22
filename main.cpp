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

        vector<Tickets> TicketLog;
        populateVector(TicketLog);
        createWorkforce(TicketLog);
        //mainMenu(TicketLog);
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








