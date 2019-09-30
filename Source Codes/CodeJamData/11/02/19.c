#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,del;
  int n1,n2;
  char s1[100][10], s2[100][10];
  char in[1000];
  char res[1000]; int res_size;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&n1);
    rep(i,n1) scanf("%s",s1[i]);
    scanf("%d",&n2);
    rep(i,n2) scanf("%s",s2[i]);
    scanf("%d",&n);
    scanf("%s",in);

    res_size=0;

    rep(k,n){
      res[res_size++] = in[k];
      for(;;){
        int fg=0;

        rep(m,n1){
          rep(i,res_size) REP(j,i+1,res_size) if(i+1==j) if(!fg){
            if( (res[i]==s1[m][0]&&res[j]==s1[m][1]) || (res[i]==s1[m][1]&&res[j]==s1[m][0]) ){
              fg=1;
              res[i] = s1[m][2];
              res_size--;
              REP(l,i+1,res_size) res[l] = res[l+1];
            }
          }
        }
        
        rep(m,n2){
          rep(i,res_size) REP(j,i+1,res_size) if(!fg){
            if( (res[i]==s2[m][0]&&res[j]==s2[m][1]) || (res[i]==s2[m][1]&&res[j]==s2[m][0]) ){
              fg=1; res_size=0;
            }
          }
        }
        
        if(!fg) break;
      }
    }

    printf("Case #%d: [",++count);
    rep(i,res_size){
      if(i) printf(", ");
      putchar(res[i]);
    }
    puts("]");
  }


  return 0;
}
