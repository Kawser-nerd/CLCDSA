import java.io.*;
import java.util.*;

public class C {

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

	String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	String get() throws Exception {
		int n = nextInt();
		int q = nextInt();
		long hd[] = new long[n];
		double hs[] = new double[n];
		for (int i = 0; i < n; i++) {
			hd[i] = nextInt();
			hs[i] = nextInt();
		}
		long inf = (long) 1e12;
		long d[][] = new long[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int val = nextInt();
				d[i][j] = val == -1 ? inf : val;
			}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (d[i][k] < inf && d[k][j] < inf)
						if (d[i][j] > d[i][k] + d[k][j])
							d[i][j] = d[i][k] + d[k][j];

		// now we have actual distance table

		double t[][] = new double[n][n];
		for (int i = 0; i < n; i++)
			Arrays.fill(t[i], inf);
		// time to travel from X to Y with horse taken @ X
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (d[i][j] <= hd[i])
					t[i][j] = d[i][j] / hs[i];

		//for (int i = 0; i < n; i++)
		//	System.err.println(Arrays.toString(t[i]));

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (t[i][j] > t[i][k] + t[k][j])
						t[i][j] = t[i][k] + t[k][j];

		//for (int i = 0; i < n; i++)
		//	System.err.println(Arrays.toString(t[i]));

		StringBuilder ans = new StringBuilder("");
		for (int i = 0; i < q; i++) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;
			ans.append(String.format("%.8f ", t[from][to]));
		}
		return ans + "";
	}

	void solve() throws Exception {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.println("Case #" + (i + 1) + ": " + get());
		}
	}

	void run() {
		try {
			Locale.setDefault(Locale.US);
			final String className = this.getClass().getName().toLowerCase();
			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

}
