using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Codejame
{
	class Program
	{
		static int trans(char c)
		{
			switch (c)
			{
				case '0': return 0;
				case '1': return 1;
				case '2': return 2;
				case '3': return 3;
				case '4': return 4;
				case '5': return 5;
				case '6': return 6;
				case '7': return 7;
				case '8': return 8;
				case '9': return 9;
				case 'A': return 10;
				case 'B': return 11;
				case 'C': return 12;
				case 'D': return 13;
				case 'E': return 14;
				case 'F': return 15;
			}
			return 0;
		}
		static void Main(string[] args)
		{
			StreamReader reader = new StreamReader(@"C:\C-large.in");
			StreamWriter writer = new StreamWriter(@"C:\C-large.out");

			int T = Convert.ToInt32(reader.ReadLine());
			for (int k = 1; k <= T; k++)
			{
				int ans = 0;


				string[] s = reader.ReadLine().Split();

				int m = Convert.ToInt32(s[0]);
				int n = Convert.ToInt32(s[1]);

				int[] count = new int[m + 10];
				for (int i = 0; i < m + 10; i++)
					count[i] = 0;

				int[,] A = new int[m, n];
				
				for (int i = 0; i < m; i++)
				{
					string c = reader.ReadLine();
					for (int j = 0; j < c.Length; j++)
					{
						int r = trans(c[j]);
						A[i, j * 4 + 0] = (r >> 3) & 1;
						A[i, j * 4 + 1] = (r >> 2) & 1;
						A[i, j * 4 + 2] = (r >> 1) & 1;
						A[i, j * 4 + 3] = (r >> 0) & 1;
					}
				}

				//for (int i = 0; i < m; i++)
				//{
				//    for (int j = 0; j < n; j++)
				//        if (A[i, j] == 0)
				//            writer.Write('0');
				//        else
				//            writer.Write('1');
				//    writer.WriteLine();
				//}

				int[,] B = new int[m, n];

				for (int len = Math.Min(m, n); len >= 2; len--)
				{
					for (int i = 0; i < m; i++)
						for (int j = 0; j < n; j++)
							B[i, j] = 0;
					for (int i = 0; i < m; i++)
					{
						int q = 1;
						for (int j = 1; j < n; j++)
						{
							if (A[i, j] + A[i, j - 1] == 1)
								q++;
							else
								q = A[i, j] != 2 ? 1 : 0;
							if (A[i, j] == 2)
							{
								B[i, j] = 0;
								continue;
							}
							if (q >= len)
							{
								if (i == 0)
									B[i, j] = 1;
								else
								{
									if (A[i, j] + A[i - 1, j] == 1)
										B[i, j] = B[i - 1, j] + 1;
									else
										B[i, j] = 1;
								}
							}
							else
								B[i, j] = 0;
							if (B[i, j] == len)
							{
								for (int x = 0; x < len; x++)
									for (int y = 0; y < len; y++)
										A[i - x, j - y] = 2;
								for (int x = 0; x < len; x++)
									B[i, j - x] = 0;
								q = 0;
								count[len]++;

								//writer.WriteLine(String.Format("{0} {1}", i - len + 1, j - len + 1));
							}
						}
					}
				}

				for (int i = 0; i < m; i++)
					for (int j = 0; j < n; j++)
						if (A[i, j] != 2) count[1]++;

				ans = 0;
				for (int i = 0; i < m + 10; i++)
					if (count[i] != 0) ans++;

				writer.WriteLine(String.Format("Case #{0}: {1}", k, ans));
				for (int i = m + 9; i >= 0; i--)
					if (count[i] != 0)
						writer.WriteLine(String.Format("{0} {1}", i, count[i]));
			}

			writer.Close();
			reader.Close();
		}
	}
}
