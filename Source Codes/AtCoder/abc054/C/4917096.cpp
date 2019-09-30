#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
using namespace std;

vector<int> vt[8];

int dfs(vector<int> flag, int now, int N)
{
    flag[now]=1;
    bool all_visted=true;
    for(int i=0; i<N; i++){
        if(flag[i]==0){
            all_visted=false;
        }
    }
    if(all_visted){
        return 1;
    }

    int ret=0;
    for(int i=0; i<vt[now].size(); i++){
        if(flag[vt[now][i]]==1) continue;
        
        flag[vt[now][i]]=true;
        ret+=dfs(flag, vt[now][i], N);
        flag[vt[now][i]]=false;
    }

    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> flag(N);
    fill(flag.begin(), flag.end(), 0);

    for(int i=0; i<M; i++){
        int tmpa, tmpb;
        cin >> tmpa >> tmpb;
        tmpa--;
        tmpb--;
        vt[tmpa].push_back(tmpb);
        vt[tmpb].push_back(tmpa);
    }
    
    cout << dfs(flag, 0, N) << endl;
    
    return 0;
}