#include <iostream>
#include <string>
using namespace std;

string croatian[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    
    int idx;
    string str;
    cin >> str;

    for (int i = 0; i < 8; i++) {
        while(1) {
            idx = str.find(croatian[i]);
            if (idx == -1) break;
            str.replace(idx, croatian[i].length(), "#");
        }
    }    

    cout << str.length();
}