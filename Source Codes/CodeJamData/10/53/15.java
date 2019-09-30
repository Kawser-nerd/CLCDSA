import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class c {
	
	long[] sum;
	int n;
	int[] c;
	int add = 2000000;
	long ans;
	int mi, ma;
	
	private void solve() throws Exception {
		n = nextInt();
		c = new int[5000000];
		ans = 0;
		mi = Integer.MAX_VALUE; ma = Integer.MIN_VALUE;
		for (int i = 0; i < n; ++i){
			int x = nextInt(), cnt = nextInt();
			move(x + add, cnt);
		}
		while (true){
			boolean hasM = false;
			int omi = mi, oma = ma;
			mi = Integer.MAX_VALUE; ma = Integer.MIN_VALUE;
			for (int i = omi; i <= oma; ++i){
				if (c[i] > 1){
					hasM = true;
					int cur = c[i];
					c[i] = 0;
					move(i, cur);
				}
			}
			if (!hasM)
				break;
		}
		out.println(ans);
	}

	private void move(int x, int cnt) {
		ans += sum[cnt / 2];
		if (cnt % 2 == 1){
			++c[x];
			upd(x);
		}
		for (int j = 1; j <= cnt / 2; ++j){
			++c[x - j];
			upd(x - j);
			++c[x + j];
			upd(x + j);
		}
	}

	private void upd(int x) {
		mi = Math.min(mi, x);
		ma = Math.max(ma, x);
	}

	public void run() {
		try {
			sum = new long[100001];
			for (long i = 1; i < sum.length; ++i)
				sum[(int)i] = sum[(int)i - 1] + i * i;
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
