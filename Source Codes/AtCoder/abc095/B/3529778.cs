using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var X = NextInt();

		var min = int.MaxValue;
		for (var i = 0; i < N; i++) {
			var m = NextInt();
			min = Math.Min(min, m);
			X -= m;
		}
		WriteLine(N + X / min);
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