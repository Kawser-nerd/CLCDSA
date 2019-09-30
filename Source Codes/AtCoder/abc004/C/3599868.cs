using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var n = NextInt();
		var cards = new int[6];
		for (var i = 0; i < cards.Length; i++) {
			cards[i] = i + 1;
		}

		for (var i = 0; i < n % 30; i++) {
			swap(ref cards[i % 5], ref cards[i % 5 + 1]);
		}
		WriteLine(string.Join("", cards));
	}

	static void swap<T>(ref T a, ref T b) {
		var tmp = a;
		a = b;
		b = tmp;
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