import java.io.*;
import java.util.*;

public class SolC implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolC()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof;

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "C-large";

	void solve() {
		int tests = nextInt();
		int max = 1000001;
		boolean[] np = new boolean[max];
		np[0] = np[1] = true;
		for (int i = 2; i < max; i++) {
			if (!np[i]) {
				int j = 2 * i;
				while (j < max) {
					np[j] = true;
					j += i;
				}
			}
		}
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			long n = nextLong();
			long ans = 0;
			if (n > 1) {
				ans++;
			}
			for (long i = 2; i * i <= n; i++) {
				if (np[(int) i]) continue;
				long j = i * i;
				while (j <= n) {
					ans++;
					j *= i;
				}
			}
			out.println(ans);
		}		
	}
}