import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class c {
	
	final long MOD = 100003;
	long[][] c;
	long[][] d;

	private void solve() throws Exception {
		int n = nextInt();
		long ans = 0;
		for (int len = 1; len < n; ++len)
			ans = (ans + getAns(len, n)) % MOD;
		
		out.println(ans);
	}
	
	private long getAns(int len, int n) {
		if (len >= n)
			return 0;
		if (len == 1)
			return 1;
		if (d[len][n] != -1)
			return d[len][n];
		d[len][n] = 0;
		for (int pos = 1; pos < len; ++pos)
			d[len][n] = (d[len][n] + getAns(pos, len) * c[n - len - 1][len - pos - 1]) % MOD;
		return d[len][n];
	}

	private void init() {
		c = new long[600][600];
		c[0][0] = 1;
		for (int i = 1; i < 600; ++i){
			c[i][0] = 1;
			for (int j = 1; j <= i; ++j)
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
		
		d = new long[600][600];
		for (int i = 0; i < 600; ++i)
			for (int j = 0; j < 600; ++j)
				d[i][j] = -1;
	}

	private int find(int[] num, int cur) {
		for (int i = 0; i < num.length; ++i)
			if (num[i] == cur)
				return i;
		return -1;
	}

	public void run() {
		try {
			init();
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

	private c(String name) {
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
		new c("c").run();
	}

}
