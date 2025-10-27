#include <iostream>
using namespace std;
int main() {
    string name;
cout << "Hello student. Please enter your name : "<< endl;
    cin >> name;
    cout << "Hello " << name << endl;
    int age;
    cout << "Please enter your age " << endl;
    cin >> age;
    if (age >= 18) {
        cout << "You are an adult " << name << endl;
    }
    else {
        cout << name << " you are " << age << " years old. You are NOT an adult." << endl;
    }
    return 0;
}