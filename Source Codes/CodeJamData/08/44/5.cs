using System;
using System.Collections.Generic;
using System.Linq;

public class D
{
	public void Run ()
	{
		int N = int.Parse (Console.ReadLine ());
		
		for (int I = 1; I <= N; ++I)
		{
			int k = int.Parse (Console.ReadLine ());
			int kk = 1 << k;
			string s = Console.ReadLine ();
			int n = s.Length;
			
			int?[,,] rm = new int?[kk, k, k];
			
			for (int i = 0; i < k; ++i)
				for (int j = 0; j < k; ++j)
					rm[1 << i, j, j] = 0;
			
			for (int p = 1; p < kk; ++p)
			{
//				Console.WriteLine (p);
				
				if ((p & (p - 1)) == 0)
					continue;
				
				int bits = 0;
				int pp = p;
				
				while (pp != 0)
				{
					pp &= pp - 1;
					++bits;
				}
				
				for (int i = 0; i < k; ++i)
					if ((p & (1 << i)) != 0)
						for (int j = 0; j < k; ++j)
							if (i != j && (p & (1 << j)) != 0)
						{
							rm[p, i, j] = 0;
							
							for (int q = 0; q < k; ++q)
								if (j != q && rm[p & (~(1 << j)), i, q].HasValue)
							{
								int cnt = rm[p & (~(1 << j)), i, q].Value;
								
								for (int w = 0; w < n; w += k)
									if (s[w + j] == s[w + q])
										++cnt;
								
								rm[p, i, j] = Math.Max (rm[p, i, j].Value, cnt);
							}
						}
			}
			
			for (int i = 0; i < k; ++i)
				for (int j = 0; j < k; ++j)
					if (i != j)
						for (int w = 0; w + k < n; w += k)
							if (s[w + j] == s[w + k + i])
								++rm[kk - 1, i, j];
			
			
			int best = 0;
			
			for (int i = 0; i < k; ++i)
				for (int j = 0; j < k; ++j)
					if (i != j)
						best = Math.Max (best, rm[kk - 1, i, j].Value);
			
			Console.WriteLine ("Case #{0}: {1}", I, n - best);
		}
	}
}
