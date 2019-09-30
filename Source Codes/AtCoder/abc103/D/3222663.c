#include<stdio.h>

int main(){
	int N,M,ans=0;
	scanf("%d%d",&N,&M);
	int a[M],b[M];
	for(int i=0;i<M;i++)scanf("%d%d",&a[i],&b[i]);
	
	//sort
	int h=M;
	int swapped=0;
	while(h>1 || swapped==1){
		if(h>1)h=h*10/13;
		swapped=0;
		for(int i=0;i<M-h;i++){
			if(b[i]>b[i+h] || (b[i]==b[i+h] && a[i]>a[i+h])){
				int tmp=a[i];
				a[i]=a[i+h];
				a[i+h]=tmp;
				tmp=b[i];
				b[i]=b[i+h];
				b[i+h]=tmp;
				swapped=1;
			}
		}
	}
	
	int remove=-1;
	for(int i=0;i<M;i++){
		if(i<M-1 && b[i]==b[i+1])continue;
		else if(a[i]<=remove && remove<b[i])continue;
		else {
			ans++;
			remove=b[i]-1;
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^
./Main.c:7:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<M;i++)scanf("%d%d",&a[i],&b[i]);
                      ^