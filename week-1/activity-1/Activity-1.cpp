#include <iostream>
using namespace std;

int main () {
    cout << "Enter your first number ===> ";
    int number_1;
    cin >> number_1;

    cout << "Enter your second number ===> ";
    int number_2;
    cin >> number_2;

    int sum = number_1 + number_2;
    int diff = number_1 - number_2;
    int product = number_1 * number_2;

    cout << "Your sum is ===> " << sum << endl;
    cout << "Your difference is ===> " << diff << endl;
    cout << "Your product is ===> " << product << endl;

    return 0;
}