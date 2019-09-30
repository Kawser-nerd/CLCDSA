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
#define endl '\n'
#define ll long long
#define NCONS 100001

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int A, B, C, X; cin >> A >> B >> C >> X;
    
    int ret = 0;
    for(int i = 0; i <= A; i++)
    {
        for(int j = 0; j <= B; j++)
        {
            for(int k = 0; k <= C; k++)
            {
                if(i * 500 + j * 100 + k * 50 == X)
                    ret += 1;
            }
        }
    }
    
    cout << ret << endl;
    return 0;
}