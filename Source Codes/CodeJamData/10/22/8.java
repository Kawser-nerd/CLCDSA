import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class b {
	
	int n, k;
	long b, t;
	int[] x, v;
	
	private void solve() throws Exception {
		n = nextInt(); k = nextInt(); b = nextInt(); t = nextInt();
		x = new int[n]; v = new int[n];
		for (int i = 0; i < n; ++i)
			x[i] = nextInt();
		for (int i = 0; i < n; ++i)
			v[i] = nextInt();
		int ans = 0, tot = 0, bad = 0;
		for (int i = n - 1; i >= 0 && tot < k; --i){
			if (canReach(x[i], v[i])){
				++tot;
				ans += bad;
			}
			else
				++bad;
		}
		if (tot < k)
			out.println("IMPOSSIBLE");
		else
			out.println(ans);
	}

	private boolean canReach(int x, int v) {
		long dist = b - x;
		long canGo = t * v;
		return canGo >= dist;
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
