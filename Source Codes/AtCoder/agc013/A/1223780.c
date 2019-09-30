#include <stdio.h>
int handan(int saki, int ato, int genzai)
{
	int X;		
		
	if(saki<ato){
		X=1;
	}else if(saki>ato){
		X=2;
	}else{
		X=genzai;
	}
	
	return X;
}
int main(void)
{
	int N;
	int a[100000];
	int i,num=1;
	int zougen,genzai;
	
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	N--;
	for(i=0;i<N;i++){
		if(a[i]<a[i+1]){
			genzai=1;
			break;
		}else if(a[i]>a[i+1]){
			genzai=2;
			break;
		}
	}
	for(i=i+1;i<N;i++){
		zougen=handan(a[i],a[i+1],genzai);
		if(zougen!=genzai&&genzai!=0){
			num++;
			genzai=0;
		}else{
			genzai=zougen;
		}
	}	
	printf("%d",num);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^