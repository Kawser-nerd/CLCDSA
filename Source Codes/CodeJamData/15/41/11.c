#include <stdio.h>

char p[100][101];
int rl[100][2];
int cl[100][2];

int main(){
	int T,R,C;
	int ans;
	int i,j,t;
	char buf[128];
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d %d",&R,&C);
		for(i=0;i<R;i++){
			scanf("%s",p[i]);
			rl[i][0] = 100;
			rl[i][1] = -1;
			for(j=0;j<C;j++){
				if(p[i][j] != '.'){
					if(rl[i][0] > j) rl[i][0] = j;
					rl[i][1] = j;
				}
			}
		}
		for(i=0;i<C;i++){
			cl[i][0] = 100;
			cl[i][1] = -1;
			for(j=0;j<R;j++){
				if(p[j][i] != '.'){
					if(cl[i][0] > j) cl[i][0] = j;
					cl[i][1] = j;
				}
			}
		}
		ans = 0;
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				if(p[i][j]=='.') continue;
				if(cl[j][0] == cl[j][1] && rl[i][0] == rl[i][1]) goto Impossible;
				switch(p[i][j]){
					case '^':
						if(cl[j][0] == i) ans++;
						break;
					case 'v':
						if(cl[j][1] == i) ans++;
						break;
					case '<':
						if(rl[i][0] == j) ans++;
						break;
					case '>':
						if(rl[i][1] == j) ans++;
						break;
				}
			}
		}

		printf("Case #%d: %d\n", t, ans);
		continue;

Impossible:
		printf("Case #%d: IMPOSSIBLE\n", t);
	}
	return 0;
}


