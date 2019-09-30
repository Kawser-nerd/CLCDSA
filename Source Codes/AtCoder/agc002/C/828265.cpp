#include<iostream>
#include<algorithm>

using namespace std;
int n, l, a[108000];
int main(){
  cin >> n >> l;
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  int p = -1;
  for(int i = 0;i < n - 1;i++){
    if(a[i] + a[i+1] >= l)p = i;
  }
  if(p == -1){
    cout << "Impossible" << endl;
    return 0;
  }
  p++;
  cout << "Possible" << endl;
  for(int i = 1;i < p;i++)cout << i << endl;
  for(int i = n-1;i > p;i--)cout << i << endl;
  cout << p << endl;
  return 0;
}