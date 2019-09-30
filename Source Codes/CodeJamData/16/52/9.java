import java.io.*;
import java.util.*;

public class B_optimised {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.SMALL;
	static final int ATTEMPT_NUMBER = 1;

	static final int ITERS = 100_000;
	static final Random rng = new Random();
	
	int weightedRandom(int[] bag, int[] w, int n, int sum) {
		int val = rng.nextInt(sum);
		for (int i = 0; i < n; i++) {
			if (val < w[i]) {
				return i;
			}
			val -= w[i];
		}
//		System.err.println(Arrays.toString(bag));
//		System.err.println(Arrays.toString(w));
//		System.err.println(n);
//		System.err.println(sum);
		throw new AssertionError();
	}
	
	int[] prefixFunction(char[] s) {
		int[] pi = new int[s.length];
		for (int i = 1; i < s.length; i++) {
			int q = pi[i - 1];
			while (q > 0 && s[i] != s[q]) {
				q = pi[q - 1];
			}
			if (s[i] == s[q]) {
				q++;
			}
			pi[i] = q;
		}
		return pi;
	}
	
	double go(int n, int[] sizes, int[][] g, int[] init, char[] names, char[] sub) {
		int[] bag = new int[n];
		int[] bagSizes = new int[n];
		
		int succ = 0;
		
		int[] pi = prefixFunction(sub);
		
		
		outer: for (int it = 0; it < ITERS; it++) {
			
			System.arraycopy(init, 0, bag, 0, init.length);
			for (int i = 0; i < init.length; i++) {
				bagSizes[i] = sizes[init[i]];
			}
			int sz = init.length;
			int match = 0;
			
			for (int i = 0; i < n; i++) {
				int idx = weightedRandom(bag, bagSizes, sz, n - i);
				int cur = bag[idx];
				char curC = names[cur];
				bag[idx] = bag[sz - 1];
				bagSizes[idx] = bagSizes[sz - 1];
				sz--;
				
				while (match > 0 && sub[match] != curC) {
					match = pi[match - 1];
				}
				if (sub[match] == curC) {
					match++;
				}
				
				if (match == sub.length) {
					succ++;
					continue outer;
				}
				
				for (int j = 0; j < g[cur].length; j++) {
					bag[sz] = g[cur][j];
					bagSizes[sz] = sizes[bag[sz]];
					sz++;
				}
				
			}
		}		
		
		return 1.0 * succ / ITERS;
		
	}
	
	void dfs(int v, int[][] g, int[] sizes) {
		sizes[v] = 1;
		for (int i = 0; i < g[v].length; i++) {
			int u = g[v][i];
			dfs(u, g, sizes);
			sizes[v] += sizes[u];
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int[] pre = new int[n];
		int[] deg = new int[n];
		int initSz = 0;
		for (int i = 0; i < n; i++) {
			pre[i] = nextInt() - 1;
			if (pre[i] >= 0) {
				deg[pre[i]]++;
			} else {
				initSz++;
			}
		}
		
		int[][] g = new int[n][];
		for (int i = 0; i < n; i++) {
			g[i] = new int[deg[i]];
		}
		
		int[] init = new int[initSz];
		
		for (int i = 0; i < n; i++){
			if (pre[i] >= 0) {
				g[pre[i]][--deg[pre[i]]] = i;
			} else {
				init[--initSz] = i;
			}
		}
		
		int[] sizes = new int[n];
		for (int i = 0; i < n; i++) {
			if (pre[i] == -1) {
				dfs(i, g, sizes);
			}
		}
		
		String names = nextToken();
		
		int q = nextInt();
		for (int i = 0; i < q; i++) {
			String sub = nextToken();
			out.print(go(n, sizes, g, init, names.toCharArray(), sub.toCharArray()) + " ");
		}
		out.println();
		
	}

	B_optimised() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("B-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("B-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("B-large.in"));
			out = new PrintWriter("B-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B_optimised();
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
}