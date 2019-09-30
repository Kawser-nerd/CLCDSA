#include <iostream>
#include <vector>
#include <string>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(inc, a, b) for (int inc = (a); (inc) < (b); (inc)++) //inc?a???b-a?(i?b????)?????
#define REP(inc,b) FOR(inc,0,n)

int main(){

    long long int n,d,x;
    cin >> n >> d >>x;
    int a;
    REP(i,n){
        cin >> a;
        x += 1 + ((d - 1) / a);
    }

    cout << x << endl;

    return 0;
}