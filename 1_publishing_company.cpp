#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;

        if (price < 0) {
            throw runtime_error("Price cannot be negative");
        }
    }

    void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class Book
class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData();

        cout << "Enter page count: ";
        cin >> pageCount;

        if (pageCount < 0) {
            throw runtime_error("Page count cannot be negative");
        }
    }

    void displayData() const {
        Publication::displayData();
        cout << "Page Count: " << pageCount << " pages" << endl;
    }

    void resetData() {
        title = "";
        price = 0.0;
        pageCount = 0;
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playTime;

public:
    Tape() : playTime(0.0) {}

    void getData() {
        Publication::getData();

        cout << "Enter playing time (in minutes): ";
        cin >> playTime;

        if (playTime < 0) {
            throw runtime_error("Playing time cannot be negative");
        }
    }

    void displayData() const {
        Publication::displayData();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }

    void resetData() {
        title = "";
        price = 0.0;
        playTime = 0.0;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for Book:\n";
    try {
        book.getData();
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Resetting book data to zero values.\n";
        book.resetData();
    }

    cout << "\nEnter details for Tape:\n";
    try {
        tape.getData();
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Resetting tape data to zero values.\n";
        tape.resetData();
    }

    cout << "\nDisplaying details:\n";
    cout << "\nBook details:\n";
    book.displayData();

    cout << "\nTape details:\n";
    tape.displayData();

    return 0;
}
