#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#define endl '\n'
#define ll long long
#define NCONS 8000

using namespace std;

int main(void)
{
        cin.tie(NULL); ios_base::sync_with_stdio(false);
        int N, H; cin >> N >> H;
        int a = 0;
        vector<int> b;

        for(int i = 0; i < N; i++)
        {
                int ta, tb; cin >> ta >> tb;
                a = max(a, ta);
                b.push_back(tb);
        }

        sort(b.begin(), b.end());
        int ret = 0;
        int cur_b;
        while(H > 0)
        {
                cur_b = b.back(); b.pop_back();
                if(cur_b > a)
                {
                        ret += 1;
                        H -= cur_b;
                }
                else
                {
                        ret += H / a;
                        if(H % a != 0) ret += 1;
                        break;
                }
        }

        cout << ret << endl;

        return 0;
}