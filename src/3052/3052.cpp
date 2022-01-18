#include <iostream>
using namespace std;

int arr[42] = {};

int main() {
    int num;
    int count = 0;

    for (int i = 0; i < 10; i++) {
        cin >> num;
        arr[num % 42]++;
    }

    for (int i = 0; i < 42; i++) {
        if (arr[i] != 0) count++;
    }

    cout << count << '\n';
}