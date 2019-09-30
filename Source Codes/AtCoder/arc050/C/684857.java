import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/T1";

	FastScanner in;
	PrintWriter out;
	
	static long MOD;
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
					res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD; 
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
		
		static void debug(long[][] a) {
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a[i].length; j++) {
					System.out.print(a[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
	
	long gcd(long x, long y) {
		if (x == 0 || y == 0) return x + y;
		return gcd(y, x % y);
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
	

	void solve() {
		long A = in.nextLong(), B = in.nextLong();
		MOD = in.nextLong();
		
		long G = gcd(A, B);
		
		long[][] mat1 = {
				{10 % MOD, 1},
				{0, 1}
		};
		long[][] mat2 = {
				{POW(10, G), 1},
				{0, 1}
		};
		long[][] ans1 = Matrix_L.pow(mat1, A - 1);
		long[][] ans2 = Matrix_L.pow(mat2, B / G - 1);
		System.out.println((ans1[0][0] + ans1[0][1]) * (ans2[0][0] + ans2[0][1]) % MOD);
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
			//stream = new FileInputStream(new File("dec.in"));

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