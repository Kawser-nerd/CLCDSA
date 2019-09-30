using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		long N = long.Parse(str[0]);
		long A = long.Parse(str[1]);
		long B = long.Parse(str[2]);
		long K = long.Parse(str[3]);
		long mod = 998244353;
		long [] NA = new long[N+1];
		long [] INA = new long[N+1];
		NA[0] = 1;
		INA[0] = 1;
		for(var i=1;i<NA.Length;i++){
			NA[i] = NA[i-1] * i % mod;
			INA[i] = INA[i-1] * Mpow(i,mod-2,mod) % mod;
		}
		long ans = 0;
		for(var i=0;i<=N;i++){
			if(K-A*i < 0){
				break;
			}
			if((K-A*i)%B == 0){
				long j1 = (K-A*i)/B;
				if(j1<=N){
					long an1 = NA[N] * INA[N-i] % mod;
					an1 = an1 * INA[i] % mod;
					an1 = an1 * NA[N] % mod;
					an1 = an1 * INA[N-j1] % mod;
					an1 = an1 * INA[j1] % mod;
					ans = (ans + an1) % mod;
				}
			}
		}
		Console.WriteLine(ans);
	}

	public static long Mpow(long x,long n,long m)
	{
		long ans = 1;
		while(n > 0){
			if(n % 2 == 1){
				ans = ans * x % m;
				n -= 1;
			}
			x = x * x % m;
			n /= 2;
		}
		return ans;
	}
}