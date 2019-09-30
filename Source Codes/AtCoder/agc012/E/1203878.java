import java.io.*;
import java.util.*;

public class Main {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int v = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int[] b = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			b[i] = a[i + 1] - a[i];
		}

		int[] seq = new int[40];
		int ptr = 0;
		while (true) {
			seq[ptr++] = v;
			if (v == 0) {
				break;
			}
			v /= 2;
		}
		
		for (int i = 0, j = ptr - 1; i < j; i++, j--) {
			int tmp = seq[i];
			seq[i] = seq[j];
			seq[j] = tmp;
		}

		int[][] nxt = new int[ptr][n];
		int[][] prv = new int[ptr][n];

		for (int i = 0; i < ptr; i++) {
			int gap = seq[i];
			for (int j = 0; j < n;) {
				int nxtJ = j + 1;
				while (nxtJ < n && b[nxtJ - 1] <= gap) {
					nxtJ++;
				}

				for (int k = j; k < nxtJ; k++) {
					nxt[i][k] = nxtJ - 1;
					prv[i][k] = j;
				}

				j = nxtJ;
			}
		}

		int[] pref = new int[1 << (ptr - 1)];
		int[] suff = new int[1 << (ptr - 1)];

		for (int mask = 0; mask < 1 << (ptr - 1); mask++) {
			for (int i = 0; i < ptr - 1; i++) {
				if (test(mask, i)) {
					int was = pref[mask ^ (1 << i)];
					if (was == n) {
						pref[mask] = n;
					} else {
						pref[mask] = Math.max(pref[mask], nxt[i][was] + 1);
					}

					was = suff[mask ^ (1 << i)];
					if (was == n) {
						suff[mask] = n;
					} else {
						suff[mask] = Math.max(suff[mask], n - prv[i][n - 1 - was]);
					}
				}
			}
		}

		int[] maxLeft = new int[n + 1]; // index - length of right
		Arrays.fill(maxLeft, -1);
		int allMask = (1 << (ptr - 1)) - 1;
		for (int maskL = 0; maskL <= allMask; maskL++) {
			int maskR = allMask ^ maskL;

			int valL = pref[maskL];
			int valR = suff[maskR];
			
			maxLeft[valR] = Math.max(maxLeft[valR], valL);
		}

		int canL = -1;
		for (int i = 0; i < n;) {
			int j = nxt[ptr - 1][i];
			for (int k = i; k <= j; k++) {
				canL = Math.max(canL, maxLeft[n - 1 - k]);
			}

			String outp = canL >= i ? "Possible" : "Impossible";

			for (int k = i; k <= j; k++) {
				out.println(outp);
			}

			i = j + 1;
		}
	}

	boolean test(int mask, int i) {
		return ((mask >> i) & 1) == 1;
	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Main();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}