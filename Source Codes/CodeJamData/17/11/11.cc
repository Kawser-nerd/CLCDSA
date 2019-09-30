#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
char C[MAX_N][MAX_N];

void do_case(){
  int m,n; cin >> m >> n;
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      cin >> C[i][j];

  for(int i=0;i<m;i++){
    for(int j=1;j<n;j++)
      if(C[i][j] == '?')
	C[i][j] = C[i][j-1];
    for(int j=n-2;j>=0;j--)
      if(C[i][j] == '?')
	C[i][j] = C[i][j+1];
  }

  for(int i=0;i<n;i++){
    for(int j=1;j<m;j++)
      if(C[j][i] == '?')
	C[j][i] = C[j-1][i];
    for(int j=m-2;j>=0;j--)
      if(C[j][i] == '?')
	C[j][i] = C[j+1][i];
  }

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
      cout << C[i][j];
    cout << endl;
  }
}

int main(){
  int T,C=1; cin >> T;
  while(T--){
    cout << "Case #" << C++ << ":" << endl;
    do_case();
  }
}
