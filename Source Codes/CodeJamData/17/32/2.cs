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
		static int solve(List<string> a1, List<string> a2)
		{
			int[] b1 = new int[24 * 60];
			int[] b2 = new int[24 * 60];

			for (int i = 0; i < b1.Length; i++)
			{
				b2[i] = 0;
				b1[i] = 0;
			}

			for (int i = 0; i < a1.Count; i++)
			{
				var spl = a1[i].Split(' ');

				var l = Int32.Parse(spl[0]);
				var h = Int32.Parse(spl[1]);

				for (int j = l; j < h; j++)
					b1[j] = 1;
			}

			for (int i = 0; i < a2.Count; i++)
			{
				var spl = a2[i].Split(' ');

				var l = Int32.Parse(spl[0]);
				var h = Int32.Parse(spl[1]);

				for (int j = l; j < h; j++)
					b2[j] = 1;
			}

			var dp = new int[2, 2, 24 * 60 + 1, 721];

			for (int i = 0; i < 24 * 60 + 1; i++)
				for (int j = 0; j < 721; j++)
				{
					dp[0, 0, i, j] = 99999999;
					dp[0, 1, i, j] = 99999999;
					dp[1, 0, i, j] = 99999999;
					dp[1, 1, i, j] = 99999999;
				}

			if (b1[0] == 0)
			{
				dp[0, 0, 0, 1] = 0;
				//dp[0, 1, 0, 1] = 1;
			}
			if (b2[0] == 0)
			{
				dp[1, 1, 0, 0] = 0;
				//dp[1, 0, 0, 0] = 1;
			}

			for (int i = 1; i < 24 * 60; i++)
			{
				for (int j = 1; j <= 720; j++)
				{
					//1st sit ith min
					if (b1[i] == 0)
					{
						dp[0, 0, i, j] = Math.Min(dp[0, 0, i - 1, j - 1], dp[0, 1, i - 1, j - 1] + 1);
						dp[1, 0, i, j] = Math.Min(dp[1, 0, i - 1, j - 1], dp[1, 1, i - 1, j - 1] + 1);
					}
				}

				if (b2[i] == 0)
				{
					for (int j = 0; j <= 720; j++)
					{
						//if (j > 0)
						//{
							dp[0, 1, i, j] = Math.Min(dp[0, 1, i - 1, j], dp[0, 0, i - 1, j] + 1);
							dp[1, 1, i, j] = Math.Min(dp[1, 1, i - 1, j], dp[1, 0, i - 1, j] + 1);
						//}
						//else
						//{
						//	dp[0, 1, i, j] = dp[0, 1, i - 1, j];
						//	dp[1, 1, i, j] = dp[1, 1, i - 1, j];
						//}
					}
				}
			}

			return Math.Min(Math.Min(dp[0, 0, 24 * 60 - 1, 720], dp[1, 1, 24 * 60 - 1, 720]),
				Math.Min(dp[0, 1, 24 * 60 - 1, 720] + 1, dp[1, 0, 24 * 60 - 1, 720] + 1));
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
						var m = Int32.Parse(ss[1]);

						var a1 = new List<string>();

						for (int i = 0; i < n; i++)
							a1.Add(sr.ReadLine());

						var a2 = new List<string>();

						for (int i = 0; i < m; i++)
							a2.Add(sr.ReadLine());

						var res = solve(a1, a2);
						sw.WriteLine("Case #" + kk + ": " + res);
					}
				}
			}
		}
	}
}
