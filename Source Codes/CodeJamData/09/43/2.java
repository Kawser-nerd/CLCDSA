import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class BaiC3 {

	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//PrintWriter pw = new PrintWriter(System.out);

		Scanner sc = new Scanner(new FileReader("C-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int ntest = sc.nextInt();
		for (int test = 1; test <= ntest; ++test) {
			// System.out.println(test);
			int n = sc.nextInt();
			int k = sc.nextInt();
			int[][] a = new int[n][k];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < k; ++j)
					a[i][j] = sc.nextInt();
			}

			boolean[][] b = new boolean[n][n];
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					b[i][j] = below(a[i], a[j]);

			int res = n;

			int[] y = new int[n];
			Arrays.fill(y, -1);

			for (int i = 0; i < n; ++i) {
				boolean[] vs = new boolean[n];
				if (tim(i, b, vs, y))
					--res;
			}

			pw.println("Case #" + test + ": " + res);
		}

		pw.close();
		sc.close();
	}

	static boolean tim(int i, boolean[][] b, boolean[] vs, int[] y) {
		if (vs[i])
			return false;
		vs[i] = true;
		for (int j = 0; j < y.length; ++j)
			if (b[i][j] && (y[j] == -1 || tim(y[j], b, vs, y))) {
				y[j] = i;
				return true;
			}
		return false;
	}

	static boolean below(int[] a, int[] b) {
		for (int i = 0; i < a.length; ++i)
			if (a[i] >= b[i])
				return false;
		return true;
	}
}
