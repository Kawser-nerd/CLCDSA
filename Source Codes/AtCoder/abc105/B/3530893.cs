using static System.Console;

class Program {
	static void Main() {
		var N = int.Parse(ReadLine());

		for (var c = 0; c * 4 <= N; c++) {
			for (var d = 0; d * 7 <= N; d++) {
				if (c * 4 + d * 7 == N) {
					WriteLine("Yes");
					return;
				}
			}
		}
		WriteLine("No");
	}
}