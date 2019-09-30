using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
	class Program
	{
		static void Main(string[] args)
		{
			StreamReader sr = new StreamReader(@"C:\CodeJam\B-large.in");
			StreamWriter sw = new StreamWriter(@"C:\CodeJam\B-large.out");

			int T = Convert.ToInt32(sr.ReadLine());

			for (int test = 1; test <= T; test++)
			{
				int P = Convert.ToInt32(sr.ReadLine());
				int[] M = new int[1 << P];
				int[,] Price = new int[P, 1 << (P - 1)];

				string[] s = sr.ReadLine().Split(' ');
				for (int i = 0; i < 1 << P; i++)
					M[i] = Convert.ToInt32(s[i]);

				for (int i = 0; i < P; i++)
				{
					s = sr.ReadLine().Split(' ');
					for (int j = 0; j < 1 << (P - i - 1); j++)
						Price[i, j] = Convert.ToInt32(s[j]);
				}

				int[,] K = new int[1 << P, 1 << P];
				for (int i = 0; i < 1 << P; i++)
					for (int j = 0; j < 1 << P; j++)
						K[i, j] = int.MaxValue / 2;

				for (int i = 0; i < 1 << P; i++)
				{
					int q = 0; int price = 0;
					for (int j = 0; j < P; j++)
						if (((i >> j) & 1) != 0)
						{
							q++;
							price += Price[j, 0];
						}
					if (q + M[0] >= P) K[0, i] = price;
				}

				for (int com = 1; com < 1 << P; com++)
				{
					int kol = 0;
					for (kol = 0; kol < P; kol++)
						if (((com >> kol) & 1) != 0)
							break;
					for (int i = 0; i < 1 << P; i++)
					{
						int price = int.MaxValue / 2;
						for (int j = 0; j < 1 << kol; j++)
							if (price > K[com - 1, i ^ j])
								price = K[com - 1, i ^ j];
						for (int j = 0; j < kol; j++)
							if (((i >> j) & 1) != 0)
								price += Price[j, com >> (j + 1)];
						int q = 0;
						for (int j = 0; j < P; j++)
							if (((i >> j) & 1) != 0)
								q++;
						if (q + M[com] >= P) K[com, i] = Math.Min(K[com, i], price);
					}
				}
				int ans = int.MaxValue;
				for (int i = 0; i < 1 << P; i++)
					if (ans > K[(1 << P)- 1, i])
						ans = K[(1 << P) - 1, i];
				sw.WriteLine(String.Format("Case #{0}: {1}", test, ans));
			}


			sr.Close(); sw.Close();
		}
	}
}
