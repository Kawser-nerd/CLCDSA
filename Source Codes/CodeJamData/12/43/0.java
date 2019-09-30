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

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		int best[] = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			best[i] = nextInt() - 1;
		}
		List<Integer> stack = new ArrayList<Integer>();
		List<Integer> order = new ArrayList<Integer>();
		stack.add(n - 1);
		i: for (int i = n - 2; i >= 0; i--) {
			for (int j = stack.size() - 1; j >= 0; j--) {
				if (stack.get(j) == best[i]) {
					stack.add(i);
					continue i;
				}
				order.add(stack.get(j));
				stack.remove(j);
			}
			printCase();
			out.println("Impossible");
			return;
		}
		for (int i = stack.size() - 1; i > 0; i--) {
			order.add(stack.get(i));
		}
		if (order.size() != n - 1) {
			throw new AssertionError();
		}
		int ans[] = new int[n];
		for (int i = n - 2; i >= 0; i--) {
			int cur = order.get(i);
			int angle = -i;
			ans[cur] = ans[best[cur]] - angle * (best[cur] - cur);
		}
		printCase();
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i]);
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