using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var dic = new HashSet<string>();
		for (var i = 0; i < N; i++) {
			dic.Add(NextString());
		}
		WriteLine(dic.Count == 3 ? "Three" : "Four");
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