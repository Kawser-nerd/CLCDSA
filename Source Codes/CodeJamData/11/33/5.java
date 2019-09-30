import java.io.*;
import java.util.*;
import java.math.*;

public class CS {
	public static void main(String[] args) {
		new CS().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(125475452);

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
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

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}
	
	String FNAME = "C-small-attempt0";

	private void solve() throws IOException {
		int T = nextInt();
		for (int test = 1; test <= T; ++test) {
			int n = nextInt();
			int L = nextInt();
			int  R = nextInt();
			int[] f = new int[n];
			for (int i = 0; i < n; ++i) {
				f[i] = nextInt();
			}
			
			int ans = -1;
			loop:
			for (int x = L; x <= R; ++x) {
				for (int fr : f) {
					if (x % fr != 0 && fr % x != 0) {
						continue loop;
					}
				}
				ans = x;
				break;
			}
			
			out.print("Case #" + test + ": ");
			if (ans < 0) {
				out.println("NO");
			} else {
				out.println(ans);
			}
		}
	}
}