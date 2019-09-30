using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		long N = long.Parse(Console.ReadLine());
		long mod = 1000000007;
		long[]M = new long[N];
		long[]P = new long[N];
		M[0] = 1;
		P[0] = 1;
		for(var i=1;i<N;i++){
			M[i] = (M[i-1] + Mpow(i+1,mod-2,mod)) % mod;
			P[i] = P[i-1] *(i+1) % mod;
		}
		string[] str = Console.ReadLine().Split();
		long[]A = new long[N];
		for(var i=0;i<N;i++){
			A[i] = long.Parse(str[i]);
		}
		long ans = 0;
		for(var i=0;i<N;i++){
			//ans = (ans + P[N-1] * A[i] % mod * M[i] % mod + P[N-1] * A[i] % mod * M[N-i-1] % mod - P[N-1] * A[i] % mod * M[0] % mod) % mod;
			ans = (ans + P[N-1] * A[i] % mod * (M[i] + M[N-i-1] - 1) % mod) % mod;
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