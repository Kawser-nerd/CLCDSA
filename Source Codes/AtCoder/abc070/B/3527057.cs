using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program {
	static void Main() {
		var A = NextInt();
		var B = NextInt();
		var C = NextInt();
		var D = NextInt();

		WriteLine(Max(0, Min(B, D) - Max(A, C)));
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