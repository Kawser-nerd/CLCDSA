#include <stdio.h>
     
    int main(){
    	int i, n, m, c[100010], a, b, r[100010]={1};
    	scanf("%d %d", &n, &m);
     
    for(i=0;i<n;i++)
    	c[i]=1;
     
    	while(m--){
    		scanf("%d %d", &a, &b);
    		c[--b]++;
    		c[--a]--;
    		r[b]|=r[a];
    		if(c[a]==0)
    			r[a]=0;
    	}
     
    	for(i=m=0;i<n;i++)
    		m+=r[i];
     
    	printf("%d\n", m);
     
    	return 0;
    } ./Main.c: In function ‘main’:
./Main.c:5:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d %d", &n, &m);
      ^
./Main.c:11:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d %d", &a, &b);
       ^