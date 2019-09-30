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
				
	static string Solve() {
		var nums = ReadLine().Select(int.Parse).ToArray();
		var a = nums[0];
		var b = nums[1];
		var k = nums[2];
		var res = 0;
		for (var i = 0 ; i < a ; i++) for (var j = 0 ; j < b ; j++)
			if ((i & j) < k) res++;
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