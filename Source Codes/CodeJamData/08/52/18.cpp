#include<queue>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
typedef long long ll;

int h, w;
vector<string> map;
int portal_number[20][20][4]; // y, x, ball-direction
vector<pair<int,int> > arrives;

const int dx[4] = { 1, 0, 0, -1 };
const int dy[4] = { 0, 1, -1, 0 };

int best[18][18][560][560];
struct state
{
    int y, x, blue, yellow;
};
bool operator < (const state& a, const state& b)
{
    if(a.y != b.y) return a.y < b.y;
    if(a.x != b.x) return a.x < b.x;
    if(a.blue != b.blue) return a.blue < b.blue;
    return a.yellow < b.yellow;
}

int main()
{
    int cases;
    cin >> cases;
    REP(cc,cases)
    {
        cerr << "Case " << cc+1 << endl;
        printf("Case #%d: ", cc+1);
        cin >> h >> w;
        map.clear();
        map.resize(h+2, string(w+2, '#'));
        REP(i,h) 
        {
            string row;
            cin >> row;
            map[i+1] = "#" + row + "#";
        }
        h += 2;
        w += 2;
//        REP(i,h) cout << map[i] << endl;
        arrives.clear();
        arrives.resize(1);
        CLEAR(portal_number,-1);
        int P = 1;
        REP(k,4) REP(y,h) REP(x,w)
        {
            if(map[y][x] != '#') continue;
            int ny = y + dy[k], nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(map[ny][nx] == '#') continue;            
            portal_number[y][x][3-k] = P++;
            arrives.push_back(make_pair(ny, nx));
        }
        assert(P <= 550);
        CLEAR(best,-1);
        state s;
        REP(i,h) REP(j,w) if(map[i][j] == 'O')
        {
            s.y = i; s.x = j;
            s.blue = s.yellow = 0;            
        }
        priority_queue<pair<int,state> > pq;
        pq.push(make_pair(0, s));
        best[s.y][s.x][0][0] = 0;
        bool solved = false;     
        while(!pq.empty())
        {
            int cost = -pq.top().first;
            state here = pq.top().second;
        //    printf("cost %d, y %d x %d blue %d yellow %d\n", cost, here.y, here.x, here.blue, here.yellow);
            pq.pop();
            if(best[here.y][here.x][here.blue][here.yellow] < cost) continue;
            // Shoot
            REP(dir,4)
            {
                int ny = here.y + dy[dir], nx = here.x + dx[dir];
                while(0 <= ny && ny < h && 0 <= nx && nx < w && map[ny][nx] != '#')
                {
                    ny += dy[dir];
                    nx += dx[dir];
                }
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                int portal = portal_number[ny][nx][dir];
                assert(portal != -1);
                //printf("ny %d nx %d dir %d here (%d,%d)\n", ny, nx, dir, here.y, here.x);
                if(here.blue == portal || here.yellow == portal) continue;
                state there = here;
                there.blue = portal;
                if(best[there.y][there.x][there.blue][there.yellow] == -1 ||
                   best[there.y][there.x][there.blue][there.yellow] > cost)
                {
                    best[there.y][there.x][there.blue][there.yellow] = cost;
                    pq.push(make_pair(-cost, there));
                }
                there.blue = here.blue;
                there.yellow = portal;                
                if(best[there.y][there.x][there.blue][there.yellow] == -1 ||
                   best[there.y][there.x][there.blue][there.yellow] > cost)
                {
                    best[there.y][there.x][there.blue][there.yellow] = cost;
                    pq.push(make_pair(-cost, there));
                }
            }

            // Move
            REP(dir,4)
            {
                int ny = here.y + dy[dir], nx = here.x + dx[dir];
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(map[ny][nx] == '#')
                {
                    int portal = portal_number[ny][nx][dir];
                    assert(portal != -1);
                    if((here.yellow == portal || here.blue == portal) && here.blue && here.yellow)
                    {
                        int other = (here.yellow == portal ? here.blue : here.yellow);
                        ny = arrives[other].first;
                        nx = arrives[other].second;
                    }
                    else
                        continue;
                }
                if(map[ny][nx] == 'X')
                {
                    printf("%d\n", cost+1);
                    solved = true;
                    break;
                }                                
                int& b = best[ny][nx][here.blue][here.yellow];
                if(b == -1 || b > cost+1)
                {
                    b = cost+1;
                    state there = here;
                    there.y = ny; there.x = nx;
                    pq.push(make_pair(-b, there));
                }
            }
            if(solved) break;
        }
        if(!solved)
            printf("THE CAKE IS A LIE\n");
    }
}

