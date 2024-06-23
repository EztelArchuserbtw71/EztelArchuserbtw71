#include <iostream>
#include <string>  
#include <algorithm>  
using namespace std;

int getNumStudents() {
    return 3;
}

int getNumGrades() {
    return 3;
}

void inputGrades(float gtGrades[], float quizGrades[], float maGrades[], int numGrades) {
    for (int j = 0; j < numGrades; ++j) {
        float grade;
        do {
            cout << "Enter GT " << j + 1 << " grade: ";
            cin >> grade;
            if (grade < 0 || grade > 100) {
                cout << "Invalid grade! Grade should be between 0 and 100." << endl;
            }
        } while (grade < 0 || grade > 100);
        gtGrades[j] = grade;

        do {
            cout << "Enter Quiz " << j + 1 << " grade: ";
            cin >> grade;
            if (grade < 0 || grade > 100) {
                cout << "Invalid grade! Grade should be between 0 and 100." << endl;
            }
        } while (grade < 0 || grade > 100);
        quizGrades[j] = grade;

        do {
            cout << "Enter MA " << j + 1 << " grade: ";
            cin >> grade;
            if (grade < 0 || grade > 100) {
                cout << "Invalid grade! Grade should be between 0 and 100." << endl;
            }
        } while (grade < 0 || grade > 100);
        maGrades[j] = grade;
    }
}

int main() {
    int NUM_STUDENTS = getNumStudents();
    int NUM_GRADES = getNumGrades();
    
    float semestralGrades[NUM_STUDENTS];
    float gtGrades[NUM_GRADES], quizGrades[NUM_GRADES], maGrades[NUM_GRADES];

    string studentNames[NUM_STUDENTS];

    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Enter name for Student " << i + 1 << ": ";
        cin >> studentNames[i];
        cout << "Enter grades for " << studentNames[i] << ":" << endl;
        inputGrades(gtGrades, quizGrades, maGrades, NUM_GRADES);
        
        float gtAverage = 0, quizAverage = 0, maSum = 0;
        for (int j = 0; j < NUM_GRADES; ++j) {
            gtAverage += gtGrades[j];
            quizAverage += quizGrades[j];
            maSum += maGrades[j];
        }
        gtAverage /= NUM_GRADES;
        quizAverage /= NUM_GRADES;
        semestralGrades[i] = gtAverage * 0.25 + quizAverage * 0.30 + maSum * 0.45 / 3;
    }

    cout << "\nStudent Data:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        cout << "Name: " << studentNames[i] << endl;
        cout << "Semestral Grade: " << semestralGrades[i] << endl;

        float gradePoint;
        if (semestralGrades[i] >= 96) gradePoint = 4.0;
        else if (semestralGrades[i] >= 91) gradePoint = 4.0;
        else if (semestralGrades[i] >= 88) gradePoint = 3.75;
        else if (semestralGrades[i] >= 85) gradePoint = 3.5;
        else if (semestralGrades[i] >= 82) gradePoint = 3.25;
        else if (semestralGrades[i] >= 79) gradePoint = 3.0;
        else if (semestralGrades[i] >= 76) gradePoint = 2.75;
        else if (semestralGrades[i] >= 73) gradePoint = 2.5;
        else if (semestralGrades[i] >= 70) gradePoint = 2.25;
        else if (semestralGrades[i] >= 67) gradePoint = 2.0;
        else if (semestralGrades[i] >= 64) gradePoint = 1.75;
        else if (semestralGrades[i] >= 61) gradePoint = 1.5;
        else gradePoint = 1.0;
        cout << "Grade Point: " << gradePoint << endl;

        char letterGrade;
        if (semestralGrades[i] >= 96) letterGrade = 'A';
        else if (semestralGrades[i] >= 91) letterGrade = 'A';
        else if (semestralGrades[i] >= 88) letterGrade = 'A-';
        else if (semestralGrades[i] >= 85) letterGrade = 'B+';
        else if (semestralGrades[i] >= 82) letterGrade = 'B';
        else if (semestralGrades[i] >= 79) letterGrade = 'B-';
        else if (semestralGrades[i] >= 76) letterGrade = 'C+';
        else if (semestralGrades[i] >= 73) letterGrade = 'C';
        else if (semestralGrades[i] >= 70) letterGrade = 'C-';
        else if (semestralGrades[i] >= 67) letterGrade = 'D+';
        else if (semestralGrades[i] >= 64) letterGrade = 'D';
        else if (semestralGrades[i] >= 61) letterGrade = 'D-';
        else letterGrade = 'F';
        cout << "Letter Grade: " << letterGrade << endl;
    }

    for (int i = 0; i < NUM_STUDENTS - 1; ++i

) {
        for (int j = 0; j < NUM_STUDENTS - i - 1; ++j) {
            if (semestralGrades[j] < semestralGrades[j + 1]) {
                swap(semestralGrades[j], semestralGrades[j + 1]);
                swap(gtGrades[j], gtGrades[j + 1]);
                swap(quizGrades[j], quizGrades[j + 1]);
                swap(maGrades[j], maGrades[j + 1]);
                swap(studentNames[j], studentNames[j + 1]);
            }
        }
    }

    cout << "\nRanking of Students based on Semestral Grades (Highest to Lowest):\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << i + 1 << ": " << semestralGrades[i] << endl;
    }

    return 0;
}
