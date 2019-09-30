// 4??????
// http://abc039.contest.atcoder.jp/tasks/abc039_b

#include <iostream>
using namespace std;

#define MAX_SQUARE_ROOT 178 // 177^4 < 10^9 < 178^4

int accuracy=1; // ???????????????1
int binary_search(int);
int main(void) {
    int v;
    cin >> v;
    int ans=(binary_search(v));
    cout << ans;
    return 0;
}

int binary_search(int v){
    int l=1;
    int r=MAX_SQUARE_ROOT;
    int m=(r+l)/2;
    int m4;
    if(v==1)
        m=1;
    else{
       while(r-m > accuracy || m-l > accuracy){
           m=(r+l)/2;
           m4 = m*m*m*m;
           if(m4 == v)
               break;
           if(m4>v)
               r=m;
           else
               l=m;
       }
    }
    return m;
}