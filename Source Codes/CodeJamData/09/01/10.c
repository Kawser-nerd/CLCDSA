#include <stdio.h>
#include <string.h>
long     l,d,n;
char     s[5001][30];
char     ok[5001];
char     x[1000];
void     work(){
         long i,j,len,cur=0;
         int  hash[30]={0};
         int  type=0;
         for(i=1;i<=d;i++) ok[i]=1;
         scanf("%s",x);
         len=strlen(x);
         for(i=0;i<len;i++){
             if(x[i]=='(') type=-1;
             if(x[i]==')'){
               cur++;
               for(j=i-1;x[j]!='(';j--)
                 hash[x[j]-'a']=1;
               for(j=1;j<=d;j++)
                 if( hash[s[j][cur]-'a']==0 )
                  ok[j]=0;
               for(j=i-1;x[j]!='(';j--)
                 hash[x[j]-'a']=0;
               type=0;
               continue;
             }
             if(type==0){
               cur++;
                 hash[x[i]-'a']=1;
               for(j=1;j<=d;j++)
                 if( hash[s[j][cur]-'a']==0 )
                  ok[j]=0;
                 hash[x[i]-'a']=0;

             }
         }                
         cur=0;
         for(i=1;i<=d;i++) if(ok[i])   cur++;
         printf("%ld\n",cur);      
}
int      main(){
         long i;
         freopen("A-large.in","r",stdin);
         freopen("A-large.out","w",stdout);
         scanf("%ld%ld%ld",&l,&d,&n);
         for(i=1;i<=d;i++) scanf("%s",s[i]+1);
         for(i=1;i<=n;i++){printf("Case #%ld: ",i); work();}
         return 0;
}
