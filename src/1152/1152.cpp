#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string S;
    getline(cin, S);

    for (int i = 0; i < S.length(); i++) {
        if (S[i] != ' ') {
            if (S[i+1] == ' ') cnt++;
        } 
    }

    if (S[S.length() -1] != ' ') cnt++;

    cout << cnt;
}