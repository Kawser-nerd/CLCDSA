#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>
#include<queue>

using namespace std;

#define ll long long
typedef pair<ll, ll> P;

int main(){
    string a , b , c ;
    cin >> a >> b >> c ;
    int dif = 'A' - 'a';
    // cout << dif;
    char e = a[0] + dif;
    char f = b[0] + dif;
    char g = c[0] + dif;
    cout << e << f << g << endl;;
    return 0;
}