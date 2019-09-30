using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var M = NextInt();
		var X = NextInt();

		var ans = 0;
		var cnt = 0;
		var flg = false;

		for (var i = 0; i < M; i++) {
			var A = NextInt();
			if (A > X & !flg) {
				ans = cnt;
				cnt = 0;
				flg = true;
			}
			cnt += 1;
		}
		ans = Math.Min(ans, cnt);
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