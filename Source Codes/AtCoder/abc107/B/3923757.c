#include<stdio.h>
int main(void){
    int h,w,i,j;
    scanf("%d%d\n",&h,&w);
    int a[114][514];
    for(i=0;i<h;i++){
        int check=0;
        for(j=0;j<w+1;j++){
            scanf("%c",&a[i][j]);
            check+=a[i][j];
        }
        if(check>=46*w){h--;i--;}
    }
    for(i=0;i<w;i++){
        int check=0;
        for(j=0;j<h;j++){
            check+=a[j][i];
        }
        if(check>=46*h){for(j=0;j<h;j++){a[j][i]=0;}}
    }
    for(i=0;i<h;i++){
        for(j=0;j<w+1;j++){
            if(a[i][j]!=0){printf("%c",a[i][j]);}
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:19: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
             scanf("%c",&a[i][j]);
                   ^
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d\n",&h,&w);
     ^
./Main.c:9:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c",&a[i][j]);
             ^