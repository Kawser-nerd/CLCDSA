using static System.Console;

class Program {
	static void Main() {
		var s = ReadLine();
		Write(s[0]);
		Write(s.Length - 2);
		WriteLine(s[s.Length - 1]);
	}
}