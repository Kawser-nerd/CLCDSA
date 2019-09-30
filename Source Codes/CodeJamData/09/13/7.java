import java.util.*;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;

public class Task implements Runnable {
    private static final String ID = "ev";
    private static final String IN_FILE = ID + ".in";
    private static final String OUT_FILE = ID + ".out";

    private Scanner in;
    private PrintWriter out;
    private int t, n, c;
	private double ans;
	private double[][] cc;
	private double[] e;

    private void init() {
        try {
            in = new Scanner(new File(IN_FILE));
            out = new PrintWriter(OUT_FILE);
        } catch (FileNotFoundException ignored) {}
		cc = new double[41][41];
		for (int i = 0; i < 41; i++) {
			cc[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				cc[i][j] = cc[i - 1][j - 1] + cc[i - 1][j];
			}
		}
    }

    private void read() {
		c = in.nextInt();
		n = in.nextInt();
    }

    private void solve() {
		e = new double[c + 1];
		for (int i = 1; i <= c; i++) {
			double p = 0;
			e[i] = 1;
			for (int j = 0; j < i; j++) {
				if (n - i + j < 0) continue;
				double cp = cc[i][i - j] * cc[c - i][n - i + j] / cc[c][n];
				e[i] += cp * e[j];
				p += cp;
			}
			System.out.println(p + " " + e[i]);
			e[i] /= p;
		}
		ans = e[c];
    }

    private void write() {
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
