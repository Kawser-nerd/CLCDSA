#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <climits>
#include <functional>
#include <map>
#include <stack>
#define endl '\n'
#define ll long long
#define NCONS 16001

using namespace std;

int getsum(int a)
{
    auto str = to_string(a);
    auto ret = 0;
    for(int i = 0; i < str.length(); i++) ret += str[i] - '0';
    return ret;
}

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, A, B; cin >> N >> A >> B;
    
    int acc = 0;
    for(int i = 1; i <= N; i++)
    {
        auto ret = getsum(i);
        if(A <= ret && ret <= B)
        {
//            cout << i << endl;
            acc += i;
        }
    }
    cout << acc << endl;
    return 0;
}