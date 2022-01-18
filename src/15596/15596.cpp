#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a) {
    long long sum = 0;
    vector<int>::iterator i;
    for (i = a.begin(); i != a.end() ; ++i) {
        sum += *i;
    }
    return sum;
}