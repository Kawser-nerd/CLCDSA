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
		
	static List<int[]> orders = new List<int[]>();
	static bool[] canBeUsed;
	static int[] acc;
	static int n;
	
	static void GenerateOrders(int i) {
		for (var x = 0 ; x < n ; x++) if (canBeUsed[x]) {
			acc[i] = x;
			if (i == canBeUsed.Length - 1) orders.Add(acc.ToArray());
			else {
				canBeUsed[x] = false;
				GenerateOrders(i + 1);
				canBeUsed[x] = true;
			}
		}
	
	}
		
	static bool valid(int[] order, bool[,] canGoTo) {
		var st = new Stack<int>();
		st.Push(order[0]);
		
		foreach (var v in order.Skip(1)) {
			while (st.Any() && !canGoTo[v, st.Peek()]) st.Pop();
			if (!st.Any()) return false;
			st.Push(v);
		}
		
		return true;
	}
		
	static string Solve() {
	orders.Clear();
		var nums = ReadLine().Select(int.Parse).ToArray();
		n = nums[0];
		var m = nums[1];
		
		var codes = Enumerable.Range(0, n).Select(i => Console.ReadLine()).ToArray();
		bool[,] canGoTo = new bool[n, n];
		for (var i = 0 ; i < m ; i++) {
			var cities = ReadLine().Select(int.Parse).ToArray();
			var a = cities[0];
			var b = cities[1];
			a--;
			b--;
			canGoTo[a, b] = canGoTo[b, a] = true;
		}
		canBeUsed = new bool[n];
		acc = new int[n];
		for (int i = 0 ; i < n ; i++) canBeUsed[i] = true;
		
		GenerateOrders(0);
		
		var ans = "";
		
		foreach (var order in orders) {
			if (!valid(order, canGoTo)) continue;
			string s = string.Concat(order.Select(i => codes[i]));
			if (ans == "" || s.CompareTo(ans) < 0) ans = s;
		}
		
		return ans;
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