import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskD {
		public void solve(int testNumber, FastScanner in, PrintWriter out) {
			int n = in.nextInt();
			List<Integer>[] adj = new List[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
			}
			for (int i = 0; i < n - 1; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				adj[a].add(b);
				adj[b].add(a);
			}
			int[] adjLeaves = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j : adj[i]) {
					if (adj[j].size() == 1) {
						++adjLeaves[i];
					}
				}
				if (adjLeaves[i] >= 2) {
					out.println("First");
					return;
				}
			}
			int[] q = new int[n];
			int qt = 0;
			int qh = 0;
			boolean[] dead = new boolean[n];
			boolean[] leaf = new boolean[n];
			for (int i = 0; i < n; i++) {
				if (adj[i].size() == 1) {
					q[qh++] = i;
					leaf[i] = true;
				}
			}
			int[] deg = new int[n];
			for (int i = 0; i < n; i++) {
				deg[i] = adj[i].size();
			}
			int leaves = 0;
			while (qt < qh) {
				int v = q[qt++];
				int nv = -1;
				for (int u : adj[v]) {
					if (dead[u]) {
						continue;
					}
					if (nv >= 0) {
						throw new AssertionError();
					}
					nv = u;
				}
				if (nv < 0) {
					continue;
				}
				++leaves;
				for (int x : adj[nv]) {
					if (dead[x]) {
						continue;
					}
					--deg[x];
					if (deg[x] == 1) {
						leaf[x] = true;
						q[qh++] = x;
					}
				}
				dead[v] = true;
				dead[nv] = true;
			}
			if (2 * leaves != n) {
				out.println("First");
				return;
			}
			out.println("Second");
		}

	}

	static class FastScanner {
		private BufferedReader in;
		private StringTokenizer st;

		public FastScanner(InputStream stream) {
			in = new BufferedReader(new InputStreamReader(stream));
		}

		public String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String rl = in.readLine();
					if (rl == null) {
						return null;
					}
					st = new StringTokenizer(rl);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.