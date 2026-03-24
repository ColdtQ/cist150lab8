#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void printStoreInfo(ostream& out);
double processPayroll(ifstream& inFile, ostream& outFile, int& employeeCount);

int main()
{
    ifstream inFile;
    inFile.open("payroll.txt");

    if (!inFile)
    {
        cout << "Error: Could not open payroll.txt" << endl;
        return 1;
    }

    string outputFileName;
    cout << "Enter output file name: ";
    cin >> outputFileName;

    ofstream outFile;
    outFile.open(outputFileName.c_str());

    if (!outFile)
    {
        cout << "Error: Could not create output file." << endl;
        inFile.close();
        return 1;
    }

    printStoreInfo(outFile);
    outFile << "--- Weekly Payroll Report ---" << endl;

    int employeeCount = 0;
    double totalPayroll = processPayroll(inFile, outFile, employeeCount);

    outFile << endl;
    outFile << "Number of employees: " << employeeCount << endl;
    outFile << fixed << setprecision(2);
    outFile << "Total payroll: $" << totalPayroll << endl;

    cout << fixed << setprecision(2);
    cout << "Total payroll amount written to file: $" << totalPayroll << endl;

    inFile.close();
    outFile.close();

    return 0;
}

// Prints basic store information to an output stream.
void printStoreInfo(ostream& out)
{
    out << "Rich's Smoothie Shop" << endl;
    out << "123 Berry Lane, Orlando, FL" << endl;
    out << "(407) 555-0199" << endl;
    out << endl;
}

// Processes payroll records and writes each employee payroll line to the output file.
// Uses read-before-loop and read-inside-loop structure.
double processPayroll(ifstream& inFile, ostream& outFile, int& employeeCount)
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

        outFile << left << setw(15) << lastName
                << setw(15) << firstName
                << "$" << fixed << setprecision(2) << weeklySalary << endl;

        totalPayroll = totalPayroll + weeklySalary;
        employeeCount++;

        // Read inside loop for next record.
        inFile >> firstName >> middleInitial >> lastName >> hours >> rate >> bonus;
    }

    return totalPayroll;
}
