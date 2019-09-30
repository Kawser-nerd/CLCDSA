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
int N;
char S[Max];

int main(int argc, const char * argv[]) {
    N = inputValue();
    inputArray(S, N);
    string org(S);
    string dst("b");
    int ans = -1;
    repd(i, 1, Max) {
        if (dst.compare(org) == 0) {
            ans = i-1;
            break;
        }
        if (i%3 == 0) {
            dst = 'b' + dst + 'b';
        } else if (i%3 == 1) {
            dst = 'a' + dst + 'c';
        } else {
            dst = 'c' + dst + 'a';            
        }
    }

    output(ans);

    return 0;
}

// 7 4 4 4 4 0 0 0 0
// 33