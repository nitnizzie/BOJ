#include <iostream>
using namespace std;

int n, m, r, c, d;
int cleaned = 0;
int room[50][50] = {0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_uncleaned(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int row = r + dx[i];
        int col = c + dy[i];
        // if ((row < 0) || (row >= n) || (col < 0) || (col >= n)) continue;

        if (room[row][col] == 0) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    
    bool status = true; 
    while (status) {
        if (room[r][c] == 0) {
            room[r][c] = 2; //cleaned;
            cleaned++;
        }
        if (!is_uncleaned(r, c)) {
            int back = (d+2) % 4;
            int row_back = r + dx[back];
            int col_back = c + dy[back];
            if (room[row_back][col_back] != 1) {
                r = row_back;
                c = col_back;
            }
            else status = false;
        }
        else {
            d = (d+3) % 4;
            int row = r + dx[d];
            int col = c + dy[d];
            if (room[row][col] == 0) {
                r = row;
                c = col;
            }
        }
    }

    cout << cleaned;
}