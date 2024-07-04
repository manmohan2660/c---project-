#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

// Book class to represent each book


class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }

    void display() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

// Library class to manage the collection of books


class Library {
private:
    vector<Book> books;
    queue<int> issuedBooks;

public:

    // Function to add a new book to the library


    void addBook(int id, string title, string author) {
        Book newBook(id, title, author);
        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }



    // Function to search for a book by its ID

    
    void searchBookById(int id) {
        for (Book &book : books) {
            if (book.id == id) {
                book.display();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Function to search for a book by its title



    void searchBookByTitle(string title) {
        for (Book &book : books) {
            if (book.title == title) {
                book.display();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Function to issue a book to a student


    void issueBook(int id, int studentId) {
        for (Book &book : books) {
            if (book.id == id && !book.isIssued) {
                book.isIssued = true;
                issuedBooks.push(studentId);
                cout << "Book issued successfully!" << endl;
                return;
            }
        }
        cout << "Book is either not available or already issued!" << endl;
    }

    // Function to return a book


    void returnBook(int id) {
        for (Book &book : books) {
            if (book.id == id && book.isIssued) {
                book.isIssued = false;
                issuedBooks.pop();
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "Book is not issued!" << endl;
    }

    // Function to list all books in the library


    void listAllBooks() {
        sort(books.begin(), books.end(), [](Book &a, Book &b) {
            return a.id < b.id;  // or use a.title < b.title for sorting by title
        });
        for (Book &book : books) {
            book.display();
        }
    }

    // Function to delete a book from the library
    void deleteBook(int id) {
        books.erase(remove_if(books.begin(), books.end(), [id](Book &book) {
            return book.id == id;
        }), books.end());
        cout << "Book deleted successfully!" << endl;
    }
};

// Main function to demonstrate the library management system

int main() {
    Library library;
    int choice, id, studentId;
    string title, author;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book by ID" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. List All Books" << endl;
        cout << "7. Delete Book" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;
            case 2:
                cout << "Enter Book ID: ";
                cin >> id;
                library.searchBookById(id);
                break;
            case 3:
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            case 4:
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Student ID: ";
                cin >> studentId;
                library.issueBook(id, studentId);
                break;
            case 5:
                cout << "Enter Book ID: ";
                cin >> id;
                library.returnBook(id);
                break;
            case 6:
                library.listAllBooks();
                break;
            case 7:
                cout << "Enter Book ID: ";
                cin >> id;
                library.deleteBook(id);
                break;
            case 8:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
