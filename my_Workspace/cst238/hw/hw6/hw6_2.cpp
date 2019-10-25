/*
 * Title: hw6_2.cpp
 * Abstract: This program uses a class GpaCalculator that functions on dynamic arrays to calculate
 * the gpa based on the objects member variables.
 * Author: Roy Morla
 * ID: 1534 
 * Date: 10/23/2019
 */
#include <iostream>
using namespace std;

const int SIZE = 12;
const string GRADES [SIZE] = {"A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-",
"F"};
const double GRADEPOINTS [SIZE] = {4.0, 3.67, 3.33, 3.0, 2.67, 2.33, 2.0, 1.67, 1.33, 1,
0.67, 0};

double getGradePoints(string grade) {
for (int i = 0; i < SIZE; i++) {
    if(GRADES[i] == grade) {
        return GRADEPOINTS[i];
        }
    }
    return 0;
}
class GpaCalculator {
    public:
        GpaCalculator();
        GpaCalculator(int courseCount);
        void addCourse(int credits, string grade);
        int getCourseCount() const { return myCourseCount; };
        double getTotalGradePoints() const;
        int getTotalCredits() const;
        double getGpa() const;
        ~GpaCalculator();
    private:
        int myCourseCount;
        int myCoursesEntered = 0;
        int * myCredits;
        double * myGradePoints;
};

GpaCalculator::GpaCalculator() : myCourseCount(0) {
    myCredits = new int[0];
    myGradePoints = new double[0];
}

GpaCalculator::GpaCalculator(int courseCount) : myCourseCount(courseCount) {
    myCredits = new int[courseCount];
    myGradePoints = new double[courseCount];
}

void GpaCalculator::addCourse(int credits, string grade) {
    int *tempc = new int[myCoursesEntered + 1];
    double *tempg = new double[myCoursesEntered + 1];
    for (int i = 0; i < myCoursesEntered; i++) {
        tempc[i] = myCredits[i];
        tempg[i] = myGradePoints[i];
        
    }
    tempc[myCoursesEntered] = credits;
    tempg[myCoursesEntered] = getGradePoints(grade);
    delete [] myCredits;
    delete [] myGradePoints;

    myCredits = tempc;
    myGradePoints = tempg;
    myCoursesEntered++;
    
}
double GpaCalculator::getTotalGradePoints() const {
    double totalGradePoints = 0.0;
    for (int i = 0; i < myCoursesEntered; i++) {
        totalGradePoints += myGradePoints[i] * myCredits[i];
    }
    return totalGradePoints;
}

int GpaCalculator::getTotalCredits() const {
    int totalCredits = 0;
    for (int i = 0; i < myCoursesEntered; i++) {
        totalCredits += myCredits[i];
    }
    return totalCredits;

}

double GpaCalculator::getGpa () const {
    int credits = getTotalCredits();
    double gradepoints = getTotalGradePoints();
    double myGPA = gradepoints / credits;
    return myGPA;
}

GpaCalculator::~GpaCalculator() {
    delete [] myCredits;
    delete [] myGradePoints;
}

int main () {

    return 0;
}