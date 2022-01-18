#include <iostream>
using namespace std;

int arr[9] = {};

int main() {
    int max, index;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        if (i == 0) {
            max = arr[i];
            index = 0;
        }
        if (max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }

    cout << max << '\n' << index+1;
}