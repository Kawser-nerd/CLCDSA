#include <stdio.h>

int main(void) {
	// your code goes here
	int n,b[100],i,j,s[100];
	scanf("%d",&n);
	for(i=2;i<=n;i++) scanf("%d",&b[i]);
	for(i=n;i>0;i--){
		int x=0,max=0,min=1000000007;
		for(j=i+1;j<=n;j++){
			if(b[j]==i){
				if(max<s[j]) max=s[j];
				if(min>s[j]) min=s[j];
				x++;	
			}
		}
		if(x==0) {
			s[i]=1;
		} else {
			s[i]=max+min+1;
		}
	}
	printf("%d\n",s[1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=2;i<=n;i++) scanf("%d",&b[i]);
                    ^