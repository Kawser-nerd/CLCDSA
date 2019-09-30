using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
	class Program
	{
		static double solve(int n, double u, string ps)
		{
			var p = ps.Split(' ').Select(x => Double.Parse(x)).ToList();

			var l = 0.0;
			var h = 1.0;
			var c = 0.0;

			while (h > l + 1e-9)
			{
				c = (h + l) / 2.0;

				var sum = p.Where(x => x < c).ToList().Sum(x => (c - x));

				if (sum < u)
					l = c;
				else
					h = c;
			}

			var res = 1.0;

			for (int i=0;i<p.Count;i++)
			{
				if (p[i] < c)
					res *= c;
				else
					res *= p[i];
			}

			return res;
		}

		static void Main(string[] args)
		{
			using (StreamReader sr = new StreamReader("a.in"))
			{
				using (StreamWriter sw = new StreamWriter("a.out"))
				{
					var K = Int32.Parse(sr.ReadLine());

					for (int kk = 1; kk <= K; kk++)
					{
						var ss = sr.ReadLine().Split(' ');

						var n = Int32.Parse(ss[0]);

						var u = sr.ReadLine();

						var ps = sr.ReadLine();

						var res = solve(n, Double.Parse(u), ps);

						sw.WriteLine("Case #" + kk + ": " + Math.Round(res, 10));
					}
				}
			}
		}
	}
}
