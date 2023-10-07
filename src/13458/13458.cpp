#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int B, C;
    cin >> B >> C;

    long long int total = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > B) {
            arr[i] -= B;
            total += (arr[i]/C);
            arr[i] %= C;
            if (arr[i])
                total++;
        }
        total++;
    }

    cout << total << '\n';

}