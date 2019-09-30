using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace SnapperChain
{
	class Program
	{
		static void Main(string[] args)
		{
			StringBuilder output = new StringBuilder();
			using (var stream = File.OpenRead("in.in"))
			{
				using (var reader = new StreamReader(stream))
				{
					int t = Int32.Parse(reader.ReadLine());
					for (int i = 1; i <= t; ++i)
					{
						var val = reader.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

						int n = Int32.Parse(val[0]);
						List<BigInteger> ts = new List<BigInteger>(n);
						for (int j = 1; j <= n; ++j)
						{
							ts.Add(BigInteger.Parse(val[j]));
						}

						output.Append("Case #").Append(i).Append(": ");


						output.Append(Solve(ts)).AppendLine();
					}
				}
			}

			File.WriteAllText("p2.out", output.ToString());
		}

		static BigInteger GCD(BigInteger a, BigInteger b)
		{
			BigInteger r = a % b;
			if (r == 0)
			{
				return b;
			}

			return GCD(b, r);
		}

		private static BigInteger Solve(List<BigInteger> ts)
		{
			ts.Sort();
			List<BigInteger> diffs = new List<BigInteger>(ts.Count - 1);

			for (int i = 1; i < ts.Count; ++i)
			{
				diffs.Add(ts[i] - ts[i - 1]);
			}

			diffs = diffs.Where(dx => dx != 0).ToList();
			diffs.Sort();

			BigInteger d = diffs[0];
			for (int i = 1; i < diffs.Count; ++i)
			{
				if (diffs[i] != 0)
				{
					d = GCD(diffs[i], d);
				}
			}

			BigInteger r = ts[0] % d;
			if (r > 0)
			{
				r = d - r;
			}
			return r;
		}
	}
}
