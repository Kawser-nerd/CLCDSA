#include <stdio.h>
int m[10101];
int main(){
	int T,Ti,n,i,a,b,c;
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++){
		scanf("%d",&n);
		a=0;
        c=0;
		scanf("%d",m);
		for(i=1;i<n;i++){
			scanf("%d",m+i);
			if(m[i]<m[i-1]){
                b=m[i-1]-m[i];
                a+=m[i-1]-m[i];
                if(b>c)c=b;
            }
		}
        b=0;
        for(i=0;i<n-1;i++){
            if(c>m[i])b+=m[i];
            else b+=c;
        }
        printf("Case #%d: %d %d\n",Ti,a,b);
	}
    return 0;
}