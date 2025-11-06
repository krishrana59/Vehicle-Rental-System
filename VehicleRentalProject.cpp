#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string name;
    int id;
    float rent;
    bool available;

    void input() {
        cout << "Enter Vehicle ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Vehicle Name: "; getline(cin, name);
        cout << "Enter Rent per Day: "; cin >> rent;
        available = true;
    }

    void display() {
        cout << "ID: " << id << " | Name: " << name << " | Rent: Rs." << rent;
        cout << (available ? " | Available\n" : " | Rented\n");
    }
};

int main() {
    Vehicle v[10];
    int count = 0, choice, id;

    while (true) {
        cout << "\n===== Vehicle Rental System =====\n";
        cout << "1. Add Vehicle\n2. Display Vehicles\n3. Rent Vehicle\n4. Return Vehicle\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "How many vehicles to add? ";
            int n; cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++) {
                v[count].input();
                count++;
            }
            cout << "Vehicle(s) added successfully!\n";
        }
        else if (choice == 2) {
            cout << "\nList of Vehicles:\n";
            for (int i = 0; i < count; i++) v[i].display();
        }
        else if (choice == 3) {
            cout << "Enter Vehicle ID to rent: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (v[i].id == id && v[i].available) {
                    v[i].available = false;
                    found = true;
                    cout << "Vehicle rented successfully!\n";
                    break;
                }
            }
            if (!found) cout << "Vehicle not available or invalid ID!\n";
        }
        else if (choice == 4) {
            cout << "Enter Vehicle ID to return: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (v[i].id == id && !v[i].available) {
                    v[i].available = true;
                    found = true;
                    cout << "Vehicle returned successfully!\n";
                    break;
                }
            }
            if (!found) cout << "Invalid ID or vehicle not rented!\n";
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}


