using System;
using System.Collections.Generic;

class Program {
	static void Main() {
		var N = NextInt();
		var max = int.MinValue;
		var min = int.MaxValue;

		for (var i = 0; i < N; i++) {
			var a = NextInt();
			max = Math.Max(max, a);
			min = Math.Min(min, a);
		}

		Console.WriteLine(max - min);
	}

	static int NextInt() {
		return int.Parse(NextString());
	}

	static string NextString() {
		var result = new List<char>();
		while (true) {
			int next = Console.Read();
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