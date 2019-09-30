import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	private static void swap(int[] a, int i) {
		int tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();
		int[] c = { 1, 2, 3, 4, 5, 6 };

		n %= 30;

		for (int i = 0; i < n; i++) {
			swap(c, i % 5);
		}

		for (int x : c) {
			out.print(x);
		}
		out.println();

		sc.close();
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}