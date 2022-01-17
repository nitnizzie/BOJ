#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            printf(" ");
        }
        for (int k = 0; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}