using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
using static CS_Contest.Utils;
using System.IO;
//using static CS_Contest.Library;

namespace CS_Contest {
	using Li = List<int>;
	using LLi = List<List<int>>;
	using Ls = List<string>;
	using Ll = List<long>;
	using LLl = List<List<long>>;
	class Program {
		static void Main(string[] args) {
			var sw = new StreamWriter(OpenStandardOutput()) { AutoFlush = false };
			SetOut(sw);
			new Calc().Solve();
			Out.Flush();
			return;
        }

		private class Calc {
			public void Solve() {
				SortedDictionary<string, string> dic = new SortedDictionary<string, string>();
				var N = ReadInt();
				REP(N, x => {
					var S = ReadLine().ToArray();
					dic.Add(S.Reverse().StringJoin(""), S.StringJoin(""));
				});

				foreach (var item in dic) {
					item.Value.WL();
				}

				return;
			}
			
			
		}
	}


	public static class Utils {
		public static int ModValue = (int)(1000000007);
		public static long INF = long.MaxValue;
		public static long Mod(long x) => x % ModValue;
		public static long ModPow(long x,long n) { long tmp = 1; while (n != 0) { if (n % 2 == 1) { tmp = Mod(tmp * x); }x = Mod(x * x);n /= 2; }return tmp; }
		public static long DivMod(long x, long y) => Mod(x * ModPow(y, (long)(1e9 + 5)));
        public static void WL(this object obj) => WriteLine(obj);
        public static void WL(this string obj) => WriteLine(obj);
        public static void WL<T>(this IEnumerable<T> list) => list.ToList().ForEach(x => x.WL());
		public static int ReadInt() => int.Parse(ReadLine());
		public static List<int> ReadInt(char s) => ReadLine().Split(s).Where(x=>x!="").Select(int.Parse).ToList();
		public static long ReadLong() => long.Parse(ReadLine());
		public static List<long> ReadLong(char s) => ReadLine().Split(s).Select(long.Parse).ToList();
		public static void ReadMulti(out int x, out int y) {
			var i = ReadInt(' ');
			x = i[0]; y = i[1];

		}
		public static void ReadMulti(out long x, out long y) {
			var i = ReadLong(' ');
			x = i[0];y = i[1];
		}
		public static void ReadMulti(out int x, out int y, out int z) {
			var i = ReadInt(' ');
			x = i[0];y = i[1];z = i[2];
		}
		public static void ReadMulti(out int x, out int y, out int z, out int v) {
			var i = ReadInt(' ');
			x = i[0]; y = i[1]; z = i[2];v = i[3];
		}

		public static string StringJoin<T>(this IEnumerable<T> l,string separator) => string.Join(separator, l);

		public static long GCD(long m,long n) {
			long tmp;
			if (m < n) { tmp = n;n = m;m = tmp; }
			while(m%n!=0) {
				tmp = n;
				n = m % n;
				m = tmp;
			}
			return n;
		}
		public static long LCM(long m, long n) => m * (n / GCD(m, n));

		public static void REP(int n,Action<int> act) {
			for (int i = 0; i < n; i++) {
				act(i);
			}
		}
		public static void RREP(int n,Action<int> act) {
			for (int i = n-1; i >=0; i--) {
				act(i);
			}
		}
		public static void REP(long n, Action<int> act) => REP((int)n, act);
		public static void RREP(long n, Action<int> act) => RREP((int)n, act);

		public static void Yes() => "Yes".WL();
		public static void No() => "No".WL();
		public static void YES() => "YES".WL();
		public static void NO() => "NO".WL();


		public static int ManhattanDistance(int x1, int y1, int x2, int y2) => Abs(x2 - x1) + Abs(y2 - y1);


		public class Vector2 {
			public int X { get; set; }
			public int Y { get; set; }
			public Vector2() { X = 0; Y = 0; }
			public Vector2(int x, int y) { X = x; Y = y; }
			public int ManhattanDistance(Vector2 v2) {
				return Utils.ManhattanDistance(X, Y, v2.X, v2.Y);
			}
			public static int ManhattanDistance(Vector2 v1, Vector2 v2) => v2.ManhattanDistance(v2);
			public double Distance(Vector2 v2) => Sqrt(Pow(X - v2.X, 2) + Pow(Y - v2.Y, 2));
			public static Vector2 Zero { get { return new Vector2(); } }
			public void Clear() { X = 0; Y = 0; }
		}

		public static Tuple<TKey, TSource> ToTuple<TKey, TSource>(this KeyValuePair<TKey, TSource> kvp) => new Tuple<TKey, TSource>(kvp.Key, kvp.Value);
		public static IEnumerable<Tuple<TKey, TSource>> ToTupleList<TKey, TSource>(this Dictionary<TKey, TSource> d) => d.Select(_ => _.ToTuple());
	}
}