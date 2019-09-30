import java.io.*;
import java.util.*;
import java.math.*;

public class TemplateGcj {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	static Random rnd;

	static Thread[] threads;
	static String[] results;

	class Road {
		int u, v, l, r;

		public Road(int u, int v, int l, int r) {
			this.u = u;
			this.v = v;
			this.l = l;
			this.r = r;
		}

	}

	class Solver implements Runnable {
		int testId, n, m, p;
		Road[] roads;
		int[] path;

		public Solver(int testId, int n, int m, int p, Road[] roads, int[] path) {
			this.testId = testId;
			this.n = n;
			this.m = m;
			this.p = p;
			this.roads = roads;
			this.path = path;
		}

		public String solve() {
			int ans = -1;

			for (int remove = 0; remove < p && ans == -1; remove++)
				if (checkRemove(remove))
					ans = remove;

			return (ans == -1 ? "Looks Good To Me" : (Long.toString(path[ans] + 1)));
		}

		private boolean checkRemove(int remove) {
			int total = (1 << m);
			boolean found = false;

			final int inf = Integer.MAX_VALUE / 2;
			int[] roadValue = new int[m];
			int[][] g = new int[n][n];

			int startCity = roads[path[0]].u;
			int endCity = roads[path[p - 1]].v;
			int prefixCity = roads[path[remove]].v;
			
			//out.println("Remove: " + remove);

			for (int mask = 0; mask < total && !found; mask++) {
				for (int i = 0; i < m; i++)
					roadValue[i] = (checkBit(mask, i) ? roads[i].r : roads[i].l);

				for (int i = 0; i < n; i++) {
					Arrays.fill(g[i], inf);
					g[i][i] = 0;
				}

				for (int i = 0; i < m; i++)
					g[roads[i].u][roads[i].v] = Math.min(g[roads[i].u][roads[i].v], roadValue[i]);

				for (int k = 0; k < n; k++)
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++)
							g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j]);

				int prefixPath = 0;

				for (int i = 0; i <= remove; i++)
					prefixPath += roadValue[path[i]];

				int optimalPath = g[startCity][endCity];
				int curPath = prefixPath + g[prefixCity][endCity];

				if (curPath <= optimalPath)
					found = true;
			}

			return !found;
		}

		private boolean checkBit(int mask, int i) {
			return (mask & (1 << i)) != 0;
		}

		public void run() {
			results[testId] = "Case #" + (testId + 1) + ": " + solve();
		}
	}

	void solve() throws IOException, InterruptedException {
		int tests = nextInt();

		threads = new Thread[tests];
		results = new String[tests];

		for (int testId = 0; testId < tests; testId++) {
			int n = nextInt(), m = nextInt(), p = nextInt();

			Road[] roads = new Road[m];

			for (int i = 0; i < m; i++)
				roads[i] = new Road(nextInt() - 1, nextInt() - 1, nextInt(),
						nextInt());

			int[] path = new int[p];

			for (int i = 0; i < p; i++)
				path[i] = nextInt() - 1;

			threads[testId] = new Thread(null, new Solver(testId, n, m, p,
					roads, path), "yarrr", 1 << 24);
		}

		for (Thread t : threads)
			t.start();

		for (Thread t : threads)
			t.join();

		for (String s : results)
			out.println(s);
	}

	public static void main(String[] args) {
		new TemplateGcj().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		} catch (InterruptedException e) {
			e.printStackTrace();
			System.exit(2);
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
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