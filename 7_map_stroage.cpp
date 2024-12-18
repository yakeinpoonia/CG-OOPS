#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map to store state names and their corresponding COVID-19 patient counts
    map<string, int> covidData;

    // Variable to control the loop for input
    char choice;

    // Input loop for adding states and their COVID-19 patient counts
    do {
        string stateName;
        int patientCount;

        // Prompt user for state name
        cout << "Enter the name of the state: ";
        getline(cin, stateName);

        // Prompt user for patient count
        cout << "Enter the COVID-19 patient count for " << stateName << ": ";
        cin >> patientCount;
        cin.ignore();  // Clear the newline character from the input buffer

        // Store the data in the map
        covidData[stateName] = patientCount;

        // Ask if the user wants to add another entry
        cout << "Do you want to add another state? (y/n): ";
        cin >> choice;
        cin.ignore();  // Clear the newline character from the input buffer

    } while (choice == 'y' || choice == 'Y');

    // Query loop for looking up states
    do {
        string queryState;
        
        // Prompt user to enter a state name to query
        cout << "Enter the name of a state to get its COVID-19 patient count: ";
        getline(cin, queryState);

        // Manual search through the map
        bool found = false;
        for ( auto entry : covidData) {
            if (entry.first == queryState) {
                cout << "COVID-19 Patient Count in " << queryState << ": " << entry.second << endl;
                found = true;
                break;  // Exit loop if found
            }
        }

        if (!found) {
            cout << "State not found in the database." << endl;
        }

        // Ask if the user wants to look up another state
        cout << "Do you want to look up another state? (y/n): ";
        cin >> choice;
        cin.ignore();  // Clear the newline character from the input buffer

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
