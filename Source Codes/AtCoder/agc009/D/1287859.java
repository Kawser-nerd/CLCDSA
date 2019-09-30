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
			int m = dfs(0, -1, adj);
			int ans = 31 - Integer.numberOfLeadingZeros(m);
			out.println(ans);
		}

		private int dfs(int root, int parent, List<Integer>[] adj) {
			int setBits = 0;
			int atLeastTwice = 0;
			for (int ch : adj[root]) {
				if (ch == parent) {
					continue;
				}
				int mask = dfs(ch, root, adj);
				atLeastTwice |= (setBits & mask);
				setBits |= mask;
			}
			// weight(mask) = sum(M^i) for all set bits i in mask and
			// a large number M. Find the smallest mask such that
			// weight(rootmask) > sum of weights of children's masks.
			int last = 31 - Integer.numberOfLeadingZeros(atLeastTwice);
			int mask = setBits & ~((1 << (last + 1)) - 1);
			mask += 1 << (last + 1);
			return mask;
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