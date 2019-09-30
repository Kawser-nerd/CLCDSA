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
			string[] parts = Console.ReadLine().Split();
			int K = int.Parse(parts[0]);
			int L = int.Parse(parts[1]);
			int S = int.Parse(parts[2]);
			letters = Console.ReadLine();
			target = Console.ReadLine();
			Stack<char> cur = new Stack<char>();
			count = 0;
			pay = 0;
			max = 0;
			rec(cur, S);
			Console.WriteLine("Case #" + CASE + ": " + (max - (pay / count)));
		}
	}

	static string letters, target;
	static int max;
	static double count, pay;

	static void rec(Stack<char> cur, int S)
	{
		if (S == 0)
		{
			int curcount = 0;
			for (int i = 0; i <= cur.Count - target.Length; i++)
			{
				bool ok = true;
				for (int j = 0; j < target.Length; j++)
					if (cur.ElementAt(i + j) != target[j])
						ok = false;
				if (ok) curcount++;
			}
			max = Math.Max(max, curcount);
			count++;
			pay += curcount;
		}
		else
		{
			for (int i = 0; i < letters.Length; i++)
			{
				cur.Push(letters[i]);
				rec(cur, S - 1);
				cur.Pop();
			}
		}
	}
}
