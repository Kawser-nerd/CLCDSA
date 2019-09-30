using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
	class Program
	{
		long W, H, R;
		long[] r, c;
		long[,] memo;

		long search(int cr, int cc)
		{
			if (cr >= H || cc >= W)
			{
				return 0;
			}
			if (cr == H - 1 && cc == W - 1)
			{
				return 1;
			}
			if (memo[cr, cc] >= 0)
			{
				return memo[cr, cc];
			}
			for (int i = 0; i < R; ++i)
			{
				if (r[i] == cr && c[i] == cc)
				{
					return memo[cr, cc] = 0;
				}
			}

			var res = search(cr + 2, cc + 1) + search(cr + 1, cc + 2);
			res %= 10007;
			return memo[cr, cc] = res;
		}

		public void Solve()
		{

			var tmp = GetLine();
			H = Long(tmp[0]);
			W = Long(tmp[1]);
			R = Long(tmp[2]);

			r = new long[R];
			c = new long[R];
			memo = new long[H, W];
			for (int i = 0; i < H; ++i)
			{
				for (int j = 0; j < W; ++j)
				{
					memo[i, j] = -1;
				}
			}

			for (int i = 0; i < R; ++i)
			{
				tmp = GetLine();
				r[i] = Long(tmp[0]) - 1;
				c[i] = Long(tmp[1]) - 1;
			}

			
			
			
			
			
			fout.WriteLine(search(0, 0));
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

		string[] GetLine()
		{
			return fin.ReadLine().SplitByWhiteSpaces();
		}
		int Int(string a)
		{
			return Int32.Parse(a);
		}
		long Long(string a)
		{
			return Int64.Parse(a);
		}
	}
	static class Ext
	{

		static char[] emptyChars = "\r\n\t ".ToCharArray();

		public static string[] SplitByWhiteSpaces(this string source)
		{
			return source.Split(emptyChars, StringSplitOptions.RemoveEmptyEntries);
		}
	}
}