using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

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

						int R = Int32.Parse(val[0]);
						int k = Int32.Parse(val[1]);
						int N = Int32.Parse(val[2]);

						val = reader.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

						List<long> grouops = new List<long>(N);
						for (int j = 0; j < N; ++j)
						{
							grouops.Add(Int32.Parse(val[j]));
						}

						output.Append("Case #").Append(i).Append(": ");


						output.Append(Solve(R, k, N, grouops)).AppendLine();
					}
				}
			}

			File.WriteAllText("p3.out", output.ToString());
		}

		private static long Solve(long R, long k, int n, List<long> groups)
		{
			long income = 0;

			long sum = groups.Aggregate((a, b) => a + b);

			//long m = k / sum;
			k = Math.Min(k, sum);

			int[] round = new int[n];
			long[] count = new long[n];

			for (int i = 0; i < n; ++i)
			{
				count[i] = -1;
			}

			int currIdx = 0;

			// <= 1000
			for (int r = 1; r <= R; ++r)
			{
				int prevIdx = currIdx;
				

				//income += m * sum;

				long currK = k;

				// <= 1000
				for (; groups[currIdx] <= currK; currIdx = (currIdx + 1) % n)
				{
					income += groups[currIdx];
					currK -= groups[currIdx];
				}

				if (count[currIdx] >= 0)
				{
					//long bi = count[currIdx];
					long pi = income - count[currIdx];
					int len = r - round[currIdx];
					long rest = R - r;
					income += pi * (rest / len);
					r = (int)(R - (rest % len));
				}

				count[currIdx] = income;
				round[currIdx] = r;
			}

			return income;
		}
	}
}
