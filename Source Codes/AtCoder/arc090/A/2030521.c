#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[1000];
    char *tok;
    
    int n;
    int a[100][2];
    int i1,i3,i4;
    
    fgets(str, sizeof(str), stdin);
    tok=strtok(str," ");
    n=strtol(tok,NULL,10);
    //printf("%d\n",n);
    
    fgets(str, sizeof(str), stdin);
    tok=strtok(str," ");
    a[0][0]=strtol(tok,NULL,10);
    for(i1=1;i1<n;i1++){
        tok=strtok(NULL," ");
        a[i1][0]=strtol(tok,NULL,10);
    }
    
    fgets(str, sizeof(str), stdin);
    tok=strtok(str," ");
    a[0][1]=strtol(tok,NULL,10);
    for(i1=1;i1<n;i1++){
        tok=strtok(NULL," ");
        a[i1][1]=strtol(tok,NULL,10);;
    }
    
    i4=a[n-1][1];
    for(i1=0;i1<n;i1++){
        i4+=a[i1][0];
    }
    //printf("%d\n",i4);
    
    i3=i4;
    for(i1=1;i1<n;i1++){
        i4=i4-a[n-i1][0]+a[n-1-i1][1];
        if(i4>i3){
            i3=i4;
        }
    }
    
    
    printf("%d",i3);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(str, sizeof(str), stdin);
     ^
./Main.c:19:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(str, sizeof(str), stdin);
     ^
./Main.c:27:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(str, sizeof(str), stdin);
     ^