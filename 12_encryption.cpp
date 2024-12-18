#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt the content of the file
void encryptFile(string &inputFile, string &outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    if (!inFile) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        // Encrypt character by shifting
        char encryptedChar = ch + shift;
        outFile.put(encryptedChar);
    }

    inFile.close();
    outFile.close();
    cout << "File encrypted successfully!" << endl;
}

// Function to decrypt the content of the file
void decryptFile(const string &inputFile, const string &outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    if (!inFile) {
        cerr << "Error opening input file!" << endl;
        return;
    }
    if (!outFile) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        // Decrypt character by shifting back
        char decryptedChar = ch - shift;
        outFile.put(decryptedChar);
    }

    inFile.close();
    outFile.close();
    cout << "File decrypted successfully!" << endl;
}

int main() {
    int choice, shift;
    string inputFile, outputFile;

    do {
        cout << "\n--- File Encryption & Decryption Menu ---" << endl;
        cout << "1. Encrypt a file" << endl;
        cout << "2. Decrypt a file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter input file name for encryption: ";
                cin >> inputFile;
                cout << "Enter output file name for encrypted content: ";
                cin >> outputFile;
                cout << "Enter shift value (1-25): ";
                cin >> shift;

                // Validate shift value
                if (shift < 1 || shift > 25) {
                    cout << "Invalid shift value! Please enter a value between 1 and 25." << endl;
                    break;
                }
                
                encryptFile(inputFile, outputFile, shift);
                break;

            case 2:
                cout << "Enter input file name for decryption: ";
                cin >> inputFile;
                cout << "Enter output file name for decrypted content: ";
                cin >> outputFile;
                cout << "Enter shift value (1-25): ";
                cin >> shift;

                // Validate shift value
                if (shift < 1 || shift > 25) {
                    cout << "Invalid shift value! Please enter a value between 1 and 25." << endl;
                    break;
                }
                
                decryptFile(inputFile, outputFile, shift);
                break;

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 3);

    return 0;
}
