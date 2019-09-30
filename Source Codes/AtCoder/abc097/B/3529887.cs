using System;
using static System.Console;

class Program {
	static void Main() {
		var X = int.Parse(ReadLine());
		var ans = 1;

		for (var b = 2; b * b <= X; b++) {
			for (var p = 2; ; p++) {
				if (Math.Pow(b, p) > X) {
					break;
				}
				ans = Math.Max(ans, (int)Math.Pow(b, p));
			}
		}
		WriteLine(ans);
	}
}