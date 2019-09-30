#include <string.h>
#include <stdio.h>
int Max(int a,int b){
    return a>b?a:b;
}
int main()
{   int n,m;
    scanf("%d%d",&n,&m);
    char name[n+1],kit[m+1];
    scanf("%s",name);
    scanf("%s",kit);
    int a[26]={0},b[26]={0};
    for(int i=0;i<strlen(name);i++){
        a[name[i]-'A']++;
    }
    for(int i=0;i<strlen(kit);i++){
        b[kit[i]-'A']++;
    }
    int max=0;
    for(int i=0;i<26;i++){
        if(a[i]>0&&b[i]==0){
            printf("-1\n");
            return 0;
        }else if(b[i]>0){
        max=Max(max,(a[i]-1)/b[i]+1);
        }
        
    }
    printf("%d\n",max);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",name);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",kit);
     ^