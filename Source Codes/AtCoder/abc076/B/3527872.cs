using System.Collections.Generic;
using static System.Console;
using System;

class Program {
	static void Main() {
		var N = NextInt();
		var K = NextInt();
		var t = 1;
		for (var i = 0; i < N; i++) {
			t = Math.Min(t * 2, t + K);
		}
		WriteLine(t);
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