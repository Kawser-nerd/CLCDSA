using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace GCJ {
	class Program {
		public static object SolveCase(Func<string> rl) {
			int[] info = rl().Split(' ').Select(int.Parse).ToArray();
			int j = info[0];
			int p = info[1];
			int s = info[2];
			int k = info[3];

			rnd = new Random();

			List<Tuple<int, int, int>> allCombs = new List<Tuple<int, int, int>>();

			for (int ji = 1; ji <= j; ji++) {
				for (int pi = 1; pi <= p; pi++) {
					for (int si = 1; si <= s; si++) {
						allCombs.Add(Tuple.Create(ji, pi, si));
					}
				}
			}

			string[] a = new string[1001];
			a = Enumerable.Range(0, 1001).Select(x => "").ToArray();

			for (int i = 0; i < 10000; i++) {

				List<Tuple<int, int, int>> current = Randomize(allCombs).ToList();

				int count = 0;

				Dictionary<Tuple<int, int>, int> dJP = new Dictionary<Tuple<int, int>, int>();
				Dictionary<Tuple<int, int>, int> dJS = new Dictionary<Tuple<int, int>, int>();
				Dictionary<Tuple<int, int>, int> dPS = new Dictionary<Tuple<int, int>, int>();

				for (int ji = 1; ji <= j; ji++) {
					for (int pi = 1; pi <= p; pi++) {
						dJP.Add(Tuple.Create(ji, pi), 0);
					}
				}

				for (int ji = 1; ji <= j; ji++) {
					for (int si = 1; si <= s; si++) {
						dJS.Add(Tuple.Create(ji, si), 0);
					}
				}

				for (int pi = 1; pi <= p; pi++) {
					for (int si = 1; si <= s; si++) {
						dPS.Add(Tuple.Create(pi,si), 0);
					}
				}

				HashSet<Tuple<int, int, int>> all = new HashSet<Tuple<int, int, int>>();

				string res = "";

				foreach (var t in current) {
					int ji = t.Item1;
					int pi = t.Item2;
					int si = t.Item3;
					if (dJP[Tuple.Create(ji, pi)] < k && dJS[Tuple.Create(ji, si)] < k && dPS[Tuple.Create(pi, si)] < k && !all.Contains(Tuple.Create(ji, pi, si))) {
						count++;
						res += Environment.NewLine + ji + " " + pi + " " + si;
						dJP[Tuple.Create(ji, pi)]++;
						dJS[Tuple.Create(ji, si)]++;
						dPS[Tuple.Create(pi, si)]++;
						all.Add(Tuple.Create(ji, pi, si));
					}
				}

				a[count] = res;
			}
			for(int i=a.Length-1; i>=0; i--) {
				if (a[i] != "")
					return i.ToString() + a[i];
			}
			return 0;
		}

		static Random rnd;

		public static IEnumerable<Tuple<int, int, int>> Randomize(IEnumerable<Tuple<int,int,int>> source) {
			return source.OrderBy<Tuple<int, int, int>, int>((item) => rnd.Next());
		}


		public struct Settings {
			public const bool DEBUG = false;
			public const bool TOCONSOLE = true;
			public const bool EXAMPLE = false;
			public const bool SMALL = true;
			public const char PROBLEM_LETTER = 'C';
			public const int ATTEMPT_NUMBER = 2; // 0 for the first attempt
			public const int NUMBER = 0;
			public const bool PRACTICE = false;
		}

		private static void Debug() {
			HashSet<Tuple<int, int, int>> h = new HashSet<Tuple<int, int, int>>();
			h.Add(Tuple.Create(1, 2, 3));
			h.Add(Tuple.Create(1, 2, 3));
			Console.WriteLine(h.Count);
			Console.ReadKey();
		}

		private static void Main(string[] args) {
			if (Settings.DEBUG) {
				Debug();
			} else {
				Pattern.SolveAll();
			}
			Console.ReadKey();
		}
	}

	static class Pattern {
		public static void SolveAll() {
			using (StreamReader sr = new StreamReader(CreateInfPath()))
			using (StreamWriter sw = new StreamWriter(@"C:\Users\Jakob\Desktop\outf.txt")) {
				int cases = int.Parse(sr.ReadLine());

				DateTime start;
				Console.Title = "Google Code Jam";

				for (int currentCase = 1; currentCase <= cases; currentCase++) {
					start = DateTime.Now;
					object result = Program.SolveCase(sr.ReadLine);
					sw.WriteLine("Case #{0}: {1}", currentCase, result);
					Console.WriteLine("Case {0} / {1} : {2}ms", currentCase, cases, (DateTime.Now - start).TotalMilliseconds);
					if (Program.Settings.TOCONSOLE) {
						Console.WriteLine(result);
					}
				}
			}
			Console.WriteLine("END!");
			Console.Beep(300, 500);
		}
		private static string CreateInfPath() {
			string infPath;
			if (Program.Settings.EXAMPLE)
				infPath = @"C:\Users\Jakob\Desktop\ex.txt";
			else {
				infPath = @"C:\Users\Jakob\Downloads\" + Program.Settings.PROBLEM_LETTER.ToString() + "-" + (Program.Settings.SMALL ? "small" : "large");
				if (Program.Settings.PRACTICE)
					infPath += "-practice";
				if (Program.Settings.NUMBER != 0)
					infPath += "-" + Program.Settings.NUMBER.ToString();
				else if (!Program.Settings.PRACTICE && Program.Settings.SMALL)
					infPath += "-attempt" + Program.Settings.ATTEMPT_NUMBER.ToString();
				infPath += ".in";
			}
			return infPath;
		}
	}
}