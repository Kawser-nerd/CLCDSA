#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>

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

#define Max 110
string s[Max];
string t[Max];
int N, M;

int main(int argc, const char * argv[]) {
    N = inputValue();
    inputArray(s, N);
    M = inputValue();
    inputArray(t, M);

    sort(s, s+N);

    int maximum = 0;
    rep(i, N) {
        int ans = 0;
        if (i > 0 && s[i-1].compare(s[i]) == 0) continue;
        rep(j, N) {
            if (s[i].compare(s[j]) == 0) {
                ans += 1;
            }
        }
        rep(j, M) {
            if (s[i].compare(t[j]) == 0) {
                ans -= 1;
            }
        }
        if (ans > maximum) maximum = ans;
    }

    output(maximum);

    return 0;
}