#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef long long int lli;
 
int memo[1000010] = { 0,0,1 };
double PI = 3.14159265359;
 
int N, A, B, C, D;
vvi graph;
vi flag;
vi flag_length;
 
 
//bool operator< (const pi& lhs, const pi& rhs) { return bool(lhs.first < rhs.first); }
 
//????????????
int cntX[100010], cntY[100010];
//???????????????
int sumX[100010], sumY[100010];
 
int h[100010], w[100010];
 
//combination n+mCn  (n+m)!/(n!*m!)
 
long long int MOD = pow(10,9)+7;
 
//a^(p-2) mod p
 
lli powmod(lli a,lli p,lli m){
    
    if(p == 0)
        return 1;
    if(p == 1)
        return a;
    
    lli tmp = powmod(a,p/2,m);
    tmp%=m;
    tmp*=tmp;
    tmp%=m;
    
    if(p % 2 == 1){
        tmp *= a;
        tmp %= m;
        return tmp;
    }else{
        return tmp;
    }
}

#define MAX_N 1009
lli dp[MAX_N][MAX_N],ncr[MAX_N][MAX_N],dp2[MAX_N],kaijo[MAX_N],dp3[MAX_N][MAX_N];

int main(void){
    // Here your code !
    cin >> N >> A >> B >> C >> D;
    ncr[0][0]=ncr[1][0]=ncr[1][1]=1;
    
    for(int i = 2; i < N+2; i++){
		ncr[i][i]=1;
		ncr[i][0]=1;
		for(int j = 1; j < i; j++ ){
			ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%MOD;
		}
	}
	
	
	kaijo[0] = 1;
	for(int i = 1; i < MAX_N; i++) kaijo[i] = (kaijo[i-1] * i) % MOD;
	
	
	for(int i = 0; i < MAX_N; i++){
	    dp2[i] = powmod(kaijo[i],MOD-2,MOD);
	}
	
	for(int i = 0; i < MAX_N; i++){
	    for(int j = 0; j < MAX_N; j++)
	        dp3[i][j] = powmod( powmod(kaijo[i],j,MOD) ,MOD-2,MOD);
	}
	
	dp[0][0] = 1;
	for(int i = A; i <= B; i++){
    	dp[i-1][0] = 1;
	    for(int j = 0; j <= N; j++){
	        lli tmp = 0;
	        
	        
	        tmp = dp[i-1][j];
	        tmp %= MOD;
	        for(int k = C; k <= D; k++){
	            if(j-i*k < 0) break;
	            
	            lli tmp2 = dp[i-1][j-i*k] % MOD;
	            //tmp2 = tmp2 * ((kaijo[N-j+i*k] * powmod(kaijo[N-j],MOD-2,MOD)) % MOD );
	            tmp2 = tmp2 * ((kaijo[N-j+i*k] * dp2[N-j]) % MOD );
	            tmp2 %= MOD;
	            tmp2 = tmp2 * dp2[k];
	            tmp2 %= MOD;
	            //tmp2 = tmp2 * powmod( powmod(kaijo[i],k,MOD) ,MOD-2,MOD);
	            tmp2 = tmp2 * dp3[i][k];
	            tmp2 %= MOD;
	            tmp += tmp2;
	        }
	        
	        tmp %= MOD;
	        dp[i][j] = tmp;
	    }
	}
	/*
    for(int i = 0; i <= B; i++){
        for(int j = 0; j <= N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    
    cout << dp[B][N] << endl;
}