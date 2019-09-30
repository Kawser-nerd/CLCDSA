#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  int tot,left;
  int R,O,Y,G,B,V,N,Rt,Yt,Bt;
  scanf("%d",&tot);
  for(int i = 1;i<=tot;i++){
    scanf("%d%d%d%d%d%d%d",&N,&R,&O,&Y,&G,&B,&V);
    if((R<G)||(B<O)||(Y<V)){
      printf("Case #%d: IMPOSSIBLE\n",i);
      continue;
    }
    if((Y==V)&&(R==0)&&(G==0)&&(B==0)&&(O==0)){
      printf("Case #%d: ",i);
      for(int j = 0;j<Y;j++)
        printf("YV");
      puts("");
      continue;
    }
    if((B==O)&&(R==0)&&(G==0)&&(Y==0)&&(V==0)){
      printf("Case #%d: ",i);
      for(int j = 0;j<B;j++)
        printf("BR");
      puts("");
      continue;
    }
    if((R==G)&&(Y==0)&&(V==0)&&(B==0)&&(O==0)){
      printf("Case #%d: ",i);
      for(int j = 0;j<R;j++)
        printf("RG");
      puts("");
      continue;
    }
    Rt = R-G;
    Bt = B-O;
    Yt = Y-V;
    if((Rt+Bt<Yt)||(Rt+Yt<Bt)||(Bt+Yt<Rt)){
      printf("Case #%d: IMPOSSIBLE\n",i);
      continue;
    }
    printf("Case #%d: ",i);
    if(Yt>Rt){
      if(Yt>Bt){
        left = Bt+Rt-Yt;
        for(int j = 0;j<left;j++){
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
        }
        for(int j = left;j<Rt;j++){
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
        }
        for(int j = left;j<Bt;j++){
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
        }
      } 
      else{
        left = Yt+Rt-Bt;
        for(int j = 0;j<left;j++){
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
        }
        for(int j = left;j<Rt;j++){
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
        }
        for(int j = left;j<Yt;j++){
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
        }
      }
    }
    else{
      if(Rt>Bt){
        left = Bt+Yt-Rt;
        for(int j = 0;j<left;j++){
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
        }
        for(int j = left;j<Yt;j++){
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
        }
        for(int j = left;j<Bt;j++){
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
        }
      } 
      else{
        left = Yt+Rt-Bt;
        for(int j = 0;j<left;j++){
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
        }
        for(int j = left;j<Rt;j++){
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
          if(G>0){
            for(int k = 0;k<G;k++)
              printf("RG");
            printf("R");
            G = 0;
          }
          else
            printf("R");
        }
        for(int j = left;j<Yt;j++){
          if(O>0){
            for(int k = 0;k<O;k++)
              printf("BO");
            printf("B");
            O = 0;
          }
          else
            printf("B");
          if(V>0){
            for(int k = 0;k<V;k++)
              printf("YV");
            printf("Y");
            V = 0;
          }
          else
            printf("Y");
        }
      }
    }
    printf("\n");
  }
  return 0;
}
