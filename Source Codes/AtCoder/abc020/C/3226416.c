#include <stdio.h>

typedef long long ll;

int H,W;
ll T;
int s[15][15];
ll d[10][10][10][10];

ll min(ll a,ll b){
	if(a<b){return a;}
	else{return b;}
}
ll max(ll a,ll b){
	if(a>b){return a;}
	else{return b;}
}

void warshall_floyd(){
	int i,j,k,m,v,w;

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			for(k=0;k<H;k++){
				for(m=0;m<W;m++){
					for(v=0;v<H;v++){
						for(w=0;w<W;w++){
							d[k][m][v][w]=min(d[k][m][v][w],d[k][m][i][j]+d[i][j][v][w]);
						}
					}
				}
			}
		}
	}
}
void init(ll x){

	int i,j,k,m;

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			for(k=0;k<H;k++){
				for(m=0;m<W;m++){
					d[i][j][k][m]=9999999999;
					if(i==k&&j==m){d[i][j][k][m]=0;}
				}
			}
		}
	}
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(i-1>=0){
				if(s[i-1][j]==4){
					d[i][j][i-1][j]=x;
				}
				else{
					d[i][j][i-1][j]=1;
				}
			}
			if(i+1<H){
				if(s[i+1][j]==4){
					d[i][j][i+1][j]=x;
				}
				else{
					d[i][j][i+1][j]=1;
				}
			}
			if(j-1>=0){
				if(s[i][j-1]==4){
					d[i][j][i][j-1]=x;
				}
				else{
					d[i][j][i][j-1]=1;
				}
			}
			if(j+1<W){
				if(s[i][j+1]==4){
					d[i][j][i][j+1]=x;
				}
				else{
					d[i][j][i][j+1]=1;
				}
			}
		}
	}
}

int check(int startx,int starty,int goalx,int goaly){
	warshall_floyd();
	int i,j;

	if(d[starty][startx][goaly][goalx]<=T){return 0;}
	else{return 1;}
}

int main(){


	scanf("%d %d %lld",&H,&W,&T);

	int i,j;

	int startx,starty,goalx,goaly;

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			char c;
			scanf(" %c",&c);
			if (c == '.'){ s[i][j] = 1; }
			else if (c == 'S'){ s[i][j] = 2; startx = j; starty = i; }
			else if (c == 'G'){ s[i][j] = 3; goalx = j; goaly = i; }
			else if (c == '#'){ s[i][j] = 4; }
		}
	}
	ll l=1ll;
	ll r=T;
	ll ans=0ll;
	while(1){
		if(r-l==1){break;}
		ll mid=(l+r)/2ll;
		init(mid);
		if(check(startx,starty,goalx,goaly)==0){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	printf("%lld\n",l);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:99:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %lld",&H,&W,&T);
  ^
./Main.c:108:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %c",&c);
    ^