import java.util.Scanner;

class Main{
	static int max=100002;	//nCr ? n ?????
	static int MOD=1000000007;
	static long[] fac=new long[max];
	static long[] finv=new long[max];
	static long[] inv=new long[max];
	public static void main(String[] args) {
		COMinit();	//????????
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();

		long kotae=COM(n,1)*COM(k-1,0);
		for(int i=2; i<=Math.min(n, k); i++) {
			kotae+=COM(n,i)*COM(k-1,i-1)%MOD;
			kotae%=MOD;
		}
		System.out.println(kotae);
	}

	static void COMinit() {		//?????????? nCr??????????
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for (int i = 2; i < max; i++){
			fac[i] = fac[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
			finv[i] = finv[i - 1] * inv[i] % MOD;
		}
	}
	static long COM(int n, int k){			//???????
		if (n < k) return 0;
		if (n < 0 || k < 0) return 0;
		return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
	}
}