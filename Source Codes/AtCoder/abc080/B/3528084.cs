using static System.Console;

class Program {
	static void Main() {
		var N = int.Parse(ReadLine());
		if (N % F(N) == 0) {
			WriteLine("Yes");
		} else {
			WriteLine("No");
		}
	}

	static int F(int n) {
		var result = 0;
		for (; n != 0; n /= 10) {
			result += n % 10;
		}
		return result;
	}
}