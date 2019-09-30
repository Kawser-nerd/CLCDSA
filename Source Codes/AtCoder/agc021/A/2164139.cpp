# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <cmath>
# include <algorithm>
using namespace std;
# define lowbit(x) ((x)&(-x))
# define pi acos(-1.0)
# define eps 1e-3
# define MOD 100000007
# define INF 1000000000
# define mem(a,b) memset(a,b,sizeof(a))
# define FOR(i,a,n) for(int i=a; i<=n; ++i)
# define FDR(i,a,n) for(int i=a; i>=n; --i)
# define bug puts("H");
# define lch p<<1,l,mid
# define rch p<<1|1,mid+1,r
# define mp make_pair
# define pb push_back
typedef pair<int,int> PII;
typedef vector<int> VI;
# pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long LL;
const int N=100005;
//Code begin...
inline int Scan() {
    int x=0;int f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}


int main()
{
    char s[20];
    scanf("%s", s);
    bool flag = true;
    for (int i = 1; i < strlen(s); ++i) {
        if (s[i] != '9') {
            flag = false;
            break;
        }
    }
    if (flag) printf("%d\n", s[0] - '0' + (strlen(s) - 1) * 9);
    else printf("%d\n", s[0] - '1' + (strlen(s) - 1) * 9);
    return 0;
} ./Main.cpp:51:30: warning: format specifies type 'int' but the argument has type 'unsigned long' [-Wformat]
    if (flag) printf("%d\n", s[0] - '0' + (strlen(s) - 1) * 9);
                      ~~     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      %lu
./Main.cpp:52:25: warning: format specifies type 'int' but the argument has type 'unsigned long' [-Wformat]
    else printf("%d\n", s[0] - '1' + (strlen(s) - 1) * 9);
                 ~~     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                 %lu
2 warnings generated.