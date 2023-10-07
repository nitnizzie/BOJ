#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N+1, 0);
    int T, P;
    int max_money = 0;
    for (int i = 0; i <= N; i++) {
        if (i != N)
            cin >> T >> P;
        dp[i] = max(max_money, dp[i]);
        if(T + i <= N)
            dp[T + i] = max(dp[T + i], P + dp[i]);
        max_money = max(max_money, dp[i]);
    }

    cout << max_money;
}