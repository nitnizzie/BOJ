#include <iostream>
using namespace std;

int main()
{
    string code;
    int sum = 0;
    cin >> code;

    for (int i = 0; i < code.length(); i++)
    {
        sum += ((int)code[i] - 65) / 3 + 3;

        if (code[i] == 'S' || code[i] == 'V' || code[i] == 'Y' || code[i] == 'Z')
            sum--;
    }

    cout << sum;
}