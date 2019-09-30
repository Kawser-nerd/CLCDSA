import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	long MOD = 1_000_000_007;
	int N;
	HashMap<ArrayList<Integer>, Long>[][] memo = new HashMap[900][900];
	boolean[] yes = new boolean[900];

	void solver() {
		for (int i = 0; i < 900; i++) {
			for (int j = 0; j < 900; j++) {
				memo[i][j] = new HashMap<>();
			}
		}

		N = ni();
		for (int i = 0; i < N - 1; i++) {
			yes[ni()] = true;
		}
		ArrayList<Integer> V = new ArrayList<>();
		for (int i = 0; i < N; i++)
			V.add(1);
		out.println(dfs(V, 1, 0));
	}

	long dfs(ArrayList<Integer> V, int cur, int left) {
		if (cur > N * (N - 1) / 2) {
			return 1;
		}
		if (memo[cur][left].containsKey(V)) {
			return memo[cur][left].get(V);
		}
		long ret = 0;
		if (yes[cur]) {
			for (int i = 0; i < V.size(); i++) {
				for (int j = 0; j < i; j++) {
					ArrayList<Integer> V2 = new ArrayList<>();
					for (int k = 0; k < V.size(); k++) {
						if (k != i && k != j) {
							V2.add(V.get(k));
						}
					}
					V2.add(V.get(i) + V.get(j));
					V2.sort(null);
					ret += V.get(i) * V.get(j) * dfs(V2, cur + 1, left + V.get(i) * V.get(j) - 1) % MOD;
					ret %= MOD;
				}
			}
		} else {
			if (left > 0)
				ret = left * dfs(V, cur + 1, left - 1) % MOD;
		}
		memo[cur][left].put(V, ret % MOD);
		return ret % MOD;
	}

	void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		solver();
		out.flush();

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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.