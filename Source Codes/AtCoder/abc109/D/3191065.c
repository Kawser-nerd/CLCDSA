#include <stdio.h>
int main(void){
	int h,w;
	scanf("%d%d",&h,&w);
	int b[h];
	for(int i=0;i<h;i++){
		b[i]=0;
	}
	int a[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			scanf("%d",&a[i][j]);
			a[i][j]=a[i][j]%2;
			if(a[i][j])b[i]++;
		}
	}
	int n=0;
	int e,f;
	for(int i=0;i<h;i++){
		e=0;f=-1;
		for(int j=0;j<b[i]/2;j++){
			e=f+1;
			while(a[i][e]%2==0)e++;
			f=e+1;
			while(a[i][f]%2==0)f++;
			n+=f-e;
			for(int k=f;k>e;k--){
				//printf("%d %d %d %d\n",i+1,k+1,i+1,k);
			}
		}
		if(b[i]%2){
			e=f+1;
			while(a[i][e]%2==0)e++;
			n+=w-1-e;
			for(int k=e;k<w-1;k++){
				//printf("%d %d %d %d\n",i+1,k+1,i+1,k);
			}
		}
	}
	int m=0;
	for(int i=0;i<h;i++){
		m+=b[i]%2;
	}
	f=-1;
	for(int i=0;i<m/2;i++){
		e=f+1;
		while(b[e]%2==0)e++;
		f=e+1;
		while(b[f]%2==0)f++;
		n+=f-e;
	}
	
	printf("%d\n",n);
	
	for(int i=0;i<h;i++){
		e=0;f=-1;
		for(int j=0;j<b[i]/2;j++){
			e=f+1;
			while(a[i][e]%2==0)e++;
			f=e+1;
			while(a[i][f]%2==0)f++;
			n+=f-e;
			for(int k=e;k<f;k++){
				printf("%d %d %d %d\n",i+1,k+1,i+1,k+2);
			}
		}
		if(b[i]%2){
			e=f+1;
			while(a[i][e]%2==0)e++;
			n+=w-1-e;
			for(int k=e;k<w-1;k++){
				printf("%d %d %d %d\n",i+1,k+1,i+1,k+2);
			}
		}
	}
	
	f=-1;
	for(int i=0;i<m/2;i++){
		e=f+1;
		while(b[e]%2==0)e++;
		f=e+1;
		while(b[f]%2==0)f++;
		n+=f-e;
		for(int k=f;k>e;k--){
			printf("%d %d %d %d\n",k+1,w,k,w);
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:12:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^