#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define POS(i,j) ((i)*m+(j))

typedef struct point2d{
  int x,y;
} point;

point *q=NULL;
int *used=NULL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int reachable(char *b,int n,int m,point s){
  memset(used,0,sizeof(int)*n*m);
  int front=0;
  int last=0;
  q[last++]=s;
  used[POS(s.x,s.y)]=1;
  while(front<last){
    point p=q[front++];
    if(b[POS(p.x,p.y)]=='g') return 1;
    if(b[POS(p.x,p.y)]=='#') continue;
    for(int k=0;k<4;k++){
      int x=p.x+dx[k];
      int y=p.y+dy[k];
      if(0<=x && x<n && 0<=y && y<m && !used[POS(x,y)]){
	used[POS(x,y)]=1;
	q[last++]=(point){x,y};
      }
    }
  }
  return 0;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  char *b=(char *)calloc(n*m+1,sizeof(char));
  int i,j;
  for(i=0;i<n;i++) scanf("%s",b+POS(i,0));
  point s={0,0};
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(b[POS(i,j)]=='s'){
	s=(point){i,j};
	i=j=n+m;
      }
    }
  }
  q=(point *)calloc(n*m,sizeof(point));
  used=(int *)calloc(n*m,sizeof(int));
  if(!reachable(b,n,m,s)){
    printf("-1\n");
    return;
  }
  const int f=2300;
  double *pow=(double *)calloc(f+1,sizeof(double));
  pow[0]=1;
  for(i=1;i<=f;i++) pow[i]=pow[i-1]*0.99;
  double l=0;
  double r=9;
  for(int iter=0;iter<60;iter++){
    double mid=(l+r)/2;
    memset(used,0,sizeof(int)*n*m);
    int front=0;
    int last=0;
    q[last++]=s;
    int timer=0;
    int next=1;
    used[POS(s.x,s.y)]=1;
    int can=0;
    while(front<last){
      if(front==next){
	timer++;
	next=last;
      }
      if(timer>f) break;
      point p=q[front++];
      if(b[POS(p.x,p.y)]=='#') continue;
      if(b[POS(p.x,p.y)]=='g'){
	can=1;
	break;
      }
      if(b[POS(p.x,p.y)]!='s' && (b[POS(p.x,p.y)]-'0')*pow[timer]<mid) continue;
      for(int k=0;k<4;k++){
	int x=p.x+dx[k];
	int y=p.y+dy[k];
	if(0<=x && x<n && 0<=y && y<m && !used[POS(x,y)]){
	  used[POS(x,y)]=1;
	  q[last++]=(point){x,y};
	}
      }
    }
    if(can){
      l=mid;
    } else {
      r=mid;
    }
  }
  printf("%.9lf\n",l);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:42:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%s",b+POS(i,0));
                    ^