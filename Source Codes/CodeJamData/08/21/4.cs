using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
	static class Ext
	{

		static char[] emptyChars = "\r\n\t ".ToCharArray();

		public static string[] SplitByWhiteSpaces(this string source)
		{
			return source.Split(emptyChars, StringSplitOptions.RemoveEmptyEntries);
		}
	}

	class Program
	{
		long n, A, B, C, D, x0, y0, M;
		long[,] pos;

		public void Gen()
		{
			long cx = x0;
			long cy = y0;
			pos[cx % 3, cy % 3] = 1;
			for (int i = 1; i < n; ++i)
			{
				cx = (A * cx + B) % M;
				cy = (C * cy + D) % M;
				++pos[cx % 3, cy % 3];
			}
		}

		public void Solve()
		{
			pos = new long[3, 3];
			var tmp = fin.ReadLine().SplitByWhiteSpaces();
			n = Int64.Parse(tmp[0]);
			A = Int64.Parse(tmp[1]);
			B = Int64.Parse(tmp[2]);
			C = Int64.Parse(tmp[3]);
			D = Int64.Parse(tmp[4]);
			x0 = Int64.Parse(tmp[5]);
			y0 = Int64.Parse(tmp[6]);
			M = Int64.Parse(tmp[7]);
			Gen();
			long res = 0;
			for (int p1 = 0; p1 < 9; ++p1)
			{
				for (int p2 = p1 + 1; p2 < 9; ++p2)
				{
					for (int p3 = p2 + 1; p3 < 9; ++p3)
					{
						if (((p1 / 3 + p2 / 3 + p3 / 3) % 3 == 0) &&
							(((p1 % 3) + (p2 % 3) + (p3 % 3)) % 3 == 0))
						{
							long c1 = pos[p1 / 3, p1 % 3];
							long c2 = pos[p2 / 3, p2 % 3];
							long c3 = pos[p3 / 3, p3 % 3];
							//if (p1 == p2)
							//{
							//    c2--;
							//}
							//if (p3 == p1)
							//{
							//    c3--;
							//}
							//if (p3 == p2)
							//{
							//    c3--;
							//}
							//if (c1 < 0 || c2 < 0 || c3 < 0)
							//{
							//}
							//else
							{
								res += c1 * c2 * c3;
							}
						}
					}
				}
			}
			//for (int p1 = 0; p1 < 9; ++p1)
			//{
			//    res -= pos[p1 / 3, p1 % 3] * pos[p1 / 3, p1 % 3] * pos[p1 / 3, p1 % 3];
			//}
			//for (int p1 = 0; p1 < 9; ++p1)
			//{
			//    for (int p2 = p1 + 1; p2 < 9; ++p2)
			//    {
			//        if (((p1 / 3 + p2 / 3 + p2 / 3) % 3 == 0) &&
			//            (((p1 % 3) + (p2 % 3) + (p2 % 3)) % 3 == 0))
			//        {
			//            long c1 = pos[p1 / 3, p1 % 3];
			//            long c2 = pos[p2 / 3, p2 % 3];
			//            long c3 = pos[p2 / 3, p2 % 3];
			//            res -= c1 * c2 * c3;
			//        }
			//    }
			//}
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (pos[i, j] > 2)
					{
						res += pos[i, j] * (pos[i, j] - 1) * (pos[i, j] - 2) / 6;
					}
				}
			}
			//for (int p1 = 0; p1 < 9; ++p1)
			//{
			//    for (int p2 = p1 + 1; p2 < 9; ++p2)
			//    {
			//        if (p1 != p2)
			//        {
			//            if (((p1 / 3 + p2 / 3 + p2 / 3) % 3 == 0) &&
			//                (((p1 % 3) + (p2 % 3) + (p2 % 3)) % 3 == 0))
			//            {
			//                res += pos[p1 / 3, p1 % 3] * (pos[p2 / 3, p2 % 3]) * (pos[p2 / 3, p2 % 3] - 1);
			//            }
			//        }
			//    }
			//}
			//res += pos[0, 1] * pos
			//for (int i = 0; i < n; ++i)
			//{
			//    for (int j = i + 1; j < n; ++j)
			//    {
			//        for (int k = j + 1; k < n; ++k)
			//        {
			//            var x1 = xs[i];
			//            var x2 = xs[j];
			//            var x3 = xs[k];
			//            var y1 = ys[i];
			//            var y2 = ys[j];
			//            var y3 = ys[k];
			//            if ((x1 + x2 + x3) % 3 == 0 &&
			//                (y1 + y2 + y3) % 3 == 0)
			//            {
			//                ++res;
			//            }
			//        }
			//    }
			//}
			fout.WriteLine(res);
		}

		static StreamReader fin;
		static StreamWriter fout;

		static void Main(string[] args)
		{
			DateTime s = DateTime.Now;
			using (fout = new StreamWriter("../../out.txt"))
			{
				using (fin = new StreamReader("../../in.in"))
				{

					int n = Int32.Parse(fin.ReadLine());

					for (int i = 1; i <= n; ++i)
					{
						fout.Write("Case #{0}: ", i);
						new Program().Solve();
					}

				}
			}

			TimeSpan d = DateTime.Now - s;

			Console.WriteLine(d);
			Console.ReadLine();
		}
	}
}