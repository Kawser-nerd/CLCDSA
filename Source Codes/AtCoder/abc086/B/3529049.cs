using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var a = NextString();
		var b = NextString();
		var x = int.Parse(a + b);

		var sqrt = (int)Math.Pow(x, 0.5);
		WriteLine(Math.Pow(sqrt, 2) == x ? "Yes" : "No");
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