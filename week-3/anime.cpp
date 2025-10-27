#include <iostream>
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time
#include <iomanip>
using namespace std;

int main() {
    string name, courseName, lodgeName;
    bool isPAU;
    int courseChoice, lodgeChoice;
    int days = 0;
    float regFee = 0, lodgingPerDay = 0, lodgingCost = 0, total = 0;
    float regDiscount = 0, lodgeDiscount = 0, promo = 0;

    // Seed for random number
    srand(time(0));
    int r = rand() % 100 + 1; // random number between 1 and 100

    // --- INPUTS ---
    cout << "Enter full name: ";
    getline(cin, name);

    cout << "Is PAU student? (1=true, 0=false): ";
    cin >> isPAU;

    cout << "Enter course (1-5): ";
    cin >> courseChoice;

    cout << "Enter location (1-5): ";
    cin >> lodgeChoice;

    // --- MAP COURSE CHOICE ---
    if (courseChoice == 1) { courseName = "Photography"; days = 3; regFee = 10000; }
    else if (courseChoice == 2) { courseName = "Painting"; days = 5; regFee = 8000; }
    else if (courseChoice == 3) { courseName = "Fish Farming"; days = 7; regFee = 15000; }
    else if (courseChoice == 4) { courseName = "Baking"; days = 5; regFee = 13000; }
    else if (courseChoice == 5) { courseName = "Public Speaking"; days = 2; regFee = 5000; }
    else { cout << "Invalid course number!\n"; return 0; }

    // --- MAP LODGE CHOICE ---
    if (lodgeChoice == 1) { lodgeName = "Camp House A"; lodgingPerDay = 10000; }
    else if (lodgeChoice == 2) { lodgeName = "Camp House B"; lodgingPerDay = 2500; }
    else if (lodgeChoice == 3) { lodgeName = "Camp House C"; lodgingPerDay = 5000; }
    else if (lodgeChoice == 4) { lodgeName = "Camp House D"; lodgingPerDay = 13000; }
    else if (lodgeChoice == 5) { lodgeName = "Camp House E"; lodgingPerDay = 5000; }
    else { cout << "Invalid lodge number!\n"; return 0; }

    // --- COMPUTE BASE COSTS ---
    lodgingCost = lodgingPerDay * days;
    total = regFee + lodgingCost;

    // --- DISCOUNTS (logical operators) ---
    // Lodging discount: 5% if PAU student and Camp House A or B
    if (isPAU && (lodgeChoice == 1 || lodgeChoice == 2)) {
        lodgeDiscount = 0.05 * lodgingCost;
        lodgingCost -= lodgeDiscount;
    }

    // Registration discount: 3% if days > 5 OR regFee > 12000
    if ((days > 5) || (regFee > 12000)) {
        regDiscount = 0.03 * regFee;
        regFee -= regDiscount;
    }

    // Random promo: ₦500 if r == 7 or r == 77
    if (r == 7 || r == 77) {
        promo = 500;
    }

    // --- FINAL TOTAL ---
    total = regFee + lodgingCost - promo;

    // --- OUTPUT ---
    cout << fixed << setprecision(2);
    cout << "\n--- COST SUMMARY ---\n";
    cout << "Name: " << name << "   (PAU student: " << (isPAU ? "Yes" : "No") << ")\n";
    cout << "Course: " << courseName << "   Days: " << days << "\n";
    cout << "Registration: ₦" << regFee
         << "  (reg discount: ₦" << regDiscount << ")\n";
    cout << "Lodging: ₦" << lodgingPerDay << " × " << days
         << " = ₦" << lodgingPerDay * days
         << "  (lodging discount: ₦" << lodgeDiscount << ")\n";
    cout << "Random draw: " << r << "  Promo applied: ₦" << promo << "\n";
    cout << "--------------------------------------\n";
    cout << "TOTAL: ₦" << total << "\n";
}
