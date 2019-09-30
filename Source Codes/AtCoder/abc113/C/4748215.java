import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	void solv(int[][] x) {

		Arrays.sort(x, new Comparator<int[]>() {
			@Override
			public int compare(int[] a, int[] b) {
				int x = a[1] - b[1];
				if (x == 0) {
					return a[2] - b[2];
				}
				return x;
			}
		});

		int prev = -1;
		int num = 0;
		for (int i = 0; i < x.length; i++) {
			if (x[i][1] != prev) {
				num = 1;
				prev = x[i][1];
			} else {
				num++;
			}
			x[i][3] = num;
		}

		Arrays.sort(x, (a, b) -> a[0] - b[0]);

		StringBuilder sb = new StringBuilder();
		for (int[] a : x) {
			sb.append(String.format("%06d%06d\n", a[1], a[3]));
		}
		out.print(sb);
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		int[][] x = new int[m][4]; // [idx, P, Y, num]

		for (int i = 0; i < m; i++) {
			x[i] = new int[] { i, sc.nextInt(), sc.nextInt(), -1 };
		}

		solv(x);

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}