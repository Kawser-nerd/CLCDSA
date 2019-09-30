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
	
	static HashSet<int> ReadSet() {
		var n = int.Parse(Console.ReadLine().Trim());
		var strs = Enumerable.Range(0, 4).Select(i => Console.ReadLine()).ToArray();
		var str = strs[n - 1].Trim().Split(' ').Select(int.Parse);
		
		return new HashSet<int>(str);
	}
	
	static string Solve() {
		var set1 = ReadSet();
		var set2 = ReadSet();
		var res = set1.Intersect(set2).ToArray();
		if (res.Length == 0) return "Volunteer cheated!";
		if (res.Length > 1) return "Bad magician!";
		return res.First().ToString();
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