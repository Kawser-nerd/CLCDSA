#include <stdio.h>
#include <math.h>
int main(){
  FILE *input;
  char line[10000];
  int i,j,k,l,m;
  unsigned long long X,Y;
  int c[100000][2];
  int A,B,C,D,x0,y0,n,M;
  int r,s,t;
  float fx,fy;
  unsigned long long fxi,fyi;
  int nb_k;
  int result;
  input = fopen("A.txt","r");
  fgets(line,10000,input);
  sscanf(line,"%d",&nb_k);
  for (k=1;k<=nb_k;k++){ 
    fgets(line,10000,input);
    sscanf(line,"%d %d %d %d %d %d %d %d",&n,&A,&B,&C,&D,&x0,&y0,&M);
    result = 0;
    X=x0;
    c[0][0]=X;
    Y=y0;
    c[0][1]=Y;
//    printf("P : %d %d\n",c[0][0],c[0][1]);
    for (i=1;i<n;i++){
      X = (A*X+ B)%M;
      Y = (C*Y+ D)%M;      
      c[i][0]=X;
      c[i][1]=Y;
//    printf("P : %d %d\n",c[i][0],c[i][1]);
    }  

    for (r=0;r<n;r++){
      for (s=r+1;s<n;s++){
        for (t=s+1;t<n;t++){
	  if (((c[r][0] != c[s][0])
	  ||(c[r][1]!=c[s][1]))
	  &&((c[r][0]!=c[s][0])
	  ||(c[r][1]!=c[s][1]))
	  &&((c[s][0]!=c[t][0])
	  ||(c[s][1]!=c[t][1]))){
	  fx = (c[r][0]+c[s][0]+c[t][0]);
	  fx /= 3;
	  fxi = fx;
	  fy = (c[r][1]+c[s][1]+c[t][1]);
	  fy /=3;
	  fyi = fy;
	  if ((fyi==fy)&&(fxi==fx)){
//	  printf("%f %f %d %d\n",fx,fy,fxi,fyi);
	    result++;
	  }
	  }
	}
      }
    }
  printf("Case #%d: %d\n",k,result);
  }
  return 0;

}
