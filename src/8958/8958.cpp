#include <iostream>
using namespace std;

char OXquiz[81] = {};

int main() {
    int n, i = 0, combo = 0, score = 0;
    cin >> n;

    for (int j = 0; j < n; j++) {
        scanf("%s", OXquiz);

        while (OXquiz[i] != '\0') {
            if (OXquiz[i] == 'O') {
                combo++;
                score += combo;
            }
            else combo = 0;
            i++;
        }

        cout << score << '\n';
        i = 0;
        score = 0;
        combo = 0;
    }
}