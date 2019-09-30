#include <stdio.h>

void sort(int *,int size);

int main(void){
	
	 int N,x,a[100] ,i,count=0;
  
 	 scanf("%d %d",&N,&x);

  	for(i=0;i<N;i++){
    	scanf("%d",&a[i]);
    }
  	sort(a,N);
  
  	for(i=0;i < N && x >= 0;i++){
    	x -= a[i];
      	if(x >= 0){
          count++;
        }
    }
	if(x>0){
		count--;		
	}
	
	printf("%d",count);
  
	return 0;
}

void sort(int *array,int size){
	
	int tmp,i,j;

  	for(i=0;i<size-1;i++){
    	for(j=i+1;j<size;j++){
        	if(array[i] > array[j]){
            	tmp = array[i];
            	array[i] = array[j];
              	array[j] = tmp;
            }
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&N,&x);
    ^
./Main.c:12:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&a[i]);
      ^