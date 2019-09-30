using System;
using System.Collections.Generic;

public class B
{
	static List<int> primes;
	static bool[] prime;
	
	static long[] uf;
	
	static long uf_get (long i)
	{
		if (uf[i] == i)
			return i;
		
		return uf[i] = uf_get (uf[i]);
	}
	
	static void uf_join (long a, long b)
	{
		a = uf_get (a);
		b = uf_get (b);
		
		if (a == b)
			return;
		
		uf[b] = a;
	}
	
	public static void Main ()
	{
		prime = new bool[1000001];
		primes = new List<int> ();
		
		for (int i = 2; i <= 1000000; ++i)
			prime[i] = true;
		
		for (int i = 2; i <= 1000000; ++i)
			if (prime[i])
		{
			primes.Add (i);
			for (int j = i + i; j <= 1000000; j += i)
				prime[j] = false;
		}
		
		
		int N = int.Parse (Console.ReadLine ());
		
		for (int I = 1; I <= N; ++I)
		{
			string[] s = Console.ReadLine ().Split (' ');
			
			long a = long.Parse (s[0]);
			long b = long.Parse (s[1]);
			long p = long.Parse (s[2]);
			
			long n = b - a + 1;
			
			uf = new long[n];
			for (int i = 0; i < n; ++i)
				uf[i] = i;
			
			foreach (int pr in primes)
				if (pr >= p)
			{
				long start = (((a - 1) / pr) + 1) * pr;
				
				while (start + pr <= b)
				{
					uf_join (start - a, start + pr - a);
					
					start += pr;
				}
			}
			
			int cnt = 0;
			
			for (int i = 0; i < n; ++i)
				if (uf[i] == i)
					++cnt;
			
			Console.WriteLine ("Case #{0}: {1}", I, cnt);
		}
	}
}
