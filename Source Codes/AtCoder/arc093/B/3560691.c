#include <stdio.h>
#include <string.h>
int min(int a,int b){return a<b?a:b;}
int main(void){
    int a,b,count=50;
    scanf("%d%d",&b,&a);
    printf("100 100\n");
    char t[120],s[120]="....................................................................................................";
    strcpy(t,s);
    a--;
    while(a>0){
        int p=min(50,a);
        for (int i=0; i<p; i++){
            t[i*2]='#';
        }
        printf("%s\n%s\n",t,s);
        strcpy(t,s);
        a-=50;
        count-=2;
    }
    for (int i=0; i<count; i++){
        printf("%s\n",s);
    }
    
    char v[120],u[120]="####################################################################################################";
    strcpy(v,u);
    b--;
    count=50;
    while(b>0){
        int p=min(50,b);
        for (int i=0; i<p; i++){
            v[i*2]='.';
        }
        printf("%s\n%s\n",u,v);
        strcpy(v,u);
        b-=50;
        count-=2;
    }
    for (int i=0; i<count; i++){
        printf("%s\n",u);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&b,&a);
     ^