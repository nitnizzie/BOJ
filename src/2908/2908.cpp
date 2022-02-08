#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    int new1, new2;
    cin >> num1 >> num2;

    new1 = 100*(num1%10) + 10*(num1%100 /10) + num1/100;
    new2 = 100*(num2%10) + 10*(num2%100 /10) + num2/100;

    if (new1 > new2) cout << new1;
    else cout << new2;
}