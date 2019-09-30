#include<iostream>
using namespace std;


long N,A,B,H,N2;
long X[200000];
long S[20];

void sub(long P1,long P2){
  if (P1+1==P2) return;
  long Q1,Q2;
  Q1=(P1+P2-1)/2;
  Q2=(P1+P2+1)/2;
  X[Q1]=X[P1];
  X[Q2]=X[P1];

  long R1,R2;
  R1=X[P1];R2=X[P2];
  int fix=-1;
  int modify=-1;
  for (int i=0;i<N;i++){
    if ((R1%2!=R2%2)&&(fix==-1)&&(S[i]==0)){
      fix=i;
      X[Q2]=X[Q2]^(1<<fix);

    }else if ((modify==-1)&&(S[i]==0)){
      modify=i;
      X[Q1]=X[Q1]^(1<<modify);
      X[Q2]=X[Q2]^(1<<modify);
    }
    R1>>=1;R2>>=1;
  }
  S[fix]=1;
  sub(P1,Q1);
  sub(Q2,P2);
  S[fix]=0;
  //cout << "TEST" <<fix <<modify <<endl;
}


int main(){

  cin >> N >> A >> B;
  H=0;
  long A2,B2;
  A2=A;B2=B;
  for (int i=0;i<N;i++){
    if (A2%2!=B2%2) H++;
    A2>>=1;B2>>=1;
  }
  if (H%2==0){
    cout << "NO" << endl;
    return 0;
  }
  N2=1<<N;
  for (int i=0;i<N2;i++) X[i]=0;

  for (int i=0;i<N;i++) S[i]=0;


  //cout << H << endl;
  cout << "YES" << endl;
  X[0]=A;
  X[N2-1]=B;
  sub(0,N2-1);
  for (int i=0;i<N2;i++){
    cout << X[i];
    if (i!=N2-1){
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}