#include <iostream>
using namespace std;

int N;
int ability[20][20];
bool is_team1[20] = {};
int min_diff = 1000000000;

void solve(int cnt, int idx) {
    if (cnt == N/2) {
        int team1 = 0, team2 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (is_team1[i] && is_team1[j])     team1 += ability[i][j];
                if (!is_team1[i] && !is_team1[j])   team2 += ability[i][j];
            }
        }

        int temp = abs(team1 - team2);
        if (temp < min_diff) min_diff = temp;
        return;
    }

    for (int i = idx; i < N; i++) {
        if (is_team1[i])
            continue;
        is_team1[i]= true;
        solve(cnt+1, i);
        is_team1[i] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ability[i][j];
        }
    }

    solve(0, 0); 

    cout << min_diff;
}