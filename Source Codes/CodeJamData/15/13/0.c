#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>

int n;
double p_[3000][2];
struct pt{
  const double*coor;
  double ang;
}p[6000];

int ptcmp(const void*a,const void*b){
  struct pt*c=(struct pt*)a,*d=(struct pt*)b;

  if(c->ang!=d->ang)return (c->ang<d->ang?1:-1);
  return 0;
}

#define CROSS(A,B,C,D) ((A)*(D)-(B)*(C))
#define DOT(A,B,C,D) ((A)*(C)+(B)*(D))
#define DIS(A,B) sqrt(DOT(A,B,A,B))
double computeang(double x,double y,double x0,double y0){
  double s=CROSS(x,y,x0,y0);
  double ang=DOT(x,y,x0,y0)/(DIS(x,y)*DIS(x0,y0));
  if(s<0)ang=-1-ang;
  else ang+=1;
  return ang;
}

void randinput(int n,double(*z)[2]){
  int a,b;
  for(a=0;a<n;a++){
    z[a][0]=(rand()&((1<<16)-1));
    z[a][1]=(rand()&((1<<16)-1));
    for(b=0;b<a;b++){
      if(z[b][0]==z[a][0]&&z[b][1]==z[a][1])break;
    }
    if(b<a){a--;continue;}
  }
}

int main(int argc,char*argv[]){
  int a,b,c,d,e;
  srand(32495);

  scanf("%d",&e);
  for(d=1;d<=e;d++){
    scanf("%d",&n);
    //randinput(n,p_);
    for(a=0;a<n;a++){
      scanf("%lf%lf",p_[a]+0,p_[a]+1);
    }
    printf("Case #%d:\n",d);
    if(n<=3){
      for(a=0;a<n;a++)puts("0");
      continue;
    }
    for(a=0;a<n;a++){
      const double*pa=p_[a];
      c=0;
      for(b=0;b<n;b++){
        if(b==a)continue;
        p[c].coor=p_[b];
        p[c].ang=
        computeang(p_[b][0]-pa[0],p_[b][1]-pa[1],0,1);
        c++;
      }
      qsort(p,c,sizeof(p[0]),ptcmp);
      for(b=0;b<c;b++){
        p[b+c]=p[b];
      }
/*
      for(b=0;b<c;b++){
      printf(" %.2lf %.0lf %.0lf  %.0lf %.0lf\n"
      ,p[b].ang,p_[a][0],p_[a][1],p[b].coor[0],p[b].coor[1]
      );}
*/
      int ans=100000;
      int prev=0,next=0;
      for(b=0;b<c;b++){
        if(b>0){
          if(p[b-1].ang!=p[b].ang)prev=b;
        }
        else{
          prev=0;
        }

        while(next<b+c){
          if(CROSS(
          p[next].coor[0]-pa[0],p[next].coor[1]-pa[1],
          p[b].coor[0]-pa[0],p[b].coor[1]-pa[1])<0)
            break;
          next++;
        }
        if(next==b+c){
          ans=0;
          break;
        }
        assert(next>b&&prev<=b);
        assert(CROSS(
          p[next-1].coor[0]-pa[0],p[next-1].coor[1]-pa[1],
          p[b].coor[0]-pa[0],p[b].coor[1]-pa[1])>=0
        );
        int ans2=n-1-(next-prev);
        if(ans2<ans)ans=ans2;
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}
