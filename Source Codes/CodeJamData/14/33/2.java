import java.util.*;
import java.io.*;

public class SolC {

	public static void main(String[] args) {
		try {
			new SolC().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void run() throws IOException {
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
	
	String FNAME = "C-large";
	
	int sol(int n, int m, int k) {
		int ans = k;
		for (int l1 = 1; l1 <= n; l1++) {
			for (int l2 = 1; l2 <= n; l2++) {
				for (int w = 2; w <= m; w++) {
					int diff = Math.abs(l1 - l2);
					if (diff > 2 * (w - 1)) {
						continue;
					}
					int count = l1;
					int sz = l1;
					int h = l1;
					for (int i = 0; i < w - 1; i++) {
						int left = (w - i - 2) * 2;
						if (h + 1 <= n && (h + 1 - left <= l2)) {
							h++;
							if (h + 1 <= n && (h + 1 - left <= l2)) {
								h++;
							}
						} else if (h - left - 1 == l2) {
							h--;
						} else if (h - left - 2 == l2) {
							h -= 2;
						}
						sz += h;
						count += 2;
					}
					count += l2 - 2;
					if (sz >= k) {
//						out.println(l1 + " " + l2 + " " + w + " " + sz + " " + count);
						ans = Math.min(ans, count);
					}
				}
			}
		}
		return ans;
	}

	void solve() {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			System.err.println("Solving: " + test);
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			int k = nextInt();
			int t1 = sol(n, m, k);
			int t2 = sol(m, n, k);
			out.println(Math.min(t1, t2));
		}
	}
}
