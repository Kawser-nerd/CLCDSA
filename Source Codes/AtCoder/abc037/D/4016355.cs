using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

// G?????: 
// ABC037: D: ??
// https://abc037.contest.atcoder.jp/tasks/abc037_d
// https://qiita.com/drken/items/03c7db44ccd27820ea0d
// https://atcoder.jp/contests/dp/tasks
namespace EducationalDPContest.G_ABC037D
{
	using static Util;

	// BFS ??????????????? DP
	// https://qiita.com/drken/items/03c7db44ccd27820ea0d
	public class Solver2 : SolverBase
	{
		public void Run() {
			var ary = ReadIntArray();
			var H = ary[0];
			var W = ary[1];

			// ????????????->?????????????????
			// ????????????????????????????
			// ????????????????

			// ??????????????????????????????
			// ?????????????…


			// [y] = ????????????????????
			int[] indegrees = new int[H * W];
			// List??? ? x -> y ???????
			List<int>[] Edges = new List<int>[H * W];
			for (int i = 0; i < H * W; i++) {
				Edges[i] = new List<int>();
			}

			int[] lastRow = null;
			for (int i = 0; i < H; i++) {
				var row = ReadIntArray();

				// ????????
				for (int j = 0; j < W-1; j++) {
					if (row[j] < row[j + 1]) {
						// ????????????????????
						Edges[i * W + j + 1].Add(i * W + j);
						indegrees[i * W + j]++;
					} else if (row[j] > row[j + 1]) {
						// ???
						Edges[i * W + j].Add(i * W + j + 1);
						indegrees[i * W + j + 1]++;
					}
				}
				// ????????
				if (lastRow != null) {
					for (int j = 0; j < W; j++) {
						if (row[j] < lastRow[j]) {
							// ????????????????????
							Edges[(i - 1) * W + j].Add(i * W + j);
							indegrees[i * W + j]++;
						} else if (row[j] > lastRow[j]) {
							// ???
							Edges[i * W + j].Add((i - 1) * W + j);
							indegrees[(i - 1) * W + j]++;
						}
					}
				}
				lastRow = row;
			}

			// BFS???????==0 ????
			Queue<int> que = new Queue<int>();
			for (int i = 0; i < H * W ; i++) {
				if (indegrees[i] == 0)
					que.Enqueue(i);
			}

			// ????????????
			long[] DP = new long[H * W];
			InitArray(DP, 1);	// ??????????????????????

			// BFS
			while (0 < que.Count) {
				var x = que.Dequeue();

				foreach (var y in Edges[x]) {
					// ???????
					indegrees[y]--;

					// y????????
					DP[y] = (DP[y] + DP[x]) % MOD;

					if (indegrees[y] == 0) {
						// y??????0???y?queue????
						que.Enqueue(y);
					}
				}
			}

			long ans = 0;
			for (int i = 0; i < H * W; i++) {
				ans = (ans + DP[i]) % MOD;
			}
			WriteLine(ans);
		}

#if !MYHOME
		public static void Main(string[] args) {
			new Solver2().Run();
		}
#endif
	}

	public static class Util
	{
		public readonly static long MOD = 1000000007;

		public static string DumpToString<T>(IEnumerable<T> array) where T : IFormattable {
			var sb = new StringBuilder();
			foreach (var item in array) {
				sb.Append(item);
				sb.Append(", ");
			}
			return sb.ToString();
		}

		public static void InitArray<T>(T[] ary, T value) {
			for (int i = 0; i < ary.Length; i++) {
				ary[i] = value;
			}
		}

		public static void InitDP<T>(T[,] dp, T value) {
			for (int i = 0; i < dp.GetLength(0); i++) {
				for (int j = 0; j < dp.GetLength(1); j++) {
					dp[i, j] = value;
				}
			}
		}

		public static T Max<T>(params T[] nums) where T : IComparable {
			if (nums.Length == 0) return default(T);

			T max = nums[0];
			for (int i = 1; i < nums.Length; i++) {
				max = max.CompareTo(nums[i]) > 0 ? max : nums[i];
			}
			return max;
		}
		public static T Min<T>(params T[] nums) where T : IComparable {
			if (nums.Length == 0) return default(T);

			T min = nums[0];
			for (int i = 1; i < nums.Length; i++) {
				min = min.CompareTo(nums[i]) < 0 ? min : nums[i];
			}
			return min;
		}

