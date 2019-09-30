using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
using static CS_Contest.Utils;

namespace CS_Contest {
	using Li = List<int>;
	using LLi = List<List<int>>;
	class Program {
        static void Main(string[] args) {
			new Calc().Solve();
			return;
        }

		private class Calc {
			public void Solve() {
				int N = ReadInt();
				Li s = new Li();
				REP(N, x => s.Add(ReadInt()));
				long sum = s.Sum();

				if (sum % 10 == 0) {

					if (s.Any(x => x % 10 != 0)) {
						var f = s.Where(x=>x%10!=0).Min();
						(sum - f).WL();
					}
					else {
						0.WL();
					}
				}
				else {
					sum.WL();
				}
				return;
			}
		}
    }

	
	
    public static class Utils {
		public static int INF = (int)(1e9);
        public static void WL(this object obj) => WriteLine(obj);
        public static void WL(this string obj) => WriteLine(obj);
        public static void WL<T>(this IEnumerable<T> list) => list.ToList().ForEach(x => x.WL());
		public static int ReadInt() => int.Parse(ReadLine());
		public static List<int> ReadInt(char s) => ReadLine().Split(s).Select(int.Parse).ToList();
		public static long ReadLong() => long.Parse(ReadLine());
		public static List<long> ReadLong(char s) => ReadLine().Split(s).Select(long.Parse).ToList();
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

		public static int ManhattanDistance(int x1, int y1, int x2, int y2) => Abs(x2 - x1) + Abs(y2 - y1);

		public class Tree {
			public LLi Graph;
			public Tree(int nodes) {
				Graph = new LLi();
				REP(nodes, x => {
					Graph.Add(new Li());
				});
			}
			public void Add(int x,int y) {
				Graph[x].Add(y);
				Graph[y].Add(x);
			}
		}
    }
}