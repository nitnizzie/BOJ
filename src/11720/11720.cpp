#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    char temp;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        sum += temp - '0';
    }
    cout << sum << '\n';
}