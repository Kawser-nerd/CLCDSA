import java.io.*;
import java.util.*;

public class SolutionB implements Runnable {

	public static void main(String[] args) {
		new Thread(new SolutionB()).run();
	}

	public void run() {
		try {
			Locale.setDefault(Locale.US);
			br = new BufferedReader(new FileReader(FILENAME + ".in"));
			out = new PrintWriter(FILENAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	BufferedReader br;

	PrintWriter out;

	StringTokenizer st;

	boolean eof;

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

	private static final String FILENAME = "B-large";
	
	class Pair {
		public Pair(int x, int y) {
			a = x;
			b = y;
		}

		int a, b;
	}

	public void solve() throws IOException {
		int testsn = nextInt();
		for (int test = 0; test < testsn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			int[] type = new int[n];
			int m = nextInt();
			Pair[][] a = new Pair[m][];
			int[] o = new int[m];
			for (int i = 0; i < m; i++) {
				int t = nextInt();
				a[i] = new Pair[t];
				for (int j = 0; j < t; j++) {
					a[i][j] = new Pair(nextInt() - 1, nextInt());
					if (a[i][j].b == 1) {
						o[i] = a[i][j].a;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					boolean good = false;
					for (int k = 0; k < a[j].length; k++) {
						if (a[j][k].b == type[a[j][k].a]) {
							good = true;
							break;
						}
					}
					if (!good) {
						type[o[j]] = 1;
						break;
					}
				}
			}
			boolean good = false;
			for (int j = 0; j < m; j++) {
				good = false;
				for (int k = 0; k < a[j].length; k++) {
					if (a[j][k].b == type[a[j][k].a]) {
						good = true;
						break;
					}
				}
				if (!good) {
					out.println("IMPOSSIBLE");
					break;
				}
			}
			if (good) {
				for (int i = 0; i < n; i++) {
					out.print(type[i] + " ");
				}
				out.println();
			}
		}
	}
}
