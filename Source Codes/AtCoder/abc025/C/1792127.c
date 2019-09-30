#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
}pair;

int **b, **c;
char **a;

pair solve(int rest){
	int i, j;
	pair ans, p;
	ans.a = 0;
	ans.b = 0;
	if(rest == 0){
		for(i = 0; i < 2; i++){
			for(j = 0; j < 3; j++){
				if(a[i][j] == a[i + 1][j]){
					ans.a += b[i][j];
				}
				else{
					ans.b += b[i][j];
				}
			}
		}
		for(i = 0; i < 3; i++){
			for(j = 0; j < 2; j++){
				if(a[i][j] == a[i][j + 1]){
					ans.a += c[i][j];
				}
				else{
					ans.b += c[i][j];
				}
			}
		}
	}
	else if(rest % 2 == 1){
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				if(a[i][j] == '.'){
					a[i][j] = 'o';
					p = solve(rest - 1);
					if(p.a >= ans.a){
						ans = p;
					}
					a[i][j] = '.';
				}
			}
		}
	}
	else{
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				if(a[i][j] == '.'){
					a[i][j] = 'x';
					p = solve(rest - 1);
					if(p.b >= ans.b){
						ans = p;
					}
					a[i][j] = '.';
				}
			}
		}
	}
	return ans;
}

int main(){
	int i, j;
	b = (int **)malloc(sizeof(int *) * 2);
	for(i = 0; i < 2; i++){
		b[i] = (int *)malloc(sizeof(int) * 3);
		for(j = 0; j < 3; j++){
			scanf("%d", &b[i][j]);
		}
	}
	c = (int **)malloc(sizeof(int *) * 3);
	for(i = 0; i < 3; i++){
		c[i] = (int *)malloc(sizeof(int) * 2);
		for(j = 0; j < 2; j++){
			scanf("%d", &c[i][j]);
		}
	}
	a = (char **)malloc(sizeof(char *) * 3);
	for(i = 0; i < 3; i++){
		a[i] = (char *)malloc(sizeof(char) * 3);
		for(j = 0; j < 3; j++){
			a[i][j] = '.';
		}
	}
	pair ans = solve(9);
	printf("%d\n%d\n", ans.a, ans.b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:76:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &b[i][j]);
    ^
./Main.c:83:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &c[i][j]);
    ^