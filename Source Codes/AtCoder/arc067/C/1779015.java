import java.util.*;

class Main {
    static final long MOD=1000000007;
    static long[] fact;
    static long[] invfact;
    static final int N=3000;
    static void initialize() {
	fact = new long[N];
	invfact = new long[N];
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
	    fact[i] = (i * fact[i - 1]) % MOD;
	    invfact[i] = powerMod(fact[i], MOD - 2);
	}
    }
    static long powerMod(long x, long exponent) {
	long prod = 1;
	for (int i = 63; i >= 0; --i) {
	    prod = (prod * prod) % MOD;
	    if ((exponent & 1L << i) != 0) {
		prod = (prod * x) % MOD;
	    }
	}
	return prod;
    }
    static long comb(int x, int y) {
	if (x < 0) {
	    return 0;
	}
	if (y < 0 || y > x) {
	    return 0;
	}
	long r= (fact[x] * powerMod((fact[x - y] * fact[y]) % MOD, MOD - 2)) % MOD;
	return r;
    }
    static long f(int m, int i, int k){
        long t=fact[m]*invfact[m-i*k]%MOD;
        t=t*invfact[k]%MOD;
        return t*powerMod(invfact[i],k)%MOD;
    }
    public static void main(String[] args) {
        initialize();
        Scanner scan = new Scanner(System.in);
        int n=scan.nextInt();
        int a=scan.nextInt();
        int b=scan.nextInt();
        int c=scan.nextInt();
        int d=scan.nextInt();
        long[][]dp=new long[b+2][n+1];
        dp[a][n]=1;
        for(int i=a;i<=b;++i){
            for(int j=0;j<=n;++j){
                dp[i+1][j]=dp[i][j];
                for(int k=c;k<=Math.min(d,j/i);++k){
                    dp[i+1][j-i*k]+=f(j,i,k)*dp[i][j]%MOD;
                    dp[i+1][j-i*k]%=MOD;
                }
            }
        }
        System.out.println(dp[b+1][0]);
    }
}