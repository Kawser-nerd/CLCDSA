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
                vector<string> inp;
                string s;
                REP(i,4) {cin>>s;inp.pb(s);}
                vector <int> xr(4,0);
                vector <int> xc(4,0);
                vector <int> orr(4,0);
                vector <int> oc(4,0);
                bool game=false;
                REP(i,4)REP(j,4) 
                {
                        if(inp[i][j] == 'X')
                        {
                                xr[i]++;xc[j]++;
                        }
                        else if (inp[i][j] == 'O')
                        {
                                orr[i]++;oc[j]++;
                        }
                        else if (inp[i][j] == 'T')
                        {
                                orr[i]++;oc[j]++;
                                xr[i]++;xc[j]++;
                        }
                        else if (inp[i][j] == '.')
                        {
                                game=true;
                        }
                }

                bool x=false,o=false;
                REP(i,4)
                {
                        if(xr[i] == 4 ||xc[i] == 4)
                                x=true;
                        if(orr[i] == 4 ||oc[i] == 4)
                                o=true;
                }
                //diagonal
                int dx1=0,dx2=0,do1=0,do2=0;
                REP(i,4)
                {
                        if(inp[i][i] =='X' || inp[i][i] == 'T')
                                dx1++;
                        if(inp[i][3-i] =='X' || inp[i][3-i] =='T')
                                dx2++;
                }
                REP(i,4)
                {
                        if(inp[i][i] =='O' || inp[i][i] == 'T')
                                do1++;
                        if(inp[i][3-i] =='O' || inp[i][3-i] =='T')
                                do2++;
                }
                if(dx1 == 4 || dx2 == 4) x=true;
                if(do1 == 4 || do2 == 4) o=true;
                if(x == false && o == false && game == false)
                        cout<<"Draw";
                else if(x == false && o == false && game == true)
                        cout<<"Game has not completed";
                else if(x == true && o == false)
                        cout<<"X won";
                else if(x == false && o == true)
                        cout<<"O won";
                else if(x == true && o == true)
                        cout<<"Draw";
                //Code ends Here
                cout<<endl;
        }
        return 0;
}
