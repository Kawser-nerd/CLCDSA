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

	// ABC029-D: ?DP???????????
	// https://abc029.contest.atcoder.jp/tasks/abc029_d
	public class SolverABC029D : SolverBase
	{
		public void Run() {
			var S = ReadLine();

			// DP[pos??][1??????j][?????rist] = ??????????
			//   pos????????1???
			//   121xxx, 110xxx ?? j ? 2 ?N<=10^9?????10?
			//   rist ?????:1 ????:0 ???
			//      ?????: pos???????S?????????
			//                ????????????????????
			// 
			var DP = new long[S.Length + 1, 11, 2];
			// [0??, 1?????0?, ????] = 1? ???
			DP[0, 0, 1] = 1;

			Action<long[,,]> DumpDP2 = (dp) => {
				var sb = new StringBuilder();
				for (int i = 0; i < dp.GetLength(0); i++) {
					sb.Append($"{i}: ");
					for (int j = 0; j < dp.GetLength(1); j++) {
						sb.Append($"{dp[i, j, 0]}-{dp[i, j, 1]}");
						sb.Append(", ");
					}
					sb.AppendLine();
				}
				Console.WriteLine(sb.ToString());
			};
			// ??DP
			for (int pos = 0; pos < S.Length; pos++) {
				for (int j = 0; j < 11; j++) {
					for (int rist = 0; rist <= 1; rist++) {
						if (DP[pos, j, rist] == 0) continue;

						if (rist == 0) {
							// ????
							// ???1???????:
							// pos+1?????1?j+1????????? = pos?????1?j?????????
							DP[pos + 1, j + 1, 0] += DP[pos, j, 0];
							// 1?????????:
							// pos+1?????1?j????????? = pos?????1?j????????? * 9
							DP[pos + 1, j, 0] += DP[pos, j, 0] * 9;
						} else {
							// ????????????????????
							var upper = S[pos] - '0';

							if (upper == 0) {
								// ????????????????
								DP[pos + 1, j, 1] += DP[pos, j, 1];
							} else if (upper == 1) {
								// 0??????: ???????????????????
								DP[pos + 1, j, 0] += DP[pos, j, 1];
								// 1??????: ????+1????????????
								DP[pos + 1, j + 1, 1] += DP[pos, j, 1];
							} else if (1 < upper) {
								// 1??????: ????+1????????????
								DP[pos + 1, j + 1, 0] += DP[pos, j, 1];
								// upper???????: ??????????????????
								DP[pos + 1, j, 1] += DP[pos, j, 1];
								// ???????????upper-1???:
								//                    ???????????????????
								DP[pos + 1, j, 0] += DP[pos, j, 1] * (upper - 1);
							}
						}
					}
				}
				//Console.WriteLine($"pos: {pos} =======");
				//DumpDP2(DP);
			}
			long ans = 0;
			for (int j = 1; j < 11; j++) {
				// += (???? + ????) * ????
				ans += (DP[S.Length, j, 0] + DP[S.Length, j, 1]) * j;
			}
			WriteLine(ans);
		}

#if !MYHOME
		public static void Main(string[] args) {
			new SolverABC029D().Run();
		}
#endif
	}
}