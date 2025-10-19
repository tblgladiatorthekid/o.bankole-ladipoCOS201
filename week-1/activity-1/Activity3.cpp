#include <iostream>
using namespace std;

double checkout() {
    double total = 0.0;
    int counter = 0;
    int choice = 1;

    cout << "Welcome, customer!\n";

    while (choice == 1) {
        double item;
        cout << "Enter the price of your item: ";
        cin >> item;
        total += item;
        counter++;

        cout << "Do you want to enter another item? (yes = 1 / no = 0): ";
        cin >> choice;
    }

    cout << "\nYou entered " << counter << " item(s)." << endl;
    return total;
}

int main() {
    double total = checkout();
    double sales_Tax = total * 0.06;

    cout << "\nYour total is ==> " << total;
    cout << "\nYour sales tax will be ==> " << sales_Tax;
    cout << "\nYou will be paying ==> " << sales_Tax + total << endl;

    return 0;
}
