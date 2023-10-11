#include <iostream>
using namespace std;

int K, idx, dir;
int wheel[4][8];
// int score = 0;
bool rotated[4] = {false, };

void rotate(int idx, int dir) {
    rotated[idx] = true;
    if (idx == 0) {
        if ((wheel[idx][2] != wheel[idx+1][6]) && (rotated[idx+1] == false))
            rotate(idx+1, dir * (-1));
    }
    else if (idx == 3) {
        if ((wheel[idx][6] != wheel[idx-1][2]) && (rotated[idx-1] == false))
            rotate(idx-1, dir * (-1));        
    }
    else {
        if ((wheel[idx][2] != wheel[idx+1][6]) && (rotated[idx+1] == false))
            rotate(idx+1, dir * (-1));
        if ((wheel[idx][6] != wheel[idx-1][2]) && (rotated[idx-1] == false))
            rotate(idx-1, dir * (-1));        
    }

    int temp;
    if (dir == 1) {
        temp = wheel[idx][7];
        for (int i = 7; i > 0; i--) {
            wheel[idx][i] = wheel[idx][i-1];
        }
        wheel[idx][0] = temp;
    }
    else {
        temp = wheel[idx][0];
        for (int i = 0; i < 7; i++) {
            wheel[idx][i] = wheel[idx][i+1];
        }
        wheel[idx][7] = temp;
    }
}

int compute_score() {
    int score = 0;
    if (wheel[0][0]) score += 1;
    if (wheel[1][0]) score += 2;
    if (wheel[2][0]) score += 4;
    if (wheel[3][0]) score += 8;

    return score;
}

void print_wheel() {
    cout << '\n';
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cout << wheel[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    char n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> n;
            wheel[i][j] = n - '0';
        }
    }
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        cin >> idx >> dir;
        rotate(idx-1, dir);
        for (int j = 0; j < 4; j++) {
            rotated[j] = false;
        }
        // print_wheel();
    }
    int score = compute_score();

    cout << score;
}