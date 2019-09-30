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
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class c {

	public static int[] dx = { 0, -1, 1, 0 };
	public static int[] dy = { 1, 0, 0, -1 };

	public static void main(String[] Args) throws Exception {
		// FS sc = new FS(new File("C-large.in"));
		 FS sc = new FS(new File("C-small-attempt0.in"));
		 PrintWriter out = new PrintWriter(new BufferedWriter(new
		 FileWriter(new File("c.out"))));
		// FS sc = new FS(System.in);
		// PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int cc = 0;
		int t = sc.nextInt();
		while (t-- > 0) {
			out.printf("Case #%d: ", ++cc);

			int n = sc.nextInt();
			int m = sc.nextInt();

			int[][] xr = new int[n][m];
			boolean[][] blocked = new boolean[n][m];
			int[][] source = new int[n][m];
			int sCount = 0;
			for (int i = 0; i < n; i++) {
				String s = sc.next();
				for (int j = 0; j < m; j++) {
					if (s.charAt(j) == '#')
						blocked[i][j] = true;
					else if (s.charAt(j) == '-' || s.charAt(j) == '|')
						source[i][j] = (++sCount);
					else if (s.charAt(j) == '\\')
						xr[i][j] = 2;
					else if (s.charAt(j) == '/')
						xr[i][j] = 1;
				}
			}
			boolean[][] isValid = new boolean[2][sCount];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (source[i][j] != 0) {
						Queue<Integer> q = new LinkedList<Integer>();
						boolean tmp;

						// Check -
						q.add(dx[0] + i);
						q.add(dy[0] + j);
						q.add(0);
						q.add(dx[3] + i);
						q.add(dy[3] + j);
						q.add(3);
						tmp = true;
						while (!q.isEmpty()) {
							int tx = q.poll();
							int ty = q.poll();
							int r = q.poll();
							if (tx < 0 || tx >= n || ty < 0 || ty >= m)
								continue;

							if (source[tx][ty] != 0) {
								tmp = false;
								continue;
							}
							if (blocked[tx][ty])
								continue;
							r ^= xr[tx][ty];
							q.add(tx + dx[r]);
							q.add(ty + dy[r]);
							q.add(r);
						}
						isValid[0][source[i][j] - 1] = tmp;

						// Check |
						q.add(dx[1] + i);
						q.add(dy[1] + j);
						q.add(1);
						q.add(dx[2] + i);
						q.add(dy[2] + j);
						q.add(2);
						tmp = true;
						while (!q.isEmpty()) {
							int tx = q.poll();
							int ty = q.poll();
							int r = q.poll();
							if (tx < 0 || tx >= n || ty < 0 || ty >= m)
								continue;

							if (source[tx][ty] != 0) {
								tmp = false;
								continue;
							}
							if (blocked[tx][ty])
								continue;
							r ^= xr[tx][ty];
							q.add(tx + dx[r]);
							q.add(ty + dy[r]);
							q.add(r);
						}
						isValid[1][source[i][j] - 1] = tmp;
					}
				}
			}
			TreeSet<Integer>[][] canT = new TreeSet[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					canT[i][j] = new TreeSet<Integer>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (source[i][j] != 0) {
						Queue<Integer> q = new LinkedList<Integer>();

						// Check -
						if (isValid[0][source[i][j] - 1]) {
							q.add(dx[0] + i);
							q.add(dy[0] + j);
							q.add(0);
							q.add(dx[3] + i);
							q.add(dy[3] + j);
							q.add(3);
							while (!q.isEmpty()) {
								int tx = q.poll();
								int ty = q.poll();
								int r = q.poll();
								if (tx < 0 || tx >= n || ty < 0 || ty >= m)
									continue;
								canT[tx][ty].add((source[i][j] << 1));
								if (blocked[tx][ty])
									continue;
								r ^= xr[tx][ty];
								q.add(tx + dx[r]);
								q.add(ty + dy[r]);
								q.add(r);
							}
						}

						// Check |
						if (isValid[1][source[i][j] - 1]) {
							q.add(dx[1] + i);
							q.add(dy[1] + j);
							q.add(1);
							q.add(dx[2] + i);
							q.add(dy[2] + j);
							q.add(2);
							while (!q.isEmpty()) {
								int tx = q.poll();
								int ty = q.poll();
								int r = q.poll();
								if (tx < 0 || tx >= n || ty < 0 || ty >= m)
									continue;
								canT[tx][ty].add((source[i][j] << 1) | 1);
								if (blocked[tx][ty])
									continue;
								r ^= xr[tx][ty];
								q.add(tx + dx[r]);
								q.add(ty + dy[r]);
								q.add(r);
							}
						}
					}
				}
			}
			boolean tmp = true;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (!blocked[i][j] && source[i][j] == 0) {
						if (canT[i][j].size() == 0) {
							tmp = false;
						}
					}
					if (source[i][j] != 0 && !isValid[0][source[i][j] - 1] && !isValid[1][source[i][j] - 1])
						tmp = false;
				}
			ArrayList<Integer>[] al = new ArrayList[sCount * 2];
			if (tmp) {
				for (int i = 0; i < al.length; i++)
					al[i] = new ArrayList<Integer>();
				for (int i = 0; i < sCount; i++)
					if (!isValid[0][i])
						al[i * 2 ].add(i * 2+1);
					else if (!isValid[1][i])
						al[i * 2+1].add(i * 2);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (source[i][j] == 0 && !blocked[i][j]) {
							if (canT[i][j].size() == 1) {
								al[(canT[i][j].first() - 2) ^ 1].add(canT[i][j].first() - 2);
							} else {
								int ii = (canT[i][j].first() - 2);
								int jj = (canT[i][j].last() - 2);
								al[ii ^ 1].add(jj);
								al[jj ^ 1].add(ii);
							}
						}
					}
				}
				Tarjan tj = new Tarjan(al);
				for (int i = 0; i < sCount; i++) {
					if (tj.sccId[i * 2] == tj.sccId[i * 2 + 1])
						tmp = false;
				}
			}

			if (!tmp)
				out.println("IMPOSSIBLE");
			else
				out.println("POSSIBLE");
			for (int i = 0; tmp && i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (blocked[i][j])
						out.print("#");
					else if (xr[i][j] == 2)
						out.print("\\");
					else if (xr[i][j] == 1)
						out.print("/");
					else if (source[i][j] == 0)
						out.print(".");
					else {
						boolean nn = true;
						al[source[i][j] * 2 - 2].add(source[i][j] * 2 - 1);
						Tarjan tj = new Tarjan(al);
						for (int ii = 0; ii < sCount; ii++) {
							if (tj.sccId[ii * 2] == tj.sccId[ii * 2 + 1])
								nn = false;
						}
						if (!nn) {
							al[source[i][j] * 2 - 2].remove(al[source[i][j] * 2 - 2].size() - 1);
							al[source[i][j] * 2 - 1].add(source[i][j] * 2 - 2);
							out.print("-");
						} else {
							out.print("|");
						}
					}
				}
				out.println();
			}
			out.flush();
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
