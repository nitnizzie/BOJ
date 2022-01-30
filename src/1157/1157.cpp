#include <iostream>
#include <cstring>
using namespace std;

int alphabet[26] = {};
string str;
bool is_only;

int main() {
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a') {
            alphabet[ str[i] - 'a']++;
        }
        else alphabet[ str[i] - 'A']++;
    }

    int max = 0, max_idx = 0;

    for (int i = 0; i < 26; i++) {
        if (max < alphabet[i]) {
            max = alphabet[i];
            max_idx = i;
            is_only = true;
        }
        else if (max == alphabet[i]) {
            is_only = false;
        }
    }

    if (is_only) printf("%c", 'A'+ max_idx);
    else  printf("?");
}