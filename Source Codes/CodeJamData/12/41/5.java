import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	final String file = "A-large";

	public void solve() throws IOException {
		int tests = nextInt();
		loop: for (int test = 0; test < tests; ++test) {
			out.printf("Case #%d: ", test + 1);
			int n = nextInt();
			int[] d = new int[n + 1];
			int[] l = new int[n + 1];
			for (int i = 1; i <= n; ++i) {
				d[i] = nextInt();
				l[i] = nextInt();
			}
			int D = nextInt();
			int[] maxLen = new int[n + 1];
			boolean[] col = new boolean[n + 1];
			maxLen[1] = d[1];
			while (true) {
				int i = -1;
				for (int j = 0; j <= n; ++j) {
					if (!col[j] && (i == -1 || maxLen[i] < maxLen[j])) {
						i = j;
					}
				}
				if (i == -1) {
					break;
				}
				col[i] = true;
				if (d[i] + maxLen[i] >= D) {
					out.println("YES");
					continue loop;
				}
				for (int j = i + 1; j <= n && d[i] + maxLen[i] >= d[j]; ++j) {
					maxLen[j] = Math.max(maxLen[j], Math.min(d[j] - d[i], l[j]));
				}
			}
			out.println("NO");
		}
	}

	private boolean dfs(int i, int j, int D, int[] d, int[] l, boolean[][] col) {
		
		return false;
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