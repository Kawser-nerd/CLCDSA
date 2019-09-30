import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	long MODULO = 1_000_000_000 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] f = new long[N + 1];
		long[] cum = new long[N + 1];
		Arrays.fill(f, -Integer.MAX_VALUE / 16);
		Arrays.fill(cum, -Integer.MAX_VALUE / 16);
		f[1] = N;
		cum[1] = N;
		for (int i = 2; i <= N; ++i) {
			f[i] = f[i - 1];
			f[i] = (f[i] + 1L * (N - 1) * (N - 1) % MODULO) % MODULO;
			if (i > 3) {
				f[i] = (f[i] + cum[i - 3]) % MODULO;
			}
			f[i] = (f[i] + Math.min(0, i - 3) - (i - N - 1) + 1) % MODULO;
			cum[i] = (cum[i - 1] + f[i]) % MODULO;
		}
		System.out.println(f[N]);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}