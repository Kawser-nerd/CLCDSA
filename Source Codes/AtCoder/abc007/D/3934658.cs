using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

// ?DP
//
namespace KetaDP
{
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

		public static void InitDP<T>(T[,] dp, T value) {
			for (int i = 0; i < dp.GetLength(0); i++) {
				for (int j = 0; j < dp.GetLength(1); j++) {
					dp[i, j] = value;
				}
			}
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
		virtual protected void WriteLine(string line) => Console.WriteLine(line);
		virtual protected void WriteLine<T>(T value) where T : IFormattable => Console.WriteLine(value);
		virtual protected void WriteLine(double d) => Console.WriteLine($"{d:F9}");

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

	// ABC007-D: ???????
	// https://abc007.contest.atcoder.jp/tasks/abc007_4
	public class Solver : SolverBase
	{
		long[,] DP;
		readonly int[] Digits = { 0, 1, 2, 3, 5, 6, 7, 8 };
		long SolveDP(string S) {
			// ???[A, B]????????????A??????1???????
			//   ?????? ans = f(B) - f(A-1) ????
			//
			// DP[pos??][?????rist] = ?????????????? 
			//   pos????????1???
			//   rist ?????:1 ????:0 ???
			// 
			// ?????????????????????????????????
			//  ???int(s)??????????????????????????
			// 
			DP = new long[S.Length+1, 2];
			// ???? ?1?????????
			DP[0, 1] = 1;

			// ??DP
			for (int pos = 0; pos < S.Length; pos++) {
				for (int rist = 0; rist <= 1; rist++) {
					if (DP[pos, rist] == 0) continue;

					if (rist == 0) {
						// ????
						// ?????4,9?2???????????8????
						DP[pos + 1, rist] += DP[pos, rist] * 8;
					} else {
						// ????????S??????????????
						var upper = (char)S[pos] - (char)'0';

						foreach (var v in Digits) {
							if (v == upper) {
								DP[pos + 1, 1] += DP[pos, rist];

							} else if (v < upper) {
								DP[pos + 1, 0] += DP[pos, rist];
							}
						}
					}
				}
			}
			//Console.WriteLine($"{S} ==========");
			//DumpDP(DP);

			var l = long.Parse(S);
			// ???? ? ???? - ???0??
			return l - (DP[S.Length, 0] + DP[S.Length, 1] - 1);
		}

		public void Run() {
			var ary = ReadStringArray();
			var A = ary[0];
			var B = ary[1];

			var A1 = (long.Parse(A) - 1).ToString();
			var ans = SolveDP(B) - SolveDP(A1);
			WriteLine(ans);
		}
#if !MYHOME
		public static void Main(string[] args) {
			new Solver().Run();
		}
#endif
	}
}