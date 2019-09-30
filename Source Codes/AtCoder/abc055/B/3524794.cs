using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var M = Pow(10, 9) + 7;
		var ans = 1L;

		for (var i = 1; i <= N; i++) {
			ans = (ans * i) % M;
		}
		WriteLine(ans);
	}

	static long Pow(long a, long b) {
		long result = 1;
		for (var i = 0; i < b; i++) {
			result *= a;
		}
		return result;
	}

	static int NextInt() {
		return int.Parse(NextString());
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