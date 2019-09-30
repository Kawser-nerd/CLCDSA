#include<stdio.h>
#include<stdlib.h>

int int_sort( const void * a , const void * b ) {
  if( *( int * )a < *( int * )b ) {
    return -1;
  }
  else
  if( *( int * )a == *( int * )b ) {
    return 0;
  }
  return 1;
}

int main(){
		int n;
		scanf("%d",&n);
		int a[n][2],i,j,mm;
		for(i=0;i<n;i++){
				scanf("%d",&a[i][0]);
				a[i][1]=i+1;
		}
		/*for(i=0;i<n;i++){
				int max=a[i][1];
				mm=i;
				for(j=i;j<n;j++){
						if(max<a[j][1]){
								max=a[j][1];
								mm=j;
						}
				}
				int tmp[2]={a[i][0],a[i][1]};
				a[i][0]=a[mm][0];a[i][1]=a[mm][1];
				a[mm][0]=tmp[0];a[mm][1]=tmp[1];
		}*/
		/*for(i=0;i<n;i++){
				for(j=0;j<n;j++){
						if(a[i][1]>a[j][1]){
								int tmp[2]={a[i][0],a[i][1]};
								a[i][0]=a[j][0];a[i][1]=a[j][1];
								a[j][0]=tmp[0];a[j][1]=tmp[1];	
						}
				}
		}*/
		qsort(a,n,sizeof(int[2]),int_sort);
		for(i=n-1;i>=0;i--)printf("%d\n",a[i][1]);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i][0]);
     ^