using ConsoleApplication1.Helpers;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1.OtherTasks.CodeJam2017
{
	public class TidyNumbers
	{
		public void Go(string[] args)
		{
			//foreach (var s in new[] { "132", "1000", "7", "111111111111111110" }) Console.WriteLine(Solve(s));

			//Performance();

			SolveFile(args);
		}

		public void SolveFile(string[] args)
		{
			var task = File.ReadAllLines(args[0]);
			var sb = new StringBuilder();
			var T = int.Parse(task[0]);
			for (var t = 0; t < T; t++)
				sb.AppendFormat("Case #{0}: {1}", t + 1, Solve(task[t + 1])).AppendLine();
			File.WriteAllText(args[1], sb.ToString());
		}

		public void Performance()
		{
			var rnd = new Random(123);

			for (var t = 0; t < 100; t++)
			{
				var s = RandomGenerator.RandomUlong(rnd).ToString();

				Console.WriteLine(new { t, s, sol = Solve(s) });
			}
		}

		public void Compare()
		{
			var rnd = new Random(1337);
			for (var t = 0; t < 1000000; t++)
			{
				var n = rnd.Next(1, 10000).ToString();

				var brute = SolveBrute(n);
				var actual = Solve(n);

				if (actual != brute)
				{
					Console.WriteLine(new { t, n, brute, actual });
					throw new InvalidOperationException();
				}
			}
		}

		public string Solve(string S)
		{
			if (S.Length == 1) return S;

			var s = S.ToCharArray();

			while (true)
			{
				var isTidy = true;

				for (var i = 1; i < s.Length; i++)
					if (s[i - 1] > s[i])
					{
						s[i - 1]--;
						for (var j = i; j < s.Length; j++)
							s[j] = '9';

						isTidy = false;
					}

				if (isTidy) break;
			}

			return s.SkipWhile(c => c == '0').Join("");
		}

		public string SolveBrute(string s)
		{
			for (var n = BigInteger.Parse(s); n >= 1; n--)
			{
				var strn = n.ToString();
				var isTidy = true;
				for (var i = 1; i < strn.Length; i++)
					if (strn[i - 1] > strn[i])
					{
						isTidy = false;
						break;
					}

				if (isTidy)
					return strn;
			}

			throw new InvalidOperationException("Impossibru");
		}
	}
}
