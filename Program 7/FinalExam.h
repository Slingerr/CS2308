/*=====================================================================
Programmer:Ian Eslinger
Program: Class specification header file for final exam
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 4/23/17
Description: header file that obtains and returns the final exam data then clears
the memory using a destructor
Input: the number of questions, and how many were missed
Output: returns the score achieved on the final exam
Compilation instructions: N/A
=====================================================================*/
#ifndef FINALEXAM_H
#define FINALEXAM_H
#include "GradedActivity.h"


class FinalExam : public GradedActivity
{
    private:
        int numQuestions;
        double pointsEach;
        int numMissed;

    public:
        //default constructor
        FinalExam()
        {
            numQuestions = 0;
            pointsEach = 0.0;
            numMissed = 0;
        }

        //overloaded constructor
        FinalExam(int questions, int missed)
        {set(questions, missed);}

        //destructor
        ~FinalExam() = default;

        //set final exam score
        void set(int questions, int missed)
        {
            double numericScore;

            numQuestions = questions;
            numMissed = missed;

            pointsEach = 100.0/numQuestions;

            numericScore = 100.0 - (missed * pointsEach);

            setScore( numericScore);

        }

        //get number of exam questions
        double getNumQuestions() const
        {return numQuestions;}

        //get points each question is worth
        double getPointsEach() const
        {return pointsEach;}

        //get number of missed questions
        int getNumMissed() const
        {return numMissed;}
};
#endif
