import java.util.*;

class Main {
	static int N;
	static long[] a;
	static long[][] is;
	static long[] freq;
	static long[] cum;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		a = new long[N];
		is = new long[2][N];
		freq = new long[N + 1];
		cum = new long[N];
		Arrays.fill(is[0], -1);
		Arrays.fill(is[1], -1);
		Arrays.fill(freq, -1);
		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextInt();
		}

		int p = 0;
		for (int i = 0; i < N; ++i) {
			if (i == 0 || is[0][p - 1] < a[i]) {
				is[0][p] = a[i];
				is[1][p] = i + 1;
				++p;
			}
		}
		is[0] = Arrays.copyOf(is[0], p);
		is[1] = Arrays.copyOf(is[1], p);
		Arrays.sort(a);
		for (int i = 0; i < N; ++i) {
			cum[i] = (i > 0 ? cum[i - 1] : 0) + a[i];
		}
		for (int i = p - 1; i >= 1; --i) {
			int t = binarySearch(a, is[0][i]);
			int s = binarySearch(a, is[0][i - 1]);
			freq[(int) is[1][i]] = cum[t - 1] - cum[s] - (t - s - 1) * is[0][i - 1] + (N - t) * (is[0][i] - is[0][i - 1]);
		}
		int t = binarySearch(a, is[0][0]);
		freq[(int) is[1][0]] = (t > 0 ? cum[t - 1] : 0) + (N - t) * is[0][0];

		for (int i = 1; i <= N; ++i) {
			System.out.println(Math.max(freq[i], 0));
		}
	}

	// ?????????????????????
	static int binarySearch(long[] a, long key) {
		int s = -1;
		int t = a.length;
		while (t - s > 1) {
			int m = (s + t) / 2;
			if (a[m] > key) {
				t = m;
			} else {
				s = m;
			}
		}
		if (a[s] != key)
			s *= -1;
		return s;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}