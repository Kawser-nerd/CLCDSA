#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int in_symbolsQ(char *symbols,char c,int sym) {
	int flag=1,i=0;
	while(i<sym && flag) {
		if(symbols[i]==c)
			flag=0;
		i++;
	}
	if(flag)
		return -1;
	else
		return i-1; 
}

unsigned long long int po(int x,int n) {
	int i=n;
	unsigned long long int res=1;	
	while(i>0) {
		res*=x;
		i--;
	}
	return res;
}

unsigned long long int numba(int *sims,int *val,int n,int base) {
	int i=0;
	unsigned long long int res=0;
	for(i=0;i<n;i++)
		res+=val[sims[i]]*po(base,i);
	return res;
}

int main() {
	int T,ca,i,j,k,sym,len;
	int sims[70],val[70];	
	char symbols[70];
	char number[70];	
	scanf("%d ",&T);
	for(ca=1;ca<=T;ca++) {
		scanf("%s ",number);
		len=strlen(number);
		symbols[0]=number[0];
		sims[len-1]=0;
		sym=1;
		for(i=1;i<len;i++) {
			j=in_symbolsQ(symbols,number[i],sym);
			if(j==-1) {
				symbols[sym]=number[i];
				sims[len-i-1]=sym;
				sym++;
			}
			else
				sims[len-i-1]=j;
		}
		val[0]=1;
		val[1]=0;
		for(i=2;i<sym;i++)
			val[i]=i;
		if(sym==1)
			sym=2;
		printf("Case #%d: %lld\n",ca,numba(sims,val,len,sym));
	}	
	return 0;
}
