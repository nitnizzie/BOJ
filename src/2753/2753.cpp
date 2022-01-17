#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;

    if ( !(year % 4) ) {
        if (year % 100 or !(year % 400) ) cout << "1\n";
        else cout << "0\n";
    }
    else cout << "0\n";
}