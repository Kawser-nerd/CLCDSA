using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var K = NextInt();
		var l = new int[N];
		for (var i = 0; i < N; i++) {
			l[i] = NextInt();
		}
		Array.Sort(l);
		Array.Reverse(l);
		var ans = 0;
		for (var i = 0; i < K; i++) {
			ans += l[i];
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