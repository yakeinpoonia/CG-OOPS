#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Define the name of the file
    string filename = "output.txt";

    // Create and open an output file
    ofstream outFile(filename);
    
    // Check if the file opened successfully
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1; // Exit with error code
    }

    // Write information to the file
    outFile << "Hello, World!" << endl;
    outFile << "This is a test file." << endl;
    outFile << "C++ file handling is simple." << endl;

    // Close the output file
    outFile.close();

    // Open the file again as an input file
    ifstream inFile(filename);
    
    // Check if the file opened successfully
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1; // Exit with error code
    }

    // Read and display information from the file
    string line;
    cout << "Contents of the file:" << endl;
    
    while (getline(inFile, line)) {
        cout << line << endl; // Output each line read from the file
    }

    // Close the input file
    inFile.close();

    return 0; // Successful execution
}
