import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// long t = System.currentTimeMillis();
		new Main().run();
		// System.err.println(System.currentTimeMillis() - t);
	}

	int n;
	int k;
	char[] s;
	int[][][][] f;

	long MODULO = 1_000_000__000 + 7;

	public void run() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		s = sc.next().toCharArray();
		f = new int[2][2][n + 1][2 * n + 1];
		for (int max = 0; max <= n; ++max) {
			if (max == 0)
				f[0][1][max][n] = 1;
			else
				f[0][0][max][n] = 1;
		}

		int b = 0;
		for (int i = 0; i < n; ++i) {

			for (int max = 0; max <= n; ++max) {
				for (int balance = Math.max(-k, max - k - 1); balance <= Math.min(k, max + 1); ++balance) {
					if ((s[i] == '1' || s[i] == '?') && balance + 1 <= max && balance + 1 <= k) {
						f[b ^ 1][1][max][balance + n + 1] = add(f[b ^ 1][1][max][balance + n + 1],
								f[b][1][max][balance + n]);

						if (balance + 1 == max) {
							f[b ^ 1][1][max][balance + n + 1] = add(f[b ^ 1][1][max][balance + n + 1],
									f[b][0][max][balance + n]);
						}

						if (balance + 1 < max) {
							f[b ^ 1][0][max][balance + n + 1] = add(f[b ^ 1][0][max][balance + n + 1],
									f[b][0][max][balance + n]);
						}

					}
					if ((s[i] == '0' || s[i] == '?') && -k <= balance - 1 && max - (balance - 1) <= k) {
						f[b ^ 1][1][max][balance + n - 1] = add(f[b ^ 1][1][max][balance + n - 1],
								f[b][1][max][balance + n]);
						f[b ^ 1][0][max][balance + n - 1] = add(f[b ^ 1][0][max][balance + n - 1],
								f[b][0][max][balance + n]);

					}
					f[b][0][max][balance + n] = 0;
					f[b][1][max][balance + n] = 0;

				}

			}
			b ^= 1;
		}

		long ans = 0;

		for (int i = 0; i <= n; ++i) {
			for (int balance = -k; balance <= k; ++balance) {
				ans = add(ans, f[b][1][i][balance + n]);
			}
		}

		System.out.println(ans);

	}

	int add(long a, long b) {
		long ret = a + b;
		if (ret >= MODULO) {
			ret -= MODULO;
		}
		return (int) ret;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}