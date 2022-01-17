#include <iostream>
using namespace std;

int main() {
    int N;
    int cycle = 0;
    cin >> N;

    int num = N;
    do {
        if (num < 10) {
            num = 10 * num + num;
        }
        else {
            num = (num % 10) * 10 + (num / 10 + num % 10) % 10;
        }
        cycle += 1;
    } while (num != N);

    cout << cycle << '\n';
}