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

		class node
		{
			public int s, t, f = 0;

			public node(int s, int t)
			{
				this.s = s;
				this.t = t;
			}

			public override string ToString()
			{
				return String.Format("S = {0}, T = {1}, F = {2}", s, t, f);
			}
		}

		int na, nb, T;

		static node SN = new node(0, 0);

		List<node>[] chart;

		int maxFlow(int src, int ter, int n)
		{
			var path = new node[n];
			Queue<int> que = new Queue<int>();
			while (true)
			{
				for (int i = 0; i < n; ++i)
				{
					path[i] = null;
				}

				que.Clear();
				que.Enqueue(src);
				path[src] = SN;
				while (que.Count > 0 && path[ter] == null)
				{
					var cnode = que.Dequeue();
					var sib = chart[cnode];
					foreach (var s in sib)
					{
						if (s.s == cnode && s.f == 0 && path[s.t] == null)
						{
							path[s.t] = s;
							que.Enqueue(s.t);
						}
						else if (s.t == cnode && s.f == 1 && path[s.s] == null)
						{
							path[s.s] = s;
							que.Enqueue(s.s);
						}
					}
				}
				if (path[ter] == null)
				{
					int mf = 0;
					foreach (var sn in chart[src])
					{
						mf += sn.f;
					}
					return mf;
				}

				int curId = ter;
				while (curId != src)
				{
					var curN = path[curId];
					if (curId == curN.t)
					{
						curN.f = 1;
						curId = curN.s;
					}
					else
					{
						curN.f = 0;
						curId = curN.t;
					}
				}
			}
		}

		int minTrain(List<DateTime> arr, List<DateTime> dep)
		{
			int n1 = arr.Count;
			int n2 = dep.Count;
			int src = n1 + n2;
			int ter = src + 1;
			int ntot = ter + 1;

			chart = new List<node>[ntot];
			for (int i = 0; i < ntot; ++i)
			{
				chart[i] = new List<node>();
			}
			for (int i = 0; i < n1; ++i)
			{
				var cn = new node(src, i);
				chart[i].Add(cn);
				chart[src].Add(cn);
			}
			for (int i = n1; i < src; ++i)
			{
				var cn = new node(i, ter);
				chart[i].Add(cn);
				chart[ter].Add(cn);
			}
			for (int i = 0; i < n1; ++i)
			{
				for (int j = 0; j < n2; ++j)
				{
					if (arr[i] <= dep[j])
					{
						var id_d = j + n1;
						var cn = new node(i, id_d);
						chart[i].Add(cn);
						chart[id_d].Add(cn);
					}
				}
			}

			return n2 - maxFlow(src, ter, ntot);
		}

		public void Solve()
		{
			T = Int32.Parse(fin.ReadLine());
			var tmp = fin.ReadLine().SplitByWhiteSpaces();
			na = Int32.Parse(tmp[0]);
			nb = Int32.Parse(tmp[1]);

			List<DateTime> a2b_start = new List<DateTime>(na);
			List<DateTime> a2b_end = new List<DateTime>(na);
			List<DateTime> b2a_start = new List<DateTime>(nb);
			List<DateTime> b2a_end = new List<DateTime>(nb);

			for (int i = 0; i < na; ++i)
			{
				tmp = fin.ReadLine().SplitByWhiteSpaces();
				a2b_start.Add(DateTime.Parse(tmp[0]));
				a2b_end.Add(DateTime.Parse(tmp[1]).AddMinutes(T));
			}
			for (int i = 0; i < nb; ++i)
			{
				tmp = fin.ReadLine().SplitByWhiteSpaces();
				b2a_start.Add(DateTime.Parse(tmp[0]));
				b2a_end.Add(DateTime.Parse(tmp[1]).AddMinutes(T));
			}

			var fromA = minTrain(b2a_end, a2b_start);
			var fromB = minTrain(a2b_end, b2a_start);
			fout.WriteLine("{0} {1}", fromA, fromB);
		}
	}
}