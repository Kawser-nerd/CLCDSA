using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
	class Program
	{
		int[] used;
		int[] p1, p2, p3, p4;
		static void Main(string[] args)
		{
			StreamReader sr = new StreamReader(@"C:\CodeJam\C-small-attempt0.in");
			StreamWriter sw = new StreamWriter(@"C:\CodeJam\C-small-attempt0.out");

			int T = Convert.ToInt32(sr.ReadLine());

			for (int test = 1; test <= T; test++)
			{
				int R = Convert.ToInt32(sr.ReadLine());

				int[] X1 = new int[R];
				int[] Y1 = new int[R];
				int[] X2 = new int[R];
				int[] Y2 = new int[R];

				for (int i = 0; i < R; i++)
				{
					string[] s = sr.ReadLine().Split(' ');
					X1[i] = Convert.ToInt32(s[0]);
					Y1[i] = Convert.ToInt32(s[1]);
					X2[i] = Convert.ToInt32(s[2]);
					Y2[i] = Convert.ToInt32(s[3]);
				}

				bool[,] A = new bool[302, 302];
				
				for (int i = 0; i < R; i++)
				{
					for (int x = X1[i]; x <= X2[i]; x++)
						for (int y = Y1[i]; y <= Y2[i]; y++)
							A[x, y] = true;
				}

				bool[,] B = new bool[302, 302];

				int ans = 0;
				while (true)
				{
					for (int i = 0; i < 302; i++)
						for (int j = 0; j < 302; j++)
							B[i, j] = false;
					bool f = false;
					for (int i = 1; i < 302; i++)
						for (int j = 1; j < 302; j++)
						{
							if (A[i, j] && (A[i - 1, j] || A[i, j - 1]))
							{
								B[i, j] = true;
								f = true;
							}
							if (A[i - 1, j] && A[i, j - 1])
							{
								B[i, j] = true;
								f = true;
							}
						}
					ans++;
					if (!f) break;
					for (int i = 0; i < 302; i++)
						for (int j = 0; j < 302; j++)
							A[i, j] = B[i, j];
				}

				
				sw.WriteLine(String.Format("Case #{0}: {1}", test, ans));
			}


			sr.Close(); sw.Close();
		}
	}
}
