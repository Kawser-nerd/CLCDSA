using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var a = new int[N];
		for (var i = 0; i < N; i++) {
			a[i] = NextInt();
		}
		var j = 1;
		for (var i = 1; i <= N; i++) {
			j = a[j - 1];
			if (j == 2) {
				WriteLine(i);
				return;
			}
		}
		WriteLine(-1);
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