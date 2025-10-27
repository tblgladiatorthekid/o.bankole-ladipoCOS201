#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    int number_1;
    int number_2;
    srand(time(0));
    number_1 = rand() % 10;
    number_2 = rand() % 10;
    if (number_1 < number_2) {
        int temp = number_1;
        number_1 = number_2;
        number_2 = temp;
    }
    int c_difference = number_1 - number_2;
    int user_choice;
    int count = 1;
    while (count >= 1) {
        cout << "What is the answer to number_1 - number_2?" << endl;
        cin >> user_choice;
        if (user_choice == c_difference) {
            cout << "Your choice is " << user_choice << " You are correct"
            << "\n Your answer is ==> " << c_difference << endl;
        }
        else {
            cout << "Your choice is " << user_choice << " You are wrong"
            << "\n Your answer is ==> " << c_difference << endl;
        }
        count++;
        cout<< "Do you want to continue? Yes == 1, No == 0" << endl;
        int choose;
        cin >> choose;
        if (choose == 0) {
            break;
        }
    }

}