#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_map>       // ?????????????

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<unsigned int> bits;

    long int sum = 0;
    long int base_exp = 0;
    long int base = 1;

    while(sum != N) {
        base_exp ++;
        base *= 2;
        long int b = abs(N - sum) % (long int)base;
        if(base_exp%2==0) {
            b *= -1;
        }
        bits.push_back(b==0 ? 0 : 1);
        sum += b;
    }
    if(N==0) {
        bits.push_back(0);
    }

    reverse(bits.begin(), bits.end());
    for(auto b:bits) {
        cout << b;
    }
    cout << endl;
}