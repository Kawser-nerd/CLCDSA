using static System.Console;
using static System.Math;

class Program {
	static void Main() {
		var O = ReadLine();
		var E = ReadLine();

		for (var i = 0; i < Max(O.Length, E.Length); i++) {
			if (i < O.Length) {
				Write(O[i]);
			}
			if (i < E.Length) {
				Write(E[i]);
			}
		}
		WriteLine();
	}
}