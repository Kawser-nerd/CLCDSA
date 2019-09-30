#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

template<typename T>
void inputArray(T* p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

template<typename T>
void inputVector(vector<T> * p, int a){
    rep(i, a){
        T input;
        cin >> input;
        p -> push_back(input);
    }
}

template <typename T>
void output(T a, int precision = 0) {
    if(precision > 0){
        cout << setprecision(precision)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}

#define Max 10

int N, K;
int T[Max][Max];

int search(int ans, int row) {
    if (row == N) {
        if (ans == 0) return 1;
        else return 0;
    }

    int res = 0;
    repd(i, 0, K) {
        ans ^= T[row][i];
        res = search(ans, row + 1);
        ans ^= T[row][i];
        if (res) return 1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    N = inputValue();
    K = inputValue();
    rep(i, N) {
        rep(j, K) {
            T[i][j] = inputValue();
        }
    }

    int res = search(0, 0);
    output(res ? "Found" : "Nothing");

    return 0;
}