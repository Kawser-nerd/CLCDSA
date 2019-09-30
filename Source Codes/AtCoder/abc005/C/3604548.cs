using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var T = NextInt();
		var N = NextInt();
		var A = new int[N];
		for (var j = 0; j < N; j++) {
			A[j] = NextInt();
		}
		var M = NextInt();
		var B = new int[M];
		for (var j = 0; j < M; j++) {
			B[j] = NextInt();
		}
		var i = 0;
		var flg = false;

		for (var j = 0; j < B.Length; j++) {
			while (i != N && A[i] + T < B[j]) {
				i++;
			}
			if (i == N || B[j] < A[i]) {
				flg = true;
				break;
			}
			i++;
		}
		if (!flg) {
			WriteLine("yes");
		} else {
			WriteLine("no");
		}
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