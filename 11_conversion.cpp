#include <iostream>

// Base class
class Convert {
protected:
    double val1; // Initial value
    double val2; // Converted value

public:
    // Constructor
    Convert(double initialValue) : val1(initialValue), val2(0) {}

    // Function to get the initial value
    double getinit() const {
        return val1;
    }

    // Function to get the converted value
    double getconv() const {
        return val2;
    }

    // Pure virtual function for conversion
    virtual void compute() = 0; // This makes Convert an abstract class
};

// Derived class for Celsius to Fahrenheit conversion
class CelsiusToFahrenheit : public Convert {
public:
    // Constructor
    CelsiusToFahrenheit(double celsius) : Convert(celsius) {}

    // Implementing the compute function
    void compute() override {
        val2 = (val1 * 9.0 / 5.0) + 32.0; // Conversion formula
    }
};

// Derived class for Fahrenheit to Celsius conversion
class FahrenheitToCelsius : public Convert {
public:
    // Constructor
    FahrenheitToCelsius(double fahrenheit) : Convert(fahrenheit) {}

    // Implementing the compute function
    void compute() override {
        val2 = (val1 - 32.0) * 5.0 / 9.0; // Conversion formula
    }
};

int main() {
    // Example usage of Celsius to Fahrenheit conversion
    double celsiusValue;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsiusValue;

    CelsiusToFahrenheit cToF(celsiusValue);
    cToF.compute(); // Perform conversion

    std::cout << celsiusValue << " Celsius is equal to " << cToF.getconv() << " Fahrenheit." << std::endl;

    // Example usage of Fahrenheit to Celsius conversion
    double fahrenheitValue;
    std::cout << "Enter temperature in Fahrenheit: ";
    std::cin >> fahrenheitValue;

    FahrenheitToCelsius fToC(fahrenheitValue);
    fToC.compute(); // Perform conversion

    std::cout << fahrenheitValue << " Fahrenheit is equal to " << fToC.getconv() << " Celsius." << std::endl;

    return 0;
}
