#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
using namespace std;

// ================= STUDENT STRUCTURE =================
// This structure stores all information of a student
struct Student
{
    int rollNo;          // Student Roll Number
    string name;         // Student Name
    int marks[5];        // Marks of 5 subjects
    int total;           // Total marks
    float percentage;    // Percentage
    char grade;          // Grade (A/B/C/F)
};

// ================= FUNCTION DECLARATIONS =================
// These functions are defined in students.cpp

void addStudent(Student students[], int &count);
// Adds a new student record

void viewStudents(Student students[], int count);
// Displays all student records in tabular format

void searchStudent(Student students[], int count);
// Searches student by roll number

void updateStudent(Student students[], int count);
// Updates marks of existing student

void deleteStudent(Student students[], int &count);
// Deletes student record from array

void saveToFile(Student students[], int count);
// Saves all student data into file

void loadFromFile(Student students[], int &count);
// Loads student data from file at program start

#endif
