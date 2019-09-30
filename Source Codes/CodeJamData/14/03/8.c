#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define rep(a,b) for(a = 0 ; a < b ; a++)
#define xrep(a,b,c) for(a = b ; a < c ; a++)
#define getMax(a,b) (a>b?a:b)
char map[55][55];

int main(){
	freopen("C-large.in","r",stdin);
	freopen("pc.out","w",stdout);
	int tt,t,m,r,c,i,j;
	scanf("%d",&t);
	xrep(tt,1,t+1){
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",tt);
		if(m == r*c-1){
			rep(i,r){
				rep(j,c){
					if(!i && !j){ printf("c"); }
					else{ printf("*"); }
				}
				puts("");
			}
			continue;
		}
		if(r == 1 || c == 1){
			printf("c");
			xrep(i,1,getMax(r,c)){
				if(c == 1){ puts(""); }
				if(getMax(r,c) - i <= m){ printf("*"); }
				else{ printf("."); }
			}
			printf("\n");
			continue;
		}
		if(r == 2 || c == 2){
			if((m & 1)||(m == r * c - 2)){
				puts("Impossible");
			}
			else{
				if(r == 2){
					for(i=0 ; i<c ; i++){
						if(m){
							m-=2;
							map[0][i]=map[1][i]='*';
						}
						else{
							map[0][i]=map[1][i]='.';
						}
					}
					map[0][c-1]='c';
					map[0][c]=map[1][c]=0;
				}
				else{
					for(i=0 ; i<r ; i++){
						if(m){
							m-=2;
							map[i][0]=map[i][1]='*';
						}
						else{
							map[i][0]=map[i][1]='.';
						}
						map[i][2]=0;
					}
					map[r-1][0]='c';
				}
				rep(i,r){ printf("%s\n",map[i]); }
			}
			continue;
		}
		int empty=r*c-m;
		if(empty<8 && empty!=6 && empty!=4){
			puts("Impossible");
			continue;
		}
		rep(i,r){
			map[i][c]=0;
			rep(j,c){ map[i][j]='*'; }
		}
		if(empty==4){
			map[0][0]='c';
			map[0][1]=map[1][0]=map[1][1]='.';
			rep(i,r){
				printf("%s\n",map[i]);
			}
			continue;
		}
		rep(i,r){
			if(!empty) break;
			if(empty>=3){
				empty-=3;
				map[i][0]=map[i][1]=map[i][2]='.';
			}
			else if(empty==2){
				empty-=2;
				map[i][0]=map[i][1]='.';
			}
			else if(empty==1){
				empty-=1;
				map[i][0]=map[i][1]='.';
				map[i-1][2]='*';
			}
		}
		map[0][0]='c';
		xrep(i,3,c){
			if(!empty) break;
			if(empty==1){
				empty=0;
				map[0][i]=map[1][i]='.';
				map[r-1][i-1]='*';
			}
			rep(j,r){
				if(!empty) break;
				empty--;
				map[j][i]='.';
			}
		}
		rep(i,r){
			printf("%s\n",map[i]);
		}
	}
	return 0;
}




