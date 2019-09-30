#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

int op(int a, int b, char mode){
	if (mode == '+'){
		return a+b;
	}else{
		return a-b;
	}
}

int getModulo(char * chaine, int l, int mod){
	int i, m;
	if (l>4){
		return (
			getModulo(chaine, l-4, mod) * (10000%mod)+
			getModulo(chaine+l-4, 4, mod)
		) % mod;
	}else{
		m=0;
		for (i=0;i<l;i++){
			m=m*10+chaine[i]-'0';
		}
		return m%mod;
	}
}

int somme(char * chaine, int l, int mod2, int mod3, int mod5, int mod7, char mode){
	int n, somme2;
	int mod2_, mod3_, mod5_, mod7_;

	if (l==0){
		if (mod2==0 || mod3==0 || mod5==0 || mod7==0)
			return 1;
		else
			return 0;
	}
	somme2 = 0;
	for (n=1;n<=l;n++){

		mod2_= op(mod2, getModulo(chaine, n, 2), mode) % 2;
		mod3_= op(mod3, getModulo(chaine, n, 3), mode) % 3;
		mod5_= op(mod5, getModulo(chaine, n, 5), mode) % 5;
		mod7_= op(mod7, getModulo(chaine, n, 7), mode) % 7;
		if (n!=l){
			somme2 += somme(chaine+n, l-n, mod2_, mod3_, mod5_, mod7_,
				'+');		
			somme2 += somme(chaine+n, l-n, mod2_, mod3_, mod5_, mod7_,
				'-');
		}else{
			somme2 += somme(chaine+n, l-n, mod2_, mod3_, mod5_, mod7_,
				'+');
		}
	}
	return somme2;
}

int solve2(char* chaine, int l){
	return somme(chaine, l, 0, 0, 0, 0, '+');
}

void solve(){
	char n[41];
	int s;
	scanf("%s", n);
	s=solve2(n, strlen(n));
	printf("%d", s);
}

int main(){
	int i, n;
	scanf("%d\n", &n);
	for (i=0;i<n;i++){
		printf("Case #%d: ", i+1);
		solve();
		putchar('\n');
	}
}
