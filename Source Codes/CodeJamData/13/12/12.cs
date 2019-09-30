using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());

			for (int caseNumber = 0; caseNumber < T; caseNumber++)
			{
				string[] s = Console.ReadLine().Split(' ');
				int E = int.Parse(s[0]);
				int R = int.Parse(s[1]);
				int N = int.Parse(s[2]);

				s = Console.ReadLine().Split(' ');
				int[] tasks = new int[N + 1];
				for (int i = 0; i < N; i++)
					tasks[i + 1] = int.Parse(s[i]);

				int [,]remainedEnergy = new int[N + 1, E + 1];
				int [,]gained = new int[N + 1, E + 1];

				gained[0, E] = 0;

				for (int n = 1; n <= N; n++)
				{
					for (int t = 0; t <= E; t++)
					{
						int maxGain = 0;
						for (int e = Math.Max(0, t - R); e <= E; e++)
						{
							int usingEnegry = Math.Min(E, R + e) - t;
							int gain = usingEnegry * tasks[n] + gained[n - 1, e];
							if (gain > maxGain)
								maxGain = gain;
						}
						
						gained[n, t] = maxGain;
					}
				}

				int max = 0;
				for (int e = 0; e <= E; e++)
				{
					if (max < gained[N, e])
						max = gained[N, e];
				}

				Console.WriteLine("Case #{0}: {1}", caseNumber + 1, max);
			}
		}
	}
}
