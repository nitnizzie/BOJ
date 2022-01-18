#include <iostream>
using namespace std;

int C, N;
int arr[1000] = {};

int main() {
    float avg = 0.0;
    int num = 0;
    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
            avg += arr[j];
        }
        avg = avg / N;

        for (int j = 0; j < N; j++) {
            if (arr[j] > avg) num ++;
        }
        
        printf("%0.3f%%\n", num * 100.0 / N);
        avg = 0.0;
        num = 0;
    }
}