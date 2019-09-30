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
int c[4][4];
int a[4], b[4];

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) cin >> c[i][j];
    
    a[1] = 0;
    for(int i = 1; i <= 3; i++)
        b[i] = c[1][i] - a[1];
    for(int i = 1; i <= 3; i++)
        a[i] = c[i][1] - b[1];
    
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            if(a[i] + b[j] != c[i][j])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}