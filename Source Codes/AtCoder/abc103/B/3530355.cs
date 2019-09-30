using static System.Console;

class Program {
	static void Main() {
		var S = ReadLine();
		var T = ReadLine();

		for (var i = 0; i < S.Length; i++) {
			if (S == T) {
				WriteLine("Yes");
				return;
			}
			S = S.Substring(1) + S[0];
		}
		WriteLine("No");
	}
}