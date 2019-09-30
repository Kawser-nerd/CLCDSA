#include<stdio.h>
#include<string.h>
#include<stdio.h>

int main(){
  int tot,N,Pre;
  int Q[2];
  char which[4];
  char Bishop[204][2];
  char Rook[104][2];
  char Bishopput[104][104];
  char Rookput[104][104];
  int Bishopf[200][2];
  int Rookf[100][2];
  int Queenf[100][2];
  int bcnt,rcnt,qcnt,cnt;
  scanf("%d",&tot);
  for(int i = 1;i<=tot;i++){
    bcnt = 0;
    rcnt = 0;
    qcnt = 0;
    cnt = 0;
    scanf("%d%d",&N,&Pre);
    memset(Bishop,'0',408);
    memset(Rook,'0',208);
    memset(Bishopput,'0',10816);
    memset(Rookput,'0',10816);
    for(int j = 0;j<Pre;j++){
      scanf("%s",which);
      scanf("%d%d",&Q[0],&Q[1]);
      if(which[0]=='+'||which[0]=='o'){
        Bishop[Q[0]+Q[1]][0] = '1';
        Bishop[Q[0]-Q[1]+N][1] = '1';
        Bishopput[Q[0]][Q[1]] = '3';
      }
      if(which[0]=='x'||which[0]=='o'){
        Rook[Q[0]][0] = '1';
        Rook[Q[1]][1] = '1';
        Rookput[Q[0]][Q[1]] = '3';
      }
    }
    for(int a = N,k = 1;a>=k;a--,k++){
      for(int j = k;j<=a;j++){
        if(Bishop[k+j][0]=='0'){
          if(Bishop[k-j+N][1]=='0'){
            Bishopput[k][j] = '2';
            Bishop[j+k][0] = '1';
            Bishop[k-j+N][1] = '1';
          }
        }
        if(Bishop[a+j][0]=='0'){
          if(Bishop[a-j+N][1]=='0'){
            Bishopput[a][j] = '2';
            Bishop[a+j][0] = '1';
            Bishop[a-j+N][1] = '1';
          }
        }
      }
    }
    for(int j = 1;j<=N;j++){
      for(int k = 1;k<=N;k++){
        if(Rook[j][0]=='0'&&Rook[k][1]=='0'){
          Rookput[j][k] = '2';
          Rook[j][0] = '1';
          Rook[k][1] = '1';
        }
      }
    }
    for(int j = 1;j<=N;j++){
      for(int k = 1;k<=N;k++){
        if(Rookput[j][k]=='2'&&Bishopput[j][k]>='2'){
          Queenf[qcnt][0] = j;
          Queenf[qcnt][1] = k;
          qcnt++;
        }
        else if(Rookput[j][k]=='3'&&Bishopput[j][k]=='3')
          cnt+=2;
        else if(Rookput[j][k]=='3'&&Bishopput[j][k]=='2'){
          Queenf[qcnt][0] = j;
          Queenf[qcnt][1] = k;
          qcnt++;
        }
        else if(Rookput[j][k]=='2'){
          Rookf[rcnt][0] = j;
          Rookf[rcnt][1] = k;
          rcnt++;
        }
        else if(Bishopput[j][k]=='2'){
          Bishopf[bcnt][0] = j;
          Bishopf[bcnt][1] = k;
          bcnt++;
        }
        else if(Rookput[j][k]=='3'||Bishopput[j][k]=='3')
          cnt+=1;
      }
    }
    printf("Case #%d: %d %d\n",i,cnt+rcnt+bcnt+2*qcnt,rcnt+bcnt+qcnt);
    for(int j = 0;j<qcnt;j++)
      printf("o %d %d\n",Queenf[j][0],Queenf[j][1]);
    for(int j = 0;j<bcnt;j++)
      printf("+ %d %d\n",Bishopf[j][0],Bishopf[j][1]);
    for(int j = 0;j<rcnt;j++)
      printf("x %d %d\n",Rookf[j][0],Rookf[j][1]);
  }
  return 0;
}
