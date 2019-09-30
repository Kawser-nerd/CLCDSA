# include <iostream>
# include <cstdio>
# include <algorithm>
# include <queue>
using namespace std;
typedef long long LL;
const int maxn = 3e5+80;
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct node
{
    LL x, y, z;
}a[maxn];
bool cmp1(node na, node nb){return na.x-na.y > nb.x - nb.y;}
struct cmp2 {bool operator ()(node na, node nb) {return na.x-na.z>nb.x-nb.z;}};
struct cmp3 {bool operator ()(node na, node nb) {return na.y-na.z>nb.y-nb.z;}};
priority_queue<node, vector<node>, cmp2>p;
priority_queue<node, vector<node>, cmp3>q;
LL l[maxn], r[maxn];
int main()
{
    int x, y, z;
    scanf("%d%d%d",&x,&y,&z);
    for(int i=1; i<=x+y+z; ++i) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1, a+1+x+y+z, cmp1);
    while(!q.empty()) q.pop();
    while(!p.empty()) p.pop();
    LL sum = 0;
    for(int i=1; i<=x; ++i)
    {
        sum += (LL)a[i].x;
        p.push(a[i]);
    }
    l[x] = sum;
    for(int i=x+1; i<=x+z; ++i)
    {
        if(p.empty() || a[i].x - a[i].z < p.top().x - p.top().z)
            sum += a[i].z;
        else
        {
            sum = sum - p.top().x + p.top().z + a[i].x;
            p.pop();
            p.push(a[i]);
        }
        l[i] = sum;
    }
    sum = 0;
    for(int i=x+y+z; i>x+z; --i)
    {
        q.push(a[i]);
        sum += (LL)a[i].y;
    }
    r[x+z] = sum;
    for(int i=x+z; i>x; --i)
    {
        if(q.empty() || a[i].y - a[i].z < q.top().y - q.top().z)
            sum += a[i].z;
        else
        {
            sum = sum - q.top().y + q.top().z + a[i].y;
            q.pop();
            q.push(a[i]);
        }
        r[i-1] = sum;
    }
    LL ans = 0;
    for(int i=x; i<=x+z; ++i) ans = max(ans, l[i]+r[i]);
    printf("%lld\n",ans);
    return 0;
}