import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	void solve(int n, int m, int[] cost, int[][] idol, double[][] p) {
		double[] e = new double[1 << n];
		Arrays.fill(e, 1L << 60);
		e[0] = 0;
		for (int s = 0; s < 1 << n; ++s) {
			for (int j = 0; j < m; ++j) {
				double a = 0;
				double resp = 0;
				for (int k = 0; k < idol[j].length; ++k) {
					if ((s & (1 << idol[j][k])) > 0) {
						int ns = s ^ (1 << idol[j][k]);
						a += e[ns] * p[j][k];
					} else {
						resp += p[j][k];
					}
				}
				if (resp < 0.999)
					e[s] = Math.min(e[s], (cost[j] + a) / (1 - resp));
			}
		}
		System.out.println(e[(1 << n) - 1]);
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] c = new int[m];
		int[] cost = new int[m];
		int[][] idol = new int[m][];
		double[][] p = new double[m][];
		for (int i = 0; i < m; ++i) {
			c[i] = sc.nextInt();
			cost[i] = sc.nextInt();
			idol[i] = new int[c[i]];
			p[i] = new double[c[i]];
			for (int j = 0; j < c[i]; ++j) {
				idol[i][j] = sc.nextInt();
				--idol[i][j];
				p[i][j] = sc.nextDouble() * 0.01;
			}
		}
		solve(n, m, cost, idol, p);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}