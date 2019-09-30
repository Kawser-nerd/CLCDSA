
// Headers {{{
#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
using namespace std;
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define CLR(A,v) memset((A),v,sizeof((A)))
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SIZE(x) (int)(x.size())
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef long double LD; 
typedef vector<string> VS;
// }}}

const int max_n = 100; 
int a[max_n]; 

int power(LL u, int n, int P) { 
    LL ret = 1; 
    while (n) { 
        if (n&1) ret = (ret * u) % P; 
        u = (u * u) % P; 
        n /= 2; 
    } 
    return ret; 
} 

bool prime(int aa) { 
    if (aa < 10) return (aa == 2 || aa == 3 || aa == 5 || aa == 7); 
    int b = 2; 
    while (b*b <= aa && aa % b != 0) ++b; 
    return aa %b != 0; 
}

int pr[1000000]; 
int cc; 

void nie_wiem() { 
    puts("I don't know."); 
} 

int main()
{
    int T,D,K; 
    cc = 0; 
    FOR(i,1,1000000) if (prime(i)) pr[cc++] = i;     

    scanf("%d", &T); 
    FOR(tc,1,T) { 
        scanf("%d%d",&D,&K); 
        REP(i,K) scanf("%d", &a[i]); 
        int pw = 1; 
        REP(i,D) pw *= 10; 
        printf("Case #%d: ",tc); 

        if (K == 1) { 
            nie_wiem();             
            continue; 
        } 

        if (K == 2) { 
            if (a[0] == a[1]) printf("%d\n",a[0]); 
            else nie_wiem(); 
            continue; 
        }         

        int okres = -1; 
        REP(i,K) if (okres == -1)  FOR(j,i+1,K-1) 
            if (a[i] == a[j]) { 
                okres = j - i; 
                break; 
            } 

        if (okres != -1) { 
            printf("%d\n",a[K-okres]); 
            continue; 
        } 

        VI ret; 
        int mx = 0; 
        REP(i,K) mx = max(mx, a[i]); 

        REP(i,cc) if (mx < pr[i] && pr[i] < pw) { 
           int P = pr[i]; 
           int L = (P + a[0] - a[1]) % P; 
           int R = (P + a[1] - a[2]) % P; 
           int A = ((LL)power(L,P-2,P) * R) % P; 
           int B = (P + a[1] - ((LL)a[0] * A) % P) % P; 
           int oki = 1; 
           REP(j,K-1) if ( ((LL)a[j] * A + B) % P != a[j+1]) oki = 0; 
           if (oki) { 
               ret.PB(((LL)a[K-1] * A + B) % P); 
           } 
        } 
        sort(ALL(ret)); 
        ret.erase(unique(ALL(ret)), ret.end()); 
        if (SIZE(ret) != 1) { 
            nie_wiem(); 
        } 
        else printf("%d\n",ret[0]); 
    } 

	return 0;
}

