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
    int alice = 0, bob = 0;
    vector<int> vec; int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp; cin >> temp; vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    
    for(int i = 0; i < N; i++)
    {
        if(i % 2 == 0)
        {
            alice += vec[i];
        }
        else
        {
            bob += vec[i];
        }
    }
    cout << alice - bob << endl;
    return 0;
}