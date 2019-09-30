using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace ABC119.C
{
	using static Util;

	public class Solver : SolverBase
	{
		int N;
		int[] BAry;
		int[] Targets = new int[3];
		public void Run() {
			var ary = ReadIntArray();
			N = ary[0];
			Targets[0] = ary[1];
			Targets[1] = ary[2];
			Targets[2] = ary[3];
			BAry = new int[N];
			for (int i = 0; i < N; i++) {
				BAry[i] = ReadInt();
			}

			// ??????
			var ans = Recurse(new List<int>());
			WriteLine(ans);
		}

		// MP?????????
		// uses: List<int>
		//   0:A 1:B 2:C 4:????
		int Recurse(IList<int> uses) {
			if (uses.Count == N) return CalcMP(uses);

			int minMP = int.MaxValue;
			for (int i = 0; i < 4; i++) {
				var u2 = new List<int>(uses);
				u2.Add(i);
				var mp = Recurse(u2);

				if (mp < minMP) minMP = mp;
			}
			return minMP;
		}

		int CalcMP(IList<int> uses) {
			var blen = new int[3];
			var mp = new int[3];
			for (int i = 0; i < N; i++) {
				var u = uses[i];
				if (u == 3) continue;

				// ????????????MP???
				if (0 != blen[u]) mp[u] += 10;

				// ?????????
				blen[u] += BAry[i];
			}

			for (int i = 0; i < 3; i++) {
				// 1??????????????NG -> INT_MAX???
				if (blen[i] == 0) return int.MaxValue;

				// ??????MP???
				mp[i] += Math.Abs(blen[i] - Targets[i]);
			}

			return mp.Sum();
		}

#if !MYHOME
		public static void Main(string[] args) {
			new Solver().Run();
		}
#endif
	}

	public static class Util
	{
		/// <summary>
		/// ????? ??????????? 
		/// ?a,b?????0????0?????????0????0????
		/// </summary>
		public static int Gcd(int a, int b) {
			if (a < b)
				// ??????????????
				return Gcd(b, a);
			while (b != 0) {
				var remainder = a % b;
				a = b;
				b = remainder;
			}
			return a;
		}
		public static int Gcd(params int[] nums) {
			if (nums == null || nums.Length < 1)
				throw new ArgumentException(nameof(nums));
			if (nums.Length == 1)
				return nums[0];

			var g = Gcd(nums[0], nums[1]);
			for (int i = 2; i < nums.Length; i++) {
				g = Gcd(g, nums[i]);
			}
			return g;
		}

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
		public static void InitDP2<T>(T[,] dp, T value) {
			for (int i = 0; i < dp.GetLength(0); i++) {
				for (int j = 0; j < dp.GetLength(1); j++) {
					dp[i, j] = value;
				}
			}
		}
		public static void InitDP3<T>(T[,,] dp, T value) {
			for (int i = 0; i < dp.GetLength(0); i++) {
				for (int j = 0; j < dp.GetLength(1); j++) {
					for (int k = 0; k < dp.GetLength(2); k++) {
						dp[i, j, k] = value;
					}
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
		//virtual protected void ReadInt2(out int x, out int y) {
		//	var aryS = ReadLine().Split(' ');
		//	x = int.Parse(aryS[0]);
		//	y = int.Parse(aryS[1]);
		//}
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