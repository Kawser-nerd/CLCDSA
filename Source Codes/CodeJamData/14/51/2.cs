using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
	static long N, p, q, r, s;
	static long[] num, accum;

	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			
			string[] parts = Console.ReadLine().Split();
			N = long.Parse(parts[0]);
			p = long.Parse(parts[1]);
			q = long.Parse(parts[2]);
			r = long.Parse(parts[3]);
			s = long.Parse(parts[4]);

			num = new long[N];
			accum = new long[N];
			for (int i = 0; i < N; i++)
			{
				num[i] = (i * p + q) % r + s;
				accum[i] = num[i];
				if (i > 0) accum[i] += accum[i - 1];
			}

			
			double ans = 0;
			for (long a = 0; a < N; a++)
			{
				long low = a;
				long up = N - 1;
				while (low < up - 2)
				{
					long b1 = low + (up - low) * 1 / 3;
					long b2 = low + (up - low) * 2 / 3;
					if (f(a, b1) > f(a, b2))
						up = b2;
					else
						low = b1;
				}
				ans = Math.Max(ans, f(a, low));
				ans = Math.Max(ans, f(a, up));
				ans = Math.Max(ans, f(a, (low + up) / 2));
			}
			Console.WriteLine("Case #" + CASE + ": " + ans.ToString("0.0000000000"));
		}
	}

	public static double f(long a, long b)
	{
		long sum = accum[N - 1];
		long s1 = a > 0 ? accum[a - 1] : 0;
		long s2 = accum[b] - s1;
		long s3 = sum - accum[b];
		double solv = 0;
		solv = Math.Max(solv, s1 / (double)sum);
		solv = Math.Max(solv, s2 / (double)sum);
		solv = Math.Max(solv, s3 / (double)sum);
		return 1 - solv;
	}
}
