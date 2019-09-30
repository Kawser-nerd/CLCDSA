using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
	static void Main() {
		var K = NextLong();
		var S = NextLong();
		var ans = 0;

		for (var x = 0; x <= K; x++) {
			for (var y = 0; y <= K; y++) {
				var z = S - x - y;
				if (0 <= z && z <= K) {
					ans++;
				}
			}
		}
		WriteLine(ans);
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