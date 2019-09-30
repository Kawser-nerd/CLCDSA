using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var D = NextInt();
		var N = NextInt();

		if (N == 100) {
			N++;
		}
		WriteLine(N * Math.Pow(100, D));
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