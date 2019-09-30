import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c {
	public static void main(String[] Args) throws Exception {
		FS sc = new FS(new File("C-large.in"));
		// FS sc = new FS(new File("C-small-attempt0.in"));
		// FS sc = new FS(System.in);
		// PrintWriter out = new PrintWriter(new BufferedWriter(
		// new OutputStreamWriter(System.out)));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				new File("c.out"))));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			ArrayList<Integer>[] adj = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<Integer>();
			}
			for (int k = 0; k < n; k++) {
				adj[k].add(sc.nextInt() - 1);
			}
			Tarjan tj = new Tarjan(adj);
			int best = 0;
			int sum_of_lines = 0;
			boolean[] in_line = new boolean[n];
			for (int i = 0; i < n; i++) {
				int cur = 0;
				for (int k = 0; k < n; k++) {
					if (tj.sccId[k] == tj.sccId[i])
						cur++;
				}
				if (cur == 2) {
					in_line[i] = true;
				}

				best = Math.max(best, cur);
			}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (in_line[adj[j].get(0)])
						in_line[j] = true;
			int[] dp = new int[n];
			for (int i = 0; i < n; i++)
				if (in_line[i])
					dp[i] = 1;
			for (int j = 0; j < n; j++)
				for (int i = 0; i < n; i++)
					if (in_line[i] && adj[adj[i].get(0)].get(0) != i) {
						dp[adj[i].get(0)] = Math.max(dp[adj[i].get(0)],
								dp[i] + 1);
					}
			for (int i = 0; i < n; i++)
				if (adj[adj[i].get(0)].get(0) == i)
					sum_of_lines += dp[i];

			best = Math.max(best, sum_of_lines);
			out.printf("Case #%d: %d%n", ++cc, best);
		}
		out.close();
	}

	public static class Tarjan {
		public int ind, sPtr, dsPtr, sccCount, N;
		public boolean[] onStk;
		public int[] low, pre, sStk, sccId, dStk, c, p;
		ArrayList<Integer>[] g;

		public Tarjan(ArrayList<Integer>[] g) {
			this.g = g;
			this.N = g.length;
			onStk = new boolean[N];
			low = new int[N];
			sStk = new int[N];
			dStk = new int[N];
			c = new int[N];
			Arrays.fill(p = new int[N], -1);
			Arrays.fill(sccId = new int[N], -1);
			Arrays.fill(pre = new int[N], -1);
			for (int i = 0; i < N; i++)
				if (pre[i] < 0)
					dfs(i);
		}

		void makeScc(int v) {
			for (int t = -1; t != v; onStk[t] = false)
				sccId[t = sStk[--sPtr]] = sccCount;
			sccCount++;
		}

		void addToStack(int v, int parent) {
			onStk[dStk[dsPtr++] = sStk[sPtr++] = v] = true;
			pre[v] = low[v] = ind++;
			p[v] = parent;
		}

		public void dfs(int rNode) {
			addToStack(rNode, -1);
			while (dsPtr != 0) {
				int at = dStk[dsPtr - 1];
				if (c[at] == g[at].size()) {
					dsPtr--;
					if (p[at] != -1 && low[at] < low[p[at]])
						low[p[at]] = low[at];
					if (low[at] == pre[at])
						makeScc(at);
				} else {
					int next = g[at].get(c[at]++);
					if (pre[next] < 0)
						addToStack(next, at);
					else if (onStk[next] && low[next] < low[at])
						low[at] = low[next];
				}
			}
		}
	}

	public static class FS {
		BufferedReader br;
		StringTokenizer st;

		FS(InputStream in) throws Exception {
			br = new BufferedReader(new InputStreamReader(in));
			st = new StringTokenizer(br.readLine());
		}

		FS(File in) throws Exception {
			br = new BufferedReader(new FileReader(in));
			st = new StringTokenizer(br.readLine());
		}

		String next() throws Exception {
			if (st.hasMoreTokens())
				return st.nextToken();
			st = new StringTokenizer(br.readLine());
			return next();
		}

		int nextInt() throws Exception {
			return Integer.parseInt(next());
		}
	}
}
