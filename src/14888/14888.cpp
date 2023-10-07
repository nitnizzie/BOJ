#include <iostream>
#include <vector>
using namespace std;

int N;
int operands[11];
int operators[4];
int my_min = 1000000001;
int my_max = -1000000001;

void getAnswer(int result, int idx) {
    if (idx == N) {
        if (result > my_max) {
            my_max = result;
        }
        if (result < my_min) {
            my_min = result;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i]) {
            operators[i]--;
            if (i == 0)
                getAnswer(result + operands[idx], idx+1);
            else if (i == 1)
                getAnswer(result - operands[idx], idx+1);
            else if (i == 2)
                getAnswer(result * operands[idx], idx+1);
            else
                getAnswer(result / operands[idx], idx+1);
            operators[i]++;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> operands[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }
    
    getAnswer(operands[0], 1);
    cout << my_max << '\n';
    cout << my_min;
}