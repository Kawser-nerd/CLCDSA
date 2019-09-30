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
	
	static int[] heights;
	
	static bool Check() {
		return false;
	}
	static int r;
	static int c;
	
	static bool[,,] dp;
	static bool[,,] dpCalc;
	
	static bool Build(int col, int rem, int prev) {
		if (col == c) return rem == 0;
		if (!dpCalc[col, rem, prev]) {
			dpCalc[col, rem, prev] = true;
			dp[col, rem, prev] = false;
			for (heights[col] = 0 ; heights[col] <= prev && heights[col] <= rem ; heights[col]++) {
				if (col == 1 && prev == 1 && heights[col] > 0) break;
				if (heights[col] < prev && col == 1 && prev != 1) continue;
				if (heights[col] == 1) continue;
				if (Build(col + 1, rem - heights[col], heights[col])) {
					dp[col, rem, prev] = true;
					break;
				}
			}
		}
		return dp[col, rem, prev];
	}
	
	static string Solve() {
		var nums = Console.ReadLine().Trim().Split(new [] {" "}, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
		r = nums[0];
		c = nums[1];
		var m = nums[2];
		heights = new int[c];
		var free = r * c - m;
		dp = new bool[c, free + 1, r + 1];
		dpCalc = new bool[c, free + 1, r + 1];
		
		if (r == 1) {
			var str = new char[c];
			for (int i = 0 ; i < c ; i++) str[i] = '.';
			for (int i = free ; i < c ; i++) str[i] = '*';
			str[0] = 'c';
			return Environment.NewLine + new string(str);
		}
		
		for (heights[0] = 1 ; heights[0] <= r && heights[0] <= free ; heights[0]++) {
			if (Build(1, free - heights[0], heights[0])) {
				var ans = new string[r];
				for (int i = 0 ; i < r ; i++) {
					var str = new char[c];
					for (int j = 0 ; j < c ; j++) if (heights[j] <= i) str[j] = '*'; else str[j] = '.';
					if (i == 0) str[0] = 'c';
					ans[i] = new string(str);
				}
				return Environment.NewLine + string.Join(Environment.NewLine, ans);
			}
		}
		
		return Environment.NewLine + "Impossible";
	}
	
	static void Main(string[] args) {
		if (args.Any()) {
			StreamReader reader = new StreamReader(args.First());
			Console.SetIn(reader);
		}
	
		try {
		var t = int.Parse(Console.ReadLine());
		
		for (var i = 1 ; i <= t ; i++) {
			Console.WriteLine("Case #{0}:{1}", i, Solve());
		}
		} catch (Exception e) {
			Console.WriteLine(e);
		}
	}
}