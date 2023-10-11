#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N;
int score[5] = {0, 1, 10, 100, 1000};
int ans = 0;
unordered_map <int, vector<int> > map;
int classroom[21][21] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void assign_seat(int student_num, vector<int> likes) {
    int max_cnt = -1, max_cnt_empty = -1;
    int max_i, max_j;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (classroom[i][j] != 0) continue;
            int cnt = 0, cnt_empty = 0;
            for (int d = 0; d < 4; d++) {
                int row = i + dx[d];
                int col = j + dy[d];
                if ((row <= 0) || (row > N) || (col <= 0) || (col > N)) continue;
                if (classroom[row][col] == 0) cnt_empty++;
                else {
                    for (int k = 0; k < likes.size(); k++) {
                        if (classroom[row][col] == likes[k]) cnt++;
                    }
                }
            }

            if (cnt > max_cnt) {
                max_cnt = cnt;
                max_cnt_empty = cnt_empty;
                max_i = i;
                max_j = j;
            }
            else if (cnt == max_cnt) {
                if (cnt_empty > max_cnt_empty) {
                    max_cnt_empty = cnt_empty;
                    max_i = i;
                    max_j = j;
                }
                else if (cnt_empty == max_cnt_empty) {
                    if (i < max_i) {
                        max_i = i;
                        max_j = j;
                    }
                    else if (i == max_i) {
                        if (j < max_j)
                            max_j = j;
                    }
                }
            }
        }
    }

    classroom[max_i][max_j] = student_num;
}

void compute_score() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int student_num = classroom[i][j];
            vector<int> likes = map[student_num];
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int row = i + dx[d];
                int col = j + dy[d];
                if ((row <= 0) || (row > N) || (col <= 0) || (col > N)) continue;
                for (int k = 0; k < likes.size(); k++) {
                    if (likes[k] == classroom[row][col]) cnt++;
                }
            }
            ans += score[cnt];
        }
    }
}

void print_classroom() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << classroom[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N*N; i++) {
        int student_num;
        vector<int> likes(4, 0);
        cin >> student_num;
        for (int j = 0; j < 4; j++) {
            cin >> likes[j];
        }
        map[student_num] = likes;
        assign_seat(student_num, likes);
        // print_classroom();
    }

    // print_classroom();
    compute_score();

    cout << ans;
}