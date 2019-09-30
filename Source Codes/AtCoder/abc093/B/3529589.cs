using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var A = NextInt();
		var B = NextInt();
		var K = NextInt();

		var L = new List<int>();
		for (var i = 0; i < K; i++) {
			L.Add(A + i);
		}

		for (var j = 0; j < K; j++) {
			var tmp = B - j;
			if (!L.Contains(tmp)) {
				L.Add(tmp);
			}
		}
		L.Sort();
		foreach (var x in L) {
			if (A <= x && x <= B) {
				WriteLine(x);
			}
		}
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