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
	
	static int Solve(List<int> arr) {
		if (arr.Count <= 2) return 0;
		int mnIndex = 0;
		for (var i = 1 ; i < arr.Count ; i++) if (arr[i] < arr[mnIndex]) mnIndex = i;
		int cost1 = Math.Min(mnIndex, arr.Count - 1 - mnIndex);
		arr.RemoveAt(mnIndex);
		return cost1 + Solve(arr);
	}
	
	static string Solve() {
		var n = int.Parse(Console.ReadLine());
		var arr = ReadLine().Select(int.Parse).ToList();
		return Solve(arr).ToString();
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