#include<stdio.h>

int queue[3000];
int top=0;
int bottom=0;

int vx[4]={1,0,-1,0};
int vy[4]={0,-1,0,1};

void push(int x){
	queue[bottom]=x;
	bottom++;
}

int pop(){
	if(top>=bottom)return -1;
	return queue[top++];
}

int main(){
	int H,W;
	scanf("%d%d",&H,&W);
	char s[H][W+1];
	for(int i=0;i<H;i++)scanf("%s",s[i]);
	
	int white=0;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(s[i][j]=='.')white++;
	
	int step[H][W];
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)step[i][j]=0;
	
	push(0);
	step[0][0]=1;
	
	while(1){
		int p=pop();
		if(p==-1)break;
		
		int x=p/W;
		int y=p%W;
		
		for(int i=0;i<4;i++){
			int xx=x+vx[i];
			int yy=y+vy[i];
			if(0<=xx && xx<H && 0<=yy && yy<W && s[xx][yy]=='.' && step[xx][yy]==0){
				push(xx*W+yy);
				step[xx][yy]=step[x][y]+1;
			}
		}
		
	}
	
	if(step[H-1][W-1]==0)printf("-1\n");
	else printf("%d\n",white-step[H-1][W-1]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&H,&W);
  ^
./Main.c:24:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<H;i++)scanf("%s",s[i]);
                      ^