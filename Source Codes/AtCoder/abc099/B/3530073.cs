using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var a = NextInt();
		var b = NextInt();

		var ans = 0;
		for (var i = 1; i < b - a; i++) {
			ans += i;
		}
		ans -= a;
		WriteLine(ans);
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