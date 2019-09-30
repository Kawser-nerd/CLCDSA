#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;
const int MAX_N = 100000;
int parent[MAX_N+10];

void initialize(void){
    for (int i = 0; i < MAX_N+10;i++)
    {
        parent[i] = i;
    }
}

int find(int x){
    if(parent[x]==x)
    {
        return x;
    }else
    {
        return parent[x] = find(parent[x]);
    }
}

void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y)
        return;
    else
    {
        parent[x] = y;
    }
}

bool is_same(int x,int y){
    return find(x) == find(y);
}

int main(void)
{
    initialize();
    std::vector<int> numlist;
    int N, M;
    cin >> N >> M;
    int m1,m2;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &m1);
        numlist.push_back(m1);
    }
    for (int i = 0; i < M;i++)
    {
        scanf("%d %d", &m1, &m2);
        unite(m1, m2);
    }

    int count=0;
    for (int i = 1; i <= N; i++)
    {
        if(is_same(numlist[i-1],find(i))){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}