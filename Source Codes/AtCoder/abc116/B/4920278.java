import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	int f(int n) {
		if (n % 2 == 0) {
			return n / 2;
		} else {
			return 3 * n + 1;
		}
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);
		int s = sc.nextInt();

		int[] a = new int[1000000];

		a[s] = 1;
		int i, i_1 = s;
		int n = 1;
		for (;;) {
			i = f(i_1);
			n++;
			if (a[i] == 1) {
				out.println(n);
				break;
			}
			a[i] = 1;
			i_1 = i;
		}

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}