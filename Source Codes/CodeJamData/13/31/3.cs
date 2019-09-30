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
			string[] p = Console.ReadLine().Split();
			string s = p[0];
			int n = int.Parse(p[1]);
			long ans = 0;
			int cur = 0;
			int last = -1;
			for (int i = 0; i < s.Length; i++)
			{
				if ("aeiou".Contains(s[i].ToString()))
				{
					cur = 0;
				}
				else
				{
					if (cur < n) cur++;
					if (cur == n)
					{
						ans += (long)(i - n - last + 1) * (long)(s.Length - i);
						last = i - n + 1;
					}
				}
			}
			Console.WriteLine("Case #" + CASE + ": " + ans);
		}
	}
}
