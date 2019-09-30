import java.util.*;
import java.math.*;
import java.io.*;

public class c {
	
	static final long MOD = 1000003;
	static final String DIR = "|-/\\";
	static final int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
	static final int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
	
	int n, m;
	char[][] s;
	int[][] dirInd;
	ArrayList<Integer>[] graph, iGraph;
	boolean[] used, usedIn, usedOut;

	private void solve() throws Exception {
		n = nextInt();
		m = nextInt();
		s = new char[n][];
		for (int i = 0; i < n; ++i) {
			s[i] = nextToken().toCharArray();
		}
		int total = n * m;
		graph = new ArrayList[total];
		iGraph = new ArrayList[total];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				graph[toI(i, j)] = new ArrayList<Integer>();
				iGraph[toI(i, j)] = new ArrayList<Integer>();
			}
		}
		dirInd = new int[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				dirInd[i][j] = DIR.indexOf("" + s[i][j]);
				for (int it = 0; it < 2; ++it) {
					int dir = dirInd[i][j] * 2 + it;
					int nx = i + dx[dir], ny = j + dy[dir];
					nx = ((nx % n) + n) % n;
					ny = ((ny % m) + m) % m;
					graph[toI(i, j)].add(toI(nx, ny));
					iGraph[toI(nx, ny)].add(toI(i, j));
				}
			}
		}
		
		usedIn = new boolean[total];
		usedOut = new boolean[total];
		while (true) {
			boolean ch = false;
			for (int i = 0; i < total; ++i) {
				if (!usedIn[i] && iGraph[i].size() == 1) {
					ch = true;
					usedIn[i] = true;
					int o = iGraph[i].get(0);
					
					//out.println(o + " " + i);
					
					if (usedOut[o]) {
						out.println(0);
						return;
					}
					usedOut[o] = true;
					for (int p : graph[o]) {
						iGraph[p].remove(iGraph[p].indexOf(o));
					}
				}
			}
			
			if (!ch)
				break;
		}
		
		//out.println();
		for (int i = 0; i < total; ++i) {
			//out.println(iGraph[i].size());
			if (!usedIn[i] && iGraph[i].size() /*== 0*/ != 2) {
				out.println(0);
				return;
			}
			graph[i].clear();
		}
		//out.println();
		
		for (int i = 0; i < n * m; ++i) {
			if (usedIn[i])
				continue;
			int a = iGraph[i].get(0), b = iGraph[i].get(1);
			graph[a].add(b);
			graph[b].add(a);
		}
		
		int cnt = 0;
		used = new boolean[total];
		for (int i = 0; i < total; ++i) {
			if (graph[i].size() > 0 && !used[i]) {
				int len = dfs(i);
				//out.println(len);
				++cnt;
			}
		}
		
		long ways = 1;
		for (int i = 0; i < cnt; ++i) {
			ways *= 2;
			ways %= MOD;
		}
		out.println(ways);
		
		/*int total = n * m;
		int ways = 0;
		for (int mask = 0; mask < (1 << total); ++mask) {
			int[][] inp = new int[n][m];
			boolean good = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					int cur = i * m + j;
					int dir = dirInd[i][j] * 2;
					if ((mask & (1 << cur)) > 0)
						++dir;
					int nx = i + dx[dir], ny = j + dy[dir];
					nx = ((nx % n) + n) % n;
					ny = ((ny % m) + m) % m;
					++inp[nx][ny];
					if (inp[nx][ny] > 1)
						good = false;
				}
			}
			if (good) {
				++ways;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j) {
						int cur = i * m + j;
						int dir = dirInd[i][j] * 2;
						if ((mask & (1 << cur)) > 0)
							++dir;
						int nx = i + dx[dir], ny = j + dy[dir];
						nx = ((nx % n) + n) % n;
						ny = ((ny % m) + m) % m;
						out.println(i + " " + j + " " + nx + " " + ny);
					}
				}
			}
		}
		out.println(ways % MOD);*/
	}
	
	private int dfs(int v) {
		used[v] = true;
		for (int next : graph[v]) {
			if (!used[next]) {
				return dfs(next) + 1;
			}
		}
		return 1;
	}

	int toI(int x, int y) {
		return x * m + y;
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
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

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private c(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	private c() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			St = new StringTokenizer("");
			out = new PrintWriter(System.out);
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new c("c").run();
	}
}
