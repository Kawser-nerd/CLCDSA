using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program {
	static void Main() {
		var N = NextInt();
		var M = NextInt();

		var a = new int[N];
		var b = new int[N];

		for (var i = 0; i < N; i++) {
			a[i] = NextInt();
			b[i] = NextInt();
		}

		var c = new int[M];
		var d = new int[M];

		for (var j = 0; j < M; j++) {
			c[j] = NextInt();
			d[j] = NextInt();
		}

		for (var i = 0; i < N; i++) {
			WriteLine(Calc(a[i], b[i], c, d));
		}
	}

	static int Calc(int a, int b, int[] c, int[] d) {
		int key = 0;
		int val = int.MaxValue;
		var M = c.Length;
		for (var i = 0; i < M; i++) {
			var tmp = Abs(a - c[i]) + Abs(b - d[i]);
			if (tmp < val) {
				val = tmp;
				key = i + 1;
			}
		}
		return key;
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