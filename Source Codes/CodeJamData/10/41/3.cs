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
			StreamReader sr = new StreamReader(@"C:\CodeJam\A-large.in");
			StreamWriter sw = new StreamWriter(@"C:\CodeJam\A-large.out");

			int T = Convert.ToInt32(sr.ReadLine());

			for (int test = 1; test <= T; test++)
			{
				int k = Convert.ToInt16(sr.ReadLine());

				int[,] a = new int[2*k - 1, 2 * k];

				for (int i = 0; i < 2 * k - 1; i++)
					for (int j = 0; j < 2 * k - 1; j++)
						a[i, j] = -1;

				for (int i = 0; i < k; i++)
				{
					string s = sr.ReadLine();
					for (int j = 0; j < s.Length; j++)
						if (s[j] != ' ')
							a[i, j] = s[j] - '0';
				}

				for (int i = k; i < 2 * k - 1; i++)
				{
					string s = sr.ReadLine();
					for (int j = 0; j < s.Length; j++)
						if (s[j] != ' ')
							a[i, j] = s[j] - '0';
				}

				bool[] arrx = new bool[2 * k];
				for (int x = 0; x < 2 * k - 1; x++)
				{
					bool f = true;
					for (int i = 0; i < 2 * k - 1; i++)
						if (f)
						for (int j = 0; j < 2 * k - 1; j++)
						{
							if (a[i, j] == -1)
								continue;
							if (2 * x - j < 0) continue;
							if (2 * x - j >= 2 * k - 1) continue;
							if (a[i, 2 * x - j] == -1) continue;
							if (a[i, j] != a[i, 2 * x - j])
							{
								f = false;
								break;
							}
						}
					arrx[x] = f;
				}
				bool[] arry = new bool[2 * k];
				for (int y = 0; y < 2 * k - 1; y++)
				{
					bool f = true;
					for (int i = 0; i < 2 * k - 1; i++)
						if (f)
							for (int j = 0; j < 2 * k - 1; j++)
							{
								if (a[i, j] == -1)
									continue;
								if (2 * y - i < 0) continue;
								if (2 * y - i >= 2 * k - 1) continue;
								if (a[2 * y - i, j] == -1) continue;
								if (a[i, j] != a[2 * y - i, j])
								{
									f = false;
									break;
								}
							}
					arry[y] = f;
				}

				int ans = int.MaxValue;
				for (int x = 0; x < 2 * k - 1; x++)
					for (int y = 0; y < 2 * k - 1; y++)
						if (arrx[x] && arry[y])
					{
						int cur = (Math.Abs(x - k + 1) + Math.Abs(y - k + 1) + k);
						cur = cur * cur;
						if (ans > cur) ans = cur;
					}
				sw.WriteLine(String.Format("Case #{0}: {1}", test, ans - k * k));
			}


			sr.Close(); sw.Close();
		}
	}
}
