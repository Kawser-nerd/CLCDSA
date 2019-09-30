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
	
	static string Solve() {
		var nums = Console.ReadLine().Trim().Split(new [] {" "}, StringSplitOptions.RemoveEmptyEntries).Select(double.Parse).ToArray();
		double c = nums[0];
		double f = nums[1];
		double x = nums[2];
		double rate = 2.0;
		double time = 0;
		
		while (x / rate > (c / rate) + x / (rate + f)) {
			time += c / rate;
			rate += f;
		}
		
		time += x / rate;
		return time.ToString();
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