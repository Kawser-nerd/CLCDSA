#include<cstdio>
#include<algorithm>

using namespace std;

int T,i,j,k,I,n,K,l;
const int dx[4]={1,1,0,1};
const int dy[4]={1,-1,1,0};
char map[100][100];

char col(int x,int y){
	if (x>=n || x<0 || y>=n || y<0) return 0;
	else return map[x][y];
}

int main(){
	scanf("%d",&T);
	while (T--){
		printf("Case #%d: ",++I);
		scanf("%d%d",&n,&K);
		for (i=0;i<n;++i)
		    for (j=0;j<n;++j)
				scanf(" %c",&map[i][j]);
		for (i=0;i<n;++i){
		    for (j=n-1,k=n-1;j>=0;--j){
		        for (;k>=0;--k)
		            if (map[i][k]!='.'){
						swap(map[i][k],map[i][j]);
						--k;
						break;
					}
				if (k<0) break;
			}
		}
		bool rwin=false,bwin=false;
		for (i=0;i<n;++i)
			for (j=0;j<n;++j)
			    if (map[i][j]!='.')
			        for (k=0;k<4;++k){
						bool bt=true;
			            for (l=1;l<K;++l)
			                if (col(i+dx[k]*l,j+dy[k]*l)!=map[i][j]){
			                    bt=false;
			                    break;
							}
						if (bt){
						    if (map[i][j]=='R') rwin=true;
						    else bwin=true;
						    break;
						}
					}
		if (rwin)
		    if (bwin) puts("Both");
		    else puts("Red");
		else if (bwin) puts("Blue");
		else puts("Neither");
	}
}
