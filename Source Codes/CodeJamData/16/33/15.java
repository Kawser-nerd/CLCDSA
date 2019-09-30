import java.io.*;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	final int M = 3;

	ArrayList<int[]> solve(int a, int b, int c, int K) {
		ArrayList<int[]> res = solve123(a, b, c, K);
		int[] cnt = new int[] { a, b, c };
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				int[][] f = new int[cnt[i]][cnt[j]];
				for (int[] t : res) {
					f[t[i] - 1][t[j] - 1]++;
				}
				for (int[] k : f) {
					for (int l : k) {
						if (l > K) {
							throw new AssertionError();
						}
					}
				}
			}
		}
		boolean[][][] was = new boolean[a][b][c];
		for (int[] t : res) {
			if (was[t[0] - 1][t[1] - 1][t[2] - 1]) {
				throw new AssertionError();
			}
			was[t[0] - 1][t[1] - 1][t[2] - 1] = true;
		}
		return res;
	}

	ArrayList<int[]> solve123(int a, int b, int c, int K) {
		System.err.println("sol " + a + " " + b + " " + c + " " + K);
		ArrayList<int[]> res = new ArrayList<>();
		if (K >= c) {
			for (int i = 1; i <= a; i++) {
				for (int j = 1; j <= b; j++) {
					for (int k = 1; k <= c; k++) {
						res.add(new int[] { i, j, k });
					}
				}
			}
			return res;
		}
		int[][] used13 = new int[a][c];
		int[][] used23 = new int[b][c];
		int[][] result = new int[a * b * K][3];
		Random rnd = new Random(13);
		if (a == 1 && b == 2 && c == 3 && K == 1) {
			System.err.println("???");
		}
		while (true) {
			int it = 0;
			for (int[] i : used13) {
				Arrays.fill(i, 0);
			}
			for (int[] i : used23) {
				Arrays.fill(i, 0);
			}
			boolean[][][] was = new boolean[a][b][c];
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					for (int k = 0; k < K; k++) {
						result[it][0] = i;
						result[it][1] = j;
						result[it][2] = rnd.nextInt(c);
						if (was[i][j][result[it][2]]) {
							k--;
							continue;
						}
						was[i][j][result[it][2]] = true;
						used13[result[it][0]][result[it][2]]++;
						used23[result[it][1]][result[it][2]]++;
						it++;
					}
				}
			}
			boolean ok = true;
			for (int i = 0; i < a; i++) {
				if (!ok) {
					break;
				}
				for (int j = 0; j < c; j++) {
					if (used13[i][j] > K) {
						ok = false;
						break;
					}
				}
			}
			for (int i = 0; i < b; i++) {
				if (!ok) {
					break;
				}
				for (int j = 0; j < c; j++) {
					if (used23[i][j] > K) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				break;
			}
		}
		for (int i = 0; i < result.length; i++) {
			for (int j = 0; j < 3; j++) {
				result[i][j]++;
			}
			res.add(result[i]);
		}
		return res;
	}

	void solve123() {
		for (int a = 1; a <= M; a++) {
			for (int b = a; b <= M; b++) {
				for (int c = b; c <= M; c++) {
					for (int K = 1; K <= 10; K++) {
						solve(a, b, c, K);
					}
				}
			}
		}
	}

	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ": ");
			int j = in.nextInt();
			int p = in.nextInt();
			int s = in.nextInt();
			int k = in.nextInt();
			ArrayList<int[]> result = solve(j, p, s, k);
			out.println(result.size());
			for (int[] a : result) {
				out.println(a[0] + " " + a[1] + " " + a[2]);
			}
			System.err.println((t + 1) + "/" + tc + " done");
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("C.in"));
			out = new PrintWriter(new File("C.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}