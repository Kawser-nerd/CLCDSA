import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	int gcd(int a, int b) {
		while (a % b != 0) {
			int tmp = b;
			b = a % b;
			a = tmp;
		}
		return b;
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int X = sc.nextInt();

		int[] x = new int[N];
		for (int i = 0; i < N; i++) {
			int a = sc.nextInt();
			x[i] = Math.abs(a - X);
		}
		sc.close();

		if (N == 1) {
			out.println(x[0]);
			return;
		}

		Arrays.sort(x);

		int ans = x[0];
		for (int i = 1; i < N; i++) {
			ans = gcd(ans, x[i]);
		}

		out.println(ans);

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}