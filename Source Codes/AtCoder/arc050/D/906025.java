import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	Integer[] solver(int N, String S) {
		int[] sa = suffixArray(S);
		long[] mod = { 1000000009, 1000000007, 999999937 };
		long[][] hash = new long[3][N];
		long B = 29;
		long[][] powB = new long[3][N + 1];
		for (int i = 0; i < 3; i++)
			powB[i][0] = 1;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < 3; j++) {
				hash[j][i] = ((i == N - 1 ? 0 : hash[j][i + 1] * B) + (S.charAt(i) - 'a')) % mod[j];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < 3; j++) {
				powB[j][i] = powB[j][i - 1] * B % mod[j];
			}
		}
		Integer[] ord = new Integer[N];
		for (int i = 0; i < N; i++) {
			ord[i] = i;
		}
		Arrays.sort(ord, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				if (o1.equals(o2))
					return 0;
				int same = 0;
				int unsame = Math.min(N - o1, N - o2) + 1;
				while (unsame - same > 1) {
					int mid = (same + unsame) / 2;
					boolean flag = true;
					for (int i = 0; i < 3; i++) {
						if (!((hash[i][o1] - (mid == N - o1 ? 0 : hash[i][o1 + mid]) * powB[i][mid] % mod[i] + mod[i])
								% mod[i] == (hash[i][o2]
										- (mid == N - o2 ? 0 : hash[i][o2 + mid]) * powB[i][mid] % mod[i] + mod[i])
										% mod[i])) {
							flag = false;
							break;
						}
					}
					if (flag) {
						same = mid;
					} else {
						unsame = mid;
					}
				}
				if (o1 + same == N) {
					if (same >= N - o2 - same) {
						return Integer.compare(sa[o1], sa[o2 + same]);
					} else {
						return compare(o1, o2 + same);
					}
				} else if (o2 + same == N) {
					if (same >= N - o1 - same) {
						return Integer.compare(sa[o1 + same], sa[o2]);
					} else {
						return compare(o1 + same, o2);
					}
				} else
					return Integer.compare(S.charAt(o1 + same) - 'a', S.charAt(o2 + same) - 'a');
			}
		});
		return ord;
	}


	void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		print(solver(ni(), ns()));
		out.flush();
	}

	void print(Integer[] o) {
		for (int i = 0; i < o.length; i++) {
			out.println(o[i] + 1);
		}
	}

	int[] suffixArray(String s) {
		int n = s.length();
		Integer[] sa = new Integer[n + 1];
		int[] rank = new int[n + 1];
		int[] tmp = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			sa[i] = i;
			rank[i] = (i < n ? s.charAt(i) : -1);
		}
		for (int k = 1; k <= n; k *= 2) {
			int d = k;
			Arrays.sort(sa, new Comparator<Integer>() {
				@Override
				public int compare(Integer o1, Integer o2) {
					return compare_sa(o1, o2, rank, d, n);
				}
			});
			tmp[sa[0]] = 0;
			for (int i = 1; i <= n; i++) {
				tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i], rank, k, n) == -1 ? 1 : 0);
			}

			for (int i = 0; i <= n; i++) {
				rank[i] = tmp[i];
			}
		}
		return rank;
	}

	public int compare_sa(Integer o1, Integer o2, int[] rank, int k, int n) {
		if (rank[o1] != rank[o2])
			return Integer.compare(rank[o1], rank[o2]);
		else {
			int ri = o1 + k <= n ? rank[o1 + k] : -1;
			int rj = o2 + k <= n ? rank[o2 + k] : -1;
			return Integer.compare(ri, rj);
		}
	}

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
		System.out.println(Arrays.deepToString(o));
	}
}