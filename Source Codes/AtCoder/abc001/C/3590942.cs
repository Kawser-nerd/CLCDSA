using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
	static void Main() {
		var Deg = NextInt();
		var Dis = NextInt();

		var aero = "3 16 34 55 80 108 139 172 208 245 285 327".Split(' ').Select(int.Parse).ToArray();
		foreach (var i in Enumerable.Range(0, aero.Count())) {
			aero[i] = aero[i] * 10 - 5;
		}
		var keys = "N NNE NE ENE E ESE SE SSE S SSW SW WSW W WNW NW NNW N".Split(' ');
		var Dir = keys[(Deg * 10 + 1125) / 2250];

		var w = 0;
		while (w != aero.Count() && aero[w] <= Dis * 10 / 6) {
			w++;
		}
		if (w == 0) {
			Dir = "C";
		}
		WriteLine("{0} {1}", Dir, w);
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