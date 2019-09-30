import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;
import java.util.StringTokenizer;

public class C {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static class Entry {
		final long length;
		long count;

		Entry(long length, long count) {
			this.length = length;
			this.count = count;
		}
	}

	static void solve() throws Exception {
		long n = nextLong();
		long k = nextLong();
		Deque<Entry> q = new ArrayDeque<>();
		q.add(new Entry(n, 1));
		while (true) {
			Entry e = q.removeFirst();
			if (e.count < k) {
				k -= e.count;
				if (e.length % 2 == 0) {
					if (!q.isEmpty() && q.getLast().length == e.length / 2) {
						q.getLast().count += e.count;
					} else {
						q.addLast(new Entry(e.length / 2, e.count));
					}
					q.addLast(new Entry(e.length / 2 - 1, e.count));
				} else {
					if (!q.isEmpty() && q.getLast().length == e.length / 2) {
						q.getLast().count += 2 * e.count;
					} else {
						q.addLast(new Entry(e.length / 2, 2 * e.count));
					}
				}
			} else {
				printCase();
				out.println((e.length / 2) + " " + ((e.length - 1) / 2));
				break;
			}
		}
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