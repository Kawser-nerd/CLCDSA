#include <stdio.h>

int a[3][3],b[2][3],c[3][2],sum=0;

int score(int p){
    int tmp=0,max=0,min=sum;
    if (p==9){
        for (int i=0; i<2; i++){
            for (int j=0; j<3; j++){
                if(a[i][j]==a[i+1][j]){
                    tmp+=b[i][j];
                }    
            }
        }
        for (int i=0; i<3; i++){
            for (int j=0; j<2; j++){
                if(a[i][j]==a[i][j+1]){
                    tmp+=c[i][j];
                }
            }
        }
        return (tmp);
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(a[i][j]==0){
                if(p%2==0){
                    a[i][j]=1;
                    tmp=score(p+1);
                    a[i][j]=0;
                    if (tmp>max){
                        max=tmp;
                    }
                } else {
                    a[i][j]=-1;
                    tmp=score(p+1);
                    a[i][j]=0;
                    if (tmp<min){
                        min=tmp;
                    }
                }
            }
        }
    }
    if (p%2==0){
        return (max);
    } else {
        return (min);
    }
}

int main(void){
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            scanf("%d",&b[i][j]);
            sum+=b[i][j];
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            scanf("%d",&c[i][j]);
            sum+=c[i][j];
        }
    }
    printf("%d\n%d\n",score(0),sum-score(0));
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:55:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&b[i][j]);
             ^
./Main.c:61:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&c[i][j]);
             ^