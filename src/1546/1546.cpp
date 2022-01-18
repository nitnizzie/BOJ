#include <iostream>
using namespace std;

int SCORE[1000] = {};

int main() {
    int N, M, score;
    int sum = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> score;
        if (i == 0) M = score;
        if (M < score) M = score;
        SCORE[i] = score;
        sum += score;
    }

    //test
    // cout << sum << M << '\n';

    printf("%f\n", sum * 100.0 / M / N);
}