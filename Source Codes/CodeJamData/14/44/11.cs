using System;
using System.Collections.Generic;
using System.Globalization;
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
	
	static void maximize<T>(ref T a, T b) where T : IComparable<T> {
		if (a.CompareTo(b) < 0) a = b;
	}
	
	static void minimize<T>(ref T a, T b) where T : IComparable<T> {
		if (a.CompareTo(b) > 0) a = b;
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
				
	static void write(double d) {
		Console.Write(d.ToString(CultureInfo.InvariantCulture));
	}

	static int GetCost(List<string> strs) {
		int cost = 1;
		strs.Sort();
		if (strs.Count > 0) cost += strs[0].Length;
		for (var i = 1 ; i < strs.Count ; i++) {
			int lcp = 0;
			while (lcp < strs[i].Length && lcp < strs[i - 1].Length && strs[i][lcp] == strs[i - 1][lcp]) lcp++;
			cost += strs[i].Length - lcp;
		}
		return cost;
		return 1;
	}
	
	static int GetCost(List<string>[] strs) {
		foreach (var lst in strs) if (lst.Count == 0) return 0;
		int res = 0;
		foreach (var lst in strs) res += GetCost(lst);
		return res;
	}
	
	static string Solve() {
		var l = ReadLine().Select(int.Parse).ToArray();
		var m = l[0];
		var n = l[1];
		var strs = Enumerable.Range(0, m).Select(i => Console.ReadLine()).ToArray();
		
		var worst = 0;
		var count = 0;
		
		var distr = new int[m];
		
		while (true) {
			var strs2 = new List<string>[n];
			for (var i = 0 ; i < n ; i++) strs2[i] = new List<string>();
			for (var i = 0 ; i < m ; i++) strs2[distr[i]].Add(strs[i]);
		
			int price = GetCost(strs2);
			if (price == worst) count++;
			else if (price > worst) {
				worst = price;
				count = 1;
			}
		
			int lst = m - 1;
			distr[lst]++;
			while (distr[lst] == n) {
				if (lst == 0) break;
				distr[lst] = 0;
				lst--;
				distr[lst]++;
			}
			if (distr[lst] == n) break;
		}
		
		return string.Format("{0} {1}", worst, count);
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