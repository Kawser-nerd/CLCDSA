import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int t = nextInt();
		for (int currentTest = 0; currentTest < t; currentTest++) {
			int w = nextInt();
			int h = nextInt();
			int n = nextInt() + 2;
			Rectangle[] a = new Rectangle[n];
			a[0] = new Rectangle(-1, 0, -1, h - 1);
			a[1] = new Rectangle(w, 0, w, h - 1);
			for (int i = 2; i < n; i++) {
				a[i] = new Rectangle(nextInt(), nextInt(), nextInt(), nextInt());
			}
			out.println("Case #" + (currentTest + 1) + ": " + solve(a));
		}
	}

	static long solve(Rectangle[] a) {
		int n = a.length;
		long[] d = new long[n];
		boolean[] was = new boolean[n];
		Arrays.fill(d, Long.MAX_VALUE);
		d[0] = 0;
		while (true) {
			int min = -1;
			for (int i = 0; i < n; i++) {
				if (was[i] || d[i] == Long.MAX_VALUE) {
					continue;
				}
				if (min < 0 || d[min] > d[i]) {
					min = i;
				}
			}
			if (min < 0) {
				break;
			}
			was[min] = true;
			for (int i = 0; i < n; i++) {
				if (min == i)
					continue;
				int w = getWeight(a[min], a[i]);
				if (d[i] > d[min] + w) {
					d[i] = d[min] + w;
				}
			}
		}
		return d[1];
	}

	static int getWeight(Rectangle a, Rectangle b) {
		return Math.max(
				b.x1 - a.x2 - 1,
				Math.max(a.x1 - b.x2 - 1,
						Math.max(a.y1 - b.y2 - 1, b.y1 - a.y2 - 1)));
	}

	static class Rectangle {
		int x1;
		int y1;
		int x2;
		int y2;

		public Rectangle(int x1, int y1, int x2, int y2) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}

	}

	public static void main(String[] args) throws Exception {
		File file = new File("c.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("c.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
