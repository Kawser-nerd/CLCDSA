#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second

#define INF 1000000000
#define INFLL 1000000000000000000LL

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int n, m;

bool inline ok (int x, int y)
{
     return (x>=0 && x<n && y>=0 && y<m);
}

inline pair <long long, long long> solve (long long a, long long b, long long c)
{
//cout << "solve " << a << " " << b << " " << c << endl;
     if (b==0) 
     {
          if (a<=0 && c>0)
             return pair <long long, long long> (-INFLL, INFLL);
          else
             return pair <long long, long long> (1, -1);
     }
     else if (b>0)
     {
         if (c>0) 
            c = (c-1)/b;
         else
             c = c/b-1;
         if (a>=0)
            a = (a+b-1)/b;
         else
            a = a/b;
         
         //cout << "solution " << a << " " << c << endl;
         return pair <long long, long long> (a, c);
             
     }
     else
     {
         return solve (-c+1, -b, -a+1);
     }
     
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int c;
    cin >> c;
    FOR (t, 1, c+1)
    {        
        cout << "Case #" << t << ": ";
        long long x1, y1, x2, y2;
        

        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        int x, y;
        cin >> x >> y;
       
        /*if (t==78)
        {
                  cout << n << " " << m << endl;
                  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                  cout << x << " " << y << endl;
        }
        */
        x1 <?= n+1;
        x1 >?= -n-1;
        y1 <?= m+1;
        y1 >?= -m-1;
        x2 <?= n+1;
        x2 >?= -n-1;
        y2 <?= m+1;
        y2 >?= -m-1;    
        
        if (x1*y2 - x2*y1 )
        {
            long long res = 0;
            
            if (abs (x1) + abs (y1) < abs (x2) + abs (y2) )
            {
                    swap (x1, x2);
                    swap (y1, y2);
            } 
            
            long long prevc1 = 0;
            long long prevc2 = INF;
            
           // cout << x1 << " " << y1 << endl;
           // cout << x2 << " " << y2 << endl;
            
            while (1)
            {
                  long long c1 = 0;
                  long long c2 = INFLL;
                  
                  pair <long long, long long> s1 = solve (-x, x2, n-x);
                  pair <long long, long long> s2 = solve (-y, y2, m-y);
                  
                  c1 >?= s1.X; c1 >?= s2.X;
                  c2 <?= s1.Y; c2 <?= s2.Y;                  
                //  
                //  cout << x << " "<< y << endl;
                // cout << c1 << " , " << c2 << endl;
                  
                  long long cc1 = max (c1, prevc1);
                  long long cc2 = min (c2, prevc2);
                  
                  if (cc1>cc2)
                      break;
                  res += (c2-c1+1);
                  prevc1 = c1;
                  prevc2 = c2;
                  
                  x += x1;
                  y += y1;
            }
            
            cout << res << endl;
        }
        else
        {
            set <PII> a;
            queue <PII> q;
            
            if (ok(x,y))
            {
                a.insert (PII (x, y));
                q.push (PII (x, y));
            }
            
            while (!q.empty ())
            {
                  
                PII p1 = q.front();
                PII p2 = q.front();
                
                //cout << p1 .X << " " << p1 . Y << endl;  
                
                q.pop ();
                p1.X += x1; p1.Y += y1;      
                p2.X += x2; p2.Y += y2;
                
                if (ok (p1.X, p1.Y) && a.find(p1)==a.end())
                {
                    a.insert (p1);
                    q.push(p1);
                }
                if (ok (p2.X, p2.Y) && a.find(p2)==a.end())
                {
                    a.insert (p2);
                    q.push(p2);
                }
            }
            
            cout << a.size () << endl;
        }
    }

	return 0;
}
