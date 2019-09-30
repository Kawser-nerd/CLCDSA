#include <stdio.h>

int m, n, a;
int xx1, xx2, yy1, yy2;

int go(){
	int x1, y1, x2, y2, s;
	scanf("%d%d%d", &n, &m, &a);
	if(m * n < a){
		return 0; 
	}
	for(x1 = 0; x1 <= n; x1++)
		for(y1 = 0; y1 <= m; y1++)
			for(x2 = 0; x2 <= n; x2++)
				for(y2 = 0; y2 <= m; y2++){
					s = x1 * y2 - x2 * y1;
					if(s < 0)
						s = -s;
					if(s == a){
						xx1 = x1;
						xx2 = x2;
						yy1 = y1;
						yy2 = y2;
						return 1;
					}
				}
	return 0;
}

int main(){
	int cs, i;
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &cs);
	for(i = 1; i <= cs; i++){
		printf("Case #%d: ", i);
		if(go()){
			printf("0 0 %d %d %d %d\n", xx1, yy1, xx2, yy2);
		}
		else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}