#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <climits>
#include <functional>
#define endl '\n'
#define ll long long

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll N;
    ll cur = 1;
    ll ret = 1;
    cin >> N;
    for(;cur * cur <= N; cur++) ret = cur;
    cout << ret * ret << endl;

    
    return 0;
}