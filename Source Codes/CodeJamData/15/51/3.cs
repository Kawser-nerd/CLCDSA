using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] ps = Console.ReadLine().Split();
			int N = int.Parse(ps[0]);
			int D = int.Parse(ps[1]);
			ps = Console.ReadLine().Split();
			int S0 = int.Parse(ps[0]);
			int As = int.Parse(ps[1]);
			int Cs = int.Parse(ps[2]);
			int Rs = int.Parse(ps[3]);
			ps = Console.ReadLine().Split();
			int M0 = int.Parse(ps[0]);
			int Am = int.Parse(ps[1]);
			int Cm = int.Parse(ps[2]);
			int Rm = int.Parse(ps[3]);

			int[] s = new int[N];
			s[0] = S0;
			for (int i = 1; i < N; i++)
				s[i] = (s[i - 1] * As + Cs) % Rs;

			int[] m = new int[N];
			m[0] = M0;
			for (int i = 1; i < N; i++)
				m[i] = (m[i - 1] * Am + Cm) % Rm;

			int ans = 1;
			for (int i = 0; i < N; i++)
			{
				int low = s[i];
				int up = s[i] + D;
				if (s[0] < low || s[0] > up) continue;

				int cur = 1;
				bool[] fire = new bool[N];
				for (int j = 1; j < N; j++)
				{
					int man = m[j] % j;
					if (fire[man]) fire[j] = true;
					if (s[j] < low || s[j] > up) fire[j] = true;
					if (!fire[j]) cur++;
				}
				ans = Math.Max(ans, cur);
			}

			Console.WriteLine("Case #" + CASE + ": " + ans);
		}
	}
}
