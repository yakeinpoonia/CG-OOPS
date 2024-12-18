#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    // Default constructor (creates the 0 polynomial)
    Quadratic() : a(0), b(0), c(0) {}

    // Parameterized constructor
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    // Overloaded operator+ to add two polynomials
    Quadratic operator+(Quadratic& other) {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    // Friend function to overload operator<< for output
    friend ostream& operator<<(ostream& os, Quadratic& poly) {
        os << poly.a << "x^2 + " << poly.b << "x + " << poly.c;
        return os;
    }

    // Friend function to overload operator>> for input
    friend istream& operator>>(istream& is, Quadratic& poly) {
        cout << "Enter coefficients a, b, c: ";
        is >> poly.a >> poly.b >> poly.c;
        return is;
    }

    // Function to evaluate the polynomial at a given x
    double eval(double x) {
        return a * x * x + b * x + c;
    }

    // Function to compute the roots of the equation ax^2 + bx + c = 0
    void findRoots() {
        double discriminant = b * b - 4 * a * c;

        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                    std::cout << "Infinite solutions (all x are solutions).\n";
                } else {
                    std::cout << "No solution.\n";
                }
            } else {
                std::cout << "Linear equation. Solution: x = " << -c / b << "\n";
            }
            return;
        }

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Two distinct real roots: x1 = " << root1 << ", x2 = " << root2 << "\n";
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "One real root: x = " << root << "\n";
        } else {
            cout << "No real roots. Complex roots exist.\n";
        }
    }
};

int main() {
    Quadratic poly1, poly2;

    // Input first polynomial
    std::cin >> poly1;
    
    // Input second polynomial
    std::cin >> poly2;

    // Display polynomials
    std::cout << "Polynomial 1: " << poly1 << "\n";
    std::cout << "Polynomial 2: " << poly2 << "\n";

    // Add polynomials and display result
    Quadratic sum = poly1 + poly2;
    std::cout << "Sum of polynomials: " << sum << "\n";

    // Evaluate the first polynomial at x = 1
    double x = 1.0;
    std::cout << "Value of Polynomial 1 at x = " << x << ": " << poly1.eval(x) << "\n";

    // Find roots of the first polynomial
    std::cout << "Finding roots for Polynomial 1:\n";
    poly1.findRoots();

    return 0;
}
