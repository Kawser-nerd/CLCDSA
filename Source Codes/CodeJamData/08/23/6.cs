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
		int[] cards;
		bool[] removed;
		int K, n;
		List<int> ds;

		public void Solve()
		{
			K = int.Parse(fin.ReadLine());
			cards = new int[K];
			removed = new bool[K];
			var tmp = fin.ReadLine().SplitByWhiteSpaces();
			ds = new List<int>();
			for (int i = 1; i < tmp.Length; ++i)
			{
				ds.Add(int.Parse(tmp[i]) - 1);
			}
			int curIdx = 0;
			for (int i = 1; i <= K; ++i)
			{
				for (int j = 1; j < i; )
				{
					if (!removed[curIdx])
					{
						++j;
					}
					curIdx = (curIdx + 1) % K;
				}
				while (removed[curIdx])
				{
					curIdx = (curIdx + 1) % K;
				}
				cards[curIdx] = i;
				removed[curIdx] = true;
				curIdx = (curIdx + 1) % K;
			}

			for (int i = 0; i < ds.Count; ++i)
			{
				fout.Write(" {0}", cards[ds[i]]);
			}
				fout.WriteLine();
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
						fout.Write("Case #{0}:", i);
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