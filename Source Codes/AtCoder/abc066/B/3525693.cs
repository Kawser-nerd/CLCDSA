using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var S = ReadLine();
		var ans = 0;

		for (var i = 1; i < S.Length / 2; i++) {
			if (S.Substring(0, i) == S.Substring(i, i)) {
				ans = i * 2;
			}
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