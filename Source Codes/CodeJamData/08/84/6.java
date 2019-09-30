import java.util.*;
import java.io.*;

public class Template implements Runnable {

	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private String name = "D-large";
	
	final int p = 30031; 
	
	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; ++test) {
			int n = nextInt();
//			n = 1000000000;
			int k = nextInt();
			int p = nextInt();
			ArrayList<Integer> ps = new ArrayList<Integer>();
			for (int i = 0; i < 1 << (p + 1); ++i) {
				if (Integer.bitCount(i) == k) {
					ps.add(i);
				}
			}
			int[][] ts = new int[ps.size()][ps.size()];
			for (int i : ps) {
				if ((i & 1) == 0) {
					ts[ps.indexOf(i)][ps.indexOf(i >> 1)]++;
				} else {
					for (int u = 1; u <= p; ++u) {
						if ((i & (1 << u)) == 0) {
							int j = i ^ (1 << u);
							j >>= 1;
							ts[ps.indexOf(i)][ps.indexOf(j)]++;
							if (u == 1) break;
						}
					}
				}
			}
//			for (int i : ps) {
//				System.out.print(Integer.toBinaryString(i) + " ");
//			}
//			System.out.println();
			int[][] m = pow(ts, n - k);
//			System.out.println(Arrays.deepToString(ts));
//			System.out.println(Arrays.deepToString(m));
			int start = ps.indexOf((1 << k) - 1);
			out.println("Case #" + test + ": " + m[start][start]);
		}
	}
	
	int[][] pow(int[][] a, int p) {
		int n = a.length;
		int[][] b = new int[n][n];
		for (int i = 0; i < n; ++i) {
			b[i][i] = 1;
		}
		while (p > 0) {
			if (p % 2 == 1) {
				b = mul(b, a);
			}
			a = mul(a, a);
			p >>= 1;
		}
		return b;
	}

	private int[][] mul(int[][] a, int[][] b) {
		int n = a.length;
		int[][] c = new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % p;
				}
			}
		}
		return c;
	}

	public void run() {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(name + ".out");
			
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
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		new Thread(new Template()).start();
	}

}
