using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var A = NextInt();
		var B = NextInt();
		var ans = 0;

		for (var i = A; i <= B; i++) {
			if (Judge(i)) {
				ans++;
			}
		}
		WriteLine(ans);
	}

	static bool Judge(int m) {
		var s = m.ToString();
		var n = s.Length;
		for (var i = 0; i < n / 2; i++) {
			if (s[i] != s[n - i - 1]) {
				return false;
			}
		}
		return true;
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