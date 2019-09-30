using System;
using System.Collections.Generic;
class Program
{
	static void Main(string[] args)
	{
		string[] str = Console.ReadLine().Split();
		long N = long.Parse(str[0]);
		long M = long.Parse(str[1]);
		long mod = 1000000007;
		List<long> list = PrimeFactors(M);
		long ans = 1;
		while(list.Count > 0){
			long p = 0;
			long t = list[0];
			while(true){
				p += 1;
				list.RemoveAt(0);
				if(list.Count == 0){
					break;
				}
				if(list[0] != t){
					break;
				}
			}
			ans = ans * Ncr(N+p-1,p,mod) % mod;
			if(list.Count == 0){
				break;
			}
		}
		Console.WriteLine(ans);
	}

	public static List<long> PrimeFactors(long n){
		long i = 2;
		long tmp = n;
		var list = new List<long>();
		while(i*i<=n){
			if(tmp%i==0){
				tmp /= i;
				list.Add(i);
			} else {
				i++;
			}
		}
		if(tmp != 1){
			list.Add(tmp);
		}
		return list;
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

	public static long Ncr(long n,long r,long m)
	{
		long ans = 1;
		for(var i=n-r+1;i<=n;i++){
			ans = ans * i % m;
		}
		for(var i=2;i<=r;i++){
			ans = ans * Mpow(i,m-2,m) % m;
		}
		return ans;
	}
}