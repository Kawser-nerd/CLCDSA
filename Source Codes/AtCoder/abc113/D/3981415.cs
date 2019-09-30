using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

// ABC 113
// https://atcoder.jp/contests/dp/tasks
namespace ABC113D_Amidakuji
{
	public class Solver : SolverBase
	{
		// [????] = ???????????
		static readonly long[] Total = {0, 1, 2, 3, 5, 8, 13, 21, 34};
		// W3:??3?????????????????????
		//    W3[1]? ??1-2 ?????????????
		//    ?????????1, 2, ... ???
		static readonly long[] W1 = { 0, 0 };
		static readonly long[] W2 = { 0, 1, 0 };
		static readonly long[] W3 = { 0, 1, 1, 0 };
		static readonly long[] W4 = { 0, 2, 1, 2, 0 };
		static readonly long[] W5 = { 0, 3, 2, 2, 3, 0 };
		static readonly long[] W6 = { 0, 5, 3, 4, 3, 5, 0 };
		static readonly long[] W7 = { 0, 8, 5, 6, 6, 5, 8, 0 };
		static readonly long[] W8 = { 0, 13, 8, 10, 9, 10, 8, 13, 0 };

		static readonly List<long[]> WAry = new List<long[]>{ W1, W2, W3, W4, W5, W6, W7, W8 };

		const int MOD = 1000000007;
		public void Run() {
			var ary = ReadIntArray();
			var H = ary[0];
			var W = ary[1];
			var K = ary[2];

			if (W == 1) {
				WriteLine(1);
				return;
			}

			var WP = WAry[W - 1];

			// DP[pos??][???w??] = ??????????????
			//   ???????pos=0, w=1???? 1 ?????????0
			//   ????pos1, w1-2 ????????????
			//   pos=1, w=1 ????????pos=1, w=2 ???????????
			//   ??????? mod MOD ????
			long[,] DP = new long[H+1, W+2];
			DP[0, 1] = 1;

			// ??DP
			for (int pos = 0; pos < H; pos++) {
				for (int w = 1; w <= W; w++) {
					if (DP[pos, w] == 0) continue;

					// w-1, w, w+1 ?????????????
					var lp = WP[w - 1];
					var rp = WP[w];
					var cp = Total[W] - lp - rp;

					// ??
					if (0 < lp) {
						// ????
						DP[pos + 1, w - 1] = (DP[pos + 1, w - 1] + DP[pos, w] * lp) % MOD ;
					}
					if (0 < rp) {
						// ????
						DP[pos + 1, w + 1] = (DP[pos + 1, w + 1] + DP[pos, w] * rp) % MOD;
					}
					// ????????
					DP[pos + 1, w] = (DP[pos + 1, w] + DP[pos, w] * cp) % MOD;
				}
			}
			DumpDP(DP);

			// K??????????
			var ans = DP[H, K];
			WriteLine(ans);
		}

#if !MYHOME
		public static void Main(string[] args) {
			new Solver().Run();
		}
#endif
	}


	public static class Util
	{
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