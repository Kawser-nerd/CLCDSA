using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var M = NextInt();
		var cities = new int[N];

		for (var i = 0; i < M; i++) {
			var a = NextInt();
			var b = NextInt();

			cities[a - 1]++;
			cities[b - 1]++;
		}
		foreach (var roads in cities) {
			WriteLine(roads);
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