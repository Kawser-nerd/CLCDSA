import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		solver();
		out.flush();
	}

	static final long INF = Long.MAX_VALUE / 4;

	public static class Segtree {
		int size;
		long[] val;
		long[] maxi;

		Segtree(int N) {
			size = 1;
			while (size <= N) {
				size *= 2;
			}
			val = new long[size * 2];
			maxi = new long[size * 2];
			Arrays.fill(maxi, -INF);
		}

		// ??[a,b)??v???
		public void update(int a, int b, long v, int k, int l, int r) {
			if (b <= l || a >= r)
				return;
			if (a <= l && r <= b) {
				val[k] += v;
				maxi[k] += v;
			} else {
				update(a, b, v, 2 * k + 1, l, (l + r) / 2);
				update(a, b, v, 2 * k + 2, (l + r) / 2, r);
				maxi[k] = Math.max(maxi[2 * k + 1], maxi[2 * k + 2]) + val[k];
			}
		}

		public void update(int a, int b, long v) {
			update(a, b, v, 0, 0, size);
		}
	}

	static void solver() {
		int N = ni();
		int[] w = new int[N];
		for (int i = 0; i < N; i++) {
			w[i] = ni();
		}

		ArrayList<Integer>[] drink = new ArrayList[500010];
		for (int i = 0; i < drink.length; i++) {
			drink[i] = new ArrayList<>();
		}
		for (int i = 0; i < N; i++) {
			int M = ni();
			for (int j = 0; j < M; j++) {
				int t = ni();
				drink[t / 2].add(i);
			}
		}
		long ans = 0;
		Segtree seg = new Segtree(500001);
		long[] dp = new long[500003];
		int[] pre = new int[500001];
		Arrays.fill(dp, -INF);
		dp[0] = 0;
		seg.update(0, 1, INF);
		for (int t = 1; t <= 500_000; t++) {
			for (int d : drink[t]) {
				seg.update(pre[d], t, w[d]);
				pre[d] = t;
			}
			dp[t] = seg.maxi[0];
			seg.update(t, t + 1, dp[t] + INF);
			ans = Math.max(ans, dp[t]);
		}
		out.println(ans);
	}

	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	static long nl() {
		try {
			long num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}

	static char nc() {
		try {
			int b = skip();
			if (b == -1)
				return 0;
			return (char) b;
		} catch (IOException e) {
		}
		return 0;
	}

	static double nd() {
		try {
			return Double.parseDouble(ns());
		} catch (Exception e) {
		}
		return 0;
	}

	static String ns() {
		try {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			if (b == -1)
				return "";
			sb.append((char) b);
			while (true) {
				b = is.read();
				if (b == -1)
					return sb.toString();
				if (b <= ' ')
					return sb.toString();
				sb.append((char) b);
			}
		} catch (IOException e) {
		}
		return "";
	}

	public static char[] ns(int n) {
		char[] buf = new char[n];
		try {
			int b = skip(), p = 0;
			if (b == -1)
				return null;
			buf[p++] = (char) b;
			while (p < n) {
				b = is.read();
				if (b == -1 || b <= ' ')
					break;
				buf[p++] = (char) b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}

	public static byte[] nse(int n) {
		byte[] buf = new byte[n];
		try {
			int b = skip();
			if (b == -1)
				return null;
			is.read(buf);
			return buf;
		} catch (IOException e) {
		}
		return null;
	}

	static int skip() throws IOException {
		int b;
		while ((b = is.read()) != -1 && !(b >= 33 && b <= 126))
			;
		return b;
	}

	static boolean eof() {
		try {
			is.mark(1000);
			int b = skip();
			is.reset();
			return b == -1;
		} catch (IOException e) {
			return true;
		}
	}

	static int ni() {
		try {
			int num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}

	static void tr(Object... o) {
		if (INPUT.length() != 0)
			System.out.println(Arrays.deepToString(o));
	}

} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.