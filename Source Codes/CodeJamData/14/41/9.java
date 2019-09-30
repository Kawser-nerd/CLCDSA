import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int t = nextInt();
		for (int currentTest = 0; currentTest < t; currentTest++) {
			int n = nextInt();
			int x = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			out.println("Case #" + (1 + currentTest) + ": " + solve(n, x, a));
		}
	}

	static int solve(int n, int x, int[] a) {
		Arrays.sort(a);
		int ans = 0;
		boolean[] was = new boolean[n];
		for (int i = n - 1; i >= 0; i--) {
			if (was[i])
				continue;
			was[i] = true;
			int found = -1;
			for (int j = n - 1; j >= 0; j--) {
				if (was[j])
					continue;
				if (a[i] + a[j] <= x) {
					found = j;
					break;
				}
			}
			if (found >= 0) {
				was[found] = true;
			}
			++ans;
		}
		return ans;
	}

	public static void main(String[] args) throws Exception {
		File file = new File("a.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("a.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
