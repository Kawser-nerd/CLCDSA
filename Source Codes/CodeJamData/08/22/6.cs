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

	public class DisjointSet
	{
		public readonly int size;
		public int[] rank;

		public int Size
		{
			get
			{
				return size;
			}
		}

		public DisjointSet(int size)
		{
			this.size = size;
			rank = new int[size];
			for (int i = 0; i < size; ++i)
			{
				rank[i] = -1;
			}
		}

		public void Union(int i, int j)
		{
			i = Find(i);
			j = Find(j);
			if (i == j)
			{
				return;
			}

			int tot = rank[i] + rank[j];

			if (rank[i] < rank[j])
			{
				rank[j] = i;
				rank[i] = tot;
			}
			else
			{
				rank[i] = j;
				rank[j] = tot;
			}
		}

		public bool IsUnited(int i, int j)
		{
			return Find(i) == Find(j);
		}

		private int Find(int i)
		{
			int root = i;
			while (rank[root] >= 0)
			{
				root = rank[root];
			}

			while (i != root)
			{
				int tmp = i;
				i = rank[i];
				rank[tmp] = root;
			}
			return root;
		}
	}

	class Program
	{
		int A, B, P;

		public void Solve()
		{
			var tmp = fin.ReadLine().SplitByWhiteSpaces();
			A = Int32.Parse(tmp[0]);
			B = Int32.Parse(tmp[1]);
			P = Int32.Parse(tmp[2]);
			IList<int> pr = GetPrimes((int)B);
			int pstart = 0;
			for (pstart = 0; pstart < pr.Count; ++pstart)
			{
				if (pr[pstart] >= P)
				{
					break;
				}
			}

			int res = B - A + 1;
			DisjointSet ds = new DisjointSet(B - A + 1);
			for (int i = A; i <= B; ++i)
			{
				for (int j = i + 1; j <= B; ++j)
				{
					if (!ds.IsUnited(i - A, j - A))
					{
						bool f = true;
						for (int k = pstart; k < pr.Count && f; ++k)
						{
							if ((i % pr[k] == 0) && (j % pr[k] == 0))
							{
								f = false;
							}
						}
						if (!f)
						{
							res--;
							ds.Union(i - A, j - A);
						}
					}
				}
			}

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

		public static IList<int> GetPrimes(int n)
		{
			int root = (int)Math.Sqrt((double)n);

			List<int> primes = new List<int>();

			bool[] flags = new bool[n + 1];

			for (int i = 2; i <= root; ++i)
			{
				if (!flags[i])
				{
					primes.Add(i);
					for (int j = i; j <= n; j += i)
					{
						flags[j] = true;
					}
				}
			}

			for (int i = root + 1; i <= n; ++i)
			{
				if (!flags[i])
				{
					primes.Add(i);
				}
			}

			return primes;
		}
	}
}