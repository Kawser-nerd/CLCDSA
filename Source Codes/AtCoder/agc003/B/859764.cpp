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

typedef long long ll;

ll rec(int A[],int N){
    int B[100000] = {};
    REP1(i,N){
        B[i] = A[i];
    }
    //????????????????????????
    ll max1 = 0,max2 = 0;
    REP1(i,N){
        if(A[i] != 0){
            if(i != 0){//???????
                if (A[i-1] != 0) {
                    A[i]--;
                    max1++;
                }
            }
            
            if(0 < A[i]){//?????
                max1 += A[i]/2;
                A[i] -= (A[i]/2)*2;
            }
            
        }
    }
    
    REP1(i,N){
        if(B[i] != 0){
            B[i]--;
            break;
        }
    }
    
    REP1(i,N){
        if(B[i] != 0){
            if(i != 0){//???????
                if (B[i-1] != 0) {
                    B[i]--;
                    max2++;
                }
            }
            
            if(0 < B[i]){//?????
                max2 += B[i]/2;
                B[i] -= (B[i]/2)*2;
            }
            
        }
    }
    
    return max(max1,max2);
}

int main(){
    INT(N);
    int A[100000] = {};
    REP1(i,N){
        INT(v);
        A[i] = v;
    }
    cout << rec(A,N) << endl;
    return 0;
}