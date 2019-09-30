using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextLong();
		var S = ReadLine();
		var cnt = 0;
		var ans = 0;

		foreach (var c in S) {
			switch (c) {
				case 'I':
					cnt++;
					break;
				case 'D':
					cnt--;
					break;
				default:
					break;
			}
			ans = Math.Max(ans, cnt);
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