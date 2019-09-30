import java.io.*;
import java.util.*;
import java.math.*;

public class Tiles {

	public static void main(String[] args) {
		new Tiles().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(2635243643L);

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

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "tiles";

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 1; test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			char[][] a = new char[n][m];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextToken().toCharArray();
			}
			boolean good = true;
			loop: for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] == '#') {
						if (i + 1 >= a.length || j + 1 >= a[i].length) {
							good = false;
							break loop;
						}
						if (a[i + 1][j] != '#' || a[i + 1][j + 1] != '#'
								|| a[i][j + 1] != '#') {
							good = false;
							break loop;
						}
						a[i][j] = '/';
						a[i][j + 1] = '\\';
						a[i + 1][j] = '\\';
						a[i + 1][j + 1] = '/';
					}
				}
			}
			out.println();
			if (!good) {
				out.println("Impossible");
			} else {
				for (int i = 0; i < a.length; i++) {
					for (int j = 0; j < a[i].length; j++) {
						out.print(a[i][j]);
					}
					out.println();
				}
			}
		}
	}
}
