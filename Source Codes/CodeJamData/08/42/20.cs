using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApplication2
{
	class Program
	{
		static void parseTriplet(TextReader tr, out int x, out int y, out int z)
		{
			int[] arr = Array.ConvertAll<string, int>(tr.ReadLine().Split(' '), delegate(string s) { return int.Parse(s); });
			x = arr[0];
			y = arr[1];
			z = arr[2];
		}

		static void Output(int cas, object s)
		{
			Console.WriteLine("Case #{0}: {1}", cas, s);
		}

		static void Output(int cas, int x1, int y1, int x2, int y2)
		{
			Console.WriteLine("Case #{0}: 0 0 {1} {2} {3} {4}", cas, x1, y1, x2, y2);
		}

		static bool find(int cas, int n, int m, int a)
		{
			if (n*m<a) {
				Output(cas, "IMPOSSIBLE");
				return false;
			}
			for (int x2=1; x2<=n; ++x2) {
				for (int y1=(a+x2-1)/x2; y1<=m; ++y1) {
					int rest = x2*y1-a;
					if (rest==0) {
						Output(cas, 1, y1, x2, 0);
						return true;
					}
					for (int x1=(rest+m-1)/m; x1<=a && x1<=rest; ++x1) 
						if (rest%x1==0) {
							Output(cas, x1, y1, x2, rest/x1);
							return true;
						}
				}
			}
			Output(cas, "IMPOSSIBLE");
			return false;
		}
		static void Main(string[] args)
		{
			using (TextReader tr = new StreamReader(@"d:\work\X2ND\GCJ\ConsoleApplication2\ConsoleApplication2\B-small-attempt0.in"))
			{
				int c = int.Parse(tr.ReadLine());
				for (int test=1; test<=c; ++test)
				{
					int n, m, a;
					parseTriplet(tr, out n, out m, out a);
					find(test, n, m, a);
				}
			}

		}
	}
}
