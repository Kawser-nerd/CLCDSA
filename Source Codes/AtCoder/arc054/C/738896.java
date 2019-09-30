import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/C1";

	FastScanner in;
	PrintWriter out;

	/* MOD_CALCULATION */
	int MOD = 2;
	long ADD(long a, long b) { 
		return (a % MOD + b % MOD) % MOD;
	}
	
	long SUB(long a, long b) { 
		return (a % MOD - b % MOD + MOD) % MOD;
	}	

	long MULT(long a, long b) {
		return ((a % MOD) * (b % MOD)) % MOD;
	}

	long POW(long a, long x) {
		long res = 1;
		for ( ; x > 0; x >>= 1) {
			if (x % 2 == 1) res = MULT(res, a);
			a = MULT(a, a);
		}
		
		return res;
	}
	
	long DIV(long a, long b) {
		return MULT(a, POW(b, MOD - 2));
	}
	/* end */
	
	// Matrix Calculator (long)
	static class Matrix_L {
		static long[][] add(long[][] a, long[][] b) {
			int n1 = a.length, m1 = a[0].length;
			int n2 = b.length, m2 = b[0].length;			
			if (n1 != n2 || m1 != m2) throw new RuntimeException();			

			long[][] res = new long[n1][m1];
			
			for (int i = 0; i < n1; i++) for (int j = 0; j < m1; j++) {
				res[i][j] = a[i][j] + b[i][j];
			}
			
			return res;
		}
		
		static long[][] sub(long[][] a, long[][] b) {
			int n1 = a.length, m1 = a[0].length;
			int n2 = b.length, m2 = b[0].length;			
			if (n1 != n2 || m1 != m2) throw new RuntimeException();			

			long[][] res = new long[n1][m1];
			
			for (int i = 0; i < n1; i++) for (int j = 0; j < m1; j++) {
				res[i][j] = a[i][j] - b[i][j];
			}
			
			return res;
		}
		
		static long[][] mult(long[][] a, long[][] b) {
			int n1 = a.length, m1 = a[0].length;
			int n2 = b.length, m2 = b[0].length;
			if (n1 != m2 || n2 != m1) throw new RuntimeException();			

			long[][] res = new long[n1][m2];
			
			for (int i = 0; i < n1; i++) for (int j = 0; j < m2; j++) {
				for (int k = 0; k < m1; k++) {
					res[i][j] = (res[i][j] + a[i][k] * b[k][j]); 
				}
			}

			return res;
		}
		
		static long[][] pow(long[][] a, long N) {
			int n = a.length, m = a[0].length;
			if (n != m) throw new RuntimeException();
			
			long[][] tmp = new long[n][n];
			long[][] res = new long[n][n];
			
			for (int i = 0; i < n; i++) res[i][i] = 1;					
			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
				tmp[i][j] = a[i][j];
						
			while (N > 0) {
				if (N % 2 == 1) res = mult(res, a);
				
				N /= 2;
				a = mult(a, a);
			}
			
			return res;
		}
		
		static double[][] gauss_jordan(long[][] a) {
			return gauss_jordan(a, new long[a.length]);
		}
		
		// ax = b????Ax=b????????????C={A,B}???
		static double[][] gauss_jordan(long[][] a, long[] b) {
			assert a.length == a[0].length;
			int n = a.length;
			double[][] res = new double[n][n+1];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					res[i][j] = a[i][j];
				}
				res[i][n] = b[i];				
			}
			
			for (int i = 0; i < n; i++) {
				int pivot = i;
				for (int j = i + 1; j < n; j++) {
					if (Math.abs(res[j][i]) > Math.abs(res[pivot][i])) 
						pivot = j;
				}
				
				if (Math.abs(res[pivot][i]) < 1e-9) continue;
				{ // swap
					double[] tmp = res[i]; 
					res[i] = res[pivot]; 
					res[pivot] = tmp; 
				}
				
				for (int j = 0; j < n; j++) if (i != j) {
					double rate = (double) res[j][i] / res[i][i];
					for (int k = 0; k < n + 1; k++) {
						res[j][k] -= res[i][k] * rate;
					}
				}
			}
			return res;
		}
		
		static void debug(long[][] a) {
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					System.out.print(a[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
	long[][] gauss_jordan(long[][] a, long[] b) {
		assert a.length == a[0].length;
		int n = a.length;
		long[][] res = new long[n][n+1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res[i][j] = a[i][j];
			}
			res[i][n] = b[i];				
		}
		
		for (int i = 0; i < n; i++) {
			int pivot = i;
			for (int j = i + 1; j < n; j++) {
				if (Math.abs(res[j][i]) > Math.abs(res[pivot][i])) 
					pivot = j;
			}
			
			if (Math.abs(res[pivot][i]) < 1e-9) continue;
			{ // swap
				long[] tmp = res[i]; 
				res[i] = res[pivot]; 
				res[pivot] = tmp;
			}
			
			for (int j = 0; j < n; j++) if (i != j) {
				long rate = DIV(res[j][i], res[i][i]);
				for (int k = 0; k < n + 1; k++) {
					res[j][k] = (res[j][k] - res[i][k] * rate + MOD) % MOD;
				}
			}
		}
		return res;
	}
	void solve() {
		int n = in.nextInt();
		long[][] a = new long[n][n];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			for (int j = 0; j < n; j++) {
				a[i][j] = s.charAt(j) - '0';
			}
		}
		long[][] mat = gauss_jordan(a, new long[n]);
		
		int res = 1;
		for (int i = 0; i < n; i++) {
			//System.out.println(Arrays.toString(mat[i]));
			res *= Math.abs(mat[i][i]) % 2;			
		}
		System.out.println(res % 2 == 0 ? "Even" : "Odd");		
	}

	public void run() {
		if (__FILE_DEBUG_FLAG__ == __t__) {
			try {
				is = new FileInputStream(__DEBUG_FILE_NAME__);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			System.out.println("FILE_INPUT!");
		} else {
			is = System.in;
		}
		in = new FastScanner(is);
		out = new PrintWriter(System.out);

		solve();
	}

	public static void main(String[] args) {
		new Main().run();
	}

	public void mapDebug(int[][] a) {
		System.out.println("--------map display---------");

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.printf("%3d ", a[i][j]);
			}
			System.out.println();
		}

		System.out.println("----------------------------");
		System.out.println();
	}

	public void debug(Object... obj) {
		System.out.println(Arrays.deepToString(obj));
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			// stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextIntArray(int n) {
			int[] array = new int[n];
			for (int i = 0; i < n; i++)
				array[i] = nextInt();

			return array;
		}

		int[][] nextIntMap(int n, int m) {
			int[][] map = new int[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextIntArray(m);
			}
			return map;
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		long[] nextLongArray(int n) {
			long[] array = new long[n];
			for (int i = 0; i < n; i++)
				array[i] = nextLong();

			return array;
		}

		long[][] nextLongMap(int n, int m) {
			long[][] map = new long[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextLongArray(m);
			}
			return map;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		double[] nextDoubleArray(int n) {
			double[] array = new double[n];
			for (int i = 0; i < n; i++)
				array[i] = nextDouble();

			return array;
		}

		double[][] nextDoubleMap(int n, int m) {
			double[][] map = new double[n][m];
			for (int i = 0; i < n; i++) {
				map[i] = in.nextDoubleArray(m);
			}
			return map;
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String[] nextStringArray(int n) {
			String[] array = new String[n];
			for (int i = 0; i < n; i++)
				array[i] = next();

			return array;
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
}