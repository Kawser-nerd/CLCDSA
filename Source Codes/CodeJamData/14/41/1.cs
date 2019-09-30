using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class A
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] parts = Console.ReadLine().Split();
			int N = int.Parse(parts[0]);
			int X = int.Parse(parts[1]);
			int[] S = new int[N];
			parts = Console.ReadLine().Split();
			for (int i = 0; i < N; i++)
				S[i] = int.Parse(parts[i]);
			Array.Sort(S);
			Array.Reverse(S);

			bool[] done = new bool[N];
			int ans = 0;
			for (int i = 0; i < N; i++)
			{
				if (done[i]) continue;
				int j = i + 1;
				ans++;
				while (j < N && (done[j] || S[i] + S[j] > X)) j++;
				if (j < N) done[j] = true;
			}

			Console.WriteLine("Case #" + CASE + ": " + ans);
		}
	}
}
