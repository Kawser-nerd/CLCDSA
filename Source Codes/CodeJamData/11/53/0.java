import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "C-large";
	private int[] r;
	private int[] p;
	private int n;
	private int m;

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		n = nextInt();
		m = nextInt();
		int[] ec = new int[n * m];
		r = new int[n * m];
		p = new int[n * m];
		for (int i = 0; i < n * m; ++i) {
			p[i] = i;
		}
		int comps = n * m;
		for (int i = 0; i < n; ++i) {
			char[] tmp = next().toCharArray();
			for (int j = 0; j < m; ++j) {
				int u, v;
				if (tmp[j] == '|') {
					u = cs(i - 1, j);
					v = cs(i + 1, j);
				} else if (tmp[j] == '-') {
					u = cs(i, j - 1);
					v = cs(i, j + 1);
				} else if (tmp[j] == '/') {
					u = cs(i - 1, j + 1);
					v = cs(i + 1, j - 1);
				} else if (tmp[j] == '\\') {
					u = cs(i - 1, j - 1);
					v = cs(i + 1, j + 1);
				} else {
					throw new AssertionError();
				}
				ec[u]++;
				ec[v]++;
				if (unite(u, v)) {
					comps--;
				}
			}
		}
		int[] cv = new int[n * m];
		int[] ce = new int[n * m];
		for (int i = 0; i < n * m; ++i) {
			cv[get(i)]++;
			ce[get(i)] += ec[i];
		}
		for (int i = 0; i < n * m; ++i) {
			if (ce[i] != cv[i] * 2) {
				out.println(0);
				return;
			}
		}
		int ans = 1;
		for (int i = 0; i < comps; ++i) {
			ans = (ans * 2) % 1000003;
		}
		out.println(ans);
	}

	private boolean unite(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return false;
		}
		if (r[u] < r[v]) {
			p[u] = v;
		} else {
			p[v] = u;
		}
		if (r[u] == r[v]) {
			++r[u];
		}
		return true;
	}

	private int get(int i) {
		if (p[i] != i) {
			p[i] = get(p[i]);
		}
		return p[i];
	}

	private int cs(int i, int j) {
		i = (i + n) % n;
		j = (j + m) % m;
		return i * m + j;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(file + ".in"));
			out = new PrintWriter(file + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	static boolean failed = false;
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}
