#include <iostream>
using namespace std;

bool check_hansu(int num) {
    if (num < 100) return true;

    int n1 = num / 100;
    int n2 = num % 100 / 10;
    int n3 = num % 10;

    int diff1 = n1 - n2;
    int diff2 = n2 - n3;

    if (diff1 == diff2) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (check_hansu(i)) count++;
    }

    cout << count << '\n';
}