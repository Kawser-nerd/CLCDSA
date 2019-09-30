#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long

const LL MOD = 1e9 + 7;
const int N = 200005;

LL n, A, B, in[N];

int main()
{
    while(cin >> n >> A >> B){
        for(int i=0;i<n;i++) cin >> in[i];
        sort(in, in + n);
        LL mn = 0;
        for(int i=1;i<n;i++){
            LL dis = in[i] - in[i - 1];
            LL x = dis * A;
            if(x < B) mn += x;
            else mn += B;
        }
        cout << mn << '\n';
    }
    return 0;
}