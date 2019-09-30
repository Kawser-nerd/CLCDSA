import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int MOD = 1000003;
	
	static void solveTest() throws Exception {
//		System.err.println("----- NEW TEST");
		int r = nextInt();
		int c = nextInt();
		List<Integer> graph[] = (List<Integer>[]) new List<?>[r * c];
		for (int i = 0; i < r * c; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < r; i++) {
			String s = next();
			for (int j = 0; j < c; j++) {
				int p1, p2;
				switch (s.charAt(j)) {
				case '|':
					p1 = ((i + r - 1) % r) * c + j;
					p2 = ((i + 1) % r) * c + j;
					break;
				case '-':
					p1 = i * c + (j + c - 1) % c;
					p2 = i * c + (j + 1) % c;
					break;
				case '/':
					p1 = ((i + r - 1) % r) * c + (j + 1) % c;
					p2 = ((i + 1) % r) * c + (j + c - 1) % c;
					break;
				case '\\':
					p1 = ((i + r - 1) % r) * c + (j + c - 1) % c;
					p2 = ((i + 1) % r) * c + (j + 1) % c;
					break;
				default:
					throw new AssertionError();
				}
				graph[p1].add(p2);
				graph[p2].add(p1);
			}
		}
		boolean visit[] = new boolean[graph.length];
		int ans = 1;
		for (int i = 0; i < graph.length; i++) {
			if (visit[i]) {
				continue;
			}
			cnt = 0;
			ext = 0;
//			System.err.println("DFS from " + i);
			dfs(graph, visit, i, -1);
			if (ext % 2 != 0) {
				throw new AssertionError();
			}
			ext /= 2;
			if (ext > 1) {
				ans = 0;
				break;
			} else if (ext == 1) {
				ans = (ans * 2) % MOD;
			} else {
				ans = (int) (((long) ans * cnt) % MOD);
			}
		}
		out.println(ans);
	}
	
	static int cnt, ext;
	static void dfs(List<Integer> graph[], boolean visit[], int cur, int prev) {
		if (visit[cur]) {
//			System.err.println("Entering " + cur + " - already visited");
			++ext;
			return;
		}
//		System.err.println("Entering " + cur);
		visit[cur] = true;
		++cnt;
		boolean hit = false;
		for (int next: graph[cur]) {
			if (next == prev && !hit) {
				hit = true;
				continue;
			}
			dfs(graph, visit, next, cur);
		}
		if (prev >= 0 && !hit) {
			throw new AssertionError();
		}
//		System.err.println("Exiting " + cur);
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveTest();
		}
	}

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		solve();
		in.close();
		out.close();
	}
	
	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}
	
	static char nextChar() throws IOException {
		String token = next();
		if (token.length() != 1) {
			throw new IllegalArgumentException("String \"" + token + "\" is not a single character");
		}
		return token.charAt(0);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}