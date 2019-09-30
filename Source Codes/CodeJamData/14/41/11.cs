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

	static string Solve() {
		var l = ReadLine().Select(int.Parse).ToArray();
		var n = l[0];
		var x = l[1];
		var l2 = ReadLine().Select(int.Parse).ToList();
		var counts = new int[x + 1];
		foreach (var xx in l2) counts[xx]++;
		int res = 0;
		int mn = 0;
		for (var up = x ; up >= 1 ; up--) {
			if (counts[up] == 0) continue;
			counts[up]--;
			res++;
			while (counts[mn] == 0 && mn + 1 + up <= x) mn++;
			if (counts[mn] > 0) counts[mn]--;
			up++;
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