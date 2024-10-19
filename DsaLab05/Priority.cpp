#include "Priority.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "Select an option:\n";
    cout << "1. Enter Admin values\n";
    cout << "2. Enter Faculty values\n";
    cout << "3. Enter Student values\n";
    cout << "4. Display Combined Priority Queue\n";
    cout << "5. Exit\n";
}

void displayCombinedQueue(Priority combined) {
    cout << "Combined Priority Queue: ";
    for (int i = 0; i < combined.size(); i++) {
        cout << combined.getValue(i);
        if (i < combined.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    Priority Admin(10), Faculty(10), Student(10);
    char choice;
    Priority Combined(30);

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation
        while (choice < '1' || choice > '5') {
            cout << "Invalid choice. Please select 1-5: ";
            cin >> choice;
        }

        if (choice == '5') {
            cout << "Exiting the program..." << endl; 
            exit(0);
        }

        int size;
        if (choice == '1') {
            cout << "Enter number of Admin values: ";
            cin >> size;
            Admin.clear();
            cout << "Enter Admin values:\n";
            for (int i = 0; i < size; ++i) {
                int value;
                cout << "Value " << (i + 1) << ": ";
                cin >> value;
                Admin.insert(value);
            }
        }
        else if (choice == '2') {
            cout << "Enter number of Faculty values: ";
            cin >> size;
            Faculty.clear();
            cout << "Enter Faculty values:\n";
            for (int i = 0; i < size; ++i) {
                int value;
                cout << "Value " << (i + 1) << ": ";
                cin >> value;
                Faculty.insert(value);
            }
        }
        else if (choice == '3') {
            cout << "Enter number of Student values: ";
            cin >> size;
            Student.clear();
            cout << "Enter Student values:\n";
            for (int i = 0; i < size; ++i) {
                int value;
                cout << "Value " << (i + 1) << ": ";
                cin >> value;
                Student.insert(value);
            }
        }
        else if (choice == '4') {
            Combined.clear();
            Combined.merge(Admin);
            Combined.merge(Faculty);
            Combined.merge(Student);
            displayCombinedQueue(Combined);
        }

    } while (true); 

    return 0;
}
