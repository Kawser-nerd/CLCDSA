#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define loop3(i,j,k,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)
#define loop4(i,j,k,l,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)for(int l=0; l<a; l++)if(i!=l&&j!=l&&k!=l)
#define rep1(i,a) for(int i=1; i<=a; i++)

#define scnd1(a) scanf("%d", &a)
#define scnd2(a,b) scanf("%d%d", &a,&b)
#define scnd3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define scnd4(a,b,c,d) scanf("%d%d%d%d", &a,&b,&c,&d)

#define prtd1(a) printf("%d\n", a)
#define prtd2(a,b) printf("%d %d\n", a,b)
#define prtd3(a,b,c) printf("%d %d %d\n", a,b,c)
#define prtd4(a,b,c,d) printf("%d %d %d %d\n", a,b,c,d)

#define mem(a,n) memset( a, n, sizeof(a))

typedef long long ll;

int main(void){
    int ans = 700;
    
    string s;
    cin >> s;
    
    for ( int i = 0; i < 3; i++ ){
        if ( s[i] == 'o' )ans += 100;
    }
    prtd1(ans);
    
}