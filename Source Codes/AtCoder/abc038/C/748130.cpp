#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
  int N, i, j, c=1;
  long counter = 1;
  cin >> N;
 
  vector<int> a(N);
 
  for (i=0; i<N; i+=1){
    cin >> a[i];
  }
 
  for (i=1; i<N; i+=1){
    if (a[i] > a[i-1]){
      c +=1;
      counter +=c;
    }
    else{
      c = 1;
      counter +=1;
    }
  }
 
  cout << counter << endl;
 
  return 0;
}