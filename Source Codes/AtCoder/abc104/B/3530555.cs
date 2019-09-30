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
			} else if (2 <= i && i < S.Length - 1) {
				if (S[i].ToString().ToUpper() == S[i] + "") {
					if (flg) {
						return false;
					}
					flg = true;
				}
			} else {
				if (S[i].ToString().ToUpper() == S[i] + "") {
					return false;
				}
			}
			i++;
		}
		return flg ? true : false;
	}
}