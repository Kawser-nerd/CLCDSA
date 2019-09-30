#include <stdio.h>
#include <math.h>
int is_prime (int nb)
{
  int i, compter, test;
  test = compter = 0;
  for (i = 2; ((i < nb)&&(test!=1)); i++, compter++)
    if (nb % i == 0)
      test = 1;
  if (!test)
    return 1;
  else
    return 0;
}
int main(){
  FILE *input;
  char line[10000];
  int a,b,c,p,i,j,k,l,m,x,y;
  int nb_k;
  int result;
  int intervalle[10000][3];
  int flag[10000];
  input = fopen("B.txt","r");
  fgets(line,10000,input);
  sscanf(line,"%d",&nb_k);
  for (k=1;k<=nb_k;k++){
    fgets(line,10000,input);
    sscanf(line,"%d %d %d",&a,&b,&p);
    c=b-a;
    result = 0;
    for (i=0;i<=c;i++){
      intervalle[i][1] = 1+i;
      intervalle[i][0] = a+i;
      flag[i] = 0;
    }
    for (j=p;j<=p+c;j++){
      x=y=0;
      if (is_prime(j) == 1)
        for (i=0;i<=c;i++){
	  if ((x==0)&&((intervalle[i][0]%j) == 0)){
	    x = intervalle[i][1];
//	    printf("%d : %d ",j,intervalle[i][0]);
	    }
	  else if ((x!=intervalle[i][1])&&((intervalle[i][0]%j) == 0)){
	    y = intervalle[i][1];
//	    printf("%d\n",intervalle[i][0],j);
	    for (i=0;i<=c;i++){
	      if (intervalle[i][1]==y)
  	        intervalle[i][1]=x;
	      }
	    x=y=i=0;
	  }
	}
//	  printf("\n");
    }
    for (i=0;i<=c;i++){
//    printf("%d %d\n",intervalle[i][0],intervalle[i][1]);
      if (flag[intervalle[i][1]] == 0){
        flag[intervalle[i][1]]++;
	result++;
	}
    }
    printf("Case #%d: %d\n",k,result);
  }
  return 0;

}
