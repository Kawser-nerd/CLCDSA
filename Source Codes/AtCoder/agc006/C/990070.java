import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/D1";

	FastScanner in;
	PrintWriter out;

	public void solve() {
		int N = in.nextInt();
		long[] x = in.nextLongArray(N);
		int M = in.nextInt();
		long K = in.nextLong();
		int[] a = in.nextIntArray(M);
		
		long[] dy = new long[N-1];
		long[] nextDy = new long[N-1];
		for (int i = 0; i < N - 1; i++) {
			dy[i] = x[i+1] - x[i];
		}
		int[] mapping = new int[N - 1];
		int[] nextMapping = new int[N - 1];
		for (int i = 0; i < N - 1; i++) 
			mapping[i] = i;

		for (int i = 0; i < M; i++) {
			int idx = a[i] - 2;
			// swap
			int tmp = mapping[idx];
			mapping[idx] = mapping[idx+1];
			mapping[idx+1] = tmp;
		}
		while (K > 0) {
			if (K % 2 != 0) {
				for (int i = 0; i < N - 1; i++)	nextDy[i] = dy[mapping[i]];
				for (int i = 0; i < N - 1; i++) dy[i] = nextDy[i];				
			}
			for (int i = 0; i < N - 1; i++)	nextMapping[i] = mapping[mapping[i]];
			for (int i = 0; i < N - 1; i++)	mapping[i] = nextMapping[i];
			K >>= 1;
		}
//		System.out.println(Arrays.toString(mapping));
		
		long[] res = new long[N];
		res[0] = x[0];
		for (int i = 1; i < N; i++) {
			res[i] = res[i-1] + dy[i-1];
		}
		for (int i = 0; i < N; i++) {
			out.println(res[i]);
		}
		out.close();
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

		Thread t = new Thread(null, new Runnable() {
			
			@Override
			public void run() {
				solve();
			}
		}, "lul", 1 << 30);
		t.start();
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