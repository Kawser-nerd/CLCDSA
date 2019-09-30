#include <iostream>
using namespace std;

int a[100005];
int d[100005];

long long int sumup(long long int n){
	return (n * (n + 1)) / 2;
}

int main(){
  int n;
  cin >> n;
  long long sum=0;
  for(int i=0;i<n;i++){ cin >> a[i]; sum+=a[i];}
  if(sum % sumup(n) != 0){
  	cout << "NO" << endl;
    return 0;
  }
  int t = sum / sumup(n);
  //d[i] denote a[i]-a[i-1];
  for(int i=0;i<n;i++) d[i] = a[(i+n) % n] - a[(i+n-1) % n] - t + 1;
  bool flag = true;
  for(int i=0;i<n;i++){
    if(d[i]>1){flag = false; break;}
    if(d[i]!=1){
      if((1 - d[i]) % n != 0){flag = false; break;}
      int tem = (1 - d[i]) / n;
      if(t < tem){flag = false; break;}
      d[i] = 1;
      t -= tem;
    }
  }
  if(t!=0||!flag) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}