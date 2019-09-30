using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2009
{
	class BribeThePrisoners
	{
		public void SloveFile(string file)
		{
			using (StreamReader inf = new StreamReader(file, Encoding.ASCII))
			using (StreamWriter outf = new StreamWriter(file + ".out", false, Encoding.ASCII)) {
				int cases = int.Parse(inf.ReadLine());
				for (int i = 1; i <= cases; i++) {
					string l1 = inf.ReadLine();
					string[] l1s = l1.Split();
					int P = int.Parse(l1s[0]);
					int Q = int.Parse(l1s[1]);

					string l2 = inf.ReadLine();
					int ret = Slove(P, Q, l2);
					outf.WriteLine("Case #{0}: {1}", i, ret);
					Console.WriteLine("Case #{0}: {1}", i, ret);
				}
			}
		}

		public int Slove(int p, int q, string input)
		{
			P = p;
			string[] ss = input.Split(' ');
			int[] list = new int[ss.Length];
			for (int i = 0; i < ss.Length; i++)
				list[i] = int.Parse(ss[i]);

			MinValue = int.MaxValue;
			Perm(list, 0, ss.Length - 1);
			return MinValue;
		}

		void Swap(ref int a, ref int b)
		{
			int m = a;
			a = b;
			b = m;
		}

		void Perm(int[] list, int k, int m)
		{
			int i;
			if (k > m) {
				CalcValue(list);
			} else {
				for (i = k; i <= m; i++) {
					Swap(ref list[k], ref list[i]);
					Perm(list, k + 1, m);
					Swap(ref list[k], ref list[i]);
				}
			}
		}

		void CalcValue(int[] list)
		{
			int cost = 0;
			int[] rooms = new int[P];
			for (int i = 0; i < P; i++)
				rooms[i] = 1;

			for (int i = 0; i < list.Length; i++) {
				//Console.Write("{0} ", list[i]);
				int c = list[i] - 1;
				rooms[c] = 0;

				for (int j = c - 1; j >= 0; j--) {
					if (rooms[j] == 1)
						cost++;
					else
						break;
				}

				for (int j = c + 1; j < P; j++) {
					if (rooms[j] == 1)
						cost++;
					else
						break;
				}
			}

			if (cost < MinValue)
				MinValue = cost;
			//Console.WriteLine(" Cost: {0}", cost);
		}

		int P;
		int N;
		int MinValue;
	}
}
