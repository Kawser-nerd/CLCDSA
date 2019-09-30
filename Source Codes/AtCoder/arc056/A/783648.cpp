#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<math.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;


int main()
{
    // get a integer
    ll A, B, K, L;
    cin >> A >> B >> K >> L;


    ll num_set = K / L;
    ll remain = K - num_set * L;

    ll a = remain * A + num_set * B;
    ll b = ( num_set + 1 ) * B;
    ll c = A * K;

    cout << min( min( a, b ), c ) << endl;
}