#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
long long int N, Ans;
long long int Start[20];
long long int Power10[20];
long long int i, x, y, Digits, Left, Right, Temp, Add;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	
	Power10[0] = 1;
	for (i=1; i<16; i++) Power10[i] = Power10[i-1]*10;
	
	Start[0] = 1;
	Start[1] = 10;
	x = 9; y = 10;
	for (i=2; i<16; i++){
		Start[i] = Start[i-1]+x+y;
		y *= 10;
		i++;
		Start[i] = Start[i-1]+x+y;
		x = y-1;
	}
	
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%lld", &N);
		
		if (N<=20){
			printf("%lld\n", N);
			continue;
		}
		
		Add = 0;
		if ((N%10)==0){
			Add = 1;
			N--;
		}
		
		x = N;
		Digits = 0;
		while(x){
			Digits++;
			x /= 10;
		}
		Ans = N;
		
		for (i=1; i<Digits; i++){
			Left = N / Power10[i];
			Temp = 0;
			while(Left){
				Temp *= 10;
				Temp += (Left%10);
				Left /= 10;
			}
			Left = Temp;
			Right = N % Power10[i];
			
			
			if (Left==1) Left = 0;
			Temp = Left+Right;
			
			if (Temp<Ans) Ans = Temp;
		}
		Ans += Start[Digits-1];
		Ans += Add;
		
		printf("%lld\n", Ans);
		
	}
	
	return 0;
}

