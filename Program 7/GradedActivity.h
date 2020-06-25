/*=====================================================================
Programmer:Ian Eslinger
Program: Class specification header file for graded activity
Class: CS2308
Instructor: C. Jinshong Hwang
Date: 4/23/17
Description: header file that obtains and returns the score and letter grade for the final
and the semester then clears the memory with a destructor
the memory using a destructor
Input: test score
Output: returns the calculated letter grade
Compilation instructions: N/A
=====================================================================*/
#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H


class GradedActivity
{
    private:
        double score;

    public:
        //constructor
        GradedActivity()
        {  score = 0.0;}

        //overloaded constructor
        GradedActivity(double s)
        { score = s;}

        ~GradedActivity() = default;


        //set score
        void setScore(double s)
        {score = s;}

        //retrieve score
        double getScore() const
        {return score;}

        //return letter grade
        char getLetterGrade() const
        {
            char letterGrade;

            if(score >89)
                letterGrade = 'A';
            else if(score > 79)
                letterGrade = 'B';
            else if(score > 69)
                letterGrade = 'C';
            else if(score > 59)
                letterGrade = 'D';
            else
                letterGrade = 'F';

            return letterGrade;
        }
};
#endif
