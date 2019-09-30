#include<stdio.h>
#include<string.h>
int main(){
    char s[3];
    scanf("%s",s);
    if(s[0]=='a'&&s[1]=='b'&&s[2]=='c'){
        printf("Yes\n");
    }
    else if(s[0]=='a'&&s[1]=='c'&&s[2]=='b'){
        printf("Yes\n");
    }
    else if(s[0]=='b'&&s[1]=='a'&&s[2]=='c'){
        printf("Yes\n");
    }
    else if(s[0]=='b'&&s[1]=='c'&&s[2]=='a'){
        printf("Yes\n");
    }
    else if(s[0]=='c'&&s[1]=='a'&&s[2]=='b'){
        printf("Yes\n");
    }
    else if(s[0]=='c'&&s[1]=='b'&&s[2]=='a'){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^