#include <iostream>
using namespace std;

bool num[10000] = {};

int d(int n) {
    return n + n/1000 + n % 1000 / 100 + n % 100 /10 + n % 10; 
}

void self_num() {
    int d_n;
    for (int n = 1; n < 10000; n++) {
        d_n = (d(n));
        if (d_n < 10000) num[d_n] = true;
    }
}

int main() {
    self_num();

    for (int i = 1; i < 10000; i++) {
        if (!num[i]) printf("%d\n", i);
    }
}