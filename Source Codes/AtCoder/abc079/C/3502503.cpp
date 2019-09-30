#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
    string str;
    int A,B,C,D;
    cin >> str;
    A = stoi(str) / 1000;
    B = stoi(str) / 100 % 10;
    C = stoi(str) / 10 % 10;
    D = stoi(str) % 10;

 
    REP(i,8){
        int tmp = A;
        char op1,op2,op3;
        if(i & 1){
            tmp += B;
            op1 = '+';
        }else{
            tmp -= B;
            op1 = '-';
        }
        if(i & 2){
            tmp += C;
            op2 = '+';
        }else{
            tmp -= C;
            op2 = '-';
        }
        if(i & 4){
            tmp += D;
            op3 = '+';
        }else{
            tmp -= D;
            op3 = '-';
        }
        if(tmp == 7){
            cout << A << op1 << B << op2 << C << op3 << D << "=7" << endl;
            return 0;
        }
    }
}