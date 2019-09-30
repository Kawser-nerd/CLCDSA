#include <stdio.h>

int main()
{   int n,m;
    scanf("%d%d",&n,&m);
    char a[n][n+1],b[m][m+1];
    int k[n][n+1],l[m][m+1];
    for(int i=0;i<n;i++){
        scanf("%s",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%s",&b[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='#'){
                k[i][j]=1;
            }else{
                k[i][j]=0;
            }
            //printf("%d",k[i][j]);
        }
        //printf("\n");
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]=='#'){
                l[i][j]=1;
            }else{
                l[i][j]=0;
            }
             //printf("%d",l[i][j]);
        }
        //printf("\n");
    }
    
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            int check=0;
            for(int x=0;x<m;x++){
                for(int y=0;y<m;y++){
                    if(k[i+x][j+y]==l[x][y]){
                        check++;
                        //printf("check increment at k[%d][%d]",i+x,j+y);
                    }
                }
            }
            if(check==m*m){
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[(sizetype)(n + 1)]’ [-Wformat=]
         scanf("%s",&a[i]);
               ^
./Main.c:12:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[(sizetype)(m + 1)]’ [-Wformat=]
         scanf("%s",&b[i]);
               ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",&a[i]);
         ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",&b[i]);
         ^