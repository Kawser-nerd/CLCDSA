#include <stdio.h>
int main(void){
    int n;
    scanf("%d\n",&n);
    char ans[n+2],res[n+2];
    for (int i=0; i<n; i++){
        scanf("%s",res);
    }
    ans[n]='\0';
    
    ans[0]='S';
    ans[1]='S';
    for (int i=1; i<n; i++){
        if (i==n-1 && ans[n-1]=='S'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }
        } else if (i==n-1 && ans[n-1]=='W'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }            
        } else {
            if (ans[i]=='S'){
                if (res[i]=='o'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            } else {
                if (res[i]=='x'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            }
        }
    }

    ans[0]='S';
    ans[1]='W';
    for (int i=1; i<n; i++){
        if (i==n-1 && ans[n-1]=='S'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }
        } else if (i==n-1 && ans[n-1]=='W'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }            
        } else {
            if (ans[i]=='S'){
                if (res[i]=='o'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            } else {
                if (res[i]=='x'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            }
        }
    }

    ans[0]='W';
    ans[1]='S';
    for (int i=1; i<n; i++){
        if (i==n-1 && ans[n-1]=='S'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }
        } else if (i==n-1 && ans[n-1]=='W'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }            
        } else {
            if (ans[i]=='S'){
                if (res[i]=='o'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            } else {
                if (res[i]=='x'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            }
        }
    }
    
    ans[0]='W';
    ans[1]='W';
    for (int i=1; i<n; i++){
        if (i==n-1 && ans[n-1]=='S'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }
        } else if (i==n-1 && ans[n-1]=='W'){
            if (res[0]=='o' && res[n-1]=='o'){
                if (ans[n-1]!=ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            } else if (res[0]=='o' && res[n-1]=='x'){
                if (ans[n-1]!=ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else if (res[0]=='x' && res[n-1]=='o'){
                if (ans[n-1]==ans[1] && ans[0]!=ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
                
            } else {
                if (ans[n-1]==ans[1] && ans[0]==ans[n-2]){
                    printf("%s\n",ans);
                    return 0;
                }
            }            
        } else {
            if (ans[i]=='S'){
                if (res[i]=='o'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            } else {
                if (res[i]=='x'){
                    ans[i+1]=ans[i-1];
                } else {
                    if (ans[i-1]=='S'){
                        ans[i+1]='W';
                    } else {
                        ans[i+1]='S';
                    }
                }
            }
        }
    }
    
    printf("-1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",res);
         ^