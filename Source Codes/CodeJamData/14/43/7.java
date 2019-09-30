import java.io.*;
import java.util.*;

public class BreakTheNile {

	FastScanner in;
	PrintWriter out;

	class Rect {
		int x0, y0, x1, y1;
		int[][] corners;

		public Rect(int x0, int y0, int x1, int y1) {
			super();
			this.x0 = x0;
			this.y0 = y0;
			this.x1 = x1;
			this.y1 = y1;
			this.corners = new int[][] { new int[] { x0, y0 }, new int[] { x0, y1 },
					new int[] { x1, y0 }, new int[] { x1, y1 } };
		}

		int[][] corners() {
			return corners;
		}
	}

	void solve() {
		int w = in.nextInt(), h = in.nextInt(), b = in.nextInt();
		b += 2;

		Rect[] a = new Rect[b];

		a[0] = new Rect(-1, 0, -1, h - 1);
		a[1] = new Rect(w, 0, w, h - 1);

		for (int i = 2; i < b; i++) {
			a[i] = new Rect(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt());
		}

		int[][] d = new int[b][b];

		for (int i = 0; i < b; i++) {
			for (int j = i + 1; j < b; j++) {
				d[i][j] = d[j][i] = getDist(a[i], a[j]) - 1;
			}
		}

		int[] dist = new int[b];
		Arrays.fill(dist, Integer.MAX_VALUE / 2);
		dist[0] = 0;

		boolean[] used = new boolean[b];

		for (int I = 0; I < b; I++) {
			int min = -1;
			for (int i = 0; i < b; i++) {
				if (!used[i] && (min == -1 || dist[i] < dist[min])) {
					min = i;
				}
			}

			used[min] = true;
			for (int i = 0; i < b; i++) {
				dist[i] = Math.min(dist[i], dist[min] + d[i][min]);
			}
		}

		out.println(dist[1]);
	}

	private int getDist(Rect a, Rect b) {
		int min = Integer.MAX_VALUE;
		for (int[] c1 : a.corners()) {
			min = Math.min(min, getDist(c1, b));
		}
		for (int[] c2 : b.corners()) {
			min = Math.min(min, getDist(c2, a));
		}
		return min;
	}

	private int getDist(int[] c, Rect a) {
		int min = Integer.MAX_VALUE;
		for (int[] d : a.corners()) {
			min = Math.min(min, dist(c, d));
		}
		
		if (a.x0 <= c[0] && c[0] <= a.x1){ 
			min = Math.min(min, Math.abs(c[1] - a.y0));
			min = Math.min(min, Math.abs(c[1] - a.y1));
		}
		
		if (a.y0 <= c[1] && c[1] <= a.y1){ 
			min = Math.min(min, Math.abs(c[0] - a.x0));
			min = Math.min(min, Math.abs(c[0] - a.x1));
		}
		
		return min;
	}

	int dist(int[] a, int[] b) {
		return Math.max(Math.abs(a[0] - b[0]), Math.abs(a[1] - b[1]));
	}

	void run() {
		try {
			in = new FastScanner("input.txt");
			out = new PrintWriter("output.txt");
			int T = in.nextInt();
			for (int i = 1; i <= T; i++) {
				long time = System.currentTimeMillis();
				out.printf("Case #%d: ", i);
				solve();
				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
						+ " ms");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
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
	}

	public static void main(String[] args) {
		new BreakTheNile().run();
	}
}
