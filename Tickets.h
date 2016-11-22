#ifndef TICKETS_H_INCLUDED
#define TICKETS_H_INCLUDED

#include <string>

using namespace std;

struct Employee
    {
            string employeeName;
            int employeeNumber;
            void setEmployeeName(string x){employeeName = x;}
            string getEmployeeName()const {return employeeName;}
            void setEmployeeNumber (int y) {employeeNumber = y;}
            int getEmployeeNumber () const {return employeeNumber;}
    };



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
            Employee empName;

        public:
            Tickets();
            ~Tickets();
            string getTicketNumber() const { return ticketNumber;}
            void setTicketNumber(string x) {ticketNumber = x; }
            string getApt() const { return apt; }
            void setApt(string val) { apt = val; }
            string getName() const { return name; }
            void setName(string val) { name = val; }
            string getDate() const { return date; }
            void setDate(string x) { date = x; }
            string getPhone() const { return phone; }
            void setPhone(string val) { phone = val; }
            string getIssue() const { return issue; }
            void setIssue(string val) { issue = val; }
            string getNotes() const { return notes; }
            void setNotes(string val) { notes = val; }
            string getPriority() const { return priority; }
            void setPriority(string val) { priority = val; }
            string getTicketStatus() const { return ticketStatus; }
            void setTicketStatus(string val) { ticketStatus = val; }
            Employee getEmployeeName() const {return empName;}
            void setEmployeeName (Employee x) {empName = x;}
    };

#endif // TICKETS_H_INCLUDED
