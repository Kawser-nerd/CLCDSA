import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	final long MODULO = 998244353L;
	long[] fac = new long[400];
	long[] invfac = new long[400];
	long[] inv = new long[400];
	long[][] C = new long[400][400];
	long[] pow2 = new long[400];
	{
		fac[0] = 1;
		invfac[0] = 1;
		inv[1] = 1;
		for (int i = 1; i < fac.length; ++i) {
			fac[i] = fac[i - 1] * i % MODULO;
		}
		for (int i = 2; i < inv.length; ++i) {
			inv[i] = (MODULO - (MODULO / i) * inv[(int) (MODULO % i)] % MODULO) % MODULO;
		}
		for (int i = 1; i < invfac.length; ++i) {
			invfac[i] = invfac[i - 1] * inv[i] % MODULO;
		}
		C[0][0] = 1;
		for (int i = 1; i < C.length; ++i) {
			for (int j = 0; j <= i; ++j) {
				C[i][j] = (j > 0 ? C[i - 1][j - 1] : 0) + C[i - 1][j];
				C[i][j] %= MODULO;
			}
		}
		pow2[0] = 1;
		for (int i = 1; i < pow2.length; ++i) {
			pow2[i] = pow2[i - 1] * 2 % MODULO;
		}

	}

	void run() {
		Scanner sc = new Scanner(System.in);
		Random rand = new Random();
		// while (true) {
		int n = sc.nextInt();
		// int n = rand.nextInt(5);
		long[] x = new long[n];
		long[] y = new long[n];
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			// x[i] = rand.nextInt(5);
			// y[i] = rand.nextInt(5);
		}
		solver(n, x, y);
		// }
	}

	void solver(int n, long[] x, long[] y) {
		long ans = pow2[n];

		ans = (ans - n + MODULO) % MODULO;
		for (int i = 0; i < n; ++i) {
			boolean[] vis = new boolean[n];
			vis[i] = true;
			for (int j = i + 1; j < n; ++j) {
				if (vis[j])
					continue;
				vis[j] = true;
				int cnt = 1;
				for (int k = j + 1; k < n; ++k) {
					if ((x[i] - x[j]) * (y[k] - y[i]) == (y[i] - y[j]) * (x[k] - x[i])) {
						if (vis[k]) {
							throw new AssertionError();
						}
						vis[k] = true;
						++cnt;
					}
				}
				ans = (ans - (pow2[cnt] - 1) + MODULO) % MODULO;
			}
		}
		System.out.println(ans - 1);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}