#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void printStoreInfo();
double processPayroll(ifstream& inFile, int& employeeCount);

int main()
{
    ifstream inFile;
    inFile.open("payroll.txt");

    if (!inFile)
    {
        cout << "Error: Could not open payroll.txt" << endl;
        return 1;
    }

    printStoreInfo();
    cout << "--- Weekly Payroll Report ---" << endl;

    int employeeCount = 0;
    double totalPayroll = processPayroll(inFile, employeeCount);

    cout << endl;
    cout << "Number of employees: " << employeeCount << endl;
    cout << fixed << setprecision(2);
    cout << "Total payroll: $" << totalPayroll << endl;

    inFile.close();
    return 0;
}

// Prints basic store information.
void printStoreInfo()
{
    cout << "Rich's Smoothie Shop" << endl;
    cout << "123 Berry Lane, Orlando, FL" << endl;
    cout << "(407) 555-0199" << endl;
    cout << endl;
}

// Processes payroll records and returns total payroll amount.
// Uses read-before-loop and read-inside-loop structure.
double processPayroll(ifstream& inFile, int& employeeCount)
{
    string firstName;
    char middleInitial;
    string lastName;
    double hours;
    double rate;
    double bonus;
    double weeklySalary;
    double totalPayroll = 0.0;

    // Initial read before loop.
    inFile >> firstName >> middleInitial >> lastName >> hours >> rate >> bonus;

    while (inFile)
    {
        weeklySalary = hours * rate + bonus;

        cout << left << setw(15) << lastName
             << setw(15) << firstName
             << "$" << fixed << setprecision(2) << weeklySalary << endl;

        totalPayroll = totalPayroll + weeklySalary;
        employeeCount++;

        // Read inside loop for next record.
        inFile >> firstName >> middleInitial >> lastName >> hours >> rate >> bonus;
    }

    return totalPayroll;
}
