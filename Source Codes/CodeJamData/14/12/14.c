#include <vector>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
int n;
vector <int> suraj,singh;
vector < vector <int> > arr;
vector <bool> sol;
vector <int> rot;
int arrb[2000][3];
int ans (int plc, int u)
{
    if (u == 3) 
    {
        return 10000;
    }
    if (plc == suraj.size()) 
    {
        if (u == 1) 
        {
            return 10000;
        }
        return 0;
    }
 
    int &fin = arrb[plc][u];
    if (fin != -1) 
    {
        return fin;
    }
    fin = ans (plc+1, u) + singh[plc];
    fin = min (fin, suraj[plc]+ans(plc+1, u+1));
    return fin;
}
int solve (vector <int> arr, vector <int> x)
{
    suraj = arr;
    singh = x;
    if (arr.size() == 0) 
    {
        return 0;
    }
    if (arr.size() == 1) 
    {
        return x[0];
    }
    memset (arrb, -1, sizeof(arrb));
    return ans (0, 0);
}
 
int proc (int u, int q)
{
    vector <int> suraj;
    vector <int> singh;
    int i;
    for(i=0;i<arr[u].size();i++)
    {
        int w = arr[u][i];
        if (w == q) 
        {
            continue;
        }
        int l = proc (w, u);
        suraj.push_back (l);
        singh.push_back (rot[w]);
    }
    return solve (suraj, singh);
}
 
int proc2 (int u, int q)
{
    rot[u] = 1;
    int i,sum=0;
    for(i=0;i<arr[u].size();i++) 
    {
        int w = arr[u][i];
        if (w == q) 
        {
            continue;
        }
        proc2 (w, u);
        rot[u] += rot[w];
    }
}
 
int main()
{
    int t,i,j;
    scanf("%d",&t);
    int h = 1;
    while (t--) 
    {
        cout << "Case #" << h++<< ": ";
        cin >> n;
        arr.clear();  
        arr.resize (n);
        int sum = n;
        for (i = 0; i < n-1; i++) 
        {
            int u,y;
            cin >> u >> y;
            u--;
            y--;
            arr[u].push_back (y);
            arr[y].push_back (u);
        }
       for (j = 0; j < n; j++) 
       {
            sol.resize (n);
            rot.resize (n);
            for (int h = 0; h < sol.size(); h++) 
            {
                sol[h] = false;
                rot[h] = 0;
            }
            proc2 (j, j);
            sum = min (sum, proc(j, j));
        }
        cout << sum << endl;
    }
    return 0;
}
