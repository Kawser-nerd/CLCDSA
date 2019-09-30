import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int t = nextInt();
		for (int currentTest = 0; currentTest < t; currentTest++) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			out.println("Case #" + (currentTest + 1) + ": " + solve(a));
		}
	}

	static int solve(int[] a) {
		int n = a.length;
		int[] before = new int[n];
		int[] after = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] > a[i]) {
					before[i]++;
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (a[j] > a[i]) {
					after[i]++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += Math.min(before[i], after[i]);
		}
		return ans;
	}

	public static void main(String[] args) throws Exception {
		File file = new File("b.in");
		InputStream input = System.in;
		PrintStream output = System.out;
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("b.out");
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
