#include <stdio.h>

void sort(int a[]){
    int i,j,minj=0,tmp;
    int n=5;
    

    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i;j<n-1;j++){
            if(a[j]<a[minj]){
                tmp=a[j];
	            a[j]=a[minj];
                a[minj]=tmp;
	        
            }
        }
    }
}

int main(){
    int a[5],i,x,y;
    
    for(i=0;i<5;i++){scanf("%d",&a[i]);}

    sort(a);
    x=a[0]+a[3]+a[4];
    y=a[1]+a[2]+a[4];

    printf("%d\n",(x>y)?x:y);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<5;i++){scanf("%d",&a[i]);}
                      ^