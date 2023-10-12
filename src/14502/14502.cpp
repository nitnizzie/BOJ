#include <iostream>
#include <queue>
using namespace std;

int n, m;
// 0: empty, 1: wall, 2: virus
int map_before[8][8] = {0, };
int map_after[8][8] = {0, };
int safe_area = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void print_map() {
    cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map_after[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map_after[i][j] = map_before[i][j];
        }
    }

    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map_after[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }
    
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int row = r + dx[i];
            int col = c + dy[i];
            if ((row < 0) || (row >= n) || (col < 0) || (col >= m))
                continue;
            
            if (map_after[row][col] == 0) {
                map_after[row][col] = 2;
                q.push(make_pair(row, col));
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map_after[i][j] == 0)
                cnt++;
        }
    }

    safe_area = max(safe_area, cnt);
}

void make_wall(int cnt) {
    if (cnt == 3) {
        // print_map();
        bfs();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map_before[i][j] == 0) {
                map_before[i][j] = 1;
                make_wall(cnt+1);
                map_before[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map_before[i][j];
        }
    }

    make_wall(0);

    cout << safe_area;
}