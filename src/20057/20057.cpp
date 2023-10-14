#include <iostream>
using namespace std;

int N;
int map[499][499] = {0, };
int amount_out = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int d = 0;

int sx[4][10] = {
    {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, -1, -1, 2, 1},
    {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
    {0, 0, 0, 0, -1, -1, 1, 1, -2, -1}
};
int sy[4][10] = {
    {0, 0, 0, 0, -1, -1, 1, 1, -2, -1},
    {-1, 1, -2, 2, 1, -1, -1, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, -1, -1, 2, 1},
    {1, -1, -2, 2, -1, 1, -1, 1, 0, 0}
};
int ratio_s[9] = {7, 7, 2, 2, 10, 10, 1, 1, 5};

void print_map() {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

void move_sand(int x1, int y1, int d) {
    int amount = map[x1][y1];
    if (amount == 0) return;

    map[x1][y1] = 0;
    int remaining = amount;
    for (int i = 0; i < 10; i++) {
        int x = x1 + sx[d][i];
        int y = y1 + sy[d][i];
        if (i != 9) {
            remaining -= amount * ratio_s[i] / 100;
        if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) continue;
            map[x][y] += amount * ratio_s[i] / 100;
        }
        else {
        if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) continue;
            map[x][y] += remaining;
        }
    }
}

int main() {
    int total_amount = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            total_amount += map[i][j];
        }
    }

    int x = N/2, y = N/2;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < i; k++) {
                x += dx[d];
                y += dy[d];
                move_sand(x, y, d);
    // print_map();
            }
            d = (d == 3) ? 0 : d+1;
        }
    }
    while (y != 0) {
        x += dx[d];
        y += dy[d];
        move_sand(x, y, d);
    // print_map();
    }

    // print_map();
    int remaining = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            remaining += map[i][j];
        }
    }
    amount_out = total_amount - remaining;
    cout << amount_out;
}