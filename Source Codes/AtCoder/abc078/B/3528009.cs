using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var X = NextInt();
		var Y = NextInt();
		var Z = NextInt();

		WriteLine((X - Z) / (Y + Z));
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