#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
#define ll long long int
ll ans = 0;

bool cheak_753 ( ll num ) {
  bool three = false, five = false, seven = false;
  ll temp = num;
  while ( num != 0 ) {
    ll x = num % 10;
    if ( x == 3 ) three = true;
    else if ( x == 5 ) five = true;
    else if ( x == 7 ) seven = true;
    num /= 10;
  }
  if ( three == true &&  five == true &&  seven == true ) {
    //cout << "?????????" << temp << "???" << endl;
    ++ans;  
  }
  return 0;
}

ll get_sub_753 ( ll upper_limit, ll num ) {
  if ( num > upper_limit ) return 0;
  else {
    cheak_753 ( num );
    ll plus_seven = 10 * num + 7;
    ll plus_five  = 10 * num + 5;
    ll plus_three = 10 * num + 3;
    get_sub_753 ( upper_limit, plus_seven );
    get_sub_753 ( upper_limit, plus_five  );
    get_sub_753 ( upper_limit, plus_three );
    return 0;  
  }  
}
int main(){
  ll n; cin >> n;
  get_sub_753 ( n, 0 );
  cout << ans << endl;
}