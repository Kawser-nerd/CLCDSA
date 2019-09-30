#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define INF 100000000

typedef struct{
	int x;
	int y;
}Pos;
typedef struct{
	int front;
	int rear;
	int size;
	Pos *data;
}Queue;
void init_queue(Queue *q,int s){
	q->data=calloc(s,sizeof(Pos));
	q->front=q->rear=0;
	q->size=s;
	return;
}
void end(Queue *q){
	free(q->data);
	return;
}
void push(Queue *q,int s,int t){
	q->data[q->rear].x=s,q->data[q->rear].y=t;
	q->rear=(q->rear+1)%q->size;
}
Pos pop(Queue *q){
	Pos res=q->data[q->front];
	q->front=(q->front+1)%q->size;
	return res;
}
int isempty(Queue *q){
	return q->front==q->rear;
}
char map[810][810];
int d[810][810];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int sx,sy;
void read(int w,int h,char c){
	int i,j;
	scanf("%*c");
	FOR(i,0,h+2) map[0][i]=c,map[w+1][i]=c;
	FOR(i,0,w+2) map[i][0]=c,map[i][h+1]=c;
	FOR(i,1,h+1){
		FOR(j,1,w+1){
	        scanf("%c",&map[j][i]);
	        if(map[j][i]=='S') sx=j,sy=i,map[j][i]='.';
	    }
        scanf("%*c");
    }
    return; 
}
int main(void){
	int h,w,k,nx,ny,ans=INF,t,i,j;
	Queue que;
	Pos p;
	scanf("%d%d%d",&h,&w,&k);
	FOR(i,1,h+1){
		FOR(j,1,w+1){
			d[j][i]=INF;
		}
	}
	read(w,h,'#');
	init_queue(&que,h*w);
	push(&que,sx,sy);
	d[sx][sy]=0;
	while(!isempty(&que)){
		p=pop(&que);
		FOR(j,0,4){
			nx=p.x+dx[j],ny=p.y+dy[j];
			if(d[nx][ny]==INF&&map[nx][ny]!='#'){
				d[nx][ny]=d[p.x][p.y]+1;
				push(&que,nx,ny);
			}
		}
	}
	FOR(i,1,h+1){
		FOR(j,1,w+1){
			if(d[j][i]>k) continue;
			if(i==1||j==1||i==h||j==w){
				puts("1");
				return 0;
			}
			t=MIN(MIN(i-1,j-1),MIN(h-i,w-j));
			t=(t+k-1)/k+1;
			ans=MIN(ans,t);
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘read’:
./Main.c:46:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%*c");
  ^
./Main.c:51:10: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
          scanf("%c",&map[j][i]);
          ^
./Main.c:54:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%*c");
         ^
./Main.c: In function ‘main’:
./Main.c:62:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&h,&w,&k);
  ^