import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "C-large";
	
	int[] nexts(long[] hs) {
		int n = hs.length;
		int[] ret = new int[n - 1];
		for (int i = 0; i < n - 1; ++i) {
			int r = i + 1;
			for (int j = i + 2; j < n; ++j) {
				if ((hs[j] - hs[i]) * (r - i) > (hs[r] - hs[i]) * (j - i)) {
					r = j;
				}
			}
			ret[i] = r;
		}
		return ret;
	}

	public void solve() throws IOException {
		int tests = nextInt();
		Random rnd = new Random();
		loop: for (int test = 0; test < tests; ++test) {
			out.printf("Case #%d: ", test + 1);
//			test--;
			int n = nextInt();
//			int n = 10;
			int[] next = new int[n - 1];
			for (int i = 0; i < n - 1; ++i) {
				next[i] = nextInt() - 1;
//				next[i] = rnd.nextInt(n - i - 1) + i + 1;
			}
			ArrayList<Integer>[] subCurve = new ArrayList[n];
			for (int i = 0; i < n; ++i) {
				subCurve[i] = new ArrayList<Integer>();
			}
			int[] st = new int[n];
			int stp = 0;
			st[stp++] = n - 1;
			for (int i = n - 2; i >= 0; --i) {
				while (stp > 0 && st[stp - 1] != next[i]) {
					subCurve[i].add(st[--stp]);
				}
				if (stp == 0) {
					out.println("Impossible");
					continue loop;
				}
				st[stp++] = i;
			}
			for (int i = stp - 1; i > 0; --i) {
				subCurve[n - 1].add(st[i]);
			}
			int[] slope = new int[n];
			slope[n - 1] = -2;
			calcSlope(n - 1, slope, subCurve);
			long[] ans = new long[n];
			ans[n - 1] = 1000000000;
			for (int i = n - 2; i >= 0; --i) {
				ans[i] = ans[next[i]] - (next[i] - i) * slope[i];
			}
			long min = 1000000000;
			for (int i = 0; i < n; ++i) {
				min = Math.min(min, ans[i]);
			}
			if (min < 0) {
				System.err.println("fail :( " + min);
			}
			for (int i = 0; i < n; ++i) {
				ans[i] -= min;
			}
			if (!Arrays.equals(next, nexts(ans))) {
				System.err.println(Arrays.toString(next) + " " + Arrays.toString(nexts(ans)));
			} else {
//				System.err.print(".");
			}
			for (int i = 0; i < n; ++i) {
				out.print(ans[i] + " ");
			}
			out.println();
		}
	}

	private void calcSlope(int i, int[] slope, ArrayList<Integer>[] subCurve) {
		for (int it = 0; it < subCurve[i].size(); ++it) {
			int j = subCurve[i].get(subCurve[i].size() - it - 1);
			slope[j] = slope[i] + it + 2;
			calcSlope(j, slope, subCurve);
		}
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}