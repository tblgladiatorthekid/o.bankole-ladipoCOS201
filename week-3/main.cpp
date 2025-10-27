#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Camp {
    int id;
    string course;
    int days;
    float price;
};

struct Lodge {
    int id;
    string house;
    float price;
};

Camp SelectCourse() {
    vector<Camp> courseChoice = {
        {1, "Photography", 3, 10000.0},
        {2, "Painting", 5, 8000.0},
        {3, "Fish Farming", 7, 15000.0},
        {4, "Baking", 5, 13000.0},
        {5, "Public Speaking", 2, 5000.0}
    };

    cout << "\nAvailable Courses:\n";
    for (auto c : courseChoice) {
        cout << c.id << " - " << c.course
             << " (" << c.days << " days, $" << c.price << ")\n";
    }

    int course;
    cout << "\nEnter Course ID: ";
    cin >> course;

    if (course >= 1 && course <= 5) {
        Camp selected = courseChoice[course - 1];
        cout << "\nYou selected: " << selected.course
             << "\nDuration: " << selected.days << " days"
             << "\nPrice: $" << selected.price << endl;
        return selected;
    } else {
        cout << "\nInvalid selection. Defaulting to Course 1.\n";
        return courseChoice[0];
    }
}

Lodge SelectLodge() {
    vector<Lodge> lodgeChoice = {
        {1, "Camp House A", 10000.0},
        {2, "Camp House B", 2500.0},
        {3, "Camp House C", 5000.0},
        {4, "Camp House D", 13000.0},
        {5, "Camp House E", 5000.0}
    };

    cout << "\nAvailable Lodges:\n";
    for (auto l : lodgeChoice) {
        cout << l.id << " - " << l.house
             << " ($" << l.price << " per day)\n";
    }

    int lodge;
    cout << "\nEnter Lodge ID: ";
    cin >> lodge;

    if (lodge >= 1 && lodge <= 5) {
        Lodge selected = lodgeChoice[lodge - 1];
        cout << "\nYou selected: " << selected.house
             << "\nPrice per day: $" << selected.price << endl;
        return selected;
    } else {
        cout << "\nInvalid selection. Defaulting to Lodge 1.\n";
        return lodgeChoice[0];
    }
}

int calculator () {
    Camp chosenCourse = SelectCourse();
    Lodge chosenLodge = SelectLodge();

    // 🧮 Calculations
    float lodging_price = chosenCourse.days * chosenLodge.price;
    float total = chosenCourse.price + lodging_price;

    cout << "\n--- COST SUMMARY ---\n";
    cout << "Course: " << chosenCourse.course << " - $" << chosenCourse.price << "\n";
    cout << "Lodge: " << chosenLodge.house << " ($" << chosenLodge.price
         << " x " << chosenCourse.days << " days) = $" << lodging_price << "\n";
    cout << "---------------------------------------------\n";
    cout << "TOTAL = $" << total << "\n";
}

int main() {
    string student_name;
    cout << "Please enter your name: ";
    cin >> student_name;
    cout << "Nice to meet you, " << student_name << "!\n";

    bool isPAUStudent;
    cout << "Are you a student of Pan-Atlantic University? Yes (1) No (0): ";
    cin >> isPAUStudent;

    if (isPAUStudent) {
        cout << "\nWelcome, PAU Student!\n";
        calculator();
    }

    else {
        cout << "\nWelcome, Guest Participant!\n";
        calculator();
    }
    cout << "\nThank you, " << student_name << "! Your selections have been recorded.\n";

    return 0;
}
