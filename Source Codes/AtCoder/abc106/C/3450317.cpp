#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define N 5000000000000000

int main(int argc, char const *argv[]) {
    string S;
    unsigned long long K;
    cin  >> S >> K;
    //cout << pow(2, N) << endl;

    unsigned long long cnt_left = 0;
    for(auto c:S) {
        int n = atoi(&c);
        if(n == 1) {
            cnt_left++;
            if(cnt_left == K) {
                cout << 1 << endl;
                break;
            }
        } else {
            cout << n << endl;
            break;
        }
    }

    return 0;
}