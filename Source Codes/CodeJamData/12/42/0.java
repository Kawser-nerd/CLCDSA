import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Segment {
		final int x1, y1, x2, y2;
		boolean openLeft, openRight, openTop, openBottom;
		
		private Segment(int x1, int y1, int x2, int y2) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int w = nextInt();
		int h = nextInt();
		final int r[] = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		Integer idx[] = new Integer[n];
		for (int i = 0; i < n; i++) {
			idx[i] = i;
		}
		sort(idx, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return r[o2] - r[o1];
			}
		});
		int x[] = new int[n];
		int y[] = new int[n];
		List<Segment> segments = new ArrayList<Segment>();;
		Segment all = new Segment(0, 0, w, h);
		all.openLeft = true;
		all.openRight = true;
		all.openTop = true;
		all.openBottom = true;
		segments.add(all);
		i: for (int i: idx) {
			int cr = r[i];
			for (int j = segments.size() - 1; j >= 0; j--) {
				Segment cs = segments.get(j);
				int width = cs.x2 - cs.x1;
				if (cs.openLeft) {
					width += cr;
				}
				if (cs.openRight) {
					width += cr;
				}
				if (width < 2 * cr) {
					continue;
				}
				int height = cs.y2 - cs.y1;
				if (cs.openTop) {
					height += cr;
				}
				if (cs.openBottom) {
					height += cr;
				}
				if (height < 2 * cr) {
					continue;
				}
				int cutX = cs.x1 + cr;
				x[i] = cs.x1;
				if (!cs.openLeft) {
					cutX += cr;
					x[i] += cr;
				}
				int cutY = cs.y1 + cr;
				y[i] = cs.y1;
				if (!cs.openTop) {
					cutY += cr;
					y[i] += cr;
				}
				segments.remove(j);
				if (cutX < cs.x2) {
					Segment newS = new Segment(cutX, cs.y1, cs.x2, cutY);
					if (cs.openTop) {
						newS.openTop = true;
					}
					if (cs.openRight) {
						newS.openRight = true;
					}
					segments.add(j, newS);
				}
				if (cutY < cs.y2) {
					Segment newS = new Segment(cs.x1, cutY, cs.x2, cs.y2);
					if (cs.openLeft) {
						newS.openLeft = true;
					}
					if (cs.openBottom) {
						newS.openBottom = true;
					}
					if (cs.openRight) {
						newS.openRight = true;
					}
					segments.add(j, newS);
				}
				continue i;
			}
			throw new AssertionError();
		}
		for (int i = 0; i < n; i++) {
			if (x[i] < 0 || x[i] > w || y[i] < 0 || y[i] > h) {
				throw new AssertionError();
			}
			for (int j = i + 1; j < n; j++) {
				long dx = x[i] - x[j];
				long dy = y[i] - y[j];
				long d = r[i] + r[j];
				if (dx * dx + dy * dy < d * d) {
					throw new AssertionError();
				}
			}
		}
		printCase();
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(x[i] + " " + y[i]);
		}
		out.println();
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}