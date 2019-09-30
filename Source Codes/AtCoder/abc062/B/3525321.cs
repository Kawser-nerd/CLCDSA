using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var H = NextInt();
		var W = NextInt();

		var a = new string[H];
		for (var i = 0; i < H; i++) {
			a[i] = ReadLine();
		}


		for (var i = -1; i <= H; i++) {
			Write("#");
			if (i == -1 || i == H) {
				Write(new string('#', W));
			} else {
				Write(a[i]);
			}
			WriteLine("#");
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