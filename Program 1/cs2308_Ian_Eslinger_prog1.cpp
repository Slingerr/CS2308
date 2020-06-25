/*=====================================================================
Program: Program to calculate and organize data from arrays into two
sorted tables using selection sort and bubble sort.
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 1/28/2017
Description: Calculate the listed arrays into a table then sort the table
in descending order using selection sort. Sort the table again into ascending
order using bubble sort.  Display each table followed by the total amount of
units sold and sales made.
Input: N/A
Output: 3 Tables of data (unsorted, descending order, ascending order) and
the total of units sold and the sum of the sales.
Compilation instructions: N/A
Usage:
=====================================================================*/
#include <iostream>
#include <iomanip>

using namespace std;

void SelectionSort(int id[],double sales[],int amount_sold[],int price[], const int SIZE);
void BubbleSort(int id[], double sales[],int amount_sold[],int price[], const int SIZE);

int main ()
{
    int totalSold =0;
    int totalSales =0;
    const int SIZE = 15;

    //Intialize the arrays
    int id [SIZE] = {7382,3336,9684,8578,3678,4363,1584,5848,3473,6029,9654,3521,2138,8108,5249};
    int price [SIZE] =  {250,100,350,50,25,125,325,175,300,200,275,400,450,425,500};
    int amount_sold [SIZE]  =  {15,20,75,10,5,30,25,45,40,35,55,50,65,60,70};
    double sales [SIZE];


    //Calculate sales
    for(int i = 0; i< SIZE; i++)
    {
        sales[i] = price[i] * amount_sold[i];
    }

    //display unsorted output
    cout << "Displaying unsorted table" << endl;
    cout << "Product ID" <<"\t" << "Amount Sold" <<"\t" << "Price" <<"\t";
    cout << "Sales" <<endl;
    for(int i =0; i<SIZE; i++)
    {
        cout << id[i] <<"\t\t" << amount_sold[i] <<"\t\t$";
        cout << price[i] << "\t$" <<setw(8) << sales[i] <<endl;
    }

    //calculate and display sum of the sales and units sold
    for(int i =0; i<SIZE; i++)
    {
        totalSales += sales[i];
        totalSold += amount_sold[i];
    }
    cout << "Total Units Sold: " << totalSold << endl;
    cout << "Total Sales:      $" << totalSales << endl;
    cout << endl << endl;


    //Sort the arrays w/ Selection Sort
    SelectionSort(id, sales,amount_sold,price, SIZE);

    //display selection sorted output
    cout << "Table in descending selection sort" << endl;
    cout << "Product ID" <<"\t" << "Amount Sold" <<"\t" << "Price" <<"\t";
    cout << "Sales" <<endl;
    for(int i =0; i<SIZE; i++)
    {
        cout << id[i] <<"\t\t" << amount_sold[i] <<"\t\t$";
        cout << price[i] << "\t$" <<setw(8) << sales[i] <<endl;
    }


    //calculate and display sum of the sales and units sold
    totalSales = 0;
    totalSold = 0;
    for(int i =0; i<SIZE; i++)
    {
        totalSales += sales[i];
        totalSold += amount_sold[i];
    }
    cout << "Total Units Sold: " << totalSold << endl;
    cout << "Total Sales:      $" << totalSales << endl;
    cout << endl << endl;

    //Sort the arrays w/Bubble Sort
    BubbleSort(id, sales, amount_sold,price, SIZE);

    //display bubble sorted output
    cout << "Table in ascending bubble sort" << endl;
    cout << "Product ID" <<"\t" << "Amount Sold" <<"\t" << "Price" <<"\t";
    cout << "Sales" <<endl;
    for(int i =0; i<SIZE; i++)
    {
        cout << id[i] <<"\t\t" << amount_sold[i] <<"\t\t$";
        cout << price[i] << "\t$" <<setw(8) << sales[i] <<endl;
    }

    //calculate and display sum of the sales and units sold
    totalSales = 0;
    totalSold = 0;
    for(int i =0; i<SIZE; i++)
    {
        totalSales += sales[i];
        totalSold += amount_sold[i];
    }
    cout << "Total Units Sold: " << totalSold << endl;
    cout << "Total Sales:      $" << totalSales << endl;

    return 0;
}


void SelectionSort(int id[], double sales[],int amount_sold[],int price[],const int SIZE)
{
    int startScan, maxIndex, tempid, temp_total, tempprice;
    double maxValue;

    for (startScan = 0; startScan < (SIZE-1); startScan++)
    {
        maxIndex = startScan;
        maxValue = sales[startScan];
        tempid = id[startScan];
        temp_total =amount_sold[startScan];
        tempprice = price[startScan];

        for(int index = startScan + 1; index < SIZE; index++)
        {
            if (sales[index] > maxValue)
            {
                maxValue = sales[index];
                tempid = id[index];
                tempprice=price[index];
                temp_total=amount_sold[index];
                maxIndex = index;
            }
        }
        sales[maxIndex] = sales[startScan];
        id[maxIndex] = id[startScan];
        amount_sold[maxIndex]=amount_sold[startScan];
        price[maxIndex]=price[startScan];
        sales[startScan] = maxValue;
        id[startScan] = tempid;
        amount_sold[startScan]=temp_total;
        price[startScan]=tempprice;
    }
}

void BubbleSort(int id[], double sales[],int amount_sold[],int price[], const int SIZE)
{
    bool bubble_swap;
    double temp, tempid, tempsold,temp_price;

    do
    {
        bubble_swap = false;

        for(int i = 0; i < (SIZE - 1); i++)
        {
            if(sales[i] > sales[i + 1])
            {
                temp = sales[i];
                sales[i] = sales[i + 1];
                sales[i + 1] = temp;
                tempid = id[i];
                id[i] = id[i+1];
                id[i+1]=tempid;
                tempsold = amount_sold[i];
                amount_sold[i] = amount_sold[i+1];
                amount_sold[i+1]=tempsold;
                temp_price=price[i];
                price[i]=price[i+1];
                price[i+1]=temp_price;
                bubble_swap = true;
            }
        }
    }while (bubble_swap);
}
