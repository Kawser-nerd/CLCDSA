using static System.Console;

class Program {
	static void Main() {
		var s = ReadLine();
		var n = s.Length;

		var ans = n;

		for (var i = 0; i < n && s[i] != 'A'; i++) {
			ans--;
		}

		for (var i = n - 1; i >= 0 && s[i] != 'Z'; i--) {
			ans--;
		}

		WriteLine(ans);
	}
}