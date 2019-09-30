#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
  int card[]={1,2,3,4,5,6};
  int N;
  cin >> N;

  N = N % 30;
  REP(i,N)
    swap(card[i%5],card[i%5+1]);

  REP(i,6)
    cout << card[i];
  cout << endl;
}