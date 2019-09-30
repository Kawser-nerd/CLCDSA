#include<cstdio>
int T, R, C;
char map[51][51];
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		bool ill = false;
		scanf("%d%d", &R, &C);
		for(int i = 0; i < R; i++)
		    scanf("%s", map[i]);
		for(int i = 0; i < R && !ill; i++){
			for(int j = 0; j < C && !ill; j++)
				if(map[i][j] == '#'){
					if(i == R - 1 || j == C - 1){
						ill = true;
						continue;
					}
					if(map[i][j + 1] != '#' || map[i + 1][j] != '#' || map[i + 1][j + 1] != '#'){
						ill = true;
						continue;
					}
					map[i][j] = map[i + 1][j + 1] = '/';
					map[i + 1][j] = map[i][j + 1] = '\\';
				}
		}
		printf("Case #%d:\n", t);
		if(ill)puts("Impossible");
		else{
			for(int i = 0; i < R; i++)
			    puts(map[i]);
		}
	}
}
