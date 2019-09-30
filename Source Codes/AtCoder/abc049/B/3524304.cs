using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var H = NextLong();
		var W = NextLong();
		var ans = new string[H * 2];
		for (var i = 0; i < H; i++) {
			var C = ReadLine();
			for (var j = 0; j < 2; j++) {
				ans[2 * i + j] = C;
			}
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