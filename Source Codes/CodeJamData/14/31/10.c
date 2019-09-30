#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long int gcd(long long int a, long long int b){
    if(b == 0){
         return -1;
    }
    while(a%b!=0){
        long long int tmp = a%b;
	a = b;
	b = tmp;
    }
    return b;
}

int main(){
    int T;
    char unuse;
   /*while(1){
	long long int a,b;
    scanf("%I64d %I64d",&a,&b);
    printf("%I64d\n",gcd(a,b));
} */
    scanf("%d",&T);
    scanf("%c",&unuse);

    int i,j;
    for(i = 0; i < T; i++){
        char str[30] = {0};
	scanf("%s",str);
	long long int tmp[2] = {0};
    	long long int p = 0, q = 0;
	int len = strlen(str);
	int index = 0;
	for(j = 0; j < len; j++){
	    if(str[j] == '/'){
	        index++;
	    }
	    else{
	        tmp[index] = tmp[index]*10 + (str[j]-'0');
	    }
	}
	p = tmp[0];
	q = tmp[1];
	//printf("%I64d %I64d\n",p,q);
	scanf("%c",&unuse);

	long long int t = gcd(p,q);
	//printf("t = %I64d",t);
	p/=t;
	q/=t;
	int flag = 0;
	long long int tt = q;
	while(1){
	   // printf("tt = %I64d\n",tt);
	    if(tt == 1) break;
	    if(tt%2 == 0) tt/=2;
	    else{
		flag = 1;
	        break;
	    }
	}
	if(flag == 1){
	    printf("Case #%d: impossible\n",i+1);
	}
	else{
	    int ans = 1;
	    while((double)p/q < 0.5){
	        q/=2;
		ans++;
	    }
	    printf("Case #%d: %d\n",i+1,ans);
	}
    }

    return 0;

}
