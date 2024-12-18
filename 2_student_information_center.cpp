#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:
    // Default constructor
    Student() {
        name = "";
        rollNumber = 0;
        studentClass = "";
        division = ' ';
        dateOfBirth = "";
        bloodGroup = "";
        contactAddress = "";
        telephoneNumber = "";
        drivingLicenseNo = "";
    }

    // Parameterized constructor
    Student(string n, int r, string c, char d, string dob, string bg, string addr, string phone, string license) {
        name = n;
        rollNumber = r;
        studentClass = c;
        division = d;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = addr;
        telephoneNumber = phone;
        drivingLicenseNo = license;
    }

    // Copy constructor
    Student(const Student &obj) {
        name = obj.name;
        rollNumber = obj.rollNumber;
        studentClass = obj.studentClass;
        division = obj.division;
        dateOfBirth = obj.dateOfBirth;
        bloodGroup = obj.bloodGroup;
        contactAddress = obj.contactAddress;
        telephoneNumber = obj.telephoneNumber;
        drivingLicenseNo = obj.drivingLicenseNo;
    }

    // Destructor
    ~Student() {
        // You can add cleanup code here if needed
    }

    // Function to input student details
    void inputDetails() {
        cout << "Enter Name: ";
        getline(cin >> ws, name);
        
        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Class: ";
        cin >> studentClass;

        cout << "Enter Division: ";
        cin >> division;

        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin >> dateOfBirth;

        cout << "Enter Blood Group: ";
        cin >> bloodGroup;

        cout << "Enter Contact Address: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, contactAddress);

        cout << "Enter Telephone Number: ";
        cin >> telephoneNumber;

        cout << "Enter Driving License No: ";
        cin >> drivingLicenseNo;

        cout << "Details Entered Successfully!" << endl;
    }

    // Function to display student details
    void displayDetails() const {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
    }
};

int main() {
    int numStudents;

    cout << "Enter number of students: ";
    cin >> numStudents;

    // Dynamic memory allocation for an array of Student objects
    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEntering details for Student #" << (i + 1) << ":" << endl;
        
        students[i].inputDetails();
    }

    // Displaying all students' details
    for (int i = 0; i < numStudents; i++) {
         cout << "\nDisplaying details for Student #" << (i + 1) << ":" << endl; 
         students[i].displayDetails();
     }

     // Freeing dynamically allocated memory
     delete[] students;

     return 0; 
}
