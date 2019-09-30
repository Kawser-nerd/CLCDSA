#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Tnode
{
    map<string, Tnode*> sons;
};

Tnode memo[200000];
int top;

Tnode* tree;

char buf[200000];
int totNode;

int n, m;

Tnode* GetNode()
{
    totNode ++;
    memo[top].sons.clear();
    return &memo[top ++];
}

vector<string> Split(const char* buf)
{
    string line = buf;
    vector<string> res;

    int p = 0;
    while (p < line.length())
    {
        int q = p + 1;
        while (q < line.length() && line[q] != '/')
            q ++;
        res.push_back( line.substr(p + 1, q - p - 1) );
        p = q;
    }

    return res;
}

void Insert(const vector<string>& list)
{
    Tnode* t = tree;

    for (int i = 0; i < list.size(); i ++)
    {
        if (!t->sons.count(list[i]))
        {
            t->sons.insert(make_pair(list[i], GetNode()));
        }
        t = t->sons[list[i]];
    }
}


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int caseNo = 0;
    int t;

    scanf("%d", &caseNo);
    for (t = 1; t <= caseNo; t ++)
    {
        scanf("%d%d", &n, &m);

        totNode = 0;
        top = 0;

        tree = GetNode();

        for (int i = 0; i < n; i ++)
        {
            scanf("%s", buf);
            vector<string> token = Split(buf);
            Insert(token);
        }

        int totNodeTemp = totNode;
        for (int i = 0; i < m; i ++)
        {
            scanf("%s", buf);
            vector<string> token = Split(buf);
            Insert(token);
        }

        printf("Case #%d: %d\n", t, totNode - totNodeTemp);
    }

    return 0;
}
