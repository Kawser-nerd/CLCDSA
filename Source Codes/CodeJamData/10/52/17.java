import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class b {
	
	final long INF = Long.MAX_VALUE;
	long l;
	int n;
	int[] b;
	long[] best;
	
	private void solve() throws Exception {
		l = nextLong(); n = nextInt();
		b = new int[n];
		for (int i = 0; i < n; ++i)
			b[i] = nextInt();
		int ma = 100000;
		best = new long[ma];
		Arrays.fill(best, INF);
		best[0] = 0;
		for (int ind = 0; ind < n; ++ind){
			for (int i = 0; i < ma - b[ind]; ++i)
				if (best[i] != INF)
					best[i + b[ind]] = Math.min(best[i + b[ind]], best[i] + 1);
		}
		long ans = INF;
		for (int i = 0; i < n; ++i){
			long cur = l / b[i];
			int tmp = (int)(l % b[i]);
			while (tmp < ma && tmp <= l){
				if (best[tmp] != INF)
					ans = Math.min(ans, best[tmp] + cur);
				--cur;
				tmp += b[i];
			}
		}
		if (ans == INF)
			out.println("IMPOSSIBLE");
		else
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
		System.exit(1);
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
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private b(String name) {
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
		new b("b").run();
	}

}
