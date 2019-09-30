using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
	static void Main() {
		var A = NextInt();
		var B = NextInt();
		var C = NextInt();
		var K = NextInt();

		var L = new int[] { A, B, C };

		WriteLine(L.Sum() + L.Max() * (Math.Pow(2, K) - 1));
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