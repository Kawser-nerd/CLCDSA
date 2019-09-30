import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static final int MIN_HEIGHT = 50;
	static final int MIN_KAYAK = 20;
	
	static final int DX[] = {1, 0, -1, 0};
	static final int DY[] = {0, 1, 0, -1};
	
	static class Event implements Comparable<Event> {
		
		final int i, j, time;

		Event(int i, int j, int time) {
			this.i = i;
			this.j = j;
			this.time = time;
		}
		
		public int compareTo(Event o) {
			return time - o.time;
		}
	}
	
	static void solve() throws Exception {
		int hInitial = nextInt();
		int h = hInitial;
		int n = nextInt();
		int m = nextInt();
		int ceil[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ceil[i][j] = nextInt();
			}
		}
		int floor[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				floor[i][j] = nextInt();
			}
		}
		int time[][] = new int[n][m];
		for (int t[]: time) {
			fill(t, Integer.MAX_VALUE);
		}
		PriorityQueue<Event> events = new PriorityQueue<>();
		time[0][0] = 0;
		events.add(new Event(0, 0, 0));
		do {
			Event e = events.remove();
			int i = e.i, j = e.j;
			int eTime = e.time;
			if (time[i][j] != eTime) {
				continue;
			}
			for (int d = 0; d < 4; d++) {
				int ni = i + DX[d];
				int nj = j + DY[d];
				if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
					continue;
				}
				if (max(floor[i][j], floor[ni][nj]) + MIN_HEIGHT > min(ceil[i][j], ceil[ni][nj])) {
					continue;
				}
				int nTime = max(0, h + MIN_HEIGHT - min(ceil[i][j], ceil[ni][nj]));
				nTime = max(eTime, nTime);
				if (nTime > 0) {
					nTime += (h - nTime - floor[i][j] >= MIN_KAYAK) ? 10 : 100;
				}
				if (time[ni][nj] <= nTime) {
					continue;
				}
				time[ni][nj] = nTime;
				events.add(new Event(ni, nj, nTime));
			}
		} while (!events.isEmpty());
		printCase();
		int ans = time[n - 1][m - 1];
		out.println(ans / 10 + "." + ans % 10);
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