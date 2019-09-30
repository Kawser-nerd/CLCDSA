using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
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
						var parts = sr.ReadLine().Split(' ');
						Solve(sw, i + 1, long.Parse(parts[0]), long.Parse(parts[1]), long.Parse(parts[2]));
					}
				}
			}
		}

		static void Solve(StreamWriter sw, long runId, long R, long C, long W)
		{
			long res = 0;
			res += R * (C / W);

			if(C % W > 0)
				res += 1;

			res += W - 1;
			sw.WriteLine(string.Format(@"Case #{0}: {1}", runId, res));
		}
	}
}
