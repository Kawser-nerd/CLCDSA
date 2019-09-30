using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var ans = 0;

		for (var i = 1; i <= N; i += 2) {
			if (Judge(i)) {
				ans++;
			}
		}
		WriteLine(ans);
	}

	static bool Judge(int n) {
		var dic = new HashSet<int>();
		for (var i = 1; i <= n; i++) {
			if (n % i == 0) {
				dic.Add(i);
				dic.Add(n / i);
			}
		}
		if (dic.Count == 8) {
			return true;
		}
		return false;
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