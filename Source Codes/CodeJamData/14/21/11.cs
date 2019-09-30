using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

class App {
	static bool _isDebug = true;
	
	static void Debug(object o) { Debug(o.ToString(), new object[0]); }
	static void Debug(string str, params object[] ps) {
		if (!_isDebug) return;
		Console.WriteLine("Debug: " + string.Format(str, ps));
	}
	
	static string[] ReadLine() {
		return Console.ReadLine().Split(new [] { " " }, StringSplitOptions.RemoveEmptyEntries);
	}
	
	static long ReadLong(string s) {
		var res = 0L;
		for (int i = 0 ; i < s.Length ; i++) {
			if (s[s.Length - 1 - i] == '1') res++;
			res *= 2;
		}
		
		return res;
	}
	
	static List<Tuple<char, int> > toCount(string s) {
		var count = new List<Tuple<char, int> >();
		char lastC = s[0];
		int cc = 1;
		for (int i = 1 ; i <= s.Length ; i++) {
			char c = i == s.Length ? '-' : s[i];
			if (c == lastC) cc++;
			else {
				count.Add(Tuple.Create(lastC, cc));
				lastC = c;
				cc = 1;
			}
		}
		return count;
	}
	
	static bool check(List<Tuple<char, int> > c1, List<Tuple<char, int > > c2) {
		if (c1.Count != c2.Count) return false;
		
		for (int i = 0 ; i < c1.Count ; i++) if (c1[i].Item1 != c2[i].Item1) {
			return false;
		}
		return true;
	}
	
	static int getOps(List<int> x) {
		int best = int.MaxValue;
		
		foreach (var n in x) {
			int cur = 0;
			foreach (var n2 in x) cur += Math.Abs(n2 - n);
			best = Math.Min(best, cur);
		}
		
		return best;
	}
	
	static string Solve() {
		var n = int.Parse(Console.ReadLine());
		var counts = Enumerable.Range(0, n).Select(i => Console.ReadLine().Trim()).Select(toCount).ToArray();
		if (counts.Skip(1).Any(cc => !check(cc, counts[0]))) return "Fegla Won";
		
		int res = 0;
		var x = new List<int>();
		for (int i = 0 ; i < counts[0].Count ; i++) {
			x.Clear();
			foreach (var xx in counts) x.Add(xx[i].Item2);
			res += getOps(x);
		}
		
		return res.ToString();
	}
	
	static void Main(string[] args) {
		if (args.Any()) {
			StreamReader reader = new StreamReader(args.First());
			Console.SetIn(reader);
		}
	
		try {
			var t = int.Parse(Console.ReadLine());
		
		for (var i = 1 ; i <= t ; i++) {
			Console.WriteLine("Case #{0}: {1}", i, Solve());
		}
		} catch (Exception e) {
			Console.WriteLine(e);
		}
	}
}