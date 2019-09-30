import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	Random rnd = new Random(123);

	String gen(int len) {
		char[] s = new char[len];
		for (int i = 0; i < len; i++) {
			s[i] = rnd.nextBoolean() ? '1' : '0';
		}
		s[0] = s[len - 1] = '1';
		return new String(s);
	}

	long[] check(String s) {
		long[] all = new long[11];
		for (int base = 2; base <= 10; base++) {
			BigInteger z = BigInteger.ONE, val = BigInteger.ZERO;
			for (int i = s.length() - 1; i >= 0; i--) {
				if (s.charAt(i) == '1') {
					val = val.add(z);
				}
				z = z.multiply(BigInteger.valueOf(base));
			}
			if (val.isProbablePrime(100)) {
				return null;
			}
			for (long k = 2; k <= 100 && BigInteger.valueOf(k).compareTo(val) < 0; k++) {
				if (val.mod(BigInteger.valueOf(k)).equals(BigInteger.ZERO)) {
					all[base] = k;
					break;
				}
			}
			if (all[base] == 0) {
				return null;
			}
		}
		return all;
	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.println("Case #" + (t + 1) + ":");
			int n = in.nextInt();
			int cnt = in.nextInt();
			HashMap<String, long[]> was = new HashMap<>();
			HashSet<String> bad = new HashSet<>();
			while (was.size() < cnt) {
				String s = gen(n);
				if (was.containsKey(s)) {
					continue;
				}
				if (bad.contains(s)) {
					continue;
				}
				long[] check = check(s);
				if (check == null) {
					bad.add(s);
				} else {
					was.put(s, check);
				}
				System.err.println("current size is = " + was.size());
			}
			for (Map.Entry<String, long[]> entry : was.entrySet()) {
				out.print(entry.getKey());
				for (int i = 2; i <= 10; i++) {
					out.print(" " + entry.getValue()[i]);
				}
				out.println();
			}
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("C.in"));
			out = new PrintWriter(new File("C.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}