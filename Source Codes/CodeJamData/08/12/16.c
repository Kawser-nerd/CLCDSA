#include <stdio.h>

int likes[2010][2010];
int ans[2010];
int n,m;

int try (int malted,int start);

int main(){
  int cases,ccases;
  int i,j;
  int temp,type;
  int flag;

  scanf(" %d ", &cases);
  for(ccases=1; ccases<=cases; ccases++){
    for(i=0;i<2010;i++){
      for(j=0; j<2010; j++)
	likes[i][j]=-1;
    }

    scanf(" %d ", &n);
    scanf(" %d ", &m);
    for(i=0; i<m; i++){
      scanf(" %d ", &likes[i][0]);
      for(j=0; j<likes[i][0]; j++){
	scanf(" %d %d ", &temp, &type);
	likes[i][temp] = type;
      }
    }

    flag = 0;
    for(i=0; i<=n; i++){
      for(j=1; j<=n; j++)
	ans[j]=0;

      if(try(i,1)){
	flag = 1;
	break;
      }
    }

    printf("Case #%d: ",ccases);
    if(!flag)
      printf("IMPOSSIBLE\n");
    else{
      for(i=1; i<=n-1; i++)
	printf("%d ",ans[i]);
      printf("%d\n",ans[n]);
    }
  }

  return 0;
}

int try (int malted,int start){
  int i,j;
  int count;

  if(malted==0){
/*     for(i=1;i<=n;i++) */
/*       printf("%d ",ans[i]); */
/*     printf("\n"); */
    count = 0;
    for(i=0; i<m; i++){
      for(j=1;j<=n;j++){
	if(likes[i][j]!=-1){
	  if(likes[i][j]==ans[j]){
	    count++;
	    break;
	  }
	}
      }
    }
    if(count==m)
      return 1;
  }
  else{
    for(i=start; i<=n-malted+1; i++){
      ans[i]=1;
      count=try(malted-1,i+1);
      if(count)
	return 1;
      ans[i]=0;
    }

  }

  return 0;
}
