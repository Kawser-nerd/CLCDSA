using static System.Console;

class Program {
	static void Main() {
		var N = int.Parse(ReadLine());
		for (var i = 1; ; i *= 2) {
			if (2 * i > N) {
				WriteLine(i);
				break;
			}
		}
	}
}