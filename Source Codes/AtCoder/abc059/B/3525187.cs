using static System.Console;

class Program {
	static void Main() {
		var A = ReadLine();
		var B = ReadLine();
		WriteLine(new string[] { "GREATER", "LESS", "EQUAL" }[Judge(A, B)]);
	}

	static int Judge(string A, string B) {
		if (A.Length > B.Length) {
			return 0;
		} else if (A.Length < B.Length) {
			return 1;
		} else {
			for (var i = 0; i < A.Length; i++) {
				if (A[i] > B[i]) {
					return 0;
				}
				if (B[i] > A[i]) {
					return 1;
				}
			}
		}
		return 2;
	}
}