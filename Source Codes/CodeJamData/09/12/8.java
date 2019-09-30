import java.util.*;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;

public class Task implements Runnable {
    private static final String ID = "cross";
    private static final String IN_FILE = ID + ".in";
    private static final String OUT_FILE = ID + ".out";

    private Scanner in;
    private PrintWriter out;
    private int t, n, m, ans;
	private int[][] s, w, r, d;
	private boolean[][] a;

    private void init() {
        try {
            in = new Scanner(new File(IN_FILE));
            out = new PrintWriter(OUT_FILE);
        } catch (FileNotFoundException ignored) {}
    }

    private void read() {
		n = in.nextInt();
		m = in.nextInt();
		s = new int[n][m];
		w = new int[n][m];
		r = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				s[i][j] = in.nextInt();
				w[i][j] = in.nextInt();
				r[i][j] = in.nextInt();
			}
		}
    }

    private void solve() {
		a = new boolean[2 * n][2 * m];
		d = new int[2 * n][2 * m];
		for (int[] x : d)
			Arrays.fill(x, 1000000000);
		d[2 * n - 1][0] = 0;
		for (int i = 0; ; i++) {
			int u = 0, v = 0;
			int ccc = 1000000000;
			for (int x = 0; x < 2 * n; x++) {
				for (int y = 0; y < 2 * m; y++) {
					if (!a[x][y] && d[x][y] < ccc) {
						u = x;
						v = y;
						ccc = d[x][y];
					}
				}
			}
			if (u == 0 && v == 2 * m - 1) {
				ans = d[0][2 * m - 1];
				return;
			}
			a[u][v] = true;
			int cu = u - 2 * (u % 2) + 1;
			int cv = v - 2 * (v % 2) + 1;
			int tt = d[u][v];
			int ss = s[u / 2][v / 2];
			int ww = w[u / 2][v / 2];
			int mod = ss + ww;
			int rr = r[u / 2][v / 2] % mod;
			System.out.println(ss + " " + ww + " " + rr + " " + tt);
			if (tt % mod >= rr % mod && tt % mod < rr % mod + ss ||
					tt % mod + mod >= rr % mod && tt % mod + mod < rr % mod + ss) {
				d[cu][v] = Math.min(d[cu][v], d[u][v] + 1);
			} else {
				int nt;
				if (tt % mod < rr % mod)
					nt = tt + (rr % mod) - (tt % mod) + 1;
				else
					nt = tt + (rr % mod) - tt % mod + mod + 1;
				d[cu][v] = Math.min(d[cu][v], nt);
			}
			if (tt % mod >= (rr + ss) % mod && tt % mod < (rr + ss) % mod + ww ||
					tt % mod + mod >= (rr + ss) % mod && tt % mod + mod < (rr + ss) % mod + ww) {
				d[u][cv] = Math.min(d[u][cv], d[u][v] + 1);
			} else {
				int nt;
				if (tt % mod < (rr + ss) % mod)
					nt = tt + ((rr + ss) % mod) - (tt % mod) + 1;
				else
					nt = tt + ((rr + ss) % mod) - (tt % mod) + mod + 1;
				d[u][cv] = Math.min(d[u][cv], nt);
			}
			cu = 2 * u - cu;
			cv = 2 * v - cv;
			if (cu >= 0 && cu < 2 * n)
				d[cu][v] = Math.min(d[cu][v], d[u][v] + 2);
			if (cv >= 0 && cv < 2 * m)
				d[u][cv] = Math.min(d[u][cv], d[u][v] + 2);
		}
    }

    private void write() {
		System.out.println(Arrays.deepToString(d));
		out.println("Case #" + t + ": " + ans);
    }

    public void run() {
        init();
		int n = in.nextInt();
        for (t = 1; t <= n; t++) {
            read();
            solve();
            write();
        }
		out.close();
    }

    public static void main(String[] args) {
        new Thread(new Task()).start();
    }
}
