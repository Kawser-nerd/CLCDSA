#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

#define REPEAT(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) REPEAT(i,0,n)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define EACH(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
#define mkp make_pair
typedef long long ll;
int main()
{
        int N;
        cin>>N;
        REPEAT(Case,1,N+1){
                cout<<"Case #"<<Case<<": ";
                //Code Starts Here
                int n,m;
                cin>>n>>m;
                int mp[n][m];
                int cmp[n][m];
                REP(i,n)REP(j,m) cin>>mp[i][j];
                REP(i,n)REP(j,m) cmp[i][j]=100;

                vector<int> x(n,0);
                vector<int> y(m,0);

                REP(i,n)
                {
                    REP(j,m)
                    {
                            if(x[i] < mp[i][j])
                                  x[i]=mp[i][j];
                    }
                }

                REP(j,m)
                {
                    REP(i,n)
                    {
                            if(y[j] < mp[i][j])
                                  y[j]=mp[i][j];
                    }
                }
                
                REP(i,n)
                {
                        REP(j,m)
                        {
                                if(x[i] < cmp[i][j])
                                        cmp[i][j]=x[i];
                        }
                }

                REP(j,m)
                {
                        REP(i,n)
                        {
                                if(y[j] < cmp[i][j])
                                        cmp[i][j]=y[j];
                        }
                }

                bool result=true;
                REP(i,n)
                {
                        REP(j,m)
                        {
                                if(cmp[i][j]!=mp[i][j])
                                {
                                        result=false;
                                        break;
                                }
                        }
                        if(!result)break;
                }
                cout<<(result ? "YES" : "NO");
                //Code ends Here
                cout<<endl;
        }
        return 0;
}
