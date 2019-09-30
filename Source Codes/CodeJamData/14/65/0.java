import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class E {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Event {
		final long days, count;

		public Event(long days, long count) {
			this.days = days;
			this.count = count;
		}
	}
	
	static void solve() throws Exception {
		long n = nextLong();
		long a = nextLong();
		long b = nextLong();
//		if (n == 1) {
//			printCase();
//			out.println(0);
//			return;
//		}
		List<Event> events = new ArrayList<>();
		events.add(new Event(0, 1));
		int pa = 0, pb = -1;
		long time = a;
		while (events.get(events.size() - 1).count < n) {
			long c1 = events.get(pa).count;
			long c2 = pb < 0 ? 1 : events.get(pb).count;
			events.add(new Event(time, c1 + c2));
			long toA = events.get(pa + 1).days + a - time;
			long toB = events.get(pb + 1).days + b - time;
			if (toA < toB) {
				++pa;
				time = events.get(pa).days + a;
			} else if (toB < toA) {
				++pb;
				time = events.get(pb).days + b;
			} else {
				++pa;
				++pb;
				time = events.get(pa).days + a;
			}
		}
		printCase();
		out.println(events.get(events.size() - 1).days);
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