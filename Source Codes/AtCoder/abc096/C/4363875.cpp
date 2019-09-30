#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    int h,w;
    string board[60];

    cin>>h>>w;
    for(int i=0;i<h;i++){
        cin>>board[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(board[i][j]=='#'){
                
                if((board[i-1][j]=='.' && i-1>=0) && (board[i+1][j]=='.' && i+1<h)
                &&(board[i][j-1]=='.' && j-1>=0)&& (board[i][j+1]=='.' && j+1<w )){
                    cout<<"No"<<endl;
                    return 0;
                    


                }
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}