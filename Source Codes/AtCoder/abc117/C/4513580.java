import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		int[] x = new int[m];
		for (int i = 0; i < m; i++) {
			x[i] = sc.nextInt();
		}
		sc.close();

		Arrays.sort(x);

		int[] z = new int[m - 1];

		if (n >= m) {
			out.println(0);
			return;
		}

		for (int i = 1; i < x.length; i++) {
			z[i - 1] = (x[i] - x[i - 1]);
		}

		Arrays.sort(z);

		int ans = x[x.length - 1] - x[0];
		for (int i = 0; i < n - 1; i++) {
			ans -= z[z.length - 1 - i];
		}

		out.println(ans);

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}