#include <stdio.h>

int main(){
    int a[2];
	for(int i = 0;i < 2;i++){
		a[i] = 0;
		}
	FILE *fp;
	fp = stdin; 
	fscanf(fp,"%d %d",&a[0],&a[1]);
	
	if(a[1]> a[0]){
	printf("%d\n",a[1]); 
	}else{
	printf("%d\n",a[0]);
	}

    return 0;

 } ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
  fscanf(fp,"%d %d",&a[0],&a[1]);
  ^