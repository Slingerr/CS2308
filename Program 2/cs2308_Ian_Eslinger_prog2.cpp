/*=====================================================================
Programmer: Ian S. Eslinger
Program: Program that searches an array of Id numbers using sequential and
binary search and records how many times each search function loops.
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 2/03/2017
Description: Uses two methods to search for the target value in an array and
report its location in the array.
Input: Target value to search the array for
Output: Displays the array once, prompts user for the target value, displays
the location of the array and how many loops it took for a sequential search,
and displays the location in the array and how many loops it took for a
binary search.
Compilation instructions: N/A
Usage:
=====================================================================*/
#include <iostream>

using namespace std;

int sequentialSearch( int studID[] , const int SIZE, int target, int& position);
int binarySearch( int studID[] , const int SIZE, int target, int& position);

int main()
{
    int target;
    int position;
    const int SIZE = 20;
    int studID [SIZE] = {1042, 1185, 1516, 2109, 2139, 3010, 3062, 3147, 3807, 4429, 5242, 5605, 7102, 7582, 8354, 8394, 8702, 9058, 9125, 9580};

    //display the array
    cout << "Displaying all student IDs in ascending order" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << studID[i] << " ";
    }
    cout << endl << endl;

    //prompt user for target value
    cout <<"Input a four digit number that you wish to search the array for.";
    cout << endl;
    cin >> target;
    cout << endl;

    cout << "Searching the array using Sequential Search." << endl;
    //call sequential search func
    sequentialSearch(studID, SIZE, target, position);

    //error handling for if the target value is not located in the array
    if(position == -1)
    {
        cout << "The target number does not exist in the array." << endl;
    }
    //display the position of target value
    else
    {
        cout << "The target number is located in cell " <<position;
        cout << " of the array." << endl;
    }
    cout << endl << endl;

    cout << "Searching the array using Binary Search." << endl;
    //call binary search function
    binarySearch(studID, SIZE, target, position);

    //error handling for if the target value is not located in the array
    if(position == -1)
    {
        cout << "The target number does not exist in the array." << endl;
    }
    //display the position of target value
    else
    {
        cout << "The target number is located in cell " <<position;
        cout << " of the array." << endl;
    }
    cout << endl << endl;
    return 0;
}

int sequentialSearch( int studID[] , const int SIZE, int target, int& position)
{
    int index = 0;
    int laps = 0;           //amount of times the search loops
    bool found = false;     //flag to notify that the value has been found
    position= -1;           //-1 is placeholder for if the value is not found

    while (index < SIZE &&!found)
    {
        //checks if the current cell contains the target value
        if (studID[index] == target)
        {
            found = true;
            position = index;
        }
        index++;
        laps++;
    }

    //display how many times the search function looped
    cout << "It took this many loops to find the target number : " << laps << endl;

    //return position of target
    return position;
}

int binarySearch( int studID[] , const int SIZE, int target, int& position)
{
    int first = 0;                  //sets first to the first cell of the array
    int last = SIZE - 1;            //sets last to the last cell of the array
    int middle;                     //intializes middle cell to be used later
    int laps = 0;                   //amount of times the search loops
    bool found = false;             //flag to notify that the value has been found
    position = -1;                  //-1 is placeholder for if the value is not found

    while(!found && first<= last)
    {
        laps++;
        //calculate the middle of the array
        middle = (first +last) / 2;

        //check if the middle array is the target value
        if (studID[middle] == target)
        {
            found = true;
            position = middle;
        }

        //prepares the search if the value is less than the middle value
        else if(studID[middle] > target)
        {
            last = middle - 1;
        }

        //prepares the if the value is more than the middle value
        else
        {
            first = middle +1;
        }
    }

    //display how many times the search function looped
    cout << "It took this many loops to find the target number : " << laps;
    cout << endl;

    return position;
}
