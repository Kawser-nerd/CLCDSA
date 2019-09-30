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

int get(int n)
{
    int ret = 0;
    while(n > 1 && n % 2 == 0)
    {
        n /= 2;
        ret += 1;
    }
    return ret;
}

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N; cin >> N;
    int ret = INT_MAX;
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp;
        ret = min(ret, get(temp));
    }
    
    cout << ret << endl;
    
    return 0;
}