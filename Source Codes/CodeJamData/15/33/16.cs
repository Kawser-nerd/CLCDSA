using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			if (File.Exists("output.txt"))
				File.Delete("output.txt");
			using (var sr = new StreamReader(File.OpenRead("input.txt")))
			{
				using (var sw = new StreamWriter(File.OpenWrite("output.txt")))
				{
					var t = long.Parse(sr.ReadLine());
					for (var i = 0; i < t; i++)
					{
						var parts = sr.ReadLine().Split(' ').Select(v => long.Parse(v)).ToArray();
						var d = sr.ReadLine().Split(' ').Select(v => long.Parse(v)).ToArray();
						Solve(sw, i + 1, parts[0], parts[2], d);
					}
				}
			}
		}

		static void Solve(StreamWriter sw, long runId, long C, long V, long[] D)
		{
			// C == 1

			var hs = new HashSet<long>(D);
			for (var dns = 0; dns <= V; dns++)
			{
				if (Solve1(V, hs, dns, 0))
				{
					sw.WriteLine(string.Format(@"Case #{0}: {1}", runId, dns));
					return;
				}
			}
		}

		static bool Solve1(long v, HashSet<long> D, long dns, long last)
		{
			if (dns == 0)
			{
				return Solve2(v, D.ToArray());
			}
			else
			{
				for (var i = last + 1; i <= v; i++)
				{
					if (!D.Contains(i))
					{
						D.Add(i);
						if (Solve1(v, D, dns - 1, i))
							return true;
						D.Remove(i);
					}
				}
				return false;
			}
		}

		static bool Solve2(long v, long[] D)
		{
			for (var i = 1; i <= v; i++)
			{
				if (!Solve2(i, D, D.Length - 1, 0))
					return false;
			}
			return true;
		}
		static bool Solve2(long v, long[] D, long pos, long sum)
		{
			if (sum == v)
				return true;
			if (sum > v)
				return false;
			if (pos < 0)
				return false;

			if (Solve2(v, D, pos - 1, sum))
				return true;
			if (Solve2(v, D, pos - 1, sum + D[pos]))
				return true;
			return false;
		}

	}
}
