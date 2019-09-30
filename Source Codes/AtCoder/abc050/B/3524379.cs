using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
	static void Main() {
		var N = NextLong();
		var T = new long[N];

		for (var i = 0; i < N; i++) {
			T[i] = NextLong();
		}
		var M = NextLong();
		var ans = new long[M];
		for (var i = 0; i < M; i++) {
			var P = NextLong();
			var X = NextLong();
			ans[i] = T.Sum() - T[P - 1] + X;
		}
		WriteLine(string.Join("\n", ans));
	}

	static long NextLong() {
		return long.Parse(NextString());
	}

	static string NextString() {
		var result = new List<char>();
		while (true) {
			int next = Read();
			if (next < 0)
				break;
			var nextChar = (char)next;
			if (!char.IsWhiteSpace(nextChar))
				result.Add(nextChar);
			else if (nextChar != '\r')
				break;
		}
		return string.Join("", result);
	}
}