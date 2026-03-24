#include <iostream>
using namespace std;

const int MONTHS_IN_YEAR = 12;

// Function prototypes
void printSalesForYear(const int sales[][MONTHS_IN_YEAR], int numberOfYears);
void printSalesForMonth(const int sales[][MONTHS_IN_YEAR], int numberOfYears);

int main()
{
    // 2d array of smoothie sales: rows are years, columns are months.
    int sales[][MONTHS_IN_YEAR] = {
        { 15, 29, 42, 53, 65, 56, 29, 58, 19, 24, 81, 81 }, // Year 1
        { 43, 86, 37, 24, 63, 75, 86, 45, 64, 61, 20, 17 }, // Year 2
        { 37, 54, 63, 82, 61, 42, 13, 12, 47, 54, 74, 47 }, // Year 3
        { 22, 17, 15, 23, 26, 67, 92, 12, 82, 61, 14, 98 }  // Year 4

        // Add Year 5 and Year 6 rows below with no code changes elsewhere:
        // { 11, 43, 99, 0, 43, 67, 32, 41, 31, 52, 72, 13 }, // Year 5
        // { 14, 34, 23, 36, 26, 17, 42, 21, 47, 36, 43, 43 }  // Year 6
    };

    // determine number of years (rows) at compile time using sizeof.
    int numberOfYears = sizeof(sales) / sizeof(sales[0]);

    int choice = 0;

    // menu loop.
    do
    {
        cout << "--- Rich's Smoothie Shop ---" << endl;
        cout << "  Sales Analysis Tool" << endl;
        cout << endl;
        cout << "1) Print the sales for a year" << endl;
        cout << "2) Print sales for a month of year" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            printSalesForYear(sales, numberOfYears);
        }
        else if (choice == 2)
        {
            printSalesForMonth(sales, numberOfYears);
        }
        else if (choice == 3)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
        }

        cout << endl;

    } while (choice != 3);

    return 0;
}

// option 1: print all monthly sales for one year and that year's total.
void printSalesForYear(const int sales[][MONTHS_IN_YEAR], int numberOfYears)
{
    int year;
    int total = 0;

    cout << "Enter the year (1-" << numberOfYears << "): ";
    cin >> year;

    if (year < 1 || year > numberOfYears)
    {
        cout << "Invalid year." << endl;
        return;
    }

    cout << "Sales for year " << year << " are" << endl;
    cout << "Monthly: ";

    for (int month = 0; month < MONTHS_IN_YEAR; month++)
    {
        cout << sales[year - 1][month];
        total = total + sales[year - 1][month];

        if (month < MONTHS_IN_YEAR - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
    cout << "Total: " << total << endl;
}

// option 2: print one month across all years and the total.
void printSalesForMonth(const int sales[][MONTHS_IN_YEAR], int numberOfYears)
{
    int month;
    int total = 0;

    cout << "Enter the month (1-12): ";
    cin >> month;

    if (month < 1 || month > MONTHS_IN_YEAR)
    {
        cout << "Invalid month." << endl;
        return;
    }

    cout << "Sales for month " << month << " by year are:" << endl;
    cout << "Year Monthly: ";

    for (int year = 0; year < numberOfYears; year++)
    {
        cout << sales[year][month - 1];
        total = total + sales[year][month - 1];

        if (year < numberOfYears - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
    cout << "Total: " << total << endl;
}
