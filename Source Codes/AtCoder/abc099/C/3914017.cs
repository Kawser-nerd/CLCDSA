using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace ABC099C_StrangeBank
{
	// DP, ????, BFS ???????????
	// https://atcoder.jp/contests/abc099/tasks/abc099_c
	// https://qiita.com/drken/items/ace3142967c4f01d42e9#%E8%A7%A3%E6%B3%95-1-1-%E3%83%88%E3%83%83%E3%83%97%E3%83%80%E3%82%A6%E3%83%B3%E3%81%AB-n-%E3%82%92%E9%99%8D%E4%B8%8B%E3%81%97%E3%81%A6%E3%81%84%E3%81%8F%E3%83%A1%E3%83%A2%E5%8C%96%E5%86%8D%E5%B8%B0
	public class Solver
	{
		virtual protected string ReadLine() => Console.ReadLine();
		virtual protected int ReadInt() => int.Parse(ReadLine());
		virtual protected long ReadLong() => long.Parse(ReadLine());
		virtual protected string[] ReadStringArray() => ReadLine().Split(' ');
		virtual protected int[] ReadIntArray() => ReadLine().Split(' ').Select<string, int>(s => int.Parse(s)).ToArray();
		virtual protected long[] ReadLongArray() => ReadLine().Split(' ').Select<string, long>(s => long.Parse(s)).ToArray();
		virtual protected void WriteLine(string line) => Console.WriteLine(line);
		virtual protected void WriteLine<T>(T value) where T : IFormattable => Console.WriteLine(value);

		[Conditional("DEBUG")]
		void Dump<T>(IEnumerable<T> array) {
			var sb = new StringBuilder();
			foreach (var item in array) {
				sb.Append(item);
				sb.Append(", ");
			}
			// Console???????UnitTest?????????????????
			Console.WriteLine(sb.ToString());
			//_writer.WriteLine(sb.ToString());
		}

		int N;
		int UpperW;

		readonly int[] Sixes = { 1, 6, 36, 216, 1296, 7776, 46656 };
		readonly int[] Nines = { 1, 9, 81, 729, 6561, 59049 };
		readonly int[] Items = { 1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049 };

		public void Run() {
			UpperW = ReadInt();
			N = Items.Length;

			// ????????????DP???
			var ans = DpSolve();
			// ???????
			//var ans = MemoizeRecursive();
			// ??????
			//var ans = SearchAll(0, UpperW);
			WriteLine(ans);
		}

		// ????????????DP
		int DpSolve() {
			int[,] DP = new int[N + 1, UpperW + 1];
			for (int i = 0; i < N + 1; i++) {
				for (int j = 0; j < UpperW + 1; j++) {
					DP[i, j] = 1 << 29;	// INF
				}
			}
			// ?????0?
			for (int i = 0; i < N + 1; i++) {
				DP[i, 0] = 0;
			}

			for (int i = 0; i < N; i++) {
				for (int w = 0; w < UpperW + 1; w++) {
					if (w < Items[i]) {
						// ????????????????????????????
						// ?????? or ?????
						DP[i + 1, w] = Math.Min(DP[i, w], DP[i + 1, w]);
					} else {
						// ???????????????
						// ?????value + ??value or ?????
						DP[i + 1, w] = Math.Min(DP[i + 1, w - Items[i]] + 1, DP[i, w]);
						//??????? 1?, 6?, 9? ???DP??????
						//????INF
						//  w->0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18...
						//0    0                                             ...
						//1    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18...
						//6    0 1 2 3 4 5 1 2 3 4  5  6  2  3  4  5  6  7  3...
						//9    0 1 2 3 4 5 1 2 3 1  2  3  2  3  4  2  3  4  2...
					}
				}
			}

			return DP[N, UpperW];
		}

#if !MYHOME
		public static void Main(string[] args) {
			new Solver().Run();
		}
#endif
	}
}