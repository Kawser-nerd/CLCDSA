#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#define FOR(i,a,n) for(i=(a);i<(n);i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define MOD 1000000007
#define SIZE 100005
#define LOCAL
#ifdef LOCAL
    #define DEBUG(...) printf(" "__VA_ARGS__)
#else
    #define DEBUG(...)
#endif /* LOCAL */
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

char str[30];
int cnt[26];
int main(void)
{
	int len,i,j;
	scanf("%s",str);
	len=strlen(str);
	FOR(i,0,len) cnt[str[i]-'a']++;
	if(len<26){
		for(i=0;cnt[i];i++);
		str[len]='a'+i;
		puts(str);
		return 0;
	}else{
		for(i=len-1;i>=0;i--){
			for(j=(str[i]-'a');j<26;j++){
				if(!cnt[j]){
					str[i]='a'+j;
					puts(str);
					return 0;
				}
			}
			cnt[str[i]-'a']=0;
			str[i]='\0';
		}
	}
	puts("-1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^