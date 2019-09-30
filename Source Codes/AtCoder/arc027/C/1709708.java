import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main implements Runnable {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
		// System.err.println(System.currentTimeMillis() - t);
	}

	final long MOD = 1_000_000_000 + 7;

	public void run() {
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int N = sc.nextInt();
		int[] t = new int[N];
		int[] h = new int[N];
		for (int i = 0; i < N; ++i) {
			t[i] = sc.nextInt();
			h[i] = sc.nextInt();
		}
		long[][][] f = new long[2][X + 1][Y + 1];
		int b = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= X; ++j) {
				for (int k = 0; k <= Y; ++k) {
					f[b ^ 1][j][k] = f[b][j][k];
				}
			}

			for (int j = 1; j <= X; ++j) {
				for (int k = 0; k <= Y; ++k) {
					if (k >= t[i] - 1)
						f[b ^ 1][j - 1][k - (t[i] - 1)] = Math.max(f[b ^ 1][j - 1][k - (t[i] - 1)], f[b][j][k] + h[i]);
					else if (j + k >= t[i]) {
						f[b ^ 1][j - (t[i] - k)][0] = Math.max(f[b ^ 1][j - (t[i] - k)][0], f[b][j][k] + h[i]);
					}
				}
			}
			b ^= 1;
		}

		long ans = 0;
		for (int i = 0; i <= X; ++i) {
			for (int j = 0; j <= Y; ++j) {
				ans = Math.max(ans, f[N % 2][i][j]);
			}
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}