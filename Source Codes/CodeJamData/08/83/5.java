import java.io.*;
import java.util.*;
import java.math.*;

public class Tree implements Runnable {

	public static void main(String[] args) {
		new Thread(new Tree()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(this.hashCode());

	@Override
	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

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

	String FNAME = "tree";

	ArrayList<Integer>[] g;

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			int k = nextInt();
			g = new ArrayList[n];
			for (int i = 0; i < g.length; i++) {
				g[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n - 1; i++) {
				int x = nextInt() - 1;
				int y = nextInt() - 1;
				g[x].add(y);
				g[y].add(x);
			}
			q = new boolean[n];
			out.println(DFS(0, 0, 0, 0, k));
		}
	}

	boolean[] q;

	long P = 1000000009;

	private long DFS(int x, int z, int i, int w, int k) {
		q[x] = true;
		int j = 0;
		long ans = 1;
		for (int y : g[x]) {
			if (!q[y]) {
				j++;
			}
		}
		for (int y : g[x]) {
			if (!q[y]) {
				ans = (ans * DFS(y, z, j, z == x ? 0 : 1, k)) % P;
			}
		}
		ans = (ans * a(k - i - w, j)) % P;
		return ans;
	}

	long a(long n, long k) {
		BigInteger ans = BigInteger.ONE;
		for (long i = n - k + 1; i <= n; i++) {
			ans = ans.multiply(BigInteger.valueOf(i));
		}
		// System.out.println(n + " " + k + " " + ans);
		return ans.mod(BigInteger.valueOf(P)).longValue();
	}

}
