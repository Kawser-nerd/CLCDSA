#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int ans;
long long int num;
int len;
int qq;
int prime[4] = {2,3,5,7};
char str[50];
long long int ati(int a,int b){
	long long int sum = 0,i;
	for(i=a;i<b;i++){
		sum *= 10;
		sum += str[i] - '0';
	}
	return sum;
}
int rec(int now){
	long long int tmp;
	int i;
	if(now > len)
		return 0;
	if(now == len){
		qq++;
		//printf("%d\n",ans);
		for(i=0;i<4;i++){
			if(ans % prime[i] == 0){
				num++;
				//printf("%d\n",ans);
				return 0;
			}
		}
		//printf("%lld\n",ans);
		return 0;
	}
	for(i=now+1;i<=len;i++){
		tmp = ati(now,i);
		ans += tmp;
		rec(i);
		ans -= tmp;
		if(now != 0){
			ans -= tmp;
			rec(i);
			ans += tmp;
		}
	}
	return 0;
}
int main(){
	int t,ca;
	scanf("%d",&ca);
	for(t=0;t<ca;t++){
		scanf("%s",str);
		ans = 0;
		num = 0;qq = 0;
		len = strlen(str);
		rec(0);
		printf("Case #%d: %lld\n",t+1,num);
		//printf("qq = %d\n",qq);
	}
	return 0;
}
