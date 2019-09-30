#include <iostream>
#include <climits>
#define endl '\n'

using namespace std;

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    string str; cin >> N >> str;
    auto west = new int[N]();
    auto east = new int[N]();
    
    for(int i = 0; i < N; i++)
    {
        if(str[i] == 'W')
        {
            west[i] = 1;
            if(i == 0) continue;
            west[i] += west[i-1];
            east[i] += east[i-1];
        }
        else
        {
            east[i] = 1;
            if(i == 0) continue;
            east[i] += east[i-1];
            west[i] += west[i-1];
        }
    }
    
    int ret = INT_MAX;
    
    for(int i = 0; i < N; i++)
    {
        int left = 0;
        int right = 0;
        if(i != 0)
        {
            left = west[i-1];
        }
        right = east[N - 1] - east[i];
        
        ret = min(ret, left + right);
    }
    
    cout << ret;
    
    return 0;
}