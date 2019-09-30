import java.io.*;
import java.util.*;

public class D {
	private static String fileName = D.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	int n;
	boolean[][] e;
	int[][] next;
	int[][] nei;
	int[] rank;
	int[][] t;
	int ans;

	private void solve() {
		n = in.nextInt();
		int m = in.nextInt();
		e = new boolean[n][n];
		rank = new int[n];
		for (int i = 0; i < m; i++) {
			String[] s = in.next().split(",");
			int a = Integer.parseInt(s[0]);
			int b = Integer.parseInt(s[1]);
			e[a][b] = e[b][a] = true;
		}
		for (int a = 0; a < n; a++) {
			e[a][a] = true;
		}
		int[] queue = new int[n];
		Arrays.fill(rank, n);
		rank[0] = 0;
		queue[0] = 0;
		for (int low = 0, high = 1; low < high;) {
			int a = queue[low++];
			for (int b = 0; b < n; b++) {
				if (e[a][b] && rank[b] == n) {
					rank[b] = rank[a] + 1;
					queue[high++] = b;
				}
			}
		}
		out.print(rank[1] - 1 + " ");
		next = new int[n][];
		nei = new int[n][];
		for (int a = 0; a < n; a++) {
			m = 0;
			for (int b = 0; b < n; b++) {
				if (e[a][b] && rank[b] == rank[a] + 1) {
					m++;
				}
			}
			next[a] = new int[m];
			m = 0;
			for (int b = 0; b < n; b++) {
				if (e[a][b] && rank[b] == rank[a] + 1) {
					next[a][m++] = b;
				}
			}
			m = 0;
			for (int b = 0; b < n; b++) {
				if (e[a][b]) {
					m++;
				}
			}
			nei[a] = new int[m];
			m = 0;
			for (int b = 0; b < n; b++) {
				if (e[a][b]) {
					nei[a][m++] = b;
				}
			}
		}
		t = new int[n][n];
		ans = 0;
		step(-1, 0, nei[0].length);
		for (int r = 0; r < rank[1]; r++) {
			for (int a = 0; a < n; a++) {
				if (rank[a] != r) {
					continue;
				}
				for (int b = 0; b < n; b++) {
					if (rank[b] != r + 1) {
						continue;
					}
					step(a, b, t[a][b]);
				}
			}
		}
		ans -= rank[1];
		out.println(ans);
	}

	private void step(int a, int b, int threaten) {
		for (int c : next[b]) {
			int news = 0;
			for (int d : nei[c]) {
				if (!e[b][d] && (a < 0 || !e[a][d])) {
					news++;
				}
			}
			t[b][c] = Math.max(t[b][c], threaten + news);
			if (c == 1) {
				ans = Math.max(ans, threaten);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new D().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
