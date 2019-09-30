#include <stdio.h>
#include <string.h>

int main( void ){
	int n,i,j,w;
	int s[30000]={0},e[30000]={0};
	char buf[255];

	scanf("%d",&n);
	for( i=0;i<n;i++ ){
		scanf("%s",buf );
		sscanf( buf, "%4d-%4d",&s[i],&e[i]);
		s[i] = s[i]-(s[i]%100)%5;
		if( e[i]%5>0 ){
			e[i] = e[i]+5-(e[i]%100)%5;
			if(e[i]%100>=60) e[i]=(e[i]/100+1)*100;
		}
	}

	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if( s[i]>s[j] ){
				w=s[i];
				s[i]=s[j];
				s[j]=w;
				w=e[i];
				e[i]=e[j];
				e[j]=w;
			}
		}
	}

	printf("%04d-",s[0]);
	w=e[0];
	for(i=1;i<n;i++){
		if( w >= s[i] ){
			if( w < e[i] ) w=e[i];
		}else{
			printf("%04d\n%04d-",w,s[i]);
			w=e[i];
		}
	}
	printf("%04d\n",w);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",buf );
   ^