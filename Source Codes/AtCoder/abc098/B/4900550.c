#include <stdio.h>

int main(){
	int N,i,j,k,l,f,Ans[101]={0},maxans;
	scanf("%d",&N);
	char ss[101];
	scanf("%s",ss);
	for(i=0;i<26;i++){
      f=0;
        for(j=0;j<N;j++){
			if(ss[j]=='a'+i && f==0){
              f=1;
              for(k=N-1;k>j;k--){
                if(ss[k]=='a'+i && f==1){
                  f=2;
                  for(l=j;l<=k;l++){
                    Ans[l]++;
                  }
                }
              }
            }
		}
	}

  maxans=Ans[0];
  for(i=1;i<N;i++){
    if(maxans<Ans[i])maxans=Ans[i];
  }
  printf("%d\n",maxans);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",ss);
  ^