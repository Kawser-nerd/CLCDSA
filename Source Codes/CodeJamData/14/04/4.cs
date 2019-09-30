using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int t = 1; t <= T; t++)
			{
				int N = int.Parse(Console.ReadLine());
				List<double> lNaomi1 = new List<double>(N);
				lNaomi1.AddRange(Console.ReadLine().Split().Select(s => double.Parse(s)));
				List<double> lKen1 = new List<double>(N);
				lKen1.AddRange(Console.ReadLine().Split().Select(s => double.Parse(s)));
				
				lNaomi1.Sort();
				lKen1.Sort();

				List<double> lNaomi2 = new List<double>(N);
				lNaomi2.AddRange(lNaomi1);
				List<double> lKen2 = new List<double>(N);
				lKen2.AddRange(lKen1);

				int niStart = 0;
				int niEnd = N - 1;
				int kiEnd = N - 1;
				int kiStart = 0;
				int Deceitful = 0;

				for (int i = 0; i < N; i++)
				{
					int j = 0;
					for (j = 0; (kiStart <= kiEnd - j) && (lNaomi1[niEnd - j] > lKen1[kiEnd - j]); )
						j++;

					if (kiEnd - j < kiStart)
					{
						Deceitful += kiEnd - kiStart + 1;
						break;
					}
					else
					{
						niStart++;
						lKen1.RemoveAt(kiEnd - j);
						kiEnd--;
					}
				}

				int War = 0;
				for (int i = 0; i < N; i++)
				{
					double cur = lNaomi2[i];
					int index = lKen2.FindIndex(x => x > cur);
					if (index == -1)
					{
						War++;
						lKen2.RemoveAt(0);
					}
					else
						lKen2.RemoveAt(index);
				}

				Console.WriteLine("Case #{0}: {1} {2}", t, Deceitful, War);
			}
		}
	}
}
