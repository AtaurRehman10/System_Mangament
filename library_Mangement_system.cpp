#include <iostream>
#include <string>
using namespace std;

const int book = 100;
// declare the string array
string titles[book];
string authors[book];
int ids[book];
bool available[book];
int bookcount = 0;

void addBook()
{

     if (bookcount >= book)
     {
          cout << "library is full. cannot add more books." << endl;
          return;
     }
     // take user input information

     cout << "Enter book title: ";
     cin >> titles[bookcount];

     cout << "Enter book author: ";
     cin >> authors[bookcount];

     cout << "Enter book ID: ";
     cin >> ids[bookcount];

     available[bookcount] = true;
     bookcount++;
     cout << "book added successfully" << endl;
}
void searchBooks()
{
     // choose the choice
     int choice;
     cout << "search by 1 title or 2 author? ";
     cin >> choice;

     //  first choice check by title
     if (choice == 1)
     {
          string title;
          cout << "Enter title: ";
          cin >> title;

          for (int i = 0; i < bookcount; i++)
          {
               if (titles[i] == title)
               {
                    cout << "Book found: " << titles[i] << " by " << authors[i] << ", ID: " << ids[i];
                    if (available[i]==true)
                    {
                         cout << ", available" << endl;
                    }
                    else{
                         cout << ", not available" << endl;
                    }
                    
                    return;
               }
          }
          cout << "Book not found." << endl;
     }
     // second choice check by author
     else if (choice == 2)
     {
          string author;
          cout << "Enter author: ";
          cin >> author;

          for (int i = 0; i < bookcount; i++)
          {
               if (authors[i] == author)
               {
                    cout << "Book found: " << titles[i] << " by " << authors[i] << ", ID: " << ids[i] << endl;
                         if (available[i]==true)
                    {
                         cout << ", available" << endl;
                    }
                    else{
                         cout << ", not available"<<endl;
                    }
                    return;
               }
          }
          cout << "book not found." << endl;
     }
     else
     {
          cout << "Invalid choice." << endl;
     }
}
void displayAllBooks()
{
     if (bookcount == 0)
     {
          cout << "no books in the library." << endl;
          return;
     }

     //  loop can display the the all book
     for (int i = 0; i < bookcount; i++)
     {
          cout << "Book " << i + 1 << ": " << titles[i] << " by " << authors[i] << ", ID: " << ids[i] << endl;
     }
}
void borrowBook()
{
     int bookId;
     cout << "Enter the ID of the book to borrow: ";
     cin >> bookId;

     //  loop can display the the borrow book
     for (int i = 0; i < bookcount; i++)
     {
          if (ids[i] == bookId)
          {
               if (available[i])
               {
                    available[i] = false;
                    cout << "You have borrowed: " << titles[i] << " by " << authors[i] << endl;
               }
               else
               {
                    cout << "sorry, the book is currently not available." << endl;
               }
               return;
          }
     }
     cout << "book not found." << endl;
}

int main()
{

     while (true)
     {
          cout<<"----------------------------";
          cout << "\nlibrary management system\n";
          cout<<"-----------------------------"<<endl;
          cout << "1. add Book\n";
          cout << "2. search Books\n";
          cout << "3. display All Books\n";
          cout << "4. borrow Book\n";
          cout << "5. exit\n";
          cout << "E\enter your choice: ";

          int choice;
          cin >> choice;

          switch (choice)
          {
          case 1:
               addBook();
               break;
          case 2:
               searchBooks();
               break;
          case 3:
               displayAllBooks();
               break;
          case 4:
               borrowBook();
               break;
          case 5:
               cout << "exiting the program." << endl;
               return 0;
          default:
               cout << "invalid choice. please try again." << endl;
          }
     }

     return 0;
}
