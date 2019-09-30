#include<stdio.h>
#include<string.h>
void mozi_sort(char str[], int length) {
	int tmp[10000] = {};
	int memo = 0;
	for (int i = 0; i < length; i++) {
		tmp[(int)str[i]]++;
	}
	for (int i = 0; i < 256; i++) {
		while (tmp[i] > 0) {
			str[memo] = (char)i;
			memo++;
			tmp[i]--;
		}
	}
}
//????(?)
long long int small(long long int a, long long int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	long long int n, m, num[2000][2] = {}, result=0;
	char str[200005];
	scanf("%s",str);
  	n = strlen(str);
	mozi_sort(str,n);
  	if(str[0]!='a'){printf("a");return 0;}
	for (int i =1; i < n; i++) {
		if (str[i] == str[i - 1] || (int)str[i] == (int)str[i-1] + 1) {
			continue;
		}
		else {
			printf("%c",(str[i-1]+1));
          return 0;
		}
	}	
  		
  		if(str[n-1]!='z'){printf("%c",(str[n-1]+1));return 0;}
		printf("None");	
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^