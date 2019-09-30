using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class B
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			int N = int.Parse(Console.ReadLine());
			int[] A = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

			int[] idx = new int[N];
			for (int i = 0; i < N; i++)
				idx[i] = i;
			Array.Sort(A, idx);

			int ans = 0;
			for (int i = 0; i < N; i++)
			{
				int nl = 0;
				int nr = 0;
				for (int j = 0; j < N; j++)
				{
					if (A[j] <= A[i]) continue;
					if (idx[j] < idx[i])
						nl++;
					else
						nr++;
				}
				ans += Math.Min(nl, nr);
			}

			Console.WriteLine("Case #" + CASE + ": " + ans);
		}
	}
}
