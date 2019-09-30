import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "C-large";

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int n = nextInt();
		int m = nextInt();
		ArrayList<Integer>[] edges = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			edges[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; ++i) {
			edges[i].add((i + 1) % n);
			edges[(i + 1) % n].add(i);
		}
		int[] a = new int[m];
		int[] b = new int[m];
		for (int i = 0; i < m; ++i) {
			a[i] = nextInt() - 1;
		}
		for (int i = 0; i < m; ++i) {
			b[i] = nextInt() - 1;
		}
		for (int i = 0; i < m; ++i) {
			edges[a[i]].add(b[i]);
			edges[b[i]].add(a[i]);
		}
		int[][] col = new int[n][];
		for (int i = 0; i < n; ++i) {
			Collections.sort(edges[i]);
			col[i] = new int[edges[i].size()];
			Arrays.fill(col[i], -1);
		}
		ArrayList<ArrayList<Integer>> comps = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < edges[i].size(); ++j) {
				if (col[i][j] != -1) {
					continue;
				}
				ArrayList<Integer> c = new ArrayList<Integer>();
				int u = i, e = j;
				while (col[u][e] == -1) {
					c.add(u);
					col[u][e] = comps.size();
					int nu = edges[u].get(e);
					int ne = (Collections.binarySearch(edges[nu], u) + 1) % edges[nu].size();
					u = nu;
					e = ne;
				}
				comps.add(c);
			}
		}
		int minComp = 1;
		for (int i = 2; i < comps.size(); ++i) {
			if (comps.get(i).size() < comps.get(minComp).size()) {
				minComp = i;
			}
		}
		int ans = comps.get(minComp).size();
		int[] ansc = new int[n];
		Arrays.fill(ansc, -1);
		dfs(minComp, comps, ansc, ans, col, edges);
		System.err.println(ans);
		System.err.println(Arrays.toString(ansc));
		for (int i = 1; i < comps.size(); ++i) {
			boolean[] used = new boolean[ans];
			for (int j : comps.get(i)) {
				used[ansc[j]] = true;
			}
			for (boolean f : used) {
				if (!f) {
					throw new AssertionError();
				}
			}
		}
		out.println(ans);
		for (int i = 0; i < n; ++i) {
			out.print((ansc[i] + 1) + " ");
		}
		out.println();
	}

	private void dfs(int c, ArrayList<ArrayList<Integer>> comps,
			int[] ansc, int ans, int[][] col, ArrayList<Integer>[] edges) {
		if (c == 0) {
			return;
		}
		ArrayList<Integer> comp = comps.get(c);
		boolean[] used = new boolean[ans];
		int from = -1;
		int count = 0;
		for (int i = 0; i < comp.size(); ++i) {
			if (ansc[comp.get(i)] != -1) {
				used[ansc[comp.get(i)]] = true;
				count++;
				if (ansc[comp.get((i + 1) % comp.size())] != -1) {
					if (from != -1) {
						throw new AssertionError();
					}
					from = i;
				}
			}
		}
		for (int i = 0; i < comp.size(); ++i) {
			if (ansc[comp.get(i)] != -1) {
				continue;
			}
			ansc[comp.get(i)] = 0;
			while (ansc[comp.get(i)] < ans && used[ansc[comp.get(i)]]) {
				++ansc[comp.get(i)];
			}
			if (ansc[comp.get(i)] == ans) {
				ansc[comp.get(i)] = 0;
			}
			while (ansc[comp.get(i)] == ansc[comp.get((i + comp.size() - 1) % comp.size())] ||
				   ansc[comp.get(i)] == ansc[comp.get((i + 1) % comp.size())]) {
				ansc[comp.get(i)]  = (ansc[comp.get(i)] + 1) % ans;
			}
			used[ansc[comp.get(i)]] = true;
		}
		for (int i = 0; i < comp.size(); ++i) {
			if (i == from) {
				continue;
			}
			int u = comp.get(i);
			int v = comp.get((i + 1) % comp.size());
			dfs(col[v][Collections.binarySearch(edges[v], u)], comps, ansc, ans, col, edges);
		}
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
