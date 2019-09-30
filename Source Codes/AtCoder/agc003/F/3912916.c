#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

int inverse(int a){
	return power(a, p - 2);
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int H, W, K, i, j, max_HW;
	scanf("%lld%lld%lld", &H, &W, &K);
	max_HW = max(H, W);
	char **s = (char **)malloc(sizeof(char *) * max_HW);
	for(i = 0; i < max_HW; i++){
		s[i] = (char *)malloc(sizeof(char) * (max_HW + 1));
	}
	for(i = 0; i < H; i++){
		scanf("%s", s[i]);
	}
	if(K == 0){
		printf("1\n");
		return 0;
	}
	int f_yoko = 0, f_tate = 0;
	for(i = 0; i < H; i++){
		if(s[i][0] == '#' && s[i][W - 1] == '#'){
			f_yoko = 1;
		}
	}
	for(j = 0; j < W; j++){
		if(s[0][j] == '#' && s[H - 1][j] == '#'){
			f_tate = 1;
		}
	}
	if(f_yoko == 1 && f_tate == 1){
		printf("1\n");
		return 0;
	}
	if(f_tate == 1){
		char tmp;
		for(i = 0; i < max_HW; i++){
			for(j = 0; j < max_HW; j++){
				if(i < j){
					tmp = s[i][j];
					s[i][j] = s[j][i];
					s[j][i] = tmp;
				}
			}
		}
		H ^= W;
		W ^= H;
		H ^= W;
	}
/*	for(i = 0; i < H; i++){
		for(j = 0; j < W; j++){
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
*/	int x = 0, a = 0, b = 0, c = 0;
	for(i = 0; i < H; i++){
		int x_sub = 0;
		for(j = 0; j < W; j++){
			if(s[i][j] == '#'){
				x_sub++;
			}
		}
		int e = 0;
		for(j = 1; j < W; j++){
			if(s[i][j - 1] == '#' && s[i][j] == '#'){
				e++;
			}
		}
		if(x_sub == W){
			c++;
		}
		else{
/*			if(x_sub == 0){
				int O = 0;
				printf("%lld\n", H % O);
			}
*/			a += x_sub - e;
			if(s[i][0] == '#' && s[i][W - 1] == '#'){
				a -= 2;
				b++;
			}
		}
		x += x_sub;
	}
/*	if(a == 0 && b == 0 && c > 0 && f_yoko == 1 && f_tate == 0){
		int O = 0;
		printf("%lld\n", H % O);
	}
*/
//	printf("(x, a, b, c) = (%lld, %lld, %lld, %lld)\n", x, a, b, c);
	if(f_yoko == 0 && f_tate == 0){
		printf("%lld\n", power(x, K - 1));
	}
	else if(a == 0 && b == 0){
		printf("%lld\n", power(c, K - 1));
	}
	else{
		printf("%lld\n", MOD(MOD((a + b) * power(x, K - 1) + (x - (a + 2 * b + c)) * power(b + c, K - 1)) * inverse(x - (b + c))));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &H, &W, &K);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s[i]);
   ^