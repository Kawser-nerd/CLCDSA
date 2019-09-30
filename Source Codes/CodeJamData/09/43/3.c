#include <stdio.h>
long     n,len,m;
typedef struct{
         long a;
         long b;
         long f;
         long pre;
}EDGE;
EDGE     e[600000];
long     ed[555];
void     insert(long x,long y){
         m++;
         e[m].a=x; e[m].b=y; e[m].f=1; e[m].pre=ed[x];
         ed[x]=m;
         m++;
         e[m].a=y; e[m].b=x; e[m].f=0; e[m].pre=ed[y];
         ed[y]=m;
}
void     read(){
         long i,j,k,tmp,fail;
         long x[501][501];
         memset(ed,0,sizeof(ed));
         scanf("%ld%ld",&n,&len);
         m=0;
         for(i=1;i<=n;i++)
             for(j=1;j<=len;j++) 
                scanf("%ld",&x[i][j]);
         for(i=1;i<=n;i++){
             insert(0,i);
             insert(n+i,n+n+1);
             for(j=1;j<=n;j++){
              fail=0;
              for(k=1;k<=len;k++)
               if(x[j][k]<=x[i][k]){
                  fail=1;
                  break;
               }
              if(!fail) insert(i,j+n);
             }
         }
}
long     ans;
long     q[501];
long     dist[501];
long     now[501];
int      opsite(int x){
         if(x&1)    return x+1;
         else       return x-1;
}
int      bfs(){
         long i,F=-1,E=0,u,v;
         for(i=0;i<=n+n+1;i++) dist[i]=-1;
         q[0]=0; dist[0]=0;
         while(F<E){
             u=q[++F];
             for(i=ed[u];i;i=e[i].pre){
                 v=e[i].b;
                 if(dist[v]==-1&&e[i].f){
                      dist[v]=dist[u]+1;
                      q[++E]=v;
                 }
             }
         }
         if(dist[n+n+1]==-1) return 0;
         for(i=0;i<=n+n+1;i++) now[i]=ed[i];
         return 1;
}
int      dfs(long cur){
         long next,i;
         if(cur == n+n+1) return 1;
         for(now[cur];now[cur];now[cur]=e[now[cur]].pre){
             i=now[cur];
             next = e[i].b;
             if(dist[next]==dist[cur]+1 && e[i].f>0){
               if(dfs(next)){
                 e[i].f--;
                 e[opsite(i)].f++;
                 return 1;
               }
             }
         }
         return 0;
}
void     dinic(long zz){
         long tmp;
         ans=0;
         while(bfs())
           while(dfs(0))
             ans++;
         printf("Case #%ld: %ld\n",zz,n-ans);
}
int      main(){
         long T,z;
         freopen("C-large.in","r",stdin);
         freopen("C-large.out","w",stdout);
         scanf("%ld",&T);
         for(T,z=1;T;T--,z++){
          read();
          dinic(z);
         }
         return 0;
}
   
