#include <iostream>
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

void inputVector(vector<int> * p, int a){
    rep(i, a){
        int input;
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

#define Max 100
#define Bl '#'
#define Wh '.'

char S[Max][Max];
int c[Max][Max];
int H, W;

int count_around(int i, int j) {
    if (S[i][j] == Wh) return 0;

    int count = 1;
    if (i != 0) {
        if (S[i-1][j] == Bl) count += 1;
    }
    if (i != H - 1) {
        if (S[i+1][j] == Bl) count += 1;
    }
    if (j != 0) {
        if (S[i][j-1] == Bl) count += 1;
    }
    if (j != W - 1) {
        if (S[i][j+1] == Bl) count += 1;
    }
    return count;
}

int check(int i, int j) {
    if (S[i][j] == Wh) return 1;
    if (c[i][j] >= 2) return 1;
    if (i != 0) {
        if (c[i-1][j] >= 2) return 1;
    }
    if (i != H - 1) {
        if (c[i+1][j] >= 2) return 1;
    }
    if (j != 0) {
        if (c[i][j-1] >= 2) return 1;
    }
    if (j != W - 1) {
        if (c[i][j+1] >= 2) return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    H = inputValue();
    W = inputValue();
    rep(i, H) {
        inputArray(S[i], W);
    }
    rep(i, H) {
        rep(j, W) {
            c[i][j] = count_around(i, j);
        }
    }


    int res = 1;
    rep(i, H) {
        rep(j, W) {
            res &= check(i, j);
        }
    }

    if (res) output("Yes");
    else output("No");

    return 0;
}