#include <iostream>
using namespace std;

int main(){
    int num1, num2;
    int result[4] = {};
    cin >> num1 >> num2;

    result[0] = num1 * (num2 % 10);
    result[1] = num1 * (num2 % 100 /10);
    result[2] = num1 * (num2 / 100);
    result[3] = num1 * num2;

    cout << result[0] << '\n' << result[1] << '\n' << result[2] << '\n' << result[3] << '\n';
}