		/// <summary>
		/// ??????? ary ???????????????
		/// ????????/?????????
		/// </summary>
		public static bool HasDuplicateInSortedArray<T>(T[] ary) where T : IComparable, IComparable<T> {
			if (ary.Length <= 1) return false;

			var lastNum = ary[ary.Length - 1];

			foreach (var n in ary) {
				if (lastNum.CompareTo(n) == 0) {
					return true;
				} else {
					lastNum = n;
				}
			}
			return false;
		}

		/// <summary>
		/// ????
		/// ??????????idx???
		/// ???????????? ary.Length ???
		/// ??ary??????????????????????????????
		/// ????IsOK(...)???????????????????????
		/// </summary>
		/// <param name="ary">?????? ???????????</param>
		/// <param name="key">??? ???????????IsOK?true???????index???</param>
		public static int BinarySearch<T>(T[] ary, T key) where T : IComparable, IComparable<T> {
			int left = -1;
			int right = ary.Length;

			while (1 < right - left) {
				var mid = left + (right - left) / 2;

				if (IsOK(ary, mid, key)) {
					right = mid;
				} else {
					left = mid;
				}
			}

			// left ??????????????right ?????????????????
			return right;
		}
		public static bool IsOK<T>(T[] ary, int idx, T key) where T : IComparable, IComparable<T> {
			// key <= ary[idx] ?????
			return key.CompareTo(ary[idx]) <= 0;
		}
	}

	public class SolverBase
	{
		virtual protected string ReadLine() => Console.ReadLine();
		virtual protected int ReadInt() => int.Parse(ReadLine());
		virtual protected long ReadLong() => long.Parse(ReadLine());
		virtual protected string[] ReadStringArray() => ReadLine().Split(' ');
		virtual protected int[] ReadIntArray() => ReadLine().Split(' ').Select<string, int>(s => int.Parse(s)).ToArray();
		virtual protected long[] ReadLongArray() => ReadLine().Split(' ').Select<string, long>(s => long.Parse(s)).ToArray();
		virtual protected double[] ReadDoubleArray() => ReadLine().Split(' ').Select<string, double>(s => double.Parse(s)).ToArray();
		virtual protected void WriteLine(string line) => Console.WriteLine(line);
		virtual protected void WriteLine(double d) => Console.WriteLine($"{d:F9}");
		virtual protected void WriteLine<T>(T value) where T : IFormattable => Console.WriteLine(value);

		[Conditional("DEBUG")]
		protected void Dump(string s) => Console.WriteLine(s);
		[Conditional("DEBUG")]
		protected void Dump(char c) => Console.WriteLine(c);
		[Conditional("DEBUG")]
		protected void Dump(double d) => Console.WriteLine($"{d:F9}");
		[Conditional("DEBUG")]
		protected void Dump<T>(IEnumerable<T> array) where T : IFormattable {
			string s = Util.DumpToString(array);
			// Console???????UnitTest?????????????????
			Console.WriteLine(s);
			//_writer.WriteLine(s);
		}
		[Conditional("DEBUG")]
		protected void DumpGrid<T>(IEnumerable<IEnumerable<T>> arrayOfArray) where T : IFormattable {
			var sb = new StringBuilder();
			foreach (var a in arrayOfArray) {
				sb.AppendLine(Util.DumpToString(a));
			}
			// Console???????UnitTest?????????????????
			Console.WriteLine(sb.ToString());
			//_writer.WriteLine(sb.ToString());
		}
		[Conditional("DEBUG")]
		protected void DumpDP<T>(T[,] dp) where T : IFormattable {
			var sb = new StringBuilder();
			for (int i = 0; i < dp.GetLength(0); i++) {
				for (int j = 0; j < dp.GetLength(1); j++) {
					sb.Append(dp[i, j]);
					sb.Append(", ");
				}
				sb.AppendLine();
			}
			Console.WriteLine(sb.ToString());
		}
	}
}