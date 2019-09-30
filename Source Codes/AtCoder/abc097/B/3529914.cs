using System;
using static System.Console;

class Program {
	static void Main() {
		var X = int.Parse(ReadLine());
		var ans = 1;

		for (var i = 2; i * i <= X; i++) {
			for (var j = i * i; j <= X; j *= i) {
				ans = Math.Max(ans, j);
			}
		}
		WriteLine(ans);
	}
}