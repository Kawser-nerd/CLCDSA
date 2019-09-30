#include<stdio.h>

int main(void)
{
        int n,i,j,mojisu[100],k;
        char w[100][11];

        scanf("%d",&n);
        for(i=0;i<n;i++)
                scanf("%s",w[i]);


        for(i=0;w[n-1][i]!='\0';i++);
        mojisu[n-1] = i;

        for(i=1;i<n;i++){
                for(j=0;w[i-1][j]!='\0';j++);
                if(w[i-1][j-1]!=w[i][0]){
                        printf("No\n");
                        return 0;
                }
                mojisu[i-1] = j;
        }

        for(i=0;i<n-1;i++){
                for(j=i+1;j<n;j++){
                        if(mojisu[i]==mojisu[j]){
                                k=0;
                                while(w[i][k]!='\0'){
                                        if(w[i][k]!=w[j][k])
                                                break;
                                        k++;
                                }
                                if(k==mojisu[i]){
                                        printf("No\n");
                                        return 0;
                                }
                        }
                }
        }

        printf("Yes\n");
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&n);
         ^
./Main.c:10:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%s",w[i]);
                 ^