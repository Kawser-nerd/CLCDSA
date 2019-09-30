using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class TEST{
	static void Main(){
		Sol mySol =new Sol();
		mySol.Solve();
	}
}

class Sol{
	public void Solve(){
		
		long[] fact = new long[1010];
		long[] ifact = new long[1010];
		fact[0] = ifact[0] = 1;
		for(int i=1;i<=1000;i++){
			fact[i] = (long) i * fact[i-1];
			fact[i] %= mod;
			ifact[i] = ModInv(fact[i]);
		}
		
		long[][] nCr = new long[N+1][];
		for(int i=0;i<=N;i++) nCr[i] = new long[N+1];
		nCr[0][0] = 1;
		for(int i=1;i<=N;i++){
			nCr[i][0] = 1;
			for(int j=1;j<=i;j++){
				nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j]; if(nCr[i][j] >= mod) nCr[i][j] -= mod;
			}
		
		}
		
		
		
		long[][] dp = new long[B+1][];
		for(int i=0;i<=B;i++){
			dp[i] = new long[N+1];
		}
		
		dp[0][0] = 1;
		
		for(int i=0;i<N;i++){
			long sum = dp[0][i];
			for(int j=1;j<=B;j++){
				if(j >= A){
					for(int k=C;k<=D;k++){
						if(i + k * j > N) break;
						// comb = (rest) C (k * j) * (k * j) ! / (j!)^k / k!
						long comb = nCr[N - i][k * j];
						comb *= fact[k * j]; if(comb >= mod) comb %= mod;
						comb *= ModPow(ifact[j],k); if(comb >= mod) comb %= mod;
						comb *= ifact[k]; if(comb >= mod) comb %= mod;
						dp[j][i + k * j] += sum * comb; if(dp[j][i + k * j] >= mod) dp[j][i + k * j] %= mod;
					}
				}
				sum += dp[j][i]; if(sum >= mod) sum -= mod;
			}
		}
		
		long ans = 0;
		for(int j=A;j<=B;j++){
			ans += dp[j][N]; if(ans >= mod) ans -= mod;
		}
		Console.WriteLine(ans);
		
		
	}
	
	const long mod = (long) 1e9 + 7;
	
	long ModInv(long x){
		return ModPow(x, mod - 2);
	}
	long ModPow(long x, long n){
		if(n == 0) return 1;
		if(x == 0) return 0;
		if(x == 1) return 1;
		long ret = 1;
		long v = x;
		while(n > 0){
			if((n & 1) == 1) { ret *= v; ret %= mod; }
			v *= v; v %= mod;
			n >>= 1;
		}
		return ret;
	}
	
	
	int N;
	int A,B,C,D;
	public Sol(){
		var d = ria();
		N = d[0]; A = d[1]; B = d[2]; C = d[3]; D = d[4];
	}

	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(char sep=' '){return Console.ReadLine().Split(sep);}
	static int[] ria(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>int.Parse(e));}
	static long[] rla(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>long.Parse(e));}
	static double[] rda(char sep=' '){return Array.ConvertAll(Console.ReadLine().Split(sep),e=>double.Parse(e));}
}