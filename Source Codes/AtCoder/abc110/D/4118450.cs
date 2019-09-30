using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace ABC110.D
{
	using static Util;

	public class Solver : SolverBase
	{
		public void Run() {
			var ary = ReadIntArray();
			int N = ary[0];
			int M = ary[1];

			var modulo = new Modulo(200000);

			// M??????
			int ans = 1;
			for (int i = 2; i * i <= M; i++) {
				if (M % i != 0) continue;

				// ???? ? ????????????????
				int cnt = 0;
				while (M % i == 0){
					M /= i;
					++cnt;
				}

				// ???????N???????????? nCr ????
				// cnt+n-1 C n-1
				var ncr = modulo.Ncr(cnt + N - 1, N - 1);

				// ans = ? nCr ??
				ans = Modulo.Mul(ans, ncr);
			}
			// ???1???????? ???????????1??????????????
			if (1 < M) {
				var ncr = modulo.Ncr(N, 1);
				ans = Modulo.Mul(ans, ncr);
			}
			WriteLine(ans);
		}

#if !MYHOME
		public static void Main(string[] args) {
			new Solver().Run();
		}
#endif
	}
	/// <summary>
	/// ???????????????nCr
	/// http://kumikomiya.com/competitive-programming-with-c-sharp/
	/// </summary>
	public class Modulo
	{
		private readonly static int M = 1000000007;

		/// <summary>(a * b) % M</summary>
		public static int Mul(int a, int b) {
			return (int)(Math.BigMul(a, b) % M);
		}

		/// <summary>(a?m?) % M</summary>
		/// <see cref="https://www.youtube.com/watch?v=gdQxKESnXKs ?D??"/>
		public static int Pow(int a, int m) {
			switch (m) {
				case 0:
					return 1;
				case 1:
					return a % M;
				default:
					int p1 = Pow(a, m / 2);
					int p2 = Mul(p1, p1);
					return ((m % 2) == 0) ? p2 : Mul(p2, a);
			}
		}

		/// <summary>
		/// (a / b) % M
		/// ?????????????
		/// </summary>
		/// <see cref="https://www.youtube.com/watch?v=gdQxKESnXKs ?D??"/>
		public static int Div(int a, int b) {
			return Mul(a, Pow(b, M - 2));
		}

		/// <summary>
		/// ??????? ?n! % M ??? nCr % M ???????????
		/// </summary>
		private readonly int[] m_facs;
		public Modulo(int n) {
			// x ? n ????x! % M ???????????
			m_facs = new int[n + 1];
			m_facs[0] = 1;
			for (int i = 1; i <= n; ++i) {
				m_facs[i] = Mul(m_facs[i - 1], i);
			}
		}

		/// <summary>n! % M</summary>
		public int Fac(int n) {
			return m_facs[n];
		}
		/// <summary>
		/// ????? nCr % M
		/// </summary>
		/// <see cref="https://www.youtube.com/watch?v=gdQxKESnXKs ?D??"/>
		public int Ncr(int n, int r) {
			if (n < r) { return 0; }
			if (n == r) { return 1; }
			int res = Fac(n);
			res = Div(res, Fac(r));
			res = Div(res, Fac(n - r));
			return res;
		}
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