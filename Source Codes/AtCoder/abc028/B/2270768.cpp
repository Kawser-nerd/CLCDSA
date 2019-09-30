#include <iostream>
#include <vector>
#include <string>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(inc, FnumberOFbegin, FnumberOFend) for (int inc = (FnumberOFbegin); (inc) < (FnumberOFend)); (inc)++) //inc?a???b-a?(i?b????)?????
#define REP(inc,RnumberOFend) FOR(inc,0,RnumberOFend)

int main(){

    int a=0, b=0, c=0, d=0, e=0, f=0;
    char tmp;

    while(cin>>tmp){
        if(tmp=='A'){
            a++;
        }else  if('B'==tmp){
            b++;
        }else if('C'==tmp){
            c++;
        }else if('D'==tmp){
            d++;
        }else if('E'==tmp){
            e++;
        }else{
            f++;
        }
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;

    return 0;
}