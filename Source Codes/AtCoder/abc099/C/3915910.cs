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
		int[] Items;

		public void Run() {
			UpperW = ReadInt();

			Items = Sixes.Union(Nines).ToArray();
			Array.Sort(Items);
			//Array.Reverse(Items);
			N = Items.Length;

			// ????????????DP???
			//var ans = DpSolve();
			// ????????????DP?1?????????
			//var ans = DpSolveOne();
			// ???????
			//var ans = MemoizeRecursive();
			// ??DP???
			//var ans = ReceiveDP();
			// ??DP???
			//var ans = DistributeDP();
			// BFS??????????
			var ans = Bfs();
			WriteLine(ans);
		}

		// ??DP
		int ReceiveDP() {
			int[] DP = new int[UpperW + 1];
			for (int i = 0; i < UpperW + 1; i++) {
				DP[i] = 1 << 29;	// INF
			}
			DP[0] = 0;

			// ?? DP --- dp[w] ?????????????????
			for (int w = 1; w < UpperW+1; w++) {
				for (int curW = 1; curW <= w; curW *= 6) {
					// ??? = ??? or ???+1
					DP[w] = Math.Min(DP[w], DP[w - curW] + 1);
				}
				for (int curW = 9; curW <= w; curW *= 9) {
					DP[w] = Math.Min(DP[w], DP[w - curW] + 1);
				}
			}
			return DP[UpperW];
		}
		// ??DP
		int DistributeDP() {
			int[] DP = new int[UpperW + 1];
			for (int i = 0; i < UpperW + 1; i++) {
				DP[i] = 1 << 29;    // INF
			}
			DP[0] = 0;

			// ??DP --- dp[w] ?????????????????????
			for (int w = 0; w < UpperW; w++) {
				for (int curW = 1; w + curW <= UpperW; curW *= 6) {
					// ??? = ??? or ???+1
					DP[w + curW] = Math.Min(DP[w + curW], DP[w] + 1);
				}
				for (int curW = 9; w + curW <= UpperW; curW *= 9) {
					DP[w + curW] = Math.Min(DP[w + curW], DP[w] + 1);
				}
			}
			return DP[UpperW];
		}

		// BFS???????
		int Bfs() {
			int[] DP = new int[UpperW+1];
			for (int i = 0; i < UpperW+1; i++) {
				DP[i] = -1;
			}
			DP[0] = 0;

			Queue<int> que = new Queue<int>();
			que.Enqueue(0);

			// BFS
			while (0 < que.Count) {
				var v = que.Dequeue();

				for (int w = 1; v + w <= UpperW; w *= 6) {
					if (DP[v + w] == -1) {
						DP[v + w] = DP[v] + 1;
						// ?????????????????
						// BFS?????????????????
						que.Enqueue(v + w);
					}
				}
				for (int w = 9; v + w <= UpperW; w *= 9) {
					if (DP[v + w] == -1) {
						DP[v + w] = DP[v] + 1;
						que.Enqueue(v + w);
					}
				}
			}
			// BFS 1???3?????DP?????
			// ???? -1
			//  w->0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 ...
			//0    0                                              ...
			//1    0 1         1     1                            ...
			//2    0 1 2       1 2   1  2     2        2        2 ...
			//3    0 1 2 3     1 2 3 1  2  3  2  3     2  3     2 ...
			//??????
			return DP[UpperW];
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

		// ????????????DP ?1????????
		int DpSolveOne() {
			int[] DP = new int[UpperW + 1];
			for (int i = 0; i < UpperW+1; i++) {
				DP[i] = 1 << 29;
			}
			DP[0] = 0;

			//DP?????2?????????
			//???????????????????????????????????????????????
			//??????????????
			for (int i = 0; i < N; i++) {
				for (int w = Items[i]; w < UpperW+1; w++) {
					DP[w] = Math.Min(DP[w], DP[w - Items[i]] + 1);
				}
			}
			return DP[UpperW];
		}

		// ???????????????????
		// ?Qiita??????????C#??StackOverFlow??????
		//  ?1???????????????…?C++???????????
		//   ??????????????????6/9??????rest??????????????????
		int[] Memo;
		int MemoizeRecursive() {
			Memo = new int[UpperW + 1];
			for (int i = 0; i < UpperW+1; i++) {
				Memo[i] = -1;
			}
			return Recurse(UpperW);
		}
		int Recurse(int rest) {
			if (rest < 6) return rest;

			// ?????
			if (Memo[rest] != -1)
				return Memo[rest];

			// 6??????rest??????9??????rest????????
			int result = 1 << 29; // INF

			var w = Sixes.Where((i) => i <= rest).Max();
			result = Math.Min(result, Recurse(rest - w) + 1);

			w = Nines.Where((i) => i <= rest).Max();
			result = Math.Min(result, Recurse(rest - w) + 1);

			Memo[rest] = result;
			return result;
		}

#if !MYHOME
		public static void Main(string[] args) {
			new Solver().Run();
		}
#endif
	}
}