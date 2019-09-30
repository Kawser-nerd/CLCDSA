#include <stdio.h>
#include <stdint.h>
int m[1010];
int main(){
	int Ti,T,n,B,i;
    uint64_t a,b,c,j,jj;
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++){
        scanf("%d %d\n",&B,&n);
        for(i=0;i<B;i++)scanf("%d",m+i);
        a=0;
        b=n*100000ul;
        while(a<b){//printf(".");
            c=(a+b)>>1;
            j=0;
            for(i=0;i<B;i++)j+=1+c/m[i];
            if(j<n)a=c+1;
            else b=c-1;
        }
        j=0;
        for(i=0;i<B;i++)j+=1+a/m[i];
        //printf("%d %d %d\n",a,b,j);
        /*if(j>n)printf("+");
        else */
        while(j>=n){
            //printf("-"),
            a--;
            j=0;
            for(i=0;i<B;i++)j+=1+a/m[i];
        }
        while(j<n){
            //printf("-"),
            a++;
            j=0;
            for(i=0;i<B;i++)j+=1+a/m[i];
        }
        //else printf(".");
        for(i=B;i>0;i--){
            //printf("%d %d\n",a/m[i-1],(a-1)/m[i-1]);
            if(a/m[i-1]>(a-1)/m[i-1])--j;
            if(j+1==n)break;
        }
        if(a>0)printf("Case #%d: %d\n",Ti,i);
		else printf("Case #%d: %d\n",Ti,n);
	}
	return 0;
}
