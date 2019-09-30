#include<iostream>
using namespace std;

long N;
long C[200020];
long A[200020];
long X[200020];
int main(){
  cin >> N;
  for (int i=1;i<=N;i++)cin >> C[i];
  for (int i=0;i<200020;i++)X[i]=-1;
  A[0]=1;
  for (int i=1;i<=N;i++){
    if (X[C[i]]!=-1 && X[C[i]]!=i-1){A[i]=A[X[C[i]]]+A[i-1];}
    else {A[i]=A[i-1];}
    A[i]%=1000000007;
    X[C[i]]=i;
  }
  cout << A[N] << endl;
}