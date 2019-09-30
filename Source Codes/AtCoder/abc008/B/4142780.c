#include<stdio.h>
#include<string.h>

int main(){
    int n,max=0,i,j,max_i=0;
    char str[51][51];
    int count[51]={0};

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",&str[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(str[i],str[j])==0){
                count[i]++;
            }
        }
    }
    for(i=0;i<n;i++){
        if(count[i]>max){
            max_i = i;
            max = count[i];
        }
    }
    printf("%s\n",str[max_i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[51]’ [-Wformat=]
         scanf("%s",&str[i]);
               ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",&str[i]);
         ^