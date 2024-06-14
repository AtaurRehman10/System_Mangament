#include <iostream>
#include <string>
using namespace std;

// define a structure to hold student information
struct student
{
     string rollno;
     string name;
     string fname;
     string course;
     string ID;
};

// array to store students
student s[50];
int ts = 0; // total number of students

// function to add a student
void add_student()
{
     system("clear");
     if (ts < 50)
     {
          cout << "Enter Roll No:   ";
          cin >> s[ts].rollno;
          cout << "Enter Name:   ";
          cin >> s[ts].name;
          cout << "Enter Father's Name:   ";
          cin >> s[ts].fname;
          cout << "Enter the Course name:   ";
          cin >> s[ts].course;
          cout << "Enter the System_ID:   ";
          cin >> s[ts].ID;
          ts++;
          cout << "Student added successfully." << endl;
     }
     else
     {
          cout << "maximum limit reached." << endl;
     }
}

// function to delete a student by roll number
void delete_student(string delete_rollno)
{
     system("clear");
     int index = -1;
     // find the student by roll number
     for (int i = 0; i < ts; i++)
     {
          if (s[i].rollno == delete_rollno)
          {
               index = i;
               break;
          }
     }

     // If student found, delete by shifting elements
     if (index != -1)
     {
          for (int i = index; i < ts - 1; i++)
          {
               s[i] = s[i + 1];
          }
          ts--;
          cout << "Student with roll number  : " << delete_rollno << " deleted successfully." << endl;
     }
     else
     {
          cout << "Student with roll number  : " << delete_rollno << " not found." << endl;
     }
}

// function to update student information by roll number
void update_student(string update_rollno)
{
     system("clear");
     for (int i = 0; i < ts; i++)
     {
          if (s[i].rollno == update_rollno)
          {
               cout << "Enter New Name:   ";
               cin >> s[i].name;
               cout << "Enter New Father's Name:    ";
               cin >> s[i].fname;
               cout << "Enter New course name:   ";
               cin >> s[i].course;
               cout << "Enter New System_ID:   ";
               cin >> s[i].ID;
               return;
          }
     }
     cout << "Student not found." << endl;
}

// function to search for a student by roll number
void search_student(string search_rollno)
{
     system("clear");
     for (int i = 0; i < ts; i++)
     {
          if (s[i].rollno == search_rollno)
          {
               cout << "Student found:" << endl;
               cout << "Roll No:  " << s[i].rollno << endl;
               cout << "Name:  " << s[i].name << endl;
               cout << "Father's Name:  " << s[i].fname << endl;
               cout << "Course:   " << s[i].course << endl;
               cout << "System_ID:   " << s[i].ID << endl;
               return;
          }
     }
     cout << "Student not found." << endl;
}

// function to display all students
void display_all_student()
{
     system("clear");
     if (ts == 0)
     {
          cout << "No students to display." << endl;
     }
     else
     {
          for (int i = 0; i < ts; i++)
          {
               cout << "\nStudent " << i + 1 << ":" << endl;
               cout << "Roll No:  " << s[i].rollno << endl;
               cout << "Name:  " << s[i].name << endl;
               cout << "Father's Name:  " << s[i].fname << endl;
               cout << "Course:   " << s[i].course << endl;
               cout << "System_ID:   " << s[i].ID << endl;
          }
     }
}

int main()
{
     char choice;
     string roll_number;

     // main program menu
     cout << "\t------------------------" << endl;
     cout << "\tStudent Management System" << endl;
     cout << "\t------------------------" << endl;
     cout << "\tYou are date limit is 50 Student";

     while (true)
     {
          cout << "\n\tWhat do you want to do?" << endl;
          cout << "\t----------------------" << endl;
          cout << "\t1-Add student" << endl;
          cout << "\t2-Delete student" << endl;
          cout << "\t3-Update student" << endl;
          cout << "\t4-Search student" << endl;
          cout << "\t5-Display all students" << endl;
          cout << "\t6-Quit Program" << endl;
          cout << "\t----------------------" << endl;

          cout << "Enter your choice: ";
          cin >> choice;

          switch (choice)
          {
          case '1':
               add_student();
               break;
          case '2':
               cout << "\t1-Delete Specific student data" << endl;
               cout << "\t2-Delete all student data" << endl;
               cout << "Enter your choice: ";
               cin >> choice;
               if (choice == '1')
               {
                    if (ts == 0)
                    {
                         cout << "Please add students first." << endl;
                    }
                    else
                    {
                         cout << "Enter student roll number to delete: ";
                         cin >> roll_number;
                         delete_student(roll_number);
                    }
               }
               else if (choice == '2')
               {
                    ts = 0;
                    cout << "All students data deleted successfully." << endl;
               }
               else
               {
                    cout << "Invalid choice. Please try again." << endl;
               }
               break;
          case '3':
               if (ts == 0)
               {
                    cout << "Please add students first." << endl;
               }
               else
               {
                    cout << "Enter student roll number to update:  ";
                    cin >> roll_number;
                    update_student(roll_number);
               }
               break;
          case '4':
               if (ts == 0)
               {
                    cout << "Please add students first." << endl;
               }
               else
               {
                    cout << "Enter student roll number to search:  ";
                    cin >> roll_number;
                    search_student(roll_number);
               }
               break;
          case '5':
               display_all_student();
               break;
          case '6':
               exit(0);
          default:
               cout << "Invalid choice. Please try again." << endl;
          }
     }
}
