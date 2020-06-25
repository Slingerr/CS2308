 /*=====================================================================
Program:Display the address, size, and value of multiple data types with
the use of pointers.
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 2/11/2017
Description: Display the address, size, and value of an int, bool, char, short,
long, float, double, the elements in a double array, the elements in an int
using pointers
Input: N/A
Output: Displays the address, size, and value of an int, bool, char, short,
long, float, double, the elements in a double array, the elements in an int
array
Compilation instructions: N/A
Usage:
=====================================================================*/
#include <iostream>

using namespace std;

int main()
{
    int i_num = 35;
    bool quest = true;
    char name = 'C';
    short s_num = 10000;
    long int l_num = 60000;
    float f_num = 65.8;
    double d_num = 88.8;
    double d_arr[5] = {5.5,2.2,6.8,69.7,70.1};
    int i_arr[4] = {65,987,124,568};
    int *ptr_i = &i_num;
    float *ptr_f = &f_num;
    double *ptr_d_arr = d_arr;
    int *ptr_i_arr = i_arr;


    //Display the address, size, and value of num
    cout << "The address of num is  " << &i_num << endl;
    cout << "The size of num is " << sizeof(i_num) << " bytes" << endl;
    cout << "The value in num is " << i_num << endl;
    cout << endl;

    //Display the address, size, and value of quest
    cout << "The address of quest is  " << &quest << endl;
    cout << "The size of quest is " << sizeof(quest) << " bytes" << endl;
    cout << "The value in quest is " << quest << endl;
    cout << endl;

    //Display the address, size, and value of name
    cout << "The address of name is  " << &name << endl;
    cout << "The size of name is " << sizeof(name) << " bytes" << endl;
    cout << "The value in name is " << name << endl;
    cout << endl;

    //Display the address, size, and value of short num
    cout << "The address of short num is  " << &s_num << endl;
    cout << "The size of short num is " << sizeof(s_num) << " bytes" << endl;
    cout << "The value in short num is " << s_num << endl;
    cout << endl;

    //Display the address, size, and value of long num
    cout << "The address of long num is  " << &l_num << endl;
    cout << "The size of long num is " << sizeof(l_num) << " bytes" << endl;
    cout << "The value in long num is " << l_num << endl;
    cout << endl;

    //Display the address, size, and value of float num
    cout << "The address of float num is  " << &f_num << endl;
    cout << "The size of float num is " << sizeof(f_num) << " bytes" << endl;
    cout << "The value in float num is " << f_num << endl;
    cout << endl;

    //Display the address, size, and value of double num
    cout << "The address of double num is  " << &d_num << endl;
    cout << "The size of double num is " << sizeof(d_num) << " bytes" << endl;
    cout << "The value in double num is " << d_num << endl;
    cout << endl;

    //display the address,size, and value of each element of the double array
    for(int i = 0; i< 5; i++)
    {
        cout << "The address of double arr " << i << " is " << &(ptr_d_arr) << endl;
        cout << "The size of double arr " << i << " is " << sizeof(ptr_d_arr) << endl;
        cout << "The value of double arr " << i << " is " << *(ptr_d_arr) << endl;
        cout << endl;
        ptr_d_arr++;
    }
    cout <<endl;

    //display the address,size, and value of each element of the int array
    for(int i = 0; i< 4; i++)
    {
        cout << "The address of int arr " << i << " is " << &(ptr_i_arr) << endl;
        cout << "The size of int arr " << i << " is " << sizeof(ptr_i_arr) << endl;
        cout << "The value of int arr " << i << " is " << *(ptr_i_arr) << endl;
        cout << endl;
        ptr_i_arr++;
    }

    //Use a pointer to store and display the address of int num
    cout << "According to the pointer the address of int num is " <<ptr_i << endl;
    cout << endl;

    //Use a pointer to store and display the address of float num
    cout << "According to the pointer the address of float num is " <<ptr_f << endl;
    return 0;
}

