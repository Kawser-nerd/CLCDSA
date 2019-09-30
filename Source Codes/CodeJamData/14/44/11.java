import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

	class Node {
		
		Node[] to = new Node[26];
		
	}
	
	int add(Node root, String str) {
		int ans = 0;
		Node pos = root;
		for (int i = 0; i < str.length(); i++) {
			Node to = pos.to[str.charAt(i) - 'A'];
			if (to == null) {
				to = pos.to[str.charAt(i) - 'A'] = new Node();
				ans++;
			}
			pos = to;
		}
		return ans;
	}
	
	public void solve() throws Exception {
		int T = sc.nextInt();
		for (int Case = 1; Case <= T; Case++) {
			int m = sc.nextInt(), n = sc.nextInt();
			String[] s = new String[m];
			for (int i = 0; i < m; i++) {
				s[i] = sc.nextToken();
			}
			int ans = 0;
			int anscnt = 0;
		loopmask:
			for (int mask = 0; mask < (1 << (2 * m)); mask++) {
				Node[] roots = new Node[n];
				for (int i = 0; i < n; i++) {
					roots[i] = new Node();
				}
				boolean[] good = new boolean[n];
				int msk = mask;
				int curans = 0;
				for (int i = 0; i < m; i++) {
					int toi = msk & 3;
					msk >>= 2;
					if (toi >= n) {
						continue loopmask;
					}
					curans += add(roots[toi], s[i]);
					good[toi] = true;
				}
				for (int i = 0; i < n; i++) {
					if (!good[i]) {
						continue loopmask;
					}
				}
				if (curans > ans) {
					ans = curans;
					anscnt = 1;
				} else if (curans == ans) {
					anscnt++;
				}
			}
			out.printf(Locale.US, "Case #%d: %d %d\n", Case, ans + n, anscnt);
		}
	}

	static Throwable uncaught;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("D-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("D-small-attempt0.out"));
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new PrintWriter(System.out);
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", (1 << 26));
		thread.start();
		thread.join();
		if (Solution.uncaught != null) {
			throw Solution.uncaught;
		}
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}