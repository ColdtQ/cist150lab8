#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void printStoreInfo();
int readMenu(const string& fileName, string flavors[], double prices[], int quantities[], int maxSize);
void dispMenu(const string flavors[], const double prices[], int count);
void printSummary(int totalSold, double totalSales, double totalProfit);

int main()
{
    const int MAX_ITEMS = 10;

    // arrays and control variables are declared in main.
    string flavors[MAX_ITEMS];
    double prices[MAX_ITEMS];
    int quantities[MAX_ITEMS];

    string menuFileName = "daily_flavors.txt";
    int flavorCount = 0;

    int totalSold = 0;
    double totalSales = 0.0;
    double totalProfit = 0.0;

    // read file data into arrays.
    flavorCount = readMenu(menuFileName, flavors, prices, quantities, MAX_ITEMS);

    if (flavorCount == 0)
    {
        cout << "No menu data was read." << endl;
        return 1;
    }

    // display the menu.
    dispMenu(flavors, prices, flavorCount);

    cout << fixed << setprecision(2);
    cout << "Flavor Sales Details:" << endl;

    // calculate totals and print one line per flavor.
    for (int i = 0; i < flavorCount; i++)
    {
        int sold = quantities[i];
        double sales = sold * prices[i];
        double profit = sales * 0.70;

        totalSold = totalSold + sold;
        totalSales = totalSales + sales;
        totalProfit = totalProfit + profit;

        cout << left << setw(12) << flavors[i]
             << "Price: $" << setw(6) << prices[i]
             << "Qty: " << setw(4) << sold
             << "Sales: $" << setw(8) << sales
             << "Profit: $" << profit << endl;
    }

    cout << endl;

    // print summary information.
    printSummary(totalSold, totalSales, totalProfit);

    return 0;
}

// prints basic store information.
void printStoreInfo()
{
    cout << "Rich's Smoothie Shop" << endl;
    cout << "123 Berry Lane, Orlando, FL" << endl;
    cout << "(407) 555-0199" << endl;
}

// reads flavor data from file into arrays and returns number of flavors read.
int readMenu(const string& fileName, string flavors[], double prices[], int quantities[], int maxSize)
{
    ifstream inFile;
    inFile.open(fileName.c_str());

    if (!inFile)
    {
        cout << "Error: Could not open " << fileName << endl;
        return 0;
    }

    int count = 0;
    string flavor;
    double price;
    int quantity;

    // initial read before loop.
    inFile >> flavor >> price >> quantity;

    while (inFile && count < maxSize)
    {
        flavors[count] = flavor;
        prices[count] = price;
        quantities[count] = quantity;
        count++;

        // read inside loop.
        inFile >> flavor >> price >> quantity;
    }

    inFile.close();
    return count;
}

// displays today's smoothie menu.
void dispMenu(const string flavors[], const double prices[], int count)
{
    printStoreInfo();
    cout << "Today's Smoothie Menu:" << endl;

    cout << fixed << setprecision(2);
    for (int i = 0; i < count; i++)
    {
        cout << left << setw(15) << flavors[i]
             << "$" << right << setw(6) << prices[i] << endl;
    }

    cout << endl << endl << endl;
    printStoreInfo();
    cout << endl;
}

// prints the daily summary report.
void printSummary(int totalSold, double totalSales, double totalProfit)
{
    cout << "--- Daily Sales Summary ---" << endl;
    cout << "Number Sold: " << totalSold << endl;
    cout << fixed << setprecision(2);
    cout << "Total Sales: $" << totalSales << endl;
    cout << "Profit: $" << totalProfit << endl;
}
