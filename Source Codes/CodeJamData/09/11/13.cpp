#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

int ans[3000];
int ish[2000][11];
int used[5000];

int solve(int i,int x)
{
    int ans,y;
    ans=0;
    while (x>0)
    {
        ans+=(x%i)*(x%i);
        x/=i;
    }
    return ans;
}

int main()
{
    int i,j,start,l,t,tmp,p,x,b1;
    string ss,s1;
    char s[1000];
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    memset(used,0,sizeof(used));
    for (i=2;i<2000;i++)
    {
        b1=1;
        for (j=2;j<=10;j++)
        {
            x=i;
            while (used[x]!=i*11+j)
            {
                used[x]=i*11+j;
                x=solve(j,x);
            }
            if (x!=1)
            {
                ish[i][j]=0;
            }
            else
            {
                ish[i][j]=1;
            }
        }
    }
    scanf("%d",&t);
    gets(s);
    start=2;
    for (l=0;l<t;l++)
    {
        gets(s);
        ss=s;
        ss=ss+" ";
        tmp=0;
        while (ss!="")
        {
            p=ss.find_first_of(' ');
            s1=ss.substr(0,p);
            ss.erase(0,p+1);
            tmp|=(1<<atoi(s1.c_str()));
        }
        //if (ans[tmp]!=-1)
        //{
        //    printf("Case #%d: %d\n",l+1,ans[tmp];
        //}
        //else
        {
            memset(used,0,sizeof(used));
            for (i=2;;i++)
            {
                b1=1;
                for (j=3;j<=10;j++)
                    if (((1<<j)&tmp)!=0)
                    {
                        x=i;
                        if (x>1000)
                            x=solve(j,x);
                        if (ish[x][j]==0)
                        {
                            b1=0;
                            break;
                        }
                    }
                if (b1==1)
                {
                    printf("Case #%d: %d\n",l+1,i);
                    break;
                }
            }
        }
    }
	return 0;
}

