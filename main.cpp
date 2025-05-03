#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    // Default constructor
    Book() {
        title = "";
        author = "";
        isbn = "";
        isAvailable = true;
    }

    // Method to assign values to the book’s attributes
    void setBookDetails(string t, string a, string i, bool avail = true) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = avail;
    }

    // Method to display book's title, author, ISBN, and current availability
    void displayBookDetails() {
        cout << "\nBook Details:\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }

    // Method to borrow a book if available
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "You have successfully borrowed the book.\n";
            return true;
        } else {
            cout << "This book is currently not available.\n";
            return false;
        }
    }

    // Method to return a book
    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully.\n";
    }

    // Method to get ISBN of the book
    string getISBN() {
        return isbn;
    }
};

int main() {
    const int size = 5;
    Book library[size];

    // Initialize an array of 5 books
    library[0].setBookDetails("1984", "George Orwell", "1111");
    library[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "2222");
    library[2].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "3333");
    library[3].setBookDetails("Moby Dick", "Herman Melville", "4444");
    library[4].setBookDetails("Pride and Prejudice", "Jane Austen", "5555");

    string userISBN;
    while (true) {
        cout << "\nEnter ISBN to borrow a book (or 0 to exit): ";
        cin >> userISBN;

        if (userISBN == "0") {
            cout << "Exiting the system. Thank you!\n";
            break;
        }

        bool found = false;

        for (int i = 0; i < size; i++) {
            if (library[i].getISBN() == userISBN) {
                found = true;
                library[i].displayBookDetails();
                library[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "No book found with ISBN " << userISBN << ".\n";
        }
    }

    return 0;
}

