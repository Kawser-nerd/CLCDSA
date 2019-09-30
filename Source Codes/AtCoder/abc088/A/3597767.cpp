#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <climits>
#include <functional>
#include <map>
#include <stack>
#include <cstdlib>
#include <queue>
#define endl '\n'
#define ll long long
#define NCONS 100001

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N, A; cin >> N >> A;
    N %= 500;
    if(N <= A)
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}