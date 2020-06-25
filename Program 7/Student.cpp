/*=====================================================================
Programmer:Ian Eslinger
Program: Using  a multiple class header files, create a class data type and then make a table of data using member functions
Class: CS2308
Instructor: C. Jinshong Hwang
Date:4/23/17
Description: Creates a formatted table that uses student.h to obtain the data required then clears
the memory using a destructor.  Uses a menu display to prompt user if they wish to display data tables, search for a
student's average, search the array for a student using student ids,or input final exam scores.
Input: Student records file for name and id numbers
Output: Outputs a table of data containing student names, id numbers, ten test scores, and the test averages of 15 students. Outputs a table of data containing
student names, id numbers, final exam scores and the letter grade. Outputs a table of data containing the student names, id numbers, semester average, and the letter grade.
Has a menu with options to display the tables,look up individual averages,input final exam question numbers and how many each student missed, or look up students by id using binary search
Compilation instructions: N/A
=====================================================================*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Student.h"



void displaymenu();
int binarySearch(const Student students[], const int NUM_STUD, int studID);
char semesterScore(const Student students[], const FinalExam finals[], const int NUM_STUD, int i );


int main()
{
    int i = 0;
    int id;
    int results;
    string name;
    double gpa;
    int test[] = {92,82,84,99,52,83,38,90,35,42};
    int t;
    int studID;
    int position;
    int question;
    int missed;
    char choice;
    const int NUM_STUD = 15;
    Student students[NUM_STUD];
    FinalExam finals[NUM_STUD];

    ifstream inputfile;




    //Open file for reading
    inputfile.open("C:\\Users\\kilik\\Desktop\\studentrecord.txt");

    //Error handling for reading file
    if(!inputfile)
    {
        cout << "Problem opening input file.";
    }

    //Inform user the file is being read
    cout << "File has been read" << endl;
    cout << endl << endl;



    //set name and id with data from input file
    for(i= 0; i<NUM_STUD; i++)
    {
        inputfile >> name;
        inputfile >> id;
        students[i].setName(name);
        students[i].setId(id);
    }

    //close input file
    inputfile.close();


    //set test scores for each student
    for(i = 0; i<NUM_STUD; i++)
    {

            students[i].setTest1(test[0]);
            students[i].setTest2(test[1]);
            students[i].setTest3(test[2]);
            students[i].setTest4(test[3]);
            students[i].setTest5(test[4]);
            students[i].setTest6(test[5]);
            students[i].setTest7(test[6]);
            students[i].setTest8(test[7]);
            students[i].setTest9(test[8]);
            students[i].setTest10(test[9]);
    }


    do
    {
        displaymenu();
        cin >> choice;
        while(toupper(choice) < 'A' || toupper(choice) > 'G')
        {
            cout << "Please make a choice in the range of A through G : ";
            cin >> choice;
        }

        switch(choice)
        {
        case 'a':
        case 'A': //Set display for the output
            cout << setw(10) << std::internal<< "Name";
            cout << setw(5)  << std::internal << "ID";
            cout << setw(18) <<std::internal << "Test Scores" << setw(10);
            cout << setw(30) << std::internal <<"Test Avg" << endl;
            cout << "---------------------------------------------------------------\n";

            //display the data
            for(i =0; i<NUM_STUD; i++)
            {
                cout << setw(10)<< students[i].getName() << setw(4);
                cout << setw(5) << students[i].getID() << setw(4);
                cout << setw(9) << students[i].getTest0()<< " " << students[i].getTest1() << " " << students[i].getTest2() << " " << students[i].getTest3() << " ";
                cout << students[i].getTest4() << " " << students[i].getTest5() << " " << students[i].getTest6() << " " << students[i].getTest7() << " ";
                cout << students[i].getTest8() << " " << students[i].getTest9();
                cout << setw(8) << students[i].getAvg();
                cout << endl;
            }
            break;

        case 'b':
        case 'B': //Get the average of a specific student
            cout << "Using a number from 1 to 10 choose which student you wish to see the average of : ";
            cin >> i;
            if(i < 1 || i > 10)
            {
                cout <<" Wrong selection. Please choose a number from 1 to 10.";
                cout << endl;
                cin >> i;
            }

            i--;

            cout << students[i].getName() << " has an average score of " << students[i].getAvg();
            cout << endl;
            break;

       case 'c':
       case 'C': //Search the student id records using binary search
            cout << "What is the student id you are looking for?\n" ;
            cin >> studID;

            results = binarySearch(students, NUM_STUD, studID);

            if(results == -1)
            {
                cout << "Student not found" << endl;
                cout << endl;
            }
            else
            {
                cout << "Student " << studID << " is found at element " << results << " in the array." << endl << endl;
                cout << "This is their name " << students[results].getName() <<" and their id number is " <<  students[results].getID() << endl;
                cout <<"Their test scores are as follows : ";
                cout << students[results].getTest0()<< " " << students[results].getTest1() << " " << students[results].getTest2() << " " << students[results].getTest3() << " ";
                cout << students[results].getTest4() << " " << students[results].getTest5() << " " << students[results].getTest6() << " " << students[results].getTest7() << " ";
                cout << students[results].getTest8() << " " << students[results].getTest9() << endl;
                cout << "And their test average is " << students[results].getAvg();
            }
           break;


      case 'd':
      case 'D'://Enter Final Exam Scores for each Student

          cout <<"How many questions are on the exam?\n";
          cin >> question;
          for( int i = 0; i<NUM_STUD; i++)
          {
              cout <<"How many questions did "<< students[i].getName() << " miss?\n";
              cin >> missed;

              //error handling
              if(missed > question)
              {
                  cout <<"There aren't that many questions on this exam.  There are " << question << "questions on this exam. Enter a number fewer than that." << endl;
                  cin >> missed;
              }
              finals[i].set(question, missed);
          }

           break;
      case 'e':
      case 'E'://display final exams chart
          cout << setw(10) << std::internal<< "Name";
          cout << setw(5)  << std::internal << "ID";
          cout << setw(18) <<std::internal << "Exam Scores" << setw(10);
          cout << setw(16) << std::internal <<"Letter Grade" << endl;
          cout << "---------------------------------------------------------------\n";

          for(i =0; i<NUM_STUD; i++)
          {
            cout << setw(10)<< students[i].getName() << setw(4);
            cout << setw(6) << students[i].getID() << setw(4);
            cout << setw(9) << finals[i].getScore() << setw(4);
            cout << setw(14) << finals[i].getLetterGrade() << endl;

          }


           break;
      case 'f':
      case 'F'://display semester grades
          cout << setw(10) << std::internal<< "Name";
          cout << setw(5)  << std::internal << "ID";
          cout << setw(18) <<std::internal << " Exam Scores " << setw(10);
          cout << setw(20) << std::internal <<" Semester Grade " << endl;
          cout << "----------------------------------------------------------\n";

          for(i =0; i<NUM_STUD; i++)
          {
            cout << setw(10)<< students[i].getName() << setw(4);
            cout << setw(6) << students[i].getID() << setw(4);
            cout << setw(9) << finals[i].getScore() << setw(4);
            cout << setw(14) << semesterScore(students, finals, NUM_STUD, i) << endl;
          }

           break;
        case 'g':
        case 'G'://Exiting program
           cout << "Exiting program";
        }

    }while (toupper(choice) != 'G');
    return 0;
}



void displaymenu()
{
    cout <<"\n                        Menu\n";
    cout <<"---------------------------------------------------\n";
    cout <<" A) Display table of student records\n";
    cout <<" B) Display a specific student's Average scores\n";
    cout <<" C) Search student records for a student\n";
    cout <<" D) Enter Final Exam Scores\n";
    cout <<" E) Display Final Exam Score Table\n";
    cout <<" F) Display Semester Grades for all Students\n";
    cout <<" G) Exit the program\n";
    cout <<"Enter your choice: ";
}

int binarySearch(const Student students[], const int NUM_STUD, int studID)
{
    int first = 0;
    int last = NUM_STUD - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {

        middle = (first + last) / 2;
        if(students[middle].id_num == studID)
        {
            found = true;
            position = middle;
        }
        else if (students[middle].id_num > studID)
        {
            last = middle - 1;
        }
        else
            first = middle + 1;
    }
    return position;
}


char semesterScore(const Student students[], const FinalExam finals[], const int NUM_STUD, int i )
{
    double finalScore;
    double finalAvg;
    double testScores;
    double testAvg;
    double semesterAvg;
    char lettrGrade;


    testScores += students[i].getTest0();
    testScores += students[i].getTest1();
    testScores += students[i].getTest2();
    testScores += students[i].getTest3();
    testScores += students[i].getTest4();
    testScores += students[i].getTest5();
    testScores += students[i].getTest6();
    testScores += students[i].getTest7();
    testScores += students[i].getTest8();
    testScores += students[i].getTest9();

    testAvg = (testScores / 10) * 0.6;

    finalScore = finals[i].getScore();

    finalAvg = finalScore * 0.4;

    semesterAvg = finalAvg + testAvg;

    GradedActivity semester(semesterAvg);

    lettrGrade = semester.getLetterGrade();

    return lettrGrade;
}
