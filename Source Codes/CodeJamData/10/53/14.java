import java.io.*;
import java.util.*;
import java.math.*;

public class SolC implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolC()).start();
	}

	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;
	Random random = new Random(43965743875L);

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	String FNAME = "C-small-attempt0";

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			System.out.println(test);
			out.print("Case #" + test + ": ");

			int c = nextInt();
			TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();
			for (int i = 0; i < c; i++) {
				int p = nextInt();
				int v = nextInt();
				tm.put(p, v);
			}
			int ans = 0;
			while (true) {
				boolean found = false;
				for (Integer p = tm.firstKey(); p != null; p = tm.higherKey(p)) {
					if (tm.get(p) > 1) {
						ans++;
						found = true;
						if (!tm.containsKey(p - 1)) {
							tm.put(p - 1, 0);
						}
						tm.put(p - 1, tm.get(p - 1) + 1);
						if (!tm.containsKey(p + 1)) {
							tm.put(p + 1, 0);
						}
						tm.put(p + 1, tm.get(p + 1) + 1);
						if (tm.get(p) > 2) {
							tm.put(p, tm.get(p) - 2);
						} else {
							tm.remove(p);
						}
					}
				}
				if (!found) break;
			}
			out.println(ans);
		}
	}
}
