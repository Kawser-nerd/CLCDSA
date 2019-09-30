#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <chrono>
#include <vector>

using namespace std;
typedef vector<int> targe_nodes;

int rec(vector<targe_nodes> &target_nodes_info, int v, int w, int cur, int p)
{
    if (cur == w)
    {
        return 1;
    }
    else if (cur == v)
    {
        return 0;
    }
    int cnt = 0;
    int next = target_nodes_info[cur][0] + target_nodes_info[cur][1] - p;
    cnt = rec(target_nodes_info, v, w, next, cur);
    return cnt;
}

int main()
{
    int N, M, a, b;
    cin >> N >> M;
    vector<targe_nodes> target_nodes_info(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        target_nodes_info[a].push_back(b);
        target_nodes_info[b].push_back(a);
    }
    int deg4_node_cnt = 0;
    int deg6_node_cnt = 0;
    for (int i = 1; i < N + 1; i++)
    {
        int deg_i = target_nodes_info[i].size();
        if (deg_i % 2 != 0)
        {
            cout << "No"
                 << "\n";
            return 0;
        }
        if (deg_i >= 6)
        {
            deg6_node_cnt += 1;
        }
        else if (deg_i == 4)
        {
            deg4_node_cnt += 1;
        }
    }

    if (deg6_node_cnt >= 1)
    {
        cout << "Yes"
             << "\n";
        return 0;
    }

    if (deg4_node_cnt >= 3)
    {
        cout << "Yes"
             << "\n";
        return 0;
    }
    else if (deg4_node_cnt == 2)
    {
        vector<int> deg4_node;
        for (int i = 1; i < N + 1; i++)
        {
            if (target_nodes_info[i].size() == 4)
            {
                deg4_node.push_back(i);
            }
        }
        int v = deg4_node[0];
        int w = deg4_node[1];
        int path_cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            path_cnt += rec(target_nodes_info, v, w, target_nodes_info[v][i], v);
        }
        if (path_cnt == 4)
        {
            cout << "No"
                 << "\n";
            return 0;
        }
        else if (path_cnt == 2)
        {
            cout << "Yes"
                 << "\n";
            return 0;
        }
    }
    else if (deg4_node_cnt <= 1)
    {
        cout << "No"
             << "\n";
        return 0;
    }
}