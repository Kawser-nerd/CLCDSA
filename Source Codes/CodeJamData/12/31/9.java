import java.io.*;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.ArrayBlockingQueue;

public class A {
	BufferedReader in;
	StringTokenizer str;
	PrintWriter out;
	String SK;

	String next() throws IOException {
		while ((str == null) || (!str.hasMoreTokens())) {
			SK = in.readLine();
			if (SK == null)
				return null;
			str = new StringTokenizer(SK);
		}
		return str.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int[] top;
	int t;
	ArrayList<Integer>[] a;
	int[] here;

	void dfs(int v) {
		here[v] = 1;
		for (int i : a[v]) {
			if (here[i] == 0) {
				dfs(i);
			}
		}
		top[t++] = v;
	}

	void solve() throws IOException {
		int n = nextInt();
		a = new ArrayList[n];
		top = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; i++) {
			int m = nextInt();
			for (int j = 0; j < m; j++) {
				int k = nextInt() - 1;
				a[i].add(k);
			}
		}
		here = new int[n];
		t = 0;
		for (int i = 0; i < n; i++) {
			if (here[i] == 0) {
				dfs(i);
			}
		}
		int[][] res = new int[n][n];
		for (int i = 0; i < n; i++) {
			res[i][i] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j : a[top[i]]) {
				for (int k = 0; k < n; k++) {
					res[top[i]][k] += res[j][k];
				}
			}
			for (int j = 0; j < n; j++) {
				if (res[top[i]][j] > 1) {
					out.println(" Yes");
					return;
				}
			}
		}
		out.println(" No");
	}

	void run() throws IOException {
		in = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			System.err.println(i);
			out.print("Case #" + (i + 1) + ":");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

}