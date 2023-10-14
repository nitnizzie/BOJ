#include <iostream>
using namespace std;

int N, M, R;
int arr[300][300] = {0, };
int temp[300][300] = {0, };

void print_arr() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void print_temp() {
    cout<< '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << temp[i][j] << ' ';
        }
        cout << '\n';
    }
}

void rotate() {
    int cycle = min(N, M)/2;
    int x = 0, y = 0;
    for (int i = 0; i < cycle; i++) {
        while (x != N-1-i) {
            temp[x+1][y] = arr[x][y];
            x++;
        }
        while (y != M-1-i) {
            temp[x][y+1] = arr[x][y];
            y++;
        }
        while (x != i) {
            temp[x-1][y] = arr[x][y];
            x--;
        }
        while (y != i) {
            temp[x][y-1] = arr[x][y];
            y--;
        }
        // print_temp();
        // cout << x << '\t' << y << '\n';
        x++;
        y++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        rotate();
    }

    print_arr();
}