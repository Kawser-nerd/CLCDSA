using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var H = NextInt();
		var W = NextInt();
		var map = new int[H, W];

		for (var i = 0; i < H; i++) {
			var S = ReadLine();
			for (var j = 0; j < W; j++) {
				if (S[j] == '#') {
					map[i, j] += 10;
					for (var x = -1; x <= 1; x++) {
						for (var y = -1; y <= 1; y++) {
							if (H <= i + x || i + x < 0) {
								//
							} else if (W <= j + y || j + y < 0) {
								//
							} else {
								map[i + x, j + y]++;
							}
						}
					}
				}
			}
		}

		for (var i = 0; i < H; i++) {
			for (var j = 0; j < W; j++) {
				var tmp = map[i, j];
				if (tmp >= 10) {
					Write("#");
				} else {
					Write(tmp);
				}
			}
			WriteLine();
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