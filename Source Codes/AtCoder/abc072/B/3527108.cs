using static System.Console;

class Program {
	static void Main() {
		var s = ReadLine();
		for (var i = 0; i < s.Length; i += 2) {
			Write(s[i]);
		}
		WriteLine();
	}
}