#include <stdio.h>
int main(void){
  int N,M,f_A[10]={},i_A,i,j;
  scanf("%d %d\n%d",&N,&M,&i);
  f_A[i]=1;
  for(i_A=2;i_A<=M;i_A++){
    scanf(" %d",&i);
    f_A[i]=1;
  }
  if(f_A[1]){
    f_A[1]+=N/2;
    switch(N%2){
    case 1:
      if(f_A[7]){f_A[1]--;f_A[7]++;}
      else if(f_A[5]){f_A[1]-=2;f_A[5]++;}
      else if(f_A[3]){f_A[1]-=2;f_A[3]++;}
      else if(f_A[2]){f_A[1]-=2;f_A[2]++;}
      else if(f_A[8]){f_A[1]-=3;f_A[8]++;}
    }
  }else if(f_A[7]){
    f_A[7]+=N/3;
    switch(N%3){
    case 2:
      if(f_A[5]){f_A[7]--;f_A[5]++;}
      else if(f_A[3]){f_A[7]--;f_A[3]++;}
      else if(f_A[2]){f_A[7]--;f_A[2]++;}
      else if(f_A[4]){f_A[7]-=2;f_A[4]+=2;}
      else if(f_A[8]){f_A[7]-=4;f_A[8]+=2;}
      break;
    case 1:
      if(f_A[4]){f_A[7]--;f_A[4]++;}
      else if(f_A[8]){f_A[7]-=2;f_A[8]++;}
      else if(f_A[5]){f_A[7]-=3;f_A[5]+=2;}
      else if(f_A[3]){f_A[7]-=3;f_A[3]+=2;}
      else if(f_A[2]){f_A[7]-=3;f_A[2]+=2;}
    }
  }else if(f_A[4]){
    f_A[4]+=N/4;
    switch(N%4){
    case 3:
      if(f_A[9]&&f_A[5]){f_A[4]-=2;f_A[9]++;f_A[5]++;}
      else if(f_A[9]&&f_A[3]){f_A[4]-=2;f_A[9]++;f_A[3]++;}
      else if(f_A[9]&&f_A[2]){f_A[4]-=2;f_A[9]++;f_A[2]++;}
      else if(f_A[8]){f_A[4]--;f_A[8]++;}
      else if(f_A[6]&&f_A[5]){f_A[4]-=2;f_A[6]++;f_A[5]++;}
      else if(f_A[6]&&f_A[3]){f_A[4]-=2;f_A[6]++;f_A[3]++;}
      else if(f_A[6]&&f_A[2]){f_A[4]-=2;f_A[6]++;f_A[2]++;}
      else if(f_A[5]){f_A[4]-=3;f_A[5]+=3;}
      else if(f_A[3]){f_A[4]-=3;f_A[3]+=3;}
      else if(f_A[2]){f_A[4]-=3;f_A[2]+=3;}
      break;
    case 2:
      if(f_A[9]){f_A[4]--;f_A[9]++;}
      else if(f_A[6]){f_A[4]--;f_A[6]++;}
      else if(f_A[5]){f_A[4]-=2;f_A[5]+=2;}
      else if(f_A[3]){f_A[4]-=2;f_A[3]+=2;}
      else if(f_A[2]){f_A[4]-=2;f_A[2]+=2;}
      else if(f_A[8]){f_A[4]-=3;f_A[8]+=2;}
      break;
    case 1:
      if(f_A[5]){f_A[4]--;f_A[5]++;}
      else if(f_A[3]){f_A[4]--;f_A[3]++;}
      else if(f_A[2]){f_A[4]--;f_A[2]++;}
      else if(f_A[9]&&f_A[8]){f_A[4]-=3;f_A[9]++;f_A[8]++;}
      else if(f_A[8]&&f_A[6]){f_A[4]-=3;f_A[8]++;f_A[6]++;}
      else if(f_A[8]){f_A[4]-=5;f_A[8]+=3;}
    }
  }else if(f_A[5]){
    f_A[5]+=N/5;
    switch(N%5){
    case 4:
      if(f_A[9]){f_A[5]-=4;f_A[9]+=4;}
      else if(f_A[8]){f_A[5]-=2;f_A[8]+=2;}
      else if(f_A[6]){f_A[5]-=4;f_A[6]+=4;}
      break;
    case 3:
      if(f_A[9]){f_A[5]-=3;f_A[9]+=3;}
      else if(f_A[8]&&f_A[6]){f_A[5]-=2;f_A[8]++;f_A[6]++;}
      else if(f_A[6]){f_A[5]-=3;f_A[6]+=3;}
      else if(f_A[8]){f_A[5]-=5;f_A[8]+=4;}
      break;
    case 2:
      if(f_A[9]){f_A[5]-=2;f_A[9]+=2;}
      else if(f_A[8]){f_A[5]--;f_A[8]++;}
      else if(f_A[6]){f_A[5]-=2;f_A[6]+=2;}
      break;
    case 1:
      if(f_A[9]){f_A[5]--;f_A[9]++;}
      else if(f_A[6]){f_A[5]--;f_A[6]++;}
      else if(f_A[8]){f_A[5]-=4;f_A[8]+=3;}
    }
  }else if(f_A[3]){
    f_A[3]+=N/5;
    switch(N%5){
    case 4:
      if(f_A[9]){f_A[3]-=4;f_A[9]+=4;}
      else if(f_A[8]){f_A[3]-=2;f_A[8]+=2;}
      else if(f_A[6]){f_A[3]-=4;f_A[6]+=4;}
      break;
    case 3:
      if(f_A[9]){f_A[3]-=3;f_A[9]+=3;}
      else if(f_A[8]&&f_A[6]){f_A[3]-=2;f_A[8]++;f_A[6]++;}
      else if(f_A[6]){f_A[3]-=3;f_A[6]+=3;}
      else if(f_A[8]){f_A[3]-=5;f_A[8]+=4;}
      break;
    case 2:
      if(f_A[9]){f_A[3]-=2;f_A[9]+=2;}
      else if(f_A[8]){f_A[3]--;f_A[8]++;}
      else if(f_A[6]){f_A[3]-=2;f_A[6]+=2;}
      break;
    case 1:
      if(f_A[9]){f_A[3]--;f_A[9]++;}
      else if(f_A[6]){f_A[3]--;f_A[6]++;}
      else if(f_A[8]){f_A[3]-=4;f_A[8]+=3;}
    }
  }else if(f_A[2]){
    f_A[2]+=N/5;
    switch(N%5){
    case 4:
      if(f_A[9]){f_A[2]-=4;f_A[9]+=4;}
      else if(f_A[8]){f_A[2]-=2;f_A[8]+=2;}
      else if(f_A[6]){f_A[2]-=4;f_A[6]+=4;}
      break;
    case 3:
      if(f_A[9]){f_A[2]-=3;f_A[9]+=3;}
      else if(f_A[8]&&f_A[6]){f_A[2]-=2;f_A[8]++;f_A[6]++;}
      else if(f_A[6]){f_A[2]-=3;f_A[6]+=3;}
      else if(f_A[8]){f_A[2]-=5;f_A[8]+=4;}
      break;
    case 2:
      if(f_A[9]){f_A[2]-=2;f_A[9]+=2;}
      else if(f_A[8]){f_A[2]--;f_A[8]++;}
      else if(f_A[6]){f_A[2]-=2;f_A[6]+=2;}
      break;
    case 1:
      if(f_A[9]){f_A[2]--;f_A[9]++;}
      else if(f_A[6]){f_A[2]--;f_A[6]++;}
      else if(f_A[8]){f_A[2]-=4;f_A[8]+=3;}
    }
  }else if(f_A[9]){
    f_A[9]+=N/6;
    switch(N%6){
    case 5:
      f_A[9]-=5;
      f_A[8]+=5;
      break;
    case 4:
      f_A[9]-=4;
      f_A[8]+=4;
      break;
    case 3:
      f_A[9]-=3;
      f_A[8]+=3;
      break;
    case 2:
      f_A[9]-=2;
      f_A[8]+=2;
      break;
    case 1:
      f_A[9]-=1;
      f_A[8]+=1;
      break;
    }
  }else if(f_A[6]){
    f_A[9]+=N/6;
    switch(N%6){
    case 5:
      f_A[9]-=5;
      f_A[8]+=5;
      break;
    case 4:
      f_A[9]-=4;
      f_A[8]+=4;
      break;
    case 3:
      f_A[9]-=3;
      f_A[8]+=3;
      break;
    case 2:
      f_A[9]-=2;
      f_A[8]+=2;
      break;
    case 1:
      f_A[9]-=1;
      f_A[8]+=1;
      break;
    }
  }else if(f_A[8]){
    f_A[8]+=N/7;
  }
  for(i=9;i>=1;i--)for(j=0;j<f_A[i]-1;j++)printf("%d",i);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n%d",&N,&M,&i);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %d",&i);
     ^