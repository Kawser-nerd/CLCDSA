import java.util.*;
import java.io.*;

//import java.math.*;

public class SolA implements Runnable {
	public static void main(String[] args) {
		new Thread(new SolA()).start();
	}

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

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

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

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	private final String FNAME = "A-large";
	
	int iscons(char ch) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 0;
		return 1;
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			char[] s = nextToken().toCharArray();
			int m = nextInt();
			int n = s.length;
			boolean[] good = new boolean[n];
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (iscons(s[i]) == 1) {
					cnt++;
				} else {
					cnt = 0;
				}
				if (cnt >= m) {
					good[i] = true;
				}
			}
			int last = Integer.MAX_VALUE;
			long ans = 0;
			for (int i = n - m; i >= 0; i--) {
				if (good[i + m - 1]) {
					last = i + m - 1;
				}
				if (last != Integer.MAX_VALUE) {
					ans += n - last;
				}
			}
			out.println(ans);
		}
	}
}
