/*=====================================================================
Programmer:Ian Eslinger
Program: Program that calculates and organizes data from from a array
of structs into a sorted table using selection sort.
Class: CS2308
Instructor: C. Jinshong Hwang
Date:11/26/2017
Description:Calculate the struct into an array then a table. Display the
unsorted table.   Sort the table in descending order using selection sort.
Display the table followed by the total amount of units sold and sales made.
Input: N/A
Output: 2 Tables of data (unsorted & sorted), the total of units sold,
and the sum of the sales
Compilation instructions: N/A
Usage:
=====================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

struct Product{
int id;
int price;
int amount_sold;
double sales;
};

void SelectionSort(struct Product prod_arr[],int SIZE);

int main ()
{
    int totalSold =0;
    int totalSales =0;
    const int SIZE = 15;
    int index;


    //Intialize the array
    Product prod_arr[SIZE] = {
                                {7382,250,15},
                                {3336,100,20},
                                {9684,350,75},
                                {8578,50,10},
                                {3678,25,5},
                                {4363,125,30},
                                {1584,325,25},
                                {5848,175,45},
                                {3473,300,40},
                                {6029,200,35},
                                {9654,275,55},
                                {3521,400,50},
                                {2138,450,65},
                                {8108,425,60},
                                {5249,500,70}
                            };


    //Calculate sales
    for(int index = 0; index< SIZE; index++)
    {
       prod_arr[index].sales = prod_arr[index].price * prod_arr[index].amount_sold;
    }

    //display unsorted output
    cout << "Displaying Unsorted Table" << endl;
    cout << "Product ID" <<"\t" << "Amount Sold" <<"\t" << "Price" <<"\t";
    cout << "Sales" <<endl;
    for(index = 0; index<SIZE; index++)
    {
        cout << prod_arr[index].id <<"\t\t";
        cout << prod_arr[index].amount_sold <<"\t\t$";
        cout << prod_arr[index].price << "\t$" <<setw(8);
        cout << prod_arr[index].sales <<endl;
    }

    for(index = 0; index<SIZE; index++)
    {
        totalSales += prod_arr[index].sales;
        totalSold += prod_arr[index].amount_sold;
    }
    cout << "Total Units Sold: " << totalSold << endl;
    cout << "Total Sales:      $" << totalSales << endl;
    cout << endl << endl;


    //Sort the arrays w/ Selection Sort
    SelectionSort( prod_arr, SIZE);

    //display selection sorted output
    cout << "Displaying Table Sorted In Descending Order " << endl;
    cout << "Product ID" <<"\t" << "Amount Sold" <<"\t" << "Price" <<"\t";
    cout << "Sales" <<endl;
    for(index =0; index<SIZE; index++)
    {
        cout << prod_arr[index].id <<"\t\t";
        cout << prod_arr[index].amount_sold <<"\t\t$";
        cout << prod_arr[index].price << "\t$" <<setw(8);
        cout << prod_arr[index].sales <<endl;
    }


    //calculate and display sum of the sales and units sold
    totalSales = 0;
    totalSold = 0;
    for(index = 0; index<SIZE; index++)
    {
        totalSales += prod_arr[index].sales;
        totalSold += prod_arr[index].amount_sold;
    }
    cout << "Total Units Sold: " << totalSold << endl;
    cout << "Total Sales:      $" << totalSales << endl;
    cout << endl << endl;

    return 0;
}


void SelectionSort(struct Product  prod_arr[],int SIZE)
{
    int startScan, maxIndex, tempid, temp_total, tempprice;
    double maxValue;

    for (startScan = 0; startScan < (SIZE-1); startScan++)
    {
        maxIndex = startScan;
        maxValue = prod_arr[startScan].sales;
        tempid = prod_arr[startScan].id;
        temp_total =prod_arr[startScan].amount_sold;
        tempprice = prod_arr[startScan].price;

        for(int index = startScan + 1; index < SIZE; index++)
        {
            if (prod_arr[index].sales > maxValue)
            {
                maxValue = prod_arr[index].sales;
                tempid = prod_arr[index].id;
                tempprice=prod_arr[index].price;
                temp_total=prod_arr[index].amount_sold;
                maxIndex = index;
            }
        }
        prod_arr[maxIndex].sales = prod_arr[startScan].sales;
        prod_arr[maxIndex].id = prod_arr[startScan].id;
        prod_arr[maxIndex].amount_sold = prod_arr[startScan].amount_sold;
        prod_arr[maxIndex].price = prod_arr[startScan].price;
        prod_arr[startScan].sales = maxValue;
        prod_arr[startScan].id = tempid;
        prod_arr[startScan].amount_sold = temp_total;
        prod_arr[startScan].price = tempprice;
    }
}
