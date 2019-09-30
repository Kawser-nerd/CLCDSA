using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class D
{
	static Dictionary<int, int> mapping;
	static List<int> ans;

	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);

			int P = int.Parse(Console.ReadLine());
			int[] E = new int[P];
			string[] ps = Console.ReadLine().Split();
			for (int i = 0; i < P; i++)
				E[i] = int.Parse(ps[i]);
			int[] F = new int[P];
			ps = Console.ReadLine().Split();
			for (int i = 0; i < P; i++)
				F[i] = int.Parse(ps[i]);

			mapping = new Dictionary<int, int>();
			for (int i = 0; i < P; i++)
				mapping[E[i]] = F[i];

			ans = new List<int>();

			if (E[0] != 0) throw new Exception("Not small case!");
			int zeros = log2(F[0]);
			for (int i = 0; i < zeros; i++)
				AddInt(0);

			for (int i = 1; i < P; i++)
				for (int j = 0; j < mapping[E[i]]; j++)
					AddInt(E[i]);

			Console.Write("Case #" + CASE + ":");
			foreach (int i in ans) Console.Write(" " + i);
			Console.WriteLine();
		}
	}

	static void AddInt(int x)
	{
		for (int i = 1; i < (1 << ans.Count); i++)
		{
			int cursum = x;
			for (int j = 0; j < ans.Count; j++)
				if ((i & (1 << j)) > 0)
					cursum += ans[j];
			mapping[cursum]--;
		}
		ans.Add(x);
	}

	static int log2(int x)
	{
		int y = 0;
		while ((1 << y) < x) y++;
		return y;
	}
}
