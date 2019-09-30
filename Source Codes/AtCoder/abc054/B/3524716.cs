using System;
using System.Collections.Generic;
using static System.Console;

class Program {
	static int n, m;
	static string[] a, b;

	static void Main() {
		n = NextInt();
		m = NextInt();
		Array.Resize(ref a, n);
		Array.Resize(ref b, n);

		for (var i = 0; i < n; i++) {
			a[i] = ReadLine();
		}
		for (var i = 0; i < m; i++) {
			b[i] = ReadLine();
		}
		for (var i = 0; i < n; i++) {
			for (var j = 0; j < n; j++) {
				if (Judge(i, j)) {
					WriteLine("Yes");
					return;
				}
			}
		}
		WriteLine("No");
	}

	static bool Judge(int ni, int nj) {
		for (var i = 0; i < m; i++) {
			for (var j = 0; j < m; j++) {
				if (ni + i >= n || nj + j >= n || b[i][j] != a[ni + i][nj + j]) {
					return false;
				}
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