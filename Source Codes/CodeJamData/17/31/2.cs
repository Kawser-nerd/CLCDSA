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
		static double solve(int n, int m, List<string> ss)
		{
			var r = new List<double>();
			var h = new List<double>();

			for (int i = 0; i < n; i++)
			{
				var spl = ss[i].Split(' ');
				r.Add(Double.Parse(spl[0]));
				h.Add(Double.Parse(spl[1]));
			}

			var f = new List<KeyValuePair<double, double>>();

			for (int i = 0; i < n; i++)
			{
				f.Add(new KeyValuePair<double, double>(r[i], h[i]));
			}

			f = f.OrderBy(x => -x.Key).ToList();

			var best = 0.0;

			for (int i = 0; i < n; i++)
			{
				var c = Math.PI * f[i].Key * f[i].Key + 2.0 * Math.PI * f[i].Key * f[i].Value;

				var tmp = f.ToList();
				tmp.RemoveAt(i);

				tmp = tmp.Where(x => x.Key <= f[i].Key + 0.00001).ToList();

				if (tmp.Count < m - 1)
					continue;

				tmp = tmp.OrderBy(x => -2.0 * Math.PI * x.Key * x.Value).ToList();

				for (int j = 0; j < m - 1; j++)
					c += 2.0 * Math.PI * tmp[j].Key * tmp[j].Value;

				best = Math.Max(best, c);
			}

			return best;
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

						var N = Int32.Parse(ss[0]);
						var M = Int32.Parse(ss[1]);

						List<string> tmp = new List<string>();

						for (int i = 0; i < N; i++)
							tmp.Add(sr.ReadLine());

						var res = solve(N, M, tmp);

						sw.WriteLine("Case #" + kk + ": " + res);
					}
				}
			}
		}
	}
}
