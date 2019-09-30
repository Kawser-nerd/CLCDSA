#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,k,cnt=0,p,box[26]={},box2[26],cnt2=0;
    char s[110],t[110],mini,tmp;
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    strcpy(t,s);
    for(int i=0;i<n;i++){
        box[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        for(int l=0;l<26;l++){
            if(box[l]){
                for(int j=0;j<26;j++){
                    box2[j]=box[j];
                }
                box2[l]--;
                cnt2=0;
                if(s[i]!=l+'a'){
                    cnt2++;
                }
                for(int j=i+1;j<n;j++){
                    if(box2[s[j]-'a']){
                        box2[s[j]-'a']--;
                    }
                    else{
                        cnt2++;
                    }
                }
                if(k>=cnt+cnt2){
                    t[i]=l+'a';
                    box[l]--;
                    if(t[i]!=s[i]){
                        cnt++;
                    }
                    break;
                }
            }
        }
    }
    printf("%s\n",t);
}