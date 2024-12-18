#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for Item
struct Item {
    int code;
    string name;
    double cost;
    int quantity;

    // Constructor for easy initialization
    Item(int c, const string& n, double co, int q) 
        : code(c), name(n), cost(co), quantity(q) {}
};

// Function to display all items
void displayItems(const vector<Item>& items) {
    cout << "Item Code\tName\t\tCost\tQuantity\n";
    cout << "---------------------------------------------\n";
    for (const auto& item : items) {
        cout << item.code << "\t\t" << item.name << "\t\t" 
             << item.cost << "\t" << item.quantity << endl;
    }
}

// Comparator function to sort items by code
bool compareByCode(const Item& a, const Item& b) {
    return a.code < b.code;
}

// Function to search for an item by code
int searchItemByCode(const vector<Item>& items, int code) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].code == code) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    vector<Item> items;
    
    int numItems;
    cout << "Enter the number of items you want to add: ";
    cin >> numItems;

    // Input items from user
    for (int i = 0; i < numItems; ++i) {
        int code;
        string name;
        double cost;
        int quantity;

        cout << "\nEnter details for item " << (i + 1) << ":\n";
        
        cout << "Item Code: ";
        cin >> code;

        cout << "Item Name: ";
        cin.ignore(); // Clear newline character from input buffer
        getline(cin, name);

        cout << "Item Cost: ";
        cin >> cost;

        cout << "Item Quantity: ";
        cin >> quantity;

        // Add the new item to the vector
        items.push_back(Item(code, name, cost, quantity));
    }

    // Display initial list of items
    cout << "\nInitial list of items:\n";
    displayItems(items);

    // Sort items by code
    sort(items.begin(), items.end(), compareByCode);
    
    cout << "\nSorted list of items by code:\n";
    displayItems(items);

    // Search for an item by code
    int searchCode;
    cout << "\nEnter item code to search: ";
    cin >> searchCode;

    int index = searchItemByCode(items, searchCode);
    
    if (index != -1) {
        cout << "Item found:\n";
        cout << "Item Code: " << items[index].code 
             << ", Name: " << items[index].name 
             << ", Cost: " << items[index].cost 
             << ", Quantity: " << items[index].quantity << endl;
    } else {
        cout << "Item with code " << searchCode << " not found.\n";
    }

    return 0;
}
