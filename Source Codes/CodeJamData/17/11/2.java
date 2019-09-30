import java.io.*;
import java.util.*;
import java.math.*;

public class Cake implements Runnable {

	public static void main(String[] args) {
		new Thread(new Cake()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	@Override
	public void run() {
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(255);
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

	long nextLond() {
		return Long.parseLong(nextToken());
	}

	String FNAME = "a";

	private void solve() {
		int tests = nextInt();
		nextTest: for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int m = nextInt();
			char[][] a = new char[n][];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextToken().toCharArray();
			}
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					if (a[i][j] == '?' && j > 0) {
						a[i][j] = a[i][j - 1];
					}
				}
				for (int j = a[i].length - 1; j >= 0; j--) {
					if (j + 1 < a[i].length && a[i][j] == '?') {
						a[i][j] = a[i][j + 1];
					}
				}
			}
			for (int i = 0; i < a.length; i++) {
				if (a[i][0] == '?' && i > 0 && a[i - 1][0] != '?') {
					for (int j = 0; j < a[i].length; j++) {
						a[i][j] = a[i - 1][j];
					}
				}
			}
			for (int i = a.length - 1; i >= 0; i--) {
				if (a[i][0] == '?' && i + 1 < a.length && a[i + 1][0] != '?') {
					for (int j = 0; j < a[i].length; j++) {
						a[i][j] = a[i + 1][j];
					}
				}
			}
			out.println();
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					out.print(a[i][j]);
				}
				out.println();
			}
		}
	}

}
