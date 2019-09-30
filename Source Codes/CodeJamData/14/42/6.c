#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int Numbers;
int N[1200];
int i, x, y, L, R, Ans, MinPos, Mid;

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%d", &Numbers);
		for (i=0; i<Numbers; i++) scanf("%d", &N[i]);
		L = 0;
		R = Numbers-1;
		Ans = 0;
		
		while(L<=R){
			MinPos = L;
			for (i=L+1; i<=R; i++) if (N[i]<N[MinPos]) MinPos = i;
			Mid = (L+R)/2;
			if (MinPos<=Mid){
				for (x=MinPos; x>L; x--){
					N[x] = N[x-1];
					Ans++;
				}
				L++;
			}
			else{
				for (x=MinPos; x<R; x++){
					N[x] = N[x+1];
					Ans++;
				}
				R--;
			}
			
			
		}
		
		printf("%d\n", Ans);
	}
	
	return 0;
}

