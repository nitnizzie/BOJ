#include <iostream>
#include <string>
using namespace std;

bool is_Group_word (string str) {
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < i; j++) {
            if (str[i] != str[i-1] && str[i] == str[j]) return false;
        }
    }
    return true;
}

int main() {
    int N, cnt = 0;
    string str;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> str;
        if (is_Group_word(str)) cnt++;
    }

    cout << cnt;
}