#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=500;
struct ANS {
    int a,b,c,d;
    ANS(int x,int y,int z,int w):a(x),b(y),c(z),d(w) {};
};
vector<ANS> ans;
int r,c;
int val[N+5][N+5];
bool vis[N+5][N+5];
int main() 
{
    scanf("%d%d",&r,&c);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf("%d",&val[i][j]),
            val[i][j]&=1;
    for(int i=0; i<r; i++)
        for(int j=0; j<c-1; j++) 
            if(val[i][j])
                val[i][j+1]^=val[i][j],
                ans.push_back(ANS(i+1,j+1,i+1,j+2)); //????
    for(int i=0; i<r-1; i++)
        if(val[i][c-1])
            val[i+1][c-1]^=val[i][c-1],
            ans.push_back(ANS(i+1,c,i+2,c));
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);
    return 0;
} ./Main.cpp:31:19: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
    printf("%d\n",ans.size());
            ~~    ^~~~~~~~~~
            %lu
1 warning generated.