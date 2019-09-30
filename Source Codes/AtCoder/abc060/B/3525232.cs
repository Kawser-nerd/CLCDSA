using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var A = NextInt();
		var B = NextInt();
		var C = NextInt();

		for (var i = 0; i < B; i++) {
			if (A * i % B == C) {
				WriteLine("YES");
				return;
			}
		}
		WriteLine("NO");
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