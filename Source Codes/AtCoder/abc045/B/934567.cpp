#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#define ll long long int
#define ld long double
#define INF 10000
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end
using namespace std;
typedef pair<int, int> P;
int main(){

    vector<char>n1(101,0);
    vector<char>n2(101,0);
    vector<char>n3(101,0);
    vector<char>ex(1);
    ex.erase(ex.begin());
    if(ex.empty())
       // cout << "YES" << endl;
    rep(i,3){
        char temp[100];
        cin >> temp;
        int l =(int)strlen(temp);
        rep(j,l) {if(i == 0) {n1[j] = temp[j];}
        if(i == 1) {n2[j] = temp[j];}
        if(i == 2) {n3[j] = temp[j];}
        }
    }
    char del = n1[0]; int key;
    n1.erase(n1.begin());
    while(true){
        if(del == 'a')
        {
            if(n1[0] == 0)
            {key = 1; break;}
            del = n1[0];
            n1.erase(n1.begin());

                
        }
        if(del == 'b')
        {
            if(n2[0] == 0)
            {key = 2;break;}
            del = n2[0];
            n2.erase(n2.begin());

        }
        if(del == 'c')
        {
            if(n3[0] == 0)
            {key = 3; break;}
            del = n3[0];
            n3.erase(n3.begin());
        }
        
    }
    if(key == 1)
        cout << "A" << endl;
    else if(key == 2)
        cout << "B" << endl;
    else
        cout << "C" << endl;

}