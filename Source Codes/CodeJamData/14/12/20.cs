using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApplication2
{
	class Program
	{
		static Int32[,] _f;
		static Int32 N;
		static Int32[,] edges;

		static Int32 f(Int32 x, Int32 e, Int32 p)
		{
			List<Int32> childs = new List<Int32>();

			if (_f[x,e] != Int32.MaxValue)
			{
				return _f[x,e];
			}

			for (Int32 i = 0; i < N - 1; ++i)
			{
				if (edges[i, 0] == x && edges[i, 1] != p)
					childs.Add(edges[i, 1]);
				else if (edges[i, 1] == x && edges[i, 0] != p)
					childs.Add(edges[i, 0]);
			}

			Int32 bestSolution = 0;
			Int32 power = 0;

			for (Int32 i = 0; i < childs.Count; ++i)
				power += f(childs[i], 1, x) + 1;

			bestSolution = power;

			if (e == 0)
			{
				if (childs.Count >= 2)
				{
					for (Int32 i = 0; i < childs.Count; ++i)
						for (Int32 j = i + 1; j < childs.Count; ++j)
						{
							Int32 currentSolution = f(childs[i], 0, x) + f(childs[j], 0, x) + (power - 2 - f(childs[i], 1, x) - f(childs[j], 1, x));
							if (currentSolution < bestSolution)
								bestSolution = currentSolution;
						}
				}
			}

			_f[x,e] = bestSolution;
			return bestSolution;
		}


		static void Main(string[] args)
		{
			System.Globalization.CultureInfo customCulture = (System.Globalization.CultureInfo)System.Threading.Thread.CurrentThread.CurrentCulture.Clone();
			customCulture.NumberFormat.NumberDecimalSeparator = ".";
			System.Threading.Thread.CurrentThread.CurrentCulture = customCulture;

			using (StreamReader reader = new StreamReader(@"j:\codejam\ConsoleApplication4\input.txt"))
			{
				using (StreamWriter writer = new StreamWriter(@"j:\codejam\ConsoleApplication4\output.txt"))
				{
					Int32 T = Int32.Parse(reader.ReadLine());
					for (Int32 test = 1; test <= T; ++test)
					{
						N = Int32.Parse(reader.ReadLine());
						edges = new Int32[N - 1, 2];
						Int32 bestSolution = Int32.MaxValue;

						for (Int32 i = 0; i < N - 1; ++i)
						{
							String[] line = reader.ReadLine().Split(' ');
							edges[i, 0] = Int32.Parse(line[0]);
							edges[i, 1] = Int32.Parse(line[1]);
						}

						_f = new Int32[N + 1, 2];

						for (Int32 i = 1; i <= N; ++i)
						{
							for (Int32 j = 0; j <= N; ++j)
							{
								_f[j, 0] = Int32.MaxValue;
								_f[j, 1] = Int32.MaxValue;
							}

							Int32 currentSolution = f(i, 0, 0);

							if (bestSolution > currentSolution)
								bestSolution = currentSolution;
						}

						writer.WriteLine("Case #" + test + ": " + bestSolution);
					}
				}
			}
		}
	}
}
