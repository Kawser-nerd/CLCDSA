#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; (i) < int(n); ++(i))

bool comp(const vector<int> &x, const vector<int> &y){
    return x[2] > y[2];
}

ll D[5];
int P [10]={0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,2};
int Q [10]={1 ,1 ,1 ,2 ,2 ,3 ,2 ,2 ,3 ,3};
int R [10]={2 ,3 ,4 ,3 ,4 ,4 ,3 ,4 ,4 ,4};

int main(void){

    ll m=0, a=0, r=0, c=0, h=0;
    int n;
    cin >> n;
    rep(i, n){
        string tmp;
        cin >> tmp;
        switch (tmp[0]){
            case 'M':
                m++;
                break;
            case 'A':
                a++;
                break;
            case 'R':
                r++;
                break;
            case 'C':
                c++;
                break;
            case 'H':
                h++;
                break;
            default:
                break;
        }
    }

    ll ans = 0;
    D[0] = m;
    D[1] = a;
    D[2] = r;
    D[3] = c;
    D[4] = h;

    rep(d, 10){
        ans += D[P[d]]*D[Q[d]]*D[R[d]];
    }

    cout << ans << endl;


    return 0;
}