using static System.Console;

class Program {
	static void Main() {
		var N = NextInt();
		var a = new int[N];
		for (var i = 0; i < N; i++) {
			a[i] = NextInt();
		}
		var j = 1;
		for (var i = 1; i <= N; i++) {
			j = a[j - 1];
			if (j == 2) {
				WriteLine(i);
				return;
			}
		}
		WriteLine(-1);
	}

	static int NextInt() {
		return int.Parse(ReadLine());
	}
}