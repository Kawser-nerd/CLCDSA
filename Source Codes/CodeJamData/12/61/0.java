import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Event implements Comparable<Event> {
		
		final int id, pos, time;

		public Event(int id, int pos, int time) {
			this.id = id;
			this.pos = pos;
			this.time = time;
		}
		
		public int compareTo(Event o) {
			return time - o.time;
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int x[] = new int[n];
		int y[] = new int[n];
		int t[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
			y[i] = nextInt();
			t[i] = nextInt();
		}
		int ans[][] = new int[n][1001];
		int theAns = 0;
		Event events[] = new Event[n * 1001];
		for (int id = 0; id < n; id++) {
			for (int pos = 0; pos <= 1000; pos++) {
				events[id * 1001 + pos] = new Event(id, pos, t[id] + pos);
			}
		}
		sort(events);
		for (Event e: events) {
			int id = e.id;
			int pos = e.pos;
			int time = e.time;
			int cx = x[id];
			int cy = y[id];
			int cans = 0;
			if (max(abs(cx), abs(cy)) * 100 <= time) {
				cans = 1;
			}
			if (pos > 0) {
				cans = max(cans, ans[id][pos - 1]);
			}
			for (int id2 = 0; id2 < n; id2++) {
				if (id == id2) {
					continue;
				}
				int time2 = time - max(750, 100 * max(abs(cx - x[id2]), abs(cy - y[id2])));
				if (t[id2] > time2) {
					continue;
				}
				int oans = ans[id2][min(time2 - t[id2], 1000)];
				if (oans == 0) {
					continue;
				}
				cans = max(cans, 1 + oans);
			}
			ans[id][pos] = cans;
			theAns = max(theAns, cans);
		}
		printCase();
		out.println(theAns);
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