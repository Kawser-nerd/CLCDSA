using static System.Console;

class Program {
	static void Main() {
		var S = ReadLine();
		for (var c = 'a'; c <= 'z'; c++) {
			if (!S.Contains(c + "")) {
				WriteLine(c);
				return;
			}
		}
		WriteLine("None");
	}
}