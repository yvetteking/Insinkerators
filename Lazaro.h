#ifndef LAZARO_H_INCLUDED
#define LAZARO_H_INCLUDED

using namespace std;

void adjustScreen(int);

void openTicket(){cout << "View an open ticket\n";}


/**************************************************************************

Programmer: Dale Ming

I placed closedTickets here just to show that the new vector for closed
tickets is actually accepting ticket information correctly. Do with it
whatever you like.

You can see the output of this function (displaying closed tickets) when
you choose #2 from the main menu.

**************************************************************************/
void closedTickets(vector<Tickets>& closedTicketLog)
    {
        int size = closedTicketLog.size();
        int index = 0;
        adjustScreen(12 - size);
        while(index < size)
            {
                if (closedTicketLog[index].getTicketStatus() == "Closed")
                    {
                        cout << right << setw(10)
                             << closedTicketLog[index].getTicketNumber() << "  "
                             << closedTicketLog[index].getDate() << "  "
                             << closedTicketLog[index].getApt() << "  " << left << setw(10)
                             << closedTicketLog[index].getIssue() << "  "
                             << closedTicketLog[index].getNotes() << endl;
                        ++index;
                    }
                else ++index;
            }
            adjustScreen(3);
    }



#endif // LAZARO_H_INCLUDED





