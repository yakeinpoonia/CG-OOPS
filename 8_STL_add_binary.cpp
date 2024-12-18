#include <iostream>
#include<bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;

// Function to add two binary numbers represented as strings
string addBinary(string &a, string &b) {
    stack<char> stackA, stackB;
    
    // Push each character of the binary strings onto their respective stacks
    for (char bit : a) {
        stackA.push(bit);
    }
    for (char bit : b) {
        stackB.push(bit);
    }

    string result;
    int carry = 0;

    // Process both stacks until they are empty and no carry remains
    while (!stackA.empty() || !stackB.empty() || carry) {
        int sum = carry;

        // Add the top of stackA if it exists
        if (!stackA.empty()) {
            sum += stackA.top() - '0'; // Convert char to int
            stackA.pop();
        }

        // Add the top of stackB if it exists
        if (!stackB.empty()) {
            sum += stackB.top() - '0'; // Convert char to int
            stackB.pop();
        }

        // Determine the resulting bit and the new carry
        result.push_back((sum % 2) + '0'); // Append the result bit to result string
        carry = sum / 2; // Update carry for next iteration
    }

    // The result is currently in reverse order, so we need to reverse it
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    string binary1, binary2;

    // Input two binary numbers from the user
    cout << "Enter first binary number: ";
    cin >> binary1;
    cout << "Enter second binary number: ";
    cin >> binary2;

    // Add the two binary numbers and display the result
    string sum = addBinary(binary1, binary2);
    cout << "Sum: " << sum << endl;

    return 0;
}
