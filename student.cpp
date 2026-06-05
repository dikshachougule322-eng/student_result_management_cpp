#include <iostream>
#include <fstream>
#include "student.h"

using namespace std;

// ================= ADD STUDENT =================
// This function adds new student details into array
void addStudent(Student students[], int &count)
{
    cout << "\nEnter Roll Number: ";
    cin >> students[count].rollNo;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, students[count].name);

    students[count].total = 0;

    cout << "Enter Marks of 5 Subjects:\n";

    // Taking marks input and calculating total
    for(int i = 0; i < 5; i++)
    {
        cout << "Subject " << i + 1 << ": ";
        cin >> students[count].marks[i];

        students[count].total += students[count].marks[i];
    }

    // Calculating percentage
    students[count].percentage = students[count].total / 5.0;

    // Assigning grade
    if(students[count].percentage >= 80)
        students[count].grade = 'A';
    else if(students[count].percentage >= 60)
        students[count].grade = 'B';
    else if(students[count].percentage >= 40)
        students[count].grade = 'C';
    else
        students[count].grade = 'F';

    count++;

    cout << "\nStudent Added Successfully!\n";
}

// ================= VIEW STUDENTS =================
// This function displays all student records in table format
void viewStudents(Student students[], int count)
{
    if(count == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\n====================================================\n";
    cout << "Roll No\tName\t\tTotal\tPercentage\tGrade\n";
    cout << "====================================================\n";

    for(int i = 0; i < count; i++)
    {
        cout << students[i].rollNo << "\t"
             << students[i].name << "\t\t"
             << students[i].total << "\t"
             << students[i].percentage << "%\t\t"
             << students[i].grade << endl;
    }
}

// ================= SEARCH STUDENT =================
// This function searches student using roll number
void searchStudent(Student students[], int count)
{
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll No: " << students[i].rollNo << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Total: " << students[i].total << endl;
            cout << "Percentage: " << students[i].percentage << "%" << endl;
            cout << "Grade: " << students[i].grade << endl;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "Student Record Not Found!\n";
    }
}

// ================= UPDATE STUDENT =================
// This function updates marks of existing student
void updateStudent(Student students[], int count)
{
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;

    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            found = true;
            students[i].total = 0;

            cout << "Enter New Marks for 5 Subjects:\n";

            for(int j = 0; j < 5; j++)
            {
                cout << "Subject " << j + 1 << ": ";
                cin >> students[i].marks[j];

                students[i].total += students[i].marks[j];
            }

            // Recalculate percentage
            students[i].percentage = students[i].total / 5.0;

            // Reassign grade
            if(students[i].percentage >= 80)
                students[i].grade = 'A';
            else if(students[i].percentage >= 60)
                students[i].grade = 'B';
            else if(students[i].percentage >= 40)
                students[i].grade = 'C';
            else
                students[i].grade = 'F';

            cout << "\nStudent Updated Successfully!\n";
            break;
        }
    }

    if(!found)
    {
        cout << "Student Record Not Found!\n";
    }
}

// ================= DELETE STUDENT =================
// This function deletes student record from array
void deleteStudent(Student students[], int &count)
{
    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;

    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            found = true;

            // Shift all next records left
            for(int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;

            cout << "\nStudent Record Deleted Successfully!\n";
            break;
        }
    }

    if(!found)
    {
        cout << "Student Record Not Found!\n";
    }
}

// ================= SAVE TO FILE =================
// This function saves all data into file
void saveToFile(Student students[], int count)
{
    ofstream file("students.txt");

    for(int i = 0; i < count; i++)
    {
        file << students[i].rollNo << endl;
        file << students[i].name << endl;

        for(int j = 0; j < 5; j++)
        {
            file << students[i].marks[j] << " ";
        }

        file << endl;
    }

    file.close();
}

// ================= LOAD FROM FILE =================
// This function loads data from file into array
void loadFromFile(Student students[], int &count)
{
    ifstream file("students.txt");

    count = 0;

    while(file >> students[count].rollNo)
    {
        file.ignore();

        getline(file, students[count].name);

        students[count].total = 0;

        for(int j = 0; j < 5; j++)
        {
            file >> students[count].marks[j];
            students[count].total += students[count].marks[j];
        }

        students[count].percentage = students[count].total / 5.0;

        if(students[count].percentage >= 80)
            students[count].grade = 'A';
        else if(students[count].percentage >= 60)
            students[count].grade = 'B';
        else if(students[count].percentage >= 40)
            students[count].grade = 'C';
        else
            students[count].grade = 'F';

        count++;
    }

    file.close();
}
