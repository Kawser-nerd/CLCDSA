using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program {
	static void Main() {
		var N = NextInt();
		var K = NextInt();
		var ans = 0;

		for (var i = 0; i < N; i++) {
			var x = NextInt();
			ans += 2 * Min(x, K - x);
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