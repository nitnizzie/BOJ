#include <iostream>
#include <queue>
using namespace std;

int N, M;
int A[51][51] = {0, };
bool prev_cloud[51][51] = {false, };
queue<pair<int, int> > cloud;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int total = 0;

void print_water() {
    cout << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}

void move_cloud(int d, int s) {
    int size = cloud.size();

    for (int i = 0; i < size; i++) {
        int row = (cloud.front().first + dx[d] * s) % N;
        int col = (cloud.front().second + dy[d] * s) % N;
        if (row <= 0) row += N;
        if (col <= 0) col += N;
        cloud.pop();

        cloud.push(make_pair(row, col));
        prev_cloud[row][col] = true;

        A[row][col]++;
    }
}

void copybug_magic() {
    int size = cloud.size();

    for (int i = 0; i < size; i++) {
        int r = cloud.front().first;
        int c = cloud.front().second;
        cloud.pop();
        int cnt = 0;
        for (int j = 1; j < 8; j+=2) {
            int row = r + dx[j];
            int col = c + dy[j];
            if ((row < 1) || (row > N) || (col < 1) || (col > N))
                continue;
            if (A[row][col] > 0) cnt++;
        }
        A[r][c] += cnt;
    }
}

void make_cloud() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if ((A[i][j] >= 2) && !prev_cloud[i][j]) {
                A[i][j] -= 2;
                cloud.push(make_pair(i, j));
            }
        }
    }

    //reset prev status
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prev_cloud[i][j] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    //initial state
    cloud.push(make_pair(N, 1));
    cloud.push(make_pair(N, 2));
    cloud.push(make_pair(N-1, 1));
    cloud.push(make_pair(N-1, 2));

    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;
        move_cloud(d-1, s);
        // print_water();
        copybug_magic();
        // print_water();
        make_cloud();
        // print_water();
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            total += A[i][j];
        }
    }

    cout << total;
}