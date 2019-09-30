import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Edge {
		final int a, b;

		public Edge(int a, int b) {
			this.a = min(a, b);
			this.b = max(a, b);
		}

		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + a;
			result = prime * result + b;
			return result;
		}

		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (!(obj instanceof Edge))
				return false;
			Edge other = (Edge) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			return true;
		}
	}
	
	static int solveTest() throws Exception {
		int n = nextInt();
//		Map<Edge, Integer> edges = new HashMap<B.Edge, Integer>();
//		edges.put(new Edge(0, 1), -1);
//		edges.put(new Edge(1, 2), -1);
//		edges.put(new Edge(2, 0), -1);
		List<Integer> roots[] = new List[3];
		for (int i = 0; i < 3; i++) {
			roots[i] = new ArrayList<Integer>();
		}
		List<Integer> deps[][] = new List[n][2];
		for (int i = 3; i < n; i++) {
			deps[i][0] = new ArrayList<Integer>();
			deps[i][1] = new ArrayList<Integer>();
		}
		int a[] = new int[n];
		int b[] = new int[n];
		for (int i = 3; i < n; i++) {
			a[i] = nextInt() - 1;
			b[i] = nextInt() - 1;
			int d = max(a[i], b[i]);
			if (d < 3) {
				int root = (a[i] + b[i]) % 3;
				roots[root].add(i);
			} else {
				deps[d][(min(a[i], b[i]) == a[d]) ? 0 : 1].add(i);
			}
//			if (!edges.containsKey(new Edge(a, b))) {
//				throw new AssertionError();
//			}
//			edges.put(new Edge(a, i), i);
//			edges.put(new Edge(b, i), i);
		}
		int ans[] = new int[n];
		for (int i = n - 1; i >= 3; i--) {
			int cans0 = 0;
			for (int dep: deps[i][0]) {
				cans0 = max(cans0, ans[dep]);
			}
			int cans1 = 0;
			for (int dep: deps[i][1]) {
				cans1 = max(cans1, ans[dep]);
			}
			ans[i] = cans0 + cans1 + 1;
		}
		int theans;
		{
			int cans0 = 0;
			for (int dep: roots[0]) {
				cans0 = max(cans0, ans[dep]);
			}
			int cans1 = 0;
			for (int dep: roots[1]) {
				cans1 = max(cans1, ans[dep]);
			}
			int cans2 = 0;
			for (int dep: roots[2]) {
				cans2 = max(cans2, ans[dep]);
			}
			theans = cans0 + cans1 + cans2 + 3;
		}
		for (List<Integer> dep: roots) {
			theans = max(theans, calc(dep, ans));
		}
		for (int i = 3; i < n; i++) {
			theans = max(theans, calc(deps[i][0], ans));
			theans = max(theans, calc(deps[i][1], ans));
		}
		return theans;
	}
	
	static int calc(List<Integer> dep, final int ans[]) {
		Integer arr[] = dep.toArray(new Integer[dep.size()]);
		sort(arr, new Comparator<Integer>() {

			public int compare(Integer o1, Integer o2) {
				return ans[o1] > ans[o2] ? -1 : ans[o1] < ans[o2] ? 1 : 0;
			}
		});
		if (arr.length < 2) {
			return Integer.MIN_VALUE;
		}
		return ans[arr[0]] + ans[arr[1]] + 2;
	}
	
	static int solveTestDumb() throws Exception {
		int n = nextInt();
		List<Integer> links[] = new List[n];
		for (int i = 0; i < n; i++) {
			links[i] = new ArrayList<Integer>();
		}
		links[0].add(1);
		links[1].add(0);
		links[1].add(2);
		links[2].add(1);
		links[2].add(0);
		links[0].add(2);
		for (int i = 3; i < n; i++) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			links[a].add(i);
			links[i].add(a);
			links[b].add(i);
			links[i].add(b);
		}
		boolean col[] = new boolean[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dfs(links, col, i, i));
		}
		return ans;
	}
	
	static int dfs(List<Integer> links[], boolean col[], int start, int cur) {
		if (col[cur]) {
			return cur == start ? 0 : Integer.MIN_VALUE;
		}
		col[cur] = true;
		int ans = Integer.MIN_VALUE;
		for (int t: links[cur]) {
			int cans = dfs(links, col, start, t);
			if (cans != Integer.MIN_VALUE) {
				ans = max(ans, cans + 1);
			}
		}
		col[cur] = false;
		return ans;
	}
	
	static void solve() throws Exception {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
//			StringBuilder sb;
//			{
//				sb = new StringBuilder();
//				int n = nextInt();
//				sb.append(n);
//				for (int i = 3; i < n; i++) {
//					sb.append("\n");
//					sb.append(nextInt());
//					sb.append(' ');
//					sb.append(nextInt());
//				}
//			}
//			tok = new StringTokenizer(sb.toString());
			int ans1 = solveTest();
//			tok = new StringTokenizer(sb.toString());
//			int ans2 = solveTestDumb();
			out.println(ans1);
//			out.println(ans1 + " " + ans2);
//			if (ans1 != ans2) {
//				out.println("ERROR");
//				out.println(sb.toString());
//				out.println();
//			}
			System.out.print('.');
		}
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		System.out.print("Enter filename: ");
		System.out.flush();
		String filename = new BufferedReader(new InputStreamReader(System.in)).readLine();
		in = new BufferedReader(new InputStreamReader(
			new FileInputStream(new File(filename + ".in"))));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
			new FileOutputStream(new File(filename + ".out")))));
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
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return parseLong(next());
	}
	
	static double nextDouble() throws IOException {
		return parseDouble(next());
	}
	
	static BigInteger nextBigInt() throws IOException {
		return new BigInteger(next());
	}
}