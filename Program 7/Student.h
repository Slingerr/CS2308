/*=====================================================================
Programmer:Ian Eslinger
Program: Class specification header file for student
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 4/23/17
Description: header file that obtains and displays the data to be formatted then clears
the memory using a destructor
Input: N/A
Output: Displays the name, id number, 10 test scores, and test average of 15 students
Compilation instructions: N/A
=====================================================================*/
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "FinalExam.h"

using namespace std;

class Student : public FinalExam
{
     private:
        double avg;
        string name;
        int t_score[10];
        double avg_score;
        double exam_score;
        char exam_lettr;
    public:

        int id_num;
        int q;
        int miss;

        //set defaults
        Student()
        {
            id_num = 0;
            name = " ";
            t_score[10] = 0;
            avg_score = 0.0;
            exam_score = 0.0;
            exam_lettr = 'E';
        }



        Student(string n, int id, int t, double avg, double ex, char l)
        {
            name = n;
            id_num = id;
            avg_score = avg;
            t_score[0] = t;
            t_score[1] = t;
            t_score[2] = t;
            t_score[3] = t;
            t_score[4] = t;
            t_score[5] = t;
            t_score[6] = t;
            t_score[7] = t;
            t_score[8] = t;
            t_score[9] = t;
            exam_score = ex;
            exam_lettr = l;
        }

        ~ Student() = default;

        //set name for each student
        void setName (string n)
        {name = n;}

        //set id number for each student
        void setId (int i)
        {id_num = i;}

        //set 10 test scores
        void setTest1 (int t)
        {t_score[0] = t;}

        void setTest2 (int t)
        {t_score[1] = t;}

        void setTest3 (int t)
        {t_score[2] = t;}

        void setTest4 (int t)
        {t_score[3] = t;}

        void setTest5 (int t)
        {t_score[4] = t;}

        void setTest6 (int t)
        {t_score[5] = t;}

        void setTest7 (int t)
        {t_score[6] = t;}

        void setTest8 (int t)
        {t_score[7] = t;}

        void setTest9 (int t)
        {t_score[8] = t;}

        void setTest10 (int t)
        {t_score[9] = t;}

        void setExam (double ex)
        {exam_score = ex;}

        void setExamLettt(char l)
        {exam_lettr = l;}

        //display the name
        string getName() const
        {return name;}

        //display the id
        int getID() const
        {return id_num;}

        //display the test scores
        int getTest0() const
        {return t_score[0];}

        int getTest1() const
        {return t_score[1];}

        int getTest2() const
        {return t_score[2];}

        int getTest3() const
        {return t_score[3];}

        int getTest4() const
        {return t_score[4];}

        int getTest5() const
        {return t_score[5];}

        int getTest6() const
        {return t_score[6];}

        int getTest7() const
        {return t_score[7];}

        int getTest8() const
        {return t_score[8];}

        int getTest9() const
        {return t_score[9];}

        double getExamNum() const
        {getScore();}

        char getExamLetter() const
        { getLetterGrade();}


        //figure out the average
        double getAvg() const
        {
            double sum;
            for(int i = 0; i< 10; i++)
            {
                sum += t_score[i];
            }
            return (sum/10.0);
        }
};
#endif
