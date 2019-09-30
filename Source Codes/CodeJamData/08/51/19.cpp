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

vector<pair<int,string> > mv;
struct vert
{
    int x, y1, y2;
};
vector<vert> v;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
bool rightWall[6060][6060];

int solve()
{
    int y = 0, x = 0;
    int dir = 0;
    CLEAR(rightWall,0);
    v.clear();
    v.reserve(9000000);
    REP(i,mv.sz)
    {
        int repeat = mv[i].first;
        const string& action = mv[i].second;
        REP(r,repeat)
        {
            REP(j,action.sz)
            {
                char ch = action[j];
                if(ch == 'L') { dir = (dir+3) % 4; }
                else if(ch == 'R') { dir = (dir+1) % 4; } 
                else
                {
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(dy[dir])
                    {
                        int y1 = min(ny, y) + 3010, x1 = x + 3010 - 1;
                        rightWall[y1][x1] = true;
                    }
                    y = ny; x = nx;
                }
            }
        }
    }
    int minY[6060], maxY[6060], minX[6060], maxX[6060];
    REP(i,6060) { minY[i] = minX[i] = 999999; maxY[i] = maxX[i] = -999999; }
    REP(y,6060)
    {
        int cnt = 0;
        REP(x,6060)
        {
            if(cnt%2==1)
            {
                minX[y] <?= x;
                maxX[y] >?= x;
                minY[x] <?= y;
                maxY[x] >?= y;
            }
            if(rightWall[y][x]) ++cnt;
        }
    }
    int ret = 0;
    REP(y,6060)
    {
        int cnt = 0;
        REP(x,6060)
        {
            if(cnt%2==0 && ((minX[y] <= x && x <= maxX[y]) || (minY[x] <= y && y <= maxY[x])))
                ++ret;
            if(rightWall[y][x]) ++cnt;
        }
    }
    return ret;
}

int main()
{
    int cases;
    cin >> cases;
    REP(cc,cases)
    {
        cerr << "Case " << cc+1 << endl;
        mv.clear();
        int l;
        cin >> l;
        REP(i,l)
        {
            string s;
            int t;
            cin >> s >> t;
            mv.pb(make_pair(t, s));
        }
        printf("Case #%d: %d\n", cc+1, solve());
    }
}

