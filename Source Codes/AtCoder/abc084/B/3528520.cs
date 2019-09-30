using System.Collections.Generic;
using static System.Console;

class Program {
	static void Main() {
		var A = NextInt();
		var B = NextInt();
		var S = ReadLine();

		WriteLine(Judge(A, B, S) ? "Yes" : "No");
	}

	static bool Judge(int A, int B, string S) {
		var i = 0;
		foreach (var c in S) {
			if (i < A || i + B >= S.Length) {
				if (c == '-') {
					return false;
				}
			} else if (c != '-') {
				return false;
			}
			i++;
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