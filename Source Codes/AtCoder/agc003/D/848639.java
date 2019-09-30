import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map.Entry;

public class Main {
	InputStream is;

	int __t__ = 1;
	int __f__ = 0;
	int __FILE_DEBUG_FLAG__ = __f__;
	String __DEBUG_FILE_NAME__ = "src/D3";

	FastScanner in;
	PrintWriter out;
	
	static final int PRIME_CUBE_ROOT_SIZE = 200;
	static final int PRIME_LIST_SIZE = 100000;
	static int[] primeList;
	static HashMap<Long, Integer> primeSquares = new HashMap<>();
	static {
		primeList = getPrimeList(PRIME_LIST_SIZE);
	}
	
	static int[] getPrimeList(int n) {
		boolean[] res = new boolean[n+1];
		int[] primeList = new int[n+1];
		int at = 0;
		
		Arrays.fill(res, true);

		res[0] = res[1] = false;
		for (int i = 2; i < res.length; i++) {
			if (!res[i]) continue;
			primeList[at++] = i;
			primeSquares.put((long)i * i, i);
			for (int j = 2 * i; j < res.length; j += i) {
				res[j] = false;
			}
		}
		
		return Arrays.copyOf(primeList, at);
	}
	
	long flipKey(long key) {
		long res = 1;
		
		for (int p : primeList) {
			long p2 = (long) p * p;
			if (key % p2 == 0)
				res *= p;
			else if (key % p == 0)
				res *= p2;
		}
		return res;
	}
	
	public void solve() {
		int N = in.nextInt();
		long[] s = in.nextLongArray(N);
		
		for (int i = 0; i < N; i++) {
			StringBuilder key = new StringBuilder();
			for (int j = 0; j < PRIME_CUBE_ROOT_SIZE; j++) {
				long p = primeList[j];
				long p3 = p * p * p;
				if (p3 >= (long)1e10) break;
				while (s[i] % p3 == 0) s[i] /= p3;				
			}
		}
		
		Arrays.sort(s);
		// System.out.println(Arrays.toString(s));
		HashMap<Long, Integer> map = new HashMap<>();
		for (int i = 0; i < N; i++) {
			if (map.containsKey(s[i]))
				map.put(s[i], map.get(s[i]) + 1);
			else
				map.put(s[i], 1);
		}
		
		int res = 0;
		for (Entry<Long, Integer> e : map.entrySet()) {
			if (e.getValue() == -1) continue;
			if (e.getKey() == 1) {
				res++;
				continue;
			}
			
			long current = e.getKey();
			long oppKey = 1;
			for (int i = 0; i < PRIME_CUBE_ROOT_SIZE; i++) {
				long p = primeList[i];
				long p2 = p * p;
				if (current % p2 == 0) {
					current /= p2;
					oppKey *= p;
				} else if (current % p == 0) {
					current /= p;
					oppKey *= p2;
				}
			}

			if (primeSquares.containsKey(current))
				oppKey *= primeSquares.get(current);
			else
				oppKey *= current * current;
			
			// System.out.println(e.getKey() + " " + oppKey);
			if (!map.containsKey(oppKey)) {
				res += e.getValue();
			} else {
				res += Math.max(e.getValue(), map.get(oppKey));
				map.put(e.getKey(), -1);
				map.put(oppKey, -1);
			}
		}
		System.out.println(res);
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
		}, "lul", 1 << 27);
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