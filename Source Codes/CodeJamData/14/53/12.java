import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int numTests = nextInt();
		for (int test = 1; test <= numTests; test++) {
			n = nextInt();
			enter = new boolean[n];
			id = new int[n];
			for (int i = 0; i < n; i++) {
				enter[i] = next().equals("E");
				id[i] = nextInt() - 1;
			}
			out.print("Case #" + test + ": ");
			int ans = solve();
			if (ans < 0) {
				out.println("CRIME TIME");
			} else {
				out.println(ans);
			}
		}
	}
	
	int n;
	boolean[] enter;
	int[] id;
	final int N = 2000;

	private int solve() {
		int[] col = new int[N];
		Arrays.fill(col, -1);
		int k = 0;
		for (int x : id) {
			if (x >= 0 && col[x] < 0) {
				col[x] = k++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (id[i] >= 0) {
				id[i] = col[id[i]];
			}
		}
		boolean[][] possible = new boolean[n + 1][1 << k];
		for (int mask = 0; mask < 1<<k; mask++) {
			for (int inside = Integer.bitCount(mask); inside <= n; inside++) {
				possible[inside][mask] = true;
			}
		}
		for (int step = 0; step < n; step++) {
			boolean[][] npossible = new boolean[n + 1][1 << k];
			for (int mask = 0; mask < 1<<k; mask++) {
				for (int inside = Integer.bitCount(mask); inside <= n; inside++) {
					if (!possible[inside][mask]) {
						continue;
					}
					if (id[step] < 0) {
						if (enter[step] && inside < n) {
							npossible[inside + 1][mask] = true;
						}
						if (!enter[step] && inside > 0) {
							npossible[inside - 1][mask] = true;
						}
					}
					for (int who = 0; who < k; who++) {
						if (id[step] >= 0 && id[step] != who) {
							continue;
						}
						if (enter[step]) {
							if ((mask & (1 << who)) == 0 && inside < n) {
								npossible[inside +  1][mask ^ (1 << who)] = true;
							}
						} else {
							if ((mask & (1 << who)) > 0) {
								npossible[inside - 1][mask ^ (1 << who)] = true;
							}
						}
					}
				}
			}
			possible = npossible;
		}
		int ans = 1000;
		for (int mask = 0; mask < 1<<k; mask++) {
			for (int inside = Integer.bitCount(mask); inside <= n; inside++) {
				if (possible[inside][mask]) {
					ans = Math.min(ans, inside);
				}
			}
		}
		if (ans >= 1000) {
			ans = -1;
		}
		return ans;
	}

	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("C-small-attempt0.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
