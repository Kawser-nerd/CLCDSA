using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Competition
{
	public class ExpensiveDinner
	{
		public void tester()
		{
			var sb = new StringBuilder();
			//string loc = @"C:\Pub\input.txt";
			string loc = @"C:\Pub\C-small-attempt0.in";
			string[] lines = System.IO.File.ReadAllLines(loc);
			int caseNo = 1;

			var primes = new HashSet<int>(Library.Primes.FindPrimes(1001));

			for (int i = 1; i < lines.Length; )
			{
				var spl = lines[i++].Split().Select(x => int.Parse(x)).ToArray();
				int N = spl[0];

				int min = 0;
				int max = 1; //1!
				for (int n = 2; n <= N; n++)
				{
					if (primes.Contains(n))
					{
						int start = n;
						while (start <= N)
						{
							start *= n;
							max++;
						}

						min++;
					}
				}
				if (N == 1) min = 1;

				sb.AppendFormat("Case #{0}: {1}", caseNo++, max - min);
				sb.AppendLine();
			}
			string outloc = @"C:\Pub\test.txt";
			System.IO.File.WriteAllText(outloc, sb.ToString());
		}
	}
}
