using static System.Console;

class Program {
	static void Main() {
		var N = long.Parse(ReadLine());

		for (var i = 1L;; i++) {
			if ((i + 1) * (i + 1) > N) {
				WriteLine(i * i);
				break;
			}
		}
	}
}