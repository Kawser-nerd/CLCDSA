import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// new Main().run();
	}

	final long MODULO = (long) (1e9 + 7);
	int n, c;
	int[] a, b;

	public void run() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		c = sc.nextInt();
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = sc.nextInt();
		}
		for (int i = 0; i < n; ++i) {
			b[i] = sc.nextInt();
		}

		long[][] pow = new long[c + 1][401];
		Arrays.fill(pow[0], 1);
		for (int i = 1; i <= c; ++i) {
			for (int j = 0; j < pow[i].length; ++j) {
				pow[i][j] = pow[i - 1][j] * j % MODULO;
			}
		}
		long[][] sum = new long[c + 1][401];
		for (int i = 0; i <= c; ++i) {
			for (int j = 0; j < pow[i].length; ++j) {
				sum[i][j] += (j > 0 ? sum[i][j - 1] : 0) + pow[i][j];
				if (sum[i][j] >= MODULO)
					sum[i][j] -= MODULO;
			}
		}

		long[][] g = new long[c + 1][n];
		for (int i = 0; i <= c; ++i) {
			for (int j = 0; j < n; ++j) {
				g[i][j] = sum[i][b[j]] - (a[j] > 0 ? sum[i][a[j] - 1] : 0);
				g[i][j] = (g[i][j] + MODULO) % MODULO;
			}
		}

		long[][] f = new long[n][c + 1];
		for (int i = 0; i <= c; ++i) {
			f[0][i] = g[i][0];
		}

		for (int i = 1; i < n; ++i) {
			for (int preC = 0; preC <= c; ++preC) {
				for (int curC = 0; preC + curC <= c; ++curC) {
					f[i][preC + curC] += f[i - 1][preC] * g[curC][i] % MODULO;
					f[i][preC + curC] %= MODULO;
				}
			}
		}

		System.out.println(f[n - 1][c] % MODULO);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}