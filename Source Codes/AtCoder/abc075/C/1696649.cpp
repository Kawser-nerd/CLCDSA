#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

bool visited[50];
vector<int> v[50];

void DFS(pair<int,int> forbidden,int node)
{
    if(visited[node])
        return;

    visited[node] = true;
    for(int i = 0;i < v[node].size();i++) {
        if((forbidden.first == node && forbidden.second == v[node][i]) ||
                (forbidden.second == node && forbidden.first == v[node][i]))
            continue;

        DFS(forbidden,v[node][i]);
    }

    return;
}

int Bridge(int n,vector<pair<int,int> > &edge)
{
    int count = 0;

    for(int i = 0;i < edge.size();i++)
    {
        DFS(edge[i],0);
        for(int j =0;j < n;j++)
            if(visited[j] == false) {
                count++;
                break;
            }

        memset(visited,false,50);
    }

    return count;
}

int main(void)
{
    int n,m;

    cin>>n>>m;

    vector<pair<int,int> > edge;

    memset(visited,false,50);

    for(int i = 0;i < m;i++) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);

        pair<int,int> temp;
        temp.first = a;
        temp.second = b;
        edge.push_back(temp);
    }

    cout<<Bridge(n,edge)<<endl;

    return 0;
}