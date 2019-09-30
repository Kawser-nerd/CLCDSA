#include <stdio.h>
long     change(long x,long base){
         long   tmp=0;
         while(x>0){
               tmp += (x%base)*(x%base);
               x   /= base;
         }
         return tmp;         
}
int      ok[11][1001]={0};
void     prepare(long base){
         long i,j,x;
         ok[base][1]=1;
         for(i=2;i<=1000;i++){
             x=i;
             for(j=1;j<=1000;j++){
                 x=change(x,base);
                 if(x==1) break;
             }
             if(x==1){
              x=i;
              for(j=1;j<=1000;j++){
                  ok[base][x]=1;
                  x=change(x,base);
                  if(x==1) break;
              }
             }
         }
}
int      main(){
         long T;
         long i,j,k,x;
         long base[10],flag;
         freopen("A-large.in","r",stdin);
         freopen("A-large.out","w",stdout);
         char buf;
         for(i=2;i<=10;i++) prepare(i);
         scanf("%ld",&T);        
         for(T,k=1;T;T--,k++){
          base[0]=0;
          while(1){
                  scanf("%ld",&base[++base[0]]);
                  scanf("%c",&buf);
                  if(buf=='\n') break;
          }
          for(i=2;;i++){
                  flag=1;
                  for(j=1;j<=base[0];j++) if(ok[base[j]][change(i,base[j])]==0) {flag=0; break;}                  
                  if(flag) {printf("Case #%ld: %ld\n",k,i); break;}
          }
         }return 0;
}
