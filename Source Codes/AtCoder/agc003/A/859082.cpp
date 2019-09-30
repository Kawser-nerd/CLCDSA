#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define INT(x) int x; scanf("%d",&x)
#define INPUT(x) scanf("%d",&x)
#define REP1(x,n) for(int x = 0; x < n; x++)
#define REP2(x,s,e) for(int x = s; x <= e; x++)
#define BR printf("\n")
#define INF 2000000000

//E,W,N,S
int countT[4] = {};
int path[26] = {};

int main(){
    path['E'-'E'] = 0;
    path['W'-'E'] = 1;
    path['N'-'E'] = 2;
    path['S'-'E'] = 3;
    char S[1001];
    cin >> S;
    int len = strlen(S);
    REP1(i,len){
        countT[path[S[i]-'E']]++;
    }
    
    bool B[2];
    B[0] = (countT[0] == 0 && countT[1] != 0)||(countT[1] == 0 && countT[0] != 0);
    B[1] = (countT[2] == 0 && countT[3] != 0)||(countT[3] == 0 && countT[2] != 0);
    if (B[0]||B[1]) {
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;
}