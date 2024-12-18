#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a structure for personal records
struct PersonalRecord {
    string name;
    string dob; // Date of Birth in format "YYYY-MM-DD"
    string telephone;

    // Function to display the record
    void display() const {
        cout << "Name: " << name << ", DOB: " << dob << ", Telephone: " << telephone << endl;
    }
};

// Comparator function for sorting by name
bool compareByName(const PersonalRecord &a, const PersonalRecord &b) {
    return a.name < b.name;
}

// Function to add a new record
void addRecord(vector<PersonalRecord> &records) {
    PersonalRecord record;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, record.name);
    cout << "Enter Date of Birth (YYYY-MM-DD): ";
    cin >> record.dob;
    cout << "Enter Telephone Number: ";
    cin >> record.telephone;

    records.push_back(record);
    cout << "Record added successfully!" << endl;
}

// Function to display all records
void displayRecords(const vector<PersonalRecord> &records) {
    if (records.empty()) {
        cout << "No records available." << endl;
        return;
    }
    
    cout << "Personal Records:" << endl;
    for (auto record : records) {
        record.display();
    }
}

// Function to search for a record by name
void searchRecord(vector<PersonalRecord> &records) {
    string name;
    cout << "Enter the name to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (const auto &record : records) {
        if (record.name == name) {
            cout << "Record found:" << endl;
            record.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No record found with the name: " << name << endl;
    }
}

// Main function
int main() {
    vector<PersonalRecord> records;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Sort Records by Name\n";
        cout << "4. Search Record by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord(records);
                break;
            case 2:
                displayRecords(records);
                break;
            case 3:
                sort(records.begin(), records.end(), compareByName);
                // sorting will be done if compareByName return false.
                cout << "Records sorted by name." << endl;
                break;
            case 4:
                searchRecord(records);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
