import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		int zip[] = new int[n];
		for (int i = 0; i < n; i++) {
			zip[i] = nextInt();
		}
		List<Integer> edges[] = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			edges[a].add(b);
			edges[b].add(a);
		}
		printCase();
		List<Integer> stack = new ArrayList<>();
		boolean seen[] = new boolean[n];
		int first = 0;
		for (int i = 0; i < n; i++) {
			if (zip[i] < zip[first]) {
				first = i;
			}
		}
		out.printf("%05d", zip[first]);
		seen[first] = true;
		stack.add(first);
		Queue<Integer> q = new ArrayDeque<>();
		boolean seen2[] = new boolean[n];
		for (int ii = 1; ii < n; ii++) {
			int minStackSize = 0;
			arraycopy(seen, 0, seen2, 0, n);
			int rem = n - ii;
			while (rem > 0) {
				q.add(stack.get(minStackSize));
				do {
					int cur = q.remove();
					for (int i: edges[cur]) {
						if (seen2[i]) {
							continue;
						}
						seen2[i] = true;
						--rem;
						q.add(i);
					}
				} while (!q.isEmpty());
				++minStackSize;
			}
			int next = -1;
			int nextStackSize = -1;
			for (int stackSize = stack.size(); stackSize >= minStackSize; stackSize--) {
				int cur = stack.get(stackSize - 1);
				for (int i: edges[cur]) {
					if (!seen[i] && (next < 0 || zip[next] > zip[i])) {
						next = i;
						nextStackSize = stackSize;
					}
				}
			}
			stack.subList(nextStackSize, stack.size()).clear();
			out.printf("%05d", zip[next]);
			seen[next] = true;
			stack.add(next);
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