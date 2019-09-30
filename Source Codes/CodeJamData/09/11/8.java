import java.util.Scanner;
import java.util.List;
import java.util.AbstractList;
import java.util.ArrayList;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;

public class Task implements Runnable {
    private static final String ID = "magic";
    private static final String IN_FILE = ID + ".in";
    private static final String OUT_FILE = ID + ".out";
	private static final int N = 11814986;

    private Scanner in;
    private PrintWriter out;
    private int t, ans;
	private boolean w[][];
	private boolean g[][];
	private List<Integer> a = new ArrayList<Integer>();

	private boolean go(int n, int d) {
		if (w[d][n])
			return g[d][n];
		if (n == 1)
			return true;
		int nn = 0;
		int on = n;
		while (n != 0) {
			int cd = n % d;
			nn += cd * cd;
			n /= d;
		}
		w[d][on] = true;
		return g[d][on] = go(nn, d);
	}

    private void init() {
        try {
            in = new Scanner(new File(IN_FILE));
            out = new PrintWriter(OUT_FILE);
        } catch (FileNotFoundException ignored) {}
		w = new boolean[11][N];
		g = new boolean[11][N];
		for (int i = 2; i < N; i++) {
			boolean good = true;
			for (int j = 2; j <= 10; j++) {
				if (!go(i, j))
					good = false;
			}
			if (good) {
				System.out.println(i);
				break;
			}
		}
    }

    private void read() {
		String s = in.next();
		System.out.println(s);
		a.clear();
		Scanner i = new Scanner(s);
		while (i.hasNextInt())
			a.add(i.nextInt());
    }

    private void solve() {
		System.out.println("" + g[9][91] + g[10][91]);
		for (int i = 2; i < N; i++) {
			boolean good = true;
			for (int d : a) {
				if (!g[d][i]) {
					good = false;
					break;
				}
			}
			if (good) {
				ans = i;
				break;
			}
		}
    }

    private void write() {
		out.println("Case #" + t + ": " + ans);
    }

    public void run() {
        init();
		int n = in.nextInt();
		System.out.println(n);
		in.useDelimiter("\n");
//		in.next();
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
