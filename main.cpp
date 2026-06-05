#include <iostream>
#include"student.h"

using namespace std;

int main()
{
    // Array to store student records
    Student students[100];

    // Keeps track of number of students added
    int count = 0;

    // Load existing data from file at program start
    loadFromFile(students, count);

    int choice;

    do
    {
        // ===== MENU DISPLAY =====
        cout << "\n===== Student Result Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        // ===== MENU OPERATIONS =====
        switch(choice)
        {
            // Add new student
            case 1:
                addStudent(students, count);
                break;

            // Display all students
            case 2:
                viewStudents(students, count);
                break;

            // Search student by roll number
            case 3:
                searchStudent(students, count);
                break;

            // Update marks of existing student
            case 4:
                updateStudent(students, count);
                break;

            // Delete student record
            case 5:
                deleteStudent(students, count);
                break;

            // Exit program and save data
            case 6:
                saveToFile(students, count);
                cout << "Data Saved Successfully!\n";
                cout << "Exiting Program...\n";
                break;

            // Invalid input handling
            default:
                cout << "Invalid Choice! Try again.\n";
        }

    } while(choice != 6); // loop until user exits

    return 0;
}