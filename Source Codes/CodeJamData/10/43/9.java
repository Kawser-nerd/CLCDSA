import java.io.*;
import java.util.*;
import java.math.*;

public class CSmall {
	public static void main(String[] args) throws Throwable {
		new CSmall().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(1897450987159L);

	private void run() throws Throwable {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader(FNAME + ".in"));
		out = new PrintWriter(FNAME + ".out");
		solve();
		out.close();
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

	String FNAME = "c";

	private void solve() throws IOException {
		for (int test = 1, testn = nextInt(); test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int[][] a = new int[1000][1000];
			for (int q = 0; q < n; q++) {
				int x1 = nextInt() - 1;
				int y1 = nextInt() - 1;
				int x2 = nextInt();
				int y2 = nextInt();
				for (int i = x1; i < x2; i++) {
					for (int j = y1; j < y2; j++) {
						a[i][j] = 1;
					}
				}
			}
			int ans = 0;
			while (true) {
				ans++;
				int cnt = 0;
				for (int i = a.length - 1; i >= 0; i--) {
					for (int j = a.length - 1; j >= 0; j--) {
						boolean north = i > 0 && a[i - 1][j] == 1;
						boolean west = j > 0 && a[i][j - 1] == 1;
						if (north && west) {
							a[i][j] = 1;
						}
						if (!(north || west)) {
							a[i][j] = 0;
						}
						if (a[i][j] == 1) {
							cnt++;
						}
					}
				}
				if (cnt == 0) {
					break;
				}
			}
			out.println(ans);
		}
	}
}
