using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ABC {
	 class Program {

		static void Main(string[] args) {
			new Calc().Solve();
			return;
		}
	}
	public class Calc {
		Scan cin = new Scan();
		public void Solve() {
			var S = cin.ReadLine().Split('+');
			var zeroz = S.Count(_ => _.Contains('0'));
			(S.Length - zeroz).WL();
			return;
		}
		
	}

	public class Scan {
		public int ReadInt() => int.Parse(Console.ReadLine());
		public int[] ReadInt(char separators) => Console.ReadLine().Split(separators).Select(int.Parse).ToArray();
		public double ReadDouble() => double.Parse(Console.ReadLine());
		public double[] ReadDouble(char separators) => Console.ReadLine().Split(separators).Select(double.Parse).ToArray();
		public long ReadLong() => long.Parse(Console.ReadLine());
		public long[] ReadLong(char separators) => Console.ReadLine().Split(separators).Select(long.Parse).ToArray();
		public string ReadLine() => Console.ReadLine();
	}
	public static class Utils {
		public static void WL(this object obj) {
			Console.WriteLine(obj);
		}
		public static string Docking<T>(this IEnumerable<T> collection, Func<T, string> filter = null) {
			StringBuilder sb = new StringBuilder();
			foreach (var item in collection) {
				string str = filter != null ? filter(item) : item.ToString();
				sb.Append(str);
			}
			return sb.ToString();
		}
		public static void WriteLineAll<T>(this IEnumerable<T> collection) {
			foreach (var item in collection) {
				item.WL();
			}
		}
		public static int IntParse(this string s) => int.Parse(s);
	}
}