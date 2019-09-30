using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace b
{
	class Program
	{
		static void Main(string[] args)
		{
			int T = int.Parse(Console.ReadLine());
			for (int caso = 1; caso <= T; caso++)
			{
				string[] NM = Console.ReadLine().Split(' ');
				int N = int.Parse(NM[0]);
				int M = int.Parse(NM[1]);
				List<List<int>> h = new List<List<int>>();
				List<int> maxH = new List<int>();
				List<int> maxV = new List<int>();
				for (int i = 0; i < N; i++)
				{
					string[] hs = Console.ReadLine().Split(' ');
					List<int> linea = new List<int>();

					maxH.Add(0);
					for (int j = 0; j < M; j++)
					{
						if (i == 0)
						{
							maxV.Add(0);
						}
						int n = int.Parse(hs[j]);
						linea.Add(n);
						if (n > maxH[i])
						{
							maxH[i] = n;
						}
						if (n > maxV[j])
						{
							maxV[j] = n;
						}
					}
					h.Add(linea);
				}

				Console.WriteLine("Case #{0}: {1}", caso, check(h, maxH, maxV, N, M));
			}
		}

		static string check(List<List<int>> h, List<int> maxH, List<int> maxV, int N, int M)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (h[i][j] < maxH[i] && h[i][j] < maxV[j])
					{
						return "NO";
					}
				}
			}
			return "YES";
		}
	}
}
