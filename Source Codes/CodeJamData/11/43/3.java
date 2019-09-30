import java.io.*;
import java.util.*;

public class C {

	private static int[] p = init(1000000 + 5);

	public static int[] init(int max) {
		boolean[] notPrime = new boolean[max];
		notPrime[0] = notPrime[1] = true;
		for (int i = 2; i * i < max; i++) {
			if (!notPrime[i]) {
				for (int j = i * i; j < max; j += i) {
					notPrime[j] = true;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < max; i++) {
			if (!notPrime[i])
				cnt++;
		}
		p = new int[cnt];
		cnt = 0;
		for (int i = 0; i < max; i++) {
			if (!notPrime[i])
				p[cnt++] = i;
		}
		return p;
	}

	long get(long n) {
		if (n == 1)
			return 0;
		long res = 1;
		for (int i : p) {
			long x = (long) i * i;
			int cnt = 0;
			while (x <= n) {
				cnt++;
				x *= i;
			}
			if (cnt == 0)
				break;
			res += cnt;
		}
		return res;
	}

	private void solve() throws IOException {
		out.println(get(nextLong()));
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	static final boolean large = true;

	public void run() {
		try {
			String fileName = "C-" + (large ? "large" : "small");
			br = new BufferedReader(new FileReader(fileName + ".in"));
			out = new PrintWriter(fileName + ".out");
			st = new StringTokenizer("");
			int T = nextInt();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}