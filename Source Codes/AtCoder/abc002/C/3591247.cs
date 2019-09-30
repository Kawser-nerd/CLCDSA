using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var xa = NextInt();
		var ya = NextInt();
		var xb = NextInt();
		var yb = NextInt();
		var xc = NextInt();
		var yc = NextInt();

		var s = Math.Abs((xa - xc) * (yb - yc) - (ya - yc) * (xb - xc)) / 2.0;
		WriteLine(s);
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