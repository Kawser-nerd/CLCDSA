using System;
using static System.Console;

class Program {
	static void Main() {
		var N = int.Parse(ReadLine());
		var S = ReadLine();
		var ans = 0;

		for (var i = 1; i < N; i++) {
			var a = S.Substring(0, i);
			var b = S.Substring(i);
			ans = Math.Max(ans, Calc(a, b));
		}
		WriteLine(ans);
	}

	static int Calc(string x, string y) {
		var result = 0;
		for (var c = 'a'; c <= 'z'; c++) {
			if (x.Contains(c + "") && y.Contains(c + "")) {
				result++;
			}
		}
		return result;
	}
}