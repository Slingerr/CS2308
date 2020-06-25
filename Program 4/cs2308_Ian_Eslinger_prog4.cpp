/*=====================================================================
Programmer: Ian Eslinger
Program: Program to calculate and organize data into arrays using dynamic
allocation
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 2/19/2017
Description: Dynamically allocate arrays and fill them with user input.
Display the data in a table followed by the total amount of units sold
and sales made. Display the address and size of the first element of
each array.
Input: Number of products, product ids, number of units sold, prices of
each product.
Output: A table of the inputted data and the address and size of the first
element of each array.
Compilation instructions: N/A
Usage:
=====================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

main()
{
    int *prices = nullptr;
    int *id = nullptr;
    int *units = nullptr;
    int *profit = nullptr;
    int totalSold = 0;
    int totalProfit = 0;
    int numProd;
    int counter;

    //ask user for total number of products
    cout << "How many products are being processed?" << endl;
    cin >> numProd;

    //dynamically allocate arrays large enough for each variable
    id = new int[numProd];
    units = new int[numProd];
    prices =  new int[numProd];
    profit = new int[numProd];

    cout << "Enter the id number for each product below. (Positive Integers Only)" << endl;

    //input the id numbers
    for(counter = 0; counter < numProd; counter++)
    {
        cout << "Product " << (counter +1) << ": ";
        cin >> id[counter];
    }
    cout << endl;

    cout << "Enter the price for each product below. (Positive Integers Only)" << endl;
    //input the price values
    for(counter = 0; counter < numProd; counter++)
    {
        cout << "Price " << (counter +1) << ": ";
        cin >> prices[counter];
    }
    cout << endl;

    cout << "Enter the number of units sold for each product below. (Positive Integers Only)" << endl;
    //input the units sold
    for(counter = 0; counter < numProd; counter++)
    {
        cout << "Units Sold " << (counter +1) << ": ";
        cin >> units[counter];
    }
    cout << endl;

    //Calculate sales
    for(int i = 0; i< numProd; i++)
    {
        profit[i] = prices[i] * units[i];
    }

    //display table
    cout << "Product ID" <<"\t" << "Amount Sold" <<"\t" << "Price" <<"\t";
    cout << "Sales" << endl;
    for(int i =0; i<numProd; i++)
    {
        cout << id[i] <<"\t\t" << units[i] << "\t\t";
        cout << prices[i] << "\t$" <<setw(8) << profit[i] << endl;
    }

    //calculate and display sum of the sales and units sold
    for(int i =0; i<numProd; i++)
    {
        totalProfit += profit[i];
        totalSold += units[i];
    }
    cout << "Total Units Sold: " << totalSold << endl;
    cout << "Total Sales:      $" << totalProfit << endl;
    cout << endl << endl;


    //Display the address, size, and value of id
    cout << "The address of id is  " << &id << endl;
    cout << "The size of the first element of id is " << sizeof(id) << " bytes" << endl;
    cout << endl;

    //Display the address, size, and value of units
    cout << "The address of units is  " << &units << endl;
    cout << "The size of the first element of units is " << sizeof(units) << " bytes" << endl;
    cout << endl;

    //Display the address, size, and value of prices
    cout << "The address of prices is  " << &prices << endl;
    cout << "The size of the first element of prices is " << sizeof(prices) << " bytes" << endl;
    cout << endl;

    //Display the address, size, and value of profit
    cout << "The address of profit is  " << &profit << endl;
    cout << "The size of the first element of profit is " << sizeof(profit) << " bytes" << endl;
    cout << endl;

    return 0;
}
