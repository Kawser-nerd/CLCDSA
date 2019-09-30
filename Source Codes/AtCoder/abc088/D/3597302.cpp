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
#include <queue>
#define endl '\n'
#define ll long long
#define NCONS 100001

using namespace std;

struct Pos{
    int x;
    int y;
    int dis;
};

int H, W;
vector<string> grid;
bool visited[50][50];
int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

int bfs()
{
    queue<Pos> quu; quu.push(Pos{0, 0, 1}); visited[0][0] = true;
    
    while(!quu.empty())
    {
        auto cur = quu.front(); quu.pop();
        if(cur.x == H - 1 && cur.y == W - 1)
        {
            return cur.dis;
        }
        
        for(int i = 0; i < 4; i++)
        {
            auto nx = cur.x + dx[i], ny = cur.y + dy[i];
            if(min(nx, ny) < 0 || nx >= H || ny >= W) continue;
            if(visited[nx][ny]) continue;
            if(grid[nx][ny] == '#') continue;
            quu.push(Pos{nx, ny, cur.dis + 1});
            visited[nx][ny] = true;
        }
    }
    
    return -1;
}

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> H >> W;
    int black = 0;
    for(int i = 0; i < H; i++)
    {
        string temp; cin >> temp;
        grid.push_back(temp);
        for(int j = 0; j < temp.length(); j++)
            if(temp[j] == '#')
                black += 1;
    }
    auto ret = bfs();
    if(ret == -1)
        cout << ret << endl;
    else
        cout << H * W - black - ret << endl;
    
    
    return 0;
}