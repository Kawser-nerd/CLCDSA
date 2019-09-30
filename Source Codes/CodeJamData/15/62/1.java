import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	final int MAX = (int) 1e6 + 10;
	final int mod = (int) 1e9 + 7;

	int c(int n, int k) {
		if (k == 0 || k == n) {
			return 1;
		}
		return (int) (fact[n] * 1L * factInv[k] % mod * factInv[n - k] % mod);
	}

	int[] fact, factInv;

	void solve() {
		int tc = in.nextInt();
		fact = new int[MAX];
		factInv = new int[MAX];
		fact[0] = 1;
		factInv[0] = 1;
		BigInteger MOD = BigInteger.valueOf(mod);
		for (int i = 1; i < MAX; i++) {
			fact[i] = (int) ((fact[i - 1] * 1L * i % mod));
			factInv[i] = BigInteger.valueOf(fact[i]).modInverse(MOD).intValue();
		}
		int[] dpCycles = new int[MAX];
		dpCycles[0] = 1;
		for (int sz = 2; sz < MAX; sz++) {
			dpCycles[sz] = (int) ((dpCycles[sz - 2] + dpCycles[sz - 1]) * 1L
					* (sz - 1) % mod);
		}
		int[] dp21 = new int[MAX];
		dp21[0] = 1;
		for (int sz = 1; sz < MAX; sz++) {
			dp21[sz] = (int) (dpCycles[sz] * 1L * fact[sz] % mod);
		}
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int n = in.nextInt();
			int x = in.nextInt();
			long result = 0;
			for (int three = x; three <= n; three++) {
				long tmp = c(n, three) * 1L * c(n, three) % mod * fact[three] % mod
						* dp21[n - three] % mod;
				result += tmp;
			}
			out.println(result % mod);
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("B.in"));
			out = new PrintWriter(new File("B.out"));

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
		new B().run();
	}
}