#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int R,C;
string m[20];
int t[17*17*(17*17+1)*(17*17+1)];
void add(int x,int y,int x0,int y0,int x1,int y1,int dist,vi &q){
  int code=((x*C+y)*(17*17+1)+(x0>=0&&y0>=0?x0*C+y0:17*17))*(17*17+1)+(x1>=0&&y1>=0?x1*C+y1:17*17);
  if(t[code]==-1){
    t[code]=dist;
    q.push_back(code);
  }
}
int shoots[17][17][4];
main(){
  int z;cin>>z;
  for(int c=1;c<=z;c++){
    cin>>R>>C;
    FOR(i,R)cin>>m[i];
    memset(t,-1,sizeof(t));
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    FOR(i,R)FOR(j,C)FOR(k,4){
      int x=i,y=j;
      while(x+dx[k]>=0&&x+dx[k]<R&&y+dy[k]>=0&&y+dy[k]<C&&m[x+dx[k]][y+dy[k]]!='#')x+=dx[k],y+=dy[k];
      shoots[i][j][k]=x*C+y;
    }
    cout<<"Case #"<<c<<": ";
    vi q,q2;
    FOR(i,R)FOR(j,C)if(m[i][j]=='O')add(i,j,-1,-1,-1,-1,0,q2);
    int dist=0;
    while(q2.size()){
      swap(q,q2);
      q2.clear();
      FOR(i,q.size()){
        int tmp=q[i],a,b,c;
        c=tmp%(17*17+1);
        tmp/=17*17+1;
        b=tmp%(17*17+1);
        tmp/=17*17+1;
        a=tmp;
        int x,y,x0,y0,x1,y1;
        x=a/C;y=a%C;
        if(m[x][y]=='X'){cout<<dist<<endl;goto hell;}
        if(b<17*17){x0=b/C;y0=b%C;}else x0=y0=-1;
        if(c<17*17){x1=c/C;y1=c%C;}else x1=y1=-1;
//        cout<<x<<","<<y<<" "<<x0<<","<<y0<<" "<<x1<<","<<y1<<" "<<endl;
        FOR(k,4)add(x,y,x0,y0,shoots[x][y][k]/C,shoots[x][y][k]%C,dist,q);
        FOR(k,4)add(x,y,shoots[x][y][k]/C,shoots[x][y][k]%C,x1,y1,dist,q);
        FOR(k,4)FOR(l,4)add(x,y,shoots[x][y][k]/C,shoots[x][y][k]%C,shoots[x][y][l]/C,shoots[x][y][l]%C,dist,q);
      }
      dist++;
      FOR(i,q.size()){
        int tmp=q[i],a,b,c;
        c=tmp%(17*17+1);
        tmp/=17*17+1;
        b=tmp%(17*17+1);
        tmp/=17*17+1;
        a=tmp;
        int x,y,x0,y0,x1,y1;
        x=a/C;y=a%C;
        if(b<17*17){x0=b/C;y0=b%C;}else x0=y0=-1;
        if(c<17*17){x1=c/C;y1=c%C;}else x1=y1=-1;
        if(x==x0&&y==y0&&x1>=0&&y1>=0)add(x1,y1,x0,y0,x1,y1,dist,q2);
        if(x==x1&&y==y1&&x0>=0&&y0>=0)add(x0,y0,x0,y0,x1,y1,dist,q2);
        FOR(k,4)if(x+dx[k]>=0&&x+dx[k]<R&&y+dy[k]>=0&&y+dy[k]<C&&m[x+dx[k]][y+dy[k]]!='#')add(x+dx[k],y+dy[k],x0,y0,x1,y1,dist,q2);
      }
    }
    cout<<"THE CAKE IS A LIE"<<endl;
hell:;    
  }
}
