import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] c = new int[m];
		for (int i = 0; i < m; ++i) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			c[i] = sc.nextInt();
			--a[i];
			--b[i];
		}
		solve(n, m, a, b, c);
	}

	void solve(int n, int m, int[] a, int[] b, int[] c) {
		int[] C = new int[1 << n];
		int[][] adj = new int[n][n];
		for (int i = 0; i < m; ++i) {
			adj[a[i]][b[i]] = c[i];
			adj[b[i]][a[i]] = c[i];
		}
		for (int s = 0; s < (1 << n); ++s) {
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					if (((1 << i) & s) > 0 && ((1 << j) & s) > 0) {
						C[s] += adj[i][j];
					}
				}
			}
		}

		int[][] f = new int[1 << n][n];// ???
		for (int i = 0; i < f.length; ++i) {
			for (int j = 0; j < f[i].length; ++j) {
				f[i][j] = -Integer.MAX_VALUE / 8;
			}
		}
		f[1][0] = 0;

		for (int s = 1; s < (1 << n); ++s) {
			for (int src = 0; src < n; ++src) {
				if (((1 << src) & s) == 0)
					continue;
				for (int dst = 0; dst < n; ++dst) {
					if (((1 << dst) & s) > 0 || adj[src][dst] == 0)
						continue;
					f[s | 1 << dst][dst] = Math.max(f[s | 1 << dst][dst], f[s][src] + adj[src][dst]);
				}

				int _s = (1 << n) - 1 - s;
				for (int t = ((1 << n) - 1) & _s; t > 0; t = (t - 1) & _s) {
					f[s | t][src] = Math.max(f[s | t][src], f[s][src] + C[t | 1 << src]);
				}
			}
		}

		int ans = C[(1 << n) - 1] - f[(1 << n) - 1][n - 1];
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}