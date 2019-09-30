import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	void run() throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long l = sc.nextLong();
		long t = sc.nextLong();
		long[] x = new long[n];
		long[] w = new long[n];
		long[] v = new long[n];
		long[] p = new long[n];
		int shift = 0;
		for (int i = 0; i < n; ++i) {
			x[i] = sc.nextLong();
			w[i] = sc.nextLong();
			v[i] = w[i] == 1 ? 1 : -1;
			p[i] = (x[i] + v[i] * t % l + l) % l;
			if (v[i] < 0) {
				shift += (l - x[i] + (-v[i]) * t - 1) / l % n;
			} else {
				shift -= (x[i] + v[i] * t) / l % n;
			}
			shift %= n;
		}
		while (shift < 0)
			shift += n;
		Arrays.sort(p);
		long[] ans = new long[n];
		for (int i = 0; i < n; ++i) {
			ans[i] = p[(i - shift + n) % n];
		}
		for (int i = 0; i < n; ++i) {
			System.out.println(ans[i]);
		}

	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}