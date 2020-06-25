/*=====================================================================
Programmer:Ian Eslinger
Program:  Program using struct pointers to allocate an array of struct
from an input file and outputs it in a table to an output file
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 5/5/2017
Description:  Program intializes an array of the product structure.  Uses
struct pointers to fill the id, price, and amount sold members of each element.
The data for these is inputted by a text file.  Then it calculates the sales for
each element.  Next, it outputs the array as a table to another text file.  Followed
by outputting the total sales and total sold.
Input: Input file containing product IDs, prices, and amount sold.
Output: outputs to another file a sorted table containing product IDs,
prices, amount sold, and sales.
=====================================================================*/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Product{
int id;
int price;
int amount_sold;
double sales;
};


void SelectionSort(Product product[],int ARRSIZE);
const int ARRSIZE = 15;
Product product[ARRSIZE];

int main ()
{
    ifstream inputfile;
    inputfile.open("C:\\Users\\kilik\\Desktop\\productledger.txt");
    int totalSold =0;
    int totalSales =0;
    Product *ptr =nullptr;
    ptr = &product[0];

    for(int i =0; i < ARRSIZE; i++)
    {

        inputfile >> ptr->id;
        inputfile >> ptr->price;
        inputfile >> ptr->amount_sold;
        ptr++;
    }

    SelectionSort(product, ARRSIZE);
    inputfile.close();


    //Calculate sales
    for(int index = 0; index< ARRSIZE; index++)
    {
       product[index].sales = product[index].price * product[index].amount_sold;
    }

    ofstream outputfile;
    outputfile.open("C:\\Users\\kilik\\Desktop\\productoutput.txt");

    outputfile << "NUMBER OF PRODUCTS : " << ARRSIZE << endl;
    outputfile << "PRODUCT ID  PRICE  QUANTITY  SALES" << endl;
    for(int i = 0; i <ARRSIZE; i++)
    {
        outputfile << product[i].id<<"       "<<product[i].price<<"     "<<product[i].amount_sold<<"        "<<product[i].sales<<endl;
    }
    outputfile << endl;

    for(int index = 0; index<ARRSIZE; index++)
    {
        totalSales += product[index].sales;
        totalSold += product[index].amount_sold;
    }
    outputfile << "Total Units Sold: " << totalSold << endl;
    outputfile << "Total Sales:      $" << totalSales << endl;
    outputfile.close();

    return 0;
}


void SelectionSort(Product  product[],int ARRSIZE)
{
    int startScan, maxIndex, tempid, temp_total, tempprice;
    double maxValue;

    for (startScan = 0; startScan < (ARRSIZE-1); startScan++)
    {
        maxIndex = startScan;
        maxValue = product[startScan].sales;
        tempid = product[startScan].id;
        temp_total =product[startScan].amount_sold;
        tempprice = product[startScan].price;

        for(int index = startScan + 1; index < ARRSIZE; index++)
        {
            if (product[index].sales > maxValue)
            {
                maxValue = product[index].sales;
                tempid = product[index].id;
                tempprice=product[index].price;
                temp_total=product[index].amount_sold;
                maxIndex = index;
            }
        }
        product[maxIndex].sales = product[startScan].sales;
        product[maxIndex].id = product[startScan].id;
        product[maxIndex].amount_sold = product[startScan].amount_sold;
        product[maxIndex].price = product[startScan].price;
        product[startScan].sales = maxValue;
        product[startScan].id = tempid;
        product[startScan].amount_sold = temp_total;
        product[startScan].price = tempprice;
    }
}
