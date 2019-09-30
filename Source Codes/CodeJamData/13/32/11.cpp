#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int use[2040],n;
bool check(int N,int S,int E,int W){
    //printf("(%d,%d,%d,%d)\n",N,S,E,W);
    pair<int,int>d[4];
    d[0]=make_pair(N,0);
    d[1]=make_pair(S,1);
    d[2]=make_pair(E,2);
    d[3]=make_pair(W,3);
    sort(d,d+4);
    memset(use,-1,sizeof(use));
    int i;
    for(i=0;i<4;i++){
        int now=min(n,d[i].first);
        while(d[i].first&&now>0){
            if(use[now]!=-1){
                now--;
                continue;
            }
            use[now]=d[i].second;
            d[i].first-=now;
            now=min(now,d[i].first);
        }
        if(d[i].first)return 0;
    }
    putchar(' ');
    for(i=1;i<=n;i++){
        if(use[i]==0)printf("%c",'N');
        else if(use[i]==1)printf("%c",'S');
        else if(use[i]==2)printf("%c",'E');
        else if(use[i]==3)printf("%c",'W');
    }
    puts("");
    return 1;
}
int main(){
    int T,cs=0,k,i,j,x,y;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&x,&y);
        printf("Case #%d:",++cs);
        int need=abs(x)+abs(y);
        for(k=1,i=0;;k++){
            i+=k;
            if(i>=need&&(i-need)%2==0)break;
        }
        n=k;
        int minus=(i-need)/2;
        int N=0,S=0,E=0,W=0;
        if(x>0)E=x;
        else W=-x;
        if(y>0)N=y;
        else S=-y;
        if(!check(N+minus,S+minus,E,W)){
            if(!check(N,S,E+minus,W+minus))fprintf(stderr,"error!");
        }
    }
    return 0;
}
