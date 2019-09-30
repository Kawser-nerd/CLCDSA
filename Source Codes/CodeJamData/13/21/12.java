import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {
	
	private void solve() throws Exception {
		long ourSize = nextInt();
		int n = nextInt();
		int[] sizes = new int[n];
		for (int i = 0; i < n; ++i) {
			sizes[i] = nextInt();
		}
		if (ourSize == 1) {
			out.println(n);
			return;
		}
		Arrays.sort(sizes);
		int ans = Integer.MAX_VALUE;
		int curCnt = 0;
		for (int i = 0; i < n; ++i) {
			ans = Math.min(ans, curCnt + n - i);
			while (sizes[i] >= ourSize) {
				++curCnt;
				ourSize += ourSize - 1;
			}
			ourSize += sizes[i];
		}
		ans = Math.min(ans, curCnt);
		out.println(ans);
	}

	public void run() {
		try {
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(42);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				if (line == null)
					return null;
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private A(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new A("A").run();
	}
}
