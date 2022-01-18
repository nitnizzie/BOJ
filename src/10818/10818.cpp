#include <iostream>
using namespace std;

int main() {
    int N, M;
    int min = 1000000;
    int max = -1000000;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        if (min > M) min = M;
        if (max < M) max = M;
    }
    cout << min << " " << max << "\n";
}