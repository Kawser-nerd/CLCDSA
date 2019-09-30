#include <stdio.h>

int check(char s[],int j,int n)
{
    char a[13]="TAKAHASHIKUN\0";
    char b[13]="Takahashikun\0";
    char c[13]="takahashikun\0";
    char d[13]="TAKAHASHIKUN.";
    char e[13]="Takahashikun.";
    char f[13]="takahashikun.";

    int i;
    
    for(i=0;i<13;i++){
        if(s[i]!=a[i]){break;}
        if(i==12){return 1;}
    }
    for(i=0;i<13;i++){
        if(s[i]!=b[i]){break;}
        if(i==12){return 1;}
    }
    for(i=0;i<13;i++){
        if(s[i]!=c[i]){break;}
        if(i==12){return 1;}
    }   

    if(j==n-1){ 
        for(i=0;i<13;i++){
            if(s[i]!=d[i]){break;}
            if(i==12){return 1;}
        }
        for(i=0;i<13;i++){
            if(s[i]!=e[i]){break;}
            if(i==12){return 1;}
        }
        for(i=0;i<13;i++){
            if(s[i]!=f[i]){break;}
            if(i==12){return 1;}
        }
    }
    return 0;
}

int main(){
    int n,cnt=0,i;
    char w[100];

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",w);
        if(check(w,i,n)){cnt++;}
    }

    printf("%d\n",cnt);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:51:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",w);
         ^