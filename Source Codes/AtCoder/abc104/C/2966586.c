#include<stdio.h>

int bit[10]={};

int bitplus(int d){
  int i;
  for(i=0;i<d;i++){
    if(bit[i]==0){
      bit[i]=1;
      i--;
      for(;i>=0;i--) bit[i]=0;
      break;
    }
  }
  if(i==d) return -1;
  else return 0;
}

int main(){
  int d,g;
  scanf("%d%d",&d,&g);
  int p[10],c[10],i,sum[10];
  for(i=0;i<d;i++){
    scanf("%d%d",&p[i],&c[i]);
    sum[i]=(i+1)*100*p[i]+c[i];
  }
  
  int ans=10000,tmpsum,tmpans;
  if(g<sum[d-1]){
    if(g>sum[d-1]-c[d-1]) ans=p[d-1];
    else{
      ans=g/(d*100);
      if(g%(d*100)!=0) ans++;
    }
  }
  
  while(bitplus(d)==0){
    tmpsum=0;
    tmpans=0;
    for(i=0;i<d;i++){
      if(bit[i]==1){
	tmpsum+=sum[i];
	tmpans+=p[i];
      }
    }
    if(g<tmpsum){
      if(ans>tmpans) ans=tmpans;
    }
    else{
      for(i=d-1;i>=0;i--){
	if(bit[i]==0) break;
      }
      if(g>tmpsum+sum[i]) continue;
      else{
	if(g>tmpsum+sum[i]-c[i]) tmpans+=p[i];
	else{
	  tmpans+=(g-tmpsum)/(i+1)/100;
	  if((g-tmpsum)%((i+1)*100)!=0) tmpans++;
	}
      }
    }
    if(tmpans<ans) ans=tmpans;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&d,&g);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&p[i],&c[i]);
     ^