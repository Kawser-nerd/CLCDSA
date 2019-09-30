#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define ll long long int
bool a[100];

int main(){
  int n,l;
  cin >> n >> l;
  vector < string > s(n); 
  for ( int i = 0; i < n; ++ i ) cin >> s[i];

  for ( int i = 0; i < n; ++i ) {
    int temp = 0;
    for ( int k = 0; k < n; ++k ){
      if ( a[k] == false ) {
        temp = k;  
        break;
      }
    }
    for ( int j = 0; j < n; ++j ){
      if( s[j] < s[temp] && a[j] == false && a[temp] == false){
        temp = j;
      }
    }
    a[temp] = true;
    cout << s[temp] ;
    //cout << "--------" << endl;
    //cout << "i = " << i << endl;
    //cout << "temp = " << temp << endl;

  }
  cout << endl;
  return 0;
}