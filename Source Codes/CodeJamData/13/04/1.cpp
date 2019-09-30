#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

struct door{
    int color;
    vector<int> keys;
};

bool can(vector<int> keycount, const vector<door>& doors, vector<bool> opened)
{
    queue<int> q;
    for(int i=1; i<=200; i++)
        if(keycount[i])
            q.push(i);
    int N=doors.size();
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0; i<N; i++)
        {
            if(doors[i].color == k && !opened[i])
            {
                opened[i]=true;
                for(int j=0; j<doors[i].keys.size(); j++)
                {
                    int c=doors[i].keys[j];
                    if(!keycount[c])
                    {
                        keycount[c]++;
                        q.push(c);
                    }
                }
            }
        }
    }
    for(int i=0; i<N; i++)
        if(!opened[i])
            return false;
    return true;
}

vector<int> solve(const vector<int>& keys, const vector<door>& doors)
{
    int N = doors.size();
    {
        map<int, int> allkeys, alldoors;
        for(int i=0; i<keys.size(); i++)
            allkeys[keys[i]]++;
        for(int i=0; i<N; i++)
        {
            alldoors[doors[i].color]++;
            for(int j=0; j<doors[i].keys.size(); j++)
                allkeys[doors[i].keys[j]]++;
        }
        for(int i=1; i<=200; i++)
            if(alldoors[i] > allkeys[i])
                return vector<int>();
    }
    vector<int> keycount(201, 0);
    for(int i=0; i<keys.size(); i++)
        keycount[keys[i]]++;
    vector<bool> opened(N, 0);
    if(!can(keycount, doors, opened))
        return vector<int>();
    vector<int> result;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            if(!opened[j] && keycount[doors[j].color]>0)
            {
                opened[j]=true;
                keycount[doors[j].color]--;
                for(int k=0; k<doors[j].keys.size(); k++)
                    keycount[doors[j].keys[k]]++;
                if(can(keycount, doors, opened)){
                    result.push_back(j+1);
                    break;
                }
                opened[j]=false;
                keycount[doors[j].color]++;
                for(int k=0; k<doors[j].keys.size(); k++)
                    keycount[doors[j].keys[k]]--;
            }
        assert(result.size()==i+1);
    }
    return result;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        fprintf(stderr, "t=%d\n", t);
        vector<int> keys;
        int K, N;
        scanf("%d %d", &K, &N);
        while(K--)
        {
            int c;
            scanf("%d", &c);
            keys.push_back(c);
        }
        vector<door> doors(N);
        for(int i=0; i<N; i++)
        {
            int c, n;
            scanf("%d %d", &c, &n);
            doors[i].color=c;
            while(n--)
            {
                scanf("%d", &c);
                doors[i].keys.push_back(c);
            }
        }
        vector<int> ans = solve(keys, doors);
        printf("Case #%d:", t);
        if(!ans.size())
        {
            puts(" IMPOSSIBLE");
        }else{
            for(int i=0; i<ans.size(); i++)
            {
                printf(" %d", ans[i]);
            }
            puts("");
        }
    }
}
