#include <iostream>
#include <string>
#include "InMemoryDB.h"

using namespace std;

int main() {
    InMemoryDB inmemoryDB;

    char choice;
    cout << "Welcome to your database manager!\n";

    do {
        cout << "1. Get value\n";
        cout << "2. Begin transaction\n";
        cout << "3. Put value\n";
        cout << "4. Commit transaction\n";
        cout << "5. Rollback transaction\n";
        cout << "6. Exit\n";
        cout << "\nEnter your choice: ";

        cin >> choice;

        switch (choice) {
            case '1': {
                string key;
                cout << "Enter key: ";
                cin >> key;
                cout << "Value: " << inmemoryDB.get(key) << endl;
                break;
            }
            case '2':
                inmemoryDB.begin_transaction();
                cout << "Transaction started.\n";
                break;
            case '3': {
                string key;
                int value;
                cout << "Enter key and value: ";
                cin >> key >> value;
                inmemoryDB.put(key, value);
                cout << "Value set.\n";
                break;
            }
            case '4':
                inmemoryDB.commit();
                cout << "Transaction committed.\n";
                break;
            case '5':
                inmemoryDB.rollback();
                cout << "Transaction rolled back.\n";
                break;
            case '6':
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '6');

    return 0;
}
