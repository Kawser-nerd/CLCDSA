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
	
	static double[] ReadArr(int n) { 
		var res = Console.ReadLine().Trim().Split(new [] { " " }, StringSplitOptions.RemoveEmptyEntries).Select(double.Parse).ToArray();
		Array.Sort(res);
		return res;
	}
	
	static int GetScore1(List<double> a1, List<double> a2) {
		int r = 0;
		int res = 0;
		for (int i = 0 ; i < a1.Count ; i++) {
			while (r < a2.Count && a1[i] > a2[r]) r++;
			if (r == a2.Count) res++;
			else r++;
		}
		return res;
	}
	
	static string Solve() {
		var n = int.Parse(Console.ReadLine());
		var a1 = ReadArr(n).ToList();
		var a2 = ReadArr(n).ToList();
		
		int res1 = GetScore1(a1.ToList(), a2.ToList());
		
		int res = 0;
		int r = 0;
		while (a1.Count > 0) {
			if (a1[0] < a2[0]) {
				a2.RemoveAt(a2.Count - 1);
			} else {
				a2.RemoveAt(0);
				res++;
			}
			a1.RemoveAt(0);
		}
		
		return string.Format("{0} {1}", res, res1);
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