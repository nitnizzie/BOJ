#include <iostream>
using namespace std;

int main() {
    int A, B, C, N;
    cin >> A >> B >> C;
 
    if (B >= C) {
        cout << -1;
        return 0;
    }

    N = A / (C - B) + 1;
    if (N < 0)
        cout << -1;
    else
        cout << N;
}