using static System.Console;

class Program {
	static void Main() {
		var S = ReadLine();
		WriteLine(Judge(S) ? "AC" : "WA");
	}
	static bool Judge(string S) {
		var i = 0;
		var flg = false;
		foreach (var c in S) {
			if (i == 0) {
				if (S[0] != 'A') {
					return false;
				}
			} else if (1 <= i && i < S.Length) {
				if (S[i].ToString().ToUpper() == S[i] + "") {
					if (i == 1 || i == S.Length - 1 || flg) {
						return false;
					}
					flg = true;
				}
			}
			i++;
		}
		return flg ? true : false;
	}
}