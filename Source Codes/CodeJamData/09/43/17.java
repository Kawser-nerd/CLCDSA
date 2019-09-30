import java.io.*;
import java.util.*;

public class B implements Runnable {

	public static void main(String[] args) {
		new Thread(new B()).start();
	}

	BufferedReader br;

	StringTokenizer st;

	PrintWriter out;

	public final String FN = "C-large";

	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FN + ".in"));
			out = new PrintWriter(FN + ".out");
			int T = nextInt();
			for (int i = 0; i < T; i++) {
				solve(i + 1);
			}
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
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

	class Stock implements Comparable<Stock> {
		int[] a;

		Stock(int[] a) {
			this.a = a;
		}

		@Override
		public int compareTo(Stock s) {
			int res = 0;
			for (int i = 0; i < a.length; i++) {
				if (a[i] < s.a[i])
					res--;
				if (a[i] > s.a[i])
					res++;
			}
			if (res == -a.length)
				return -1;
			if (res == a.length)
				return 1;
			return 0;
		}
	}

	int n, k;
	ArrayList<Integer> e[];

	private void solve(int T) throws IOException {
		n = nextInt();
		k = nextInt();
		Stock[] x = new Stock[n];
		for (int i = 0; i < n; i++) {
			int[] a = new int[k];
			for (int j = 0; j < a.length; j++) {
				a[j] = nextInt();
			}
			x[i] = new Stock(a);
		}
		e = new ArrayList[n];
		for (int i = 0; i < e.length; i++) {
			e[i] = new ArrayList<Integer>();
			for (int j = 0; j < e.length; j++) {
				if (x[i].compareTo(x[j]) > 0) {
					e[i].add(j);
				}
			}
		}

		int ans = get();
		out.println("Case #"+T+": "+ans);

	}

	int[][] g;
	int[] mt;
	boolean[] used;

	private int get() {
		int cnt = 0;
		mt = new int[n];
		used = new boolean[n];
		g = new int[n][];
		for (int i = 0; i < g.length; i++) {
			g[i] = new int[e[i].size()];
			for (int j = 0; j < g[i].length; j++) {
				g[i][j] = e[i].get(j);
			}
		}
		Arrays.fill(mt, -1);
		for (int i = 0; i < n; i++) {
			Arrays.fill(used, false);
			kuhn(i);
		}

		for (int i = 0; i < n; ++i)
			if (mt[i] != -1) {
				cnt++;
			}

		return n - cnt;
	}

	boolean kuhn(int v) {
		if (used[v])
			return false;
		used[v] = true;
		for (int i = 0; i < g[v].length; i++) {
			int to = g[v][i];
			if (mt[to] == -1 || kuhn(mt[to])) {
				mt[to] = v;
				return true;
			}
		}
		return false;
	}
}