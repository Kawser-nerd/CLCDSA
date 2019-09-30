using System.Linq;
using static System.Console;

class Program {
	static void Main() {
		var L = new long[] { 2, 1 };
		var N = int.Parse(ReadLine());

		for (var i = 2; i <= N; i++) {
			L[i % 2] = L.Sum();
		}
		WriteLine(L[N % 2]);
	}
}