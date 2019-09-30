import java.util.*;
import java.io.*;
import java.math.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	class Zip implements Comparable<Zip> {
		
		String zip;
		int index;
		
		public Zip(String zip, int index) {
			this.zip = zip;
			this.index = index;
		}
		
		@Override
		public int compareTo(Zip arg0) {
			return zip.compareTo(arg0.zip);
		}
		
	}
	
	int n, m;
	boolean mark[];
	boolean used[];
	boolean hold[];
	boolean can[][];
	int perm[];
	int map[];
	int g[][];
	
	int distance;
	int reach;
	Zip zip[];
	
	int bestResult;
	int[] bestPerm;
	
	void dfs(int v) {
		if (mark[v])
			return;
		mark[v] = true;
		for (int i = 0; i < n; i++)
			if (can[v][i])
				dfs(i);
	}
	
	boolean check(int wayLength, int[] way) {
		Arrays.fill(mark, false);
		for (int i = 0; i < n; i++) {
			if (hold[i])
				mark[i] = true;
		}
		for (int i = 0; i < wayLength; i++)
			dfs(way[i]);
		for (int i = 0; i < n; i++)
			if (!mark[i])
				return false;
		return true;
	}
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		outer:
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			n = sc.nextInt();
			m = sc.nextInt();
			zip = new Zip[n];
			for (int i = 0; i < n; i++) {
				zip[i] = new Zip(sc.nextToken(), i);
			}
			Arrays.sort(zip);
			map = new int [n];
			for (int i = 0; i < n; i++) {
				map[zip[i].index] = i;
			}
			can = new boolean [n][n];
			for (int i = 0; i < m; i++) {
				int v1 = map[sc.nextInt() - 1];
				int v2 = map[sc.nextInt() - 1];
				can[v1][v2] = true;
				can[v2][v1] = true;
			}
			reach = 0;
			perm = new int [n];
			used = new boolean [n];
			hold = new boolean [n];
			mark = new boolean [n];
			perm[0] = 0;
			used[0] = true;
			int way[] = new int[n];
			int wayLength = 1;
			for (int i = 1; i < n; i++) {
				outerCandidate:
				for (int candidate = 0; candidate < n; candidate++) {
					if (used[candidate]) continue;
					for (int j = wayLength - 1; j >= 0; j--) {
						if (can[way[j]][candidate] && check(wayLength, way)) {
							used[candidate] = true;
							wayLength = j + 2;
							way[wayLength - 1] = candidate;
							perm[i] = candidate;
							break outerCandidate;
						}
						hold[way[j]] = true;
					}
					for (int j = 0; j < wayLength; j++)
						hold[way[j]] = false;
				}
			}
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < n; i++) {
				sb.append(zip[perm[i]].zip);
			}
			out.println(sb.toString());
		}
	}


	static Throwable t;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.t = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", 1 << 26);
		thread.start();
		thread.join();
		if (Solution.t != null)
			throw t;
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}