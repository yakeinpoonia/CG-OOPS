#include <iostream>

using namespace std;

class Complex {
private:
    float real; // Real part
    float imag; // Imaginary part

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(float r, float i) : real(r), imag(i) {}

    // Overloaded operator+ to add two complex numbers
    Complex operator+(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded operator* to multiply two complex numbers
    Complex operator*(Complex& other) {
        return Complex(real * other.real - imag * other.imag, 
                       real * other.imag + imag * other.real);
    }

    // Overloaded operator<< to output complex numbers
    friend ostream& operator<<(ostream& cout, Complex& c) {
        if (c.imag < 0)
            cout << c.real << c.imag << "i"; // For negative imaginary part
        else
            cout << c.real << "+" << c.imag << "i"; // For positive imaginary part
        return cout;
    }

    // Overloaded operator>> to input complex numbers
    friend istream& operator>>(istream& cin, Complex& c) {
        cout << "Enter real part: ";
        cin >> c.real;
        cout << "Enter imaginary part: ";
        cin >> c.imag;
        return cin;
    }
};

int main() {
    Complex c1, c2;

    cout << "Input first complex number:\n";
    cin >> c1;

    cout << "Input second complex number:\n";
    cin >> c2;

    // Adding two complex numbers
    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    // Multiplying two complex numbers
    Complex product = c1 * c2;
    cout << "Product: " << product << endl;

    return 0;
}