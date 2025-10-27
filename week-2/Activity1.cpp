#include <iostream>
using namespace std;
int main(){
 cout << "Please enter a number: ";
 int n;
 cin >> n;

if (n % 5 == 0){
cout << "HiFive" << endl;
}

 if (n % 2 == 0) {
 cout << "HiEven" << endl;
}

else if(n % 2 != 0  || n % 5 != 0) {
 cout << "Innate" << endl;
}
}