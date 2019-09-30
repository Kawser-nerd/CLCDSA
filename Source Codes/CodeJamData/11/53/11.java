import java.util.*;
import java.io.*;
import java.math.BigInteger;
import static java.lang.Math.*;

public class Sol implements Runnable {

	void solve() throws Exception {
		int n = nextInt(), m = nextInt();
		BitSet [] a = new BitSet[n * m];
		for (int i = 0; i < a.length; i++) {
			a[i] = new BitSet(n * m + 1);
		}
		for (int i = 0; i < n; i++) {
			char [] c = in.readLine().toCharArray();
			for (int j = 0; j < m; j++) {
				int x = i * m + j;
				a[x].flip(n * m);
				char ch = c[j];
				int i1 = i, j1 = j, i2 = i, j2 = j;
				if (ch == '|' || ch == '\\' || ch == '/') {
					i1 = (i + n - 1) % n;
					i2 = (i + 1) % n;
				}	
				if (ch == '-' || ch == '\\') {
					j1 = (j + m - 1) % m;
					j2 = (j + 1) % m;
				}	
				if (ch == '/') {
					j1 = (j + 1) % m;
					j2 = (j + m - 1) % m;
				}
				//if (testNumber == 5) debug(ch + " " + i + " " + j + ": " + i1 + " " + j1 + ", " + i2 + " " + j2);	
				a[i2 * m + j2].flip(n * m);
				a[i1 * m + j1].flip(x);
				a[i2 * m + j2].flip(x);
			}
		}

		/*boolean [][] b = new boolean[n * m][n * m + 1];
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b[0].length; j++) {
				b[i][j] = a[i][j];
			}
		}*/
		Gauss g = new Gauss();
		boolean [] res = g.solve(a, n * m, n * m);
		//if (res != null && !g.check(b, n * m, n * m, res)) throw new AssertionError();
		//debug(res + " " + g.DIMENSION);
		int ans = res == null ? 0 : get(g.DIMENSION);
		
		out.printf("Case #%d: %d\n", testNumber + 1, ans);	
	}

	final int MOD = 1000003;
	int get(int pow) {
		int res = 1;
		for (int i = 0; i < pow; i++) {
			res = (res * 2) % MOD;
		}	
		return res;
	}

	public static void main(String[] args) {
		new Thread(new Sol()).start();
	}

	int testNumber;
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			sTime();
			int T = nextInt();
			for (testNumber = 0; testNumber < T; testNumber++) {
				solve();
				debug("Test " + testNumber + " finished at time: " + gTime());
			}

			out.close();

		} catch (Exception e) {
			System.err.println("exception at test = " + testNumber);
			e.printStackTrace();
		}
	}

	
	StringTokenizer tokenizer = new StringTokenizer("");
	BufferedReader in;
	PrintWriter out;

	long time;
	void sTime() { time = System.currentTimeMillis(); }
	long gTime() { return System.currentTimeMillis() - time; }
	void gMemory() { debug("Memory: " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + " kb"); }
	public void debug(Object o) { System.err.println(o); }

	
	boolean seekForToken() {
		while (!tokenizer.hasMoreTokens()) {
			String s = null;
			try {
				s = in.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (s == null)
				return false;
			tokenizer = new StringTokenizer(s);
		}
		return true;
	}

	String nextToken() {
		return seekForToken() ? tokenizer.nextToken() : null;
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBig() {
		return new BigInteger(nextToken());
	}
}


class Gauss {

	boolean NO_SOLUTION = false, INFMANY_SOLUTIONS = false;
	int DIMENSION = 0; // solution space dimension

	void RowSwap(BitSet [] a, int i, int j, int n) {
		BitSet tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	//a_0_0 * x1 + a_0_1 * x2 + ... + a_0_n-1 * xn = a_0_n
	//...
	//a_m-1_0 * x1 + ... + a_m-1_n-1_ * xn = a_m-1_n

	boolean [] solve(BitSet [] a, int m, int n) {
		int curRow = 0;
		boolean [] zeroCol = new boolean [n];
		for (int i = 0; i < n; i++) {
			int k = i;
			boolean bad = true;
			for (int j = curRow; j < m; j++) {
				if (a[j].get(i) || (bad == false && (a[j].get(i) && !a[k].get(i)))) {
					bad = false;
					k = j;
				}
			}
			if (bad) {
				zeroCol[i] = true;
				continue;
			}
			RowSwap(a, curRow, k, n);
			for (int r = 0; r < m; r++) { 
				if (r != curRow && a[r].get(i)) {
					a[r].xor(a[curRow]);
				}
			}
			curRow++;
		}

		for (int i = curRow; i < m; i++) {
			if (a[i].get(n)) {
				NO_SOLUTION = true;
				return null;
			}
		}

		int e = 0;
		boolean [] ans = new boolean [n];
		for (int i = 0; i < n; i++) {
			if (zeroCol[i]) {
				ans[i] = false;
				DIMENSION++;
			} else {
				ans[i] = a[e].get(n);
				e++;
			}	
		}

		INFMANY_SOLUTIONS = (DIMENSION > 0);
		return ans;
	}
	
	boolean check(boolean [][] a, int m, int n, boolean [] x) {
		boolean [] y = new boolean[m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				y[i] ^= a[i][j] & x[j];
			}
			if (a[i][n] != y[i]) return false;
		}	
		return true;
	}

}
