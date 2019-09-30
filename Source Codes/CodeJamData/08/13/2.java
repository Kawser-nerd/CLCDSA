import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private static final double EPS = 1e-10;
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			int n = nextInt();
			int[][] a = new int[3][3];
			a[0][1] = 1;
			a[1][2] = 1;
			a[2][0] = 4;
			a[2][1] = 990;
			a[2][2] = 7;
			a = pow(a, n);
			int r = (a[0][0] * 1 + a[0][1] * 5 + a[0][2] * 27) % 1000;
			String res = Integer.toString(r);
			while (res.length() < 3) {
				res = "0" + res;
			}
			out.println("Case #" + (test + 1) + ": " + res);
		}
	}
	
	private int[][] pow(int[][] a, int n) {
		if (n == 0) {
			int[][] r = new int[3][3];
			r[0][0] = r[1][1] = r[2][2] = 1;
			return r;
		}
		int[][] t = pow(a, n / 2);
		t = mul(t, t);
		if (n % 2 == 1) {
			t = mul(t, a);
		}
		return t;
	}

	int[][] mul(int[][] a, int[][] b) {
		int[][] r = new int[3][3];
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % 1000;
				}
			}
		}
		return r;
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
			out = new PrintWriter(System.out);
			
			solve();
			
			out.close();
		} catch (Exception ex) {
			ex.printStackTrace();
			System.exit(-1);
		}
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

	private void ass(boolean b) {
		if (!b) {
			throw new RuntimeException("Assertion failed");
		}
	}
	
	static final boolean Ъ = true;
}