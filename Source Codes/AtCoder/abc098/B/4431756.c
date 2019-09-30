#include <stdio.h>

int main(void){
    
    int n,max,count;
    max=0;
    scanf("%d",&n);
    
    char s[n+1];
    scanf("%s",s);
    
    for(int i=0; i<n; i++){
        count=0;
        int a[26]={};
        
        for(int j=0; j<i; j++)
            a[s[j]-'a']=1;
        
        for(int j=i; j<n; j++){
            if(a[s[j]-'a']==1){
                count++;
                a[s[j]-'a']=0;
            }
        }
        if(max<count)
            max=count;
    }
    printf("%d",max);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^