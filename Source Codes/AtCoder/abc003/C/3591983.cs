using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var n = NextInt();
		var k = NextInt();
		var r = new float[n];
		for (var i = 0; i < n; i++) {
			r[i] = NextInt();
		}
		Array.Sort(r);
		Array.Reverse(r);

		var ans = 0.0;
		for (var i = 1; i <= k; i++) {
			ans = (ans + r[k - i]) / 2;
		}
		WriteLine(ans);
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