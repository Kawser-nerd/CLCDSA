import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	List<Integer>[] g;

	boolean[] fixed;
	int[] val;
	boolean[] anything;
	
	int[] low, high;
	
	int[] outp;

	void solve() throws IOException {
		int n = nextInt();
		g = new List[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < n - 1; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			g[v].add(u);
			g[u].add(v);
		}

		int k = nextInt();
		fixed = new boolean[n];
		val = new int[n];
		
		int root = -1;

		for (int i = 0; i < k; i++) {
			int v = nextInt() - 1;
			fixed[v] = true;
			val[v] = nextInt();
			root = v;
		}
		
//		System.err.println(root);
		
		low = new int[n];
		high = new int[n];
		anything = new boolean[n];
		
		boolean hasAns = dfs1(root, -1);
		out.println(hasAns ? "Yes" : "No");
		
		if (hasAns) {
			outp = new int[n];
			outp[root] = val[root];
			dfs2(root, -1, val[root]);
			for (int x : outp) {
				out.println(x);
			}
		}
	}
	
	void dfs2(int v, int p, int pVal) {
		if (p != -1) {
			if (anything[v]) {
				outp[v] = pVal - 1;
			} else if (low[v] <= pVal - 1 && pVal - 1 <= high[v]) {
				outp[v] = pVal - 1;
			} else if (low[v] <= pVal + 1 && pVal + 1 <= high[v]) {
				outp[v] = pVal + 1;
			} else {
				throw new AssertionError();
			}
		}
		
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			dfs2(u, v, outp[v]);
		}
	}
	
	boolean dfs1(int v, int p) {
		if (fixed[v]) {
			low[v] = high[v] = val[v];
		} else {
			anything[v] = true;
		}
		
		for (int u : g[v]) {
			if (u == p) {
				continue;
			}
			
			boolean isOk = dfs1(u, v);
			if (!isOk) {
				return false;
			}
			
			if (anything[u]) {
				continue;
			}
			
			if (anything[v]) {
				anything[v] = false;
				low[v] = low[u] - 1;
				high[v] = high[u] + 1;
				continue;
			}
			
			if (((low[u] ^ low[v]) & 1) == 0) {
				return false;
			}
			
			low[v] = Math.max(low[v], low[u] - 1);
			high[v] = Math.min(high[v], high[u] + 1);
		}
		
		return low[v] <= high[v];
	}
	
	boolean isInside(int val, int low, int high) {
		if (((low ^ high) & 1) != 0) {
			throw new AssertionError();
		}
		return low <= val && val <= high && ((val ^ low) & 1) == 0;
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		Thread t = new Thread(null, new Runnable() {

			@Override
			public void run() {
				try {
					solve();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}, "lul", 1 << 26);
		t.start();
		try {
			t.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
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
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.