import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;


public class Main {

	private static int[] primes = sieveAtkin(100000);

	public static void main(String[] args) {
		
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		long[] s = sc.nextLongList(N);
		long[] t = new long[N];

		
		for (int i = 0; i < N; i ++) {
			if (s[i] == 1) {
				t[i] = 1;
				continue;
			}

			long x = s[i];
			long y = 1;
			for (int p : primes) {
				long q = (long)p * p * p;
				if (q > x) {
					break;
				}
				while (x % q == 0) {
					x /= q;
					s[i] /= q;
				}

				long sp = (long)p * p;
				if (s[i] % sp == 0) {
					y *= p;
					x /= sp;
				} else if (s[i] % p == 0) {
					y *= sp;
					x /= p;
				}
			}
			long rx = sqrtL(x);
			y *= rx < 0 ? x * x : rx; 
			t[i] = y;
		}

		Map<Long, Long> rev = new HashMap<>();
		Map<Long, Integer> map = new HashMap<>();
		for (int i = 0; i < N; i ++) {
			int a = !map.containsKey(s[i]) ? 0 : map.get(s[i]);
			int b = !map.containsKey(t[i]) ? 0 : map.get(t[i]);

			if (s[i] == 1) {
				map.put(s[i], a + 1);
				rev.put(1L, 1L);
			} else {

				map.put(s[i], a + 1);
				map.put(t[i], b);
				
				rev.put(s[i], t[i]);
				rev.put(t[i], s[i]);
			}
		}
		
		int count = 0;
		for (Long l : rev.keySet()) {
			if (l != 1L) {
				int max = Math.max(map.get(l), map.get(rev.get(l)));
				count += max;
			}
		}
		count /= 2;
		if (rev.containsKey(1L)) {
			count ++;
		}
		
		System.out.println(count);
		
	}
	
	public static long sqrtL(long N) {
		long left = (long)(Math.sqrt(N) * 0.99);
		long right = (long)(Math.sqrt(N) * 1.01);

		while (left <= right) {
			long mid = (left + right) / 2;
			long cmp = N - mid * mid;
			if (cmp == 0) {
				return mid;
			} else if (cmp > 0) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return -1;
	}
	
	public static int[] sieveAtkin(int size) {
		boolean[] isPrime = new boolean[size + 1];
		int sqrtN = (int) Math.sqrt(size);
		int n;
		for (int x = 1; x <= sqrtN; ++x) {
			for (int y = 1; y <= sqrtN; ++y) {
				n = 4 * x * x + y * y;
				if (n <= size && (n % 12 == 1 || n % 12 == 5)) {
					isPrime[n] = !isPrime[n];
				}
				n = 3 * x * x + y * y;
				if (n <= size && n % 12 == 7) {
					isPrime[n] = !isPrime[n];
				}
				n = 3 * x * x - y * y;
				if (x > y && n <= size && n % 12 == 11) {
					isPrime[n] = !isPrime[n];
				}
			}
		}

		for (n = 5; n <= sqrtN; ++n) {
			if (isPrime[n]) {
				for (int k = n * n; k <= size; k += n * n) {
					isPrime[k] = false;
				}
			}
		}
		isPrime[2] = isPrime[3] = true;
		
		int[] ret = new int[size];
		int count = 0;
		for (int i = 1; i < size; i ++) {
			if (isPrime[i]) {
				ret[count ++] = i;
			}
		}
		return Arrays.copyOf(ret, count);
	}
}



class FastScanner {
	public static String debug = null;

	private InputStream in = System.in;
	private int ptr = 0;
	private int buflen = 0;
	private byte[] buffer = new byte[1024];
	private boolean eos = false;

	public FastScanner() {
//		try {
//			this.in =new FileInputStream("13.txt");
//		} catch (Exception e) {
//		}
	}
	
	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				if (debug != null) {
					buflen = debug.length();
					buffer = debug.getBytes();
					debug = "";
					eos = true;
				} else {
					buflen = in.read(buffer);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen < 0) {
				eos = true;
				return false;
			} else if (buflen == 0) {
				return false;
			}
		}
		return true;
	}

	private int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
	}

	public boolean isEOS() {
		return this.eos;
	}

	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) {
			throw new NumberFormatException();
		}
		while (true) {
			if ('0' <= b && b <= '9') {
				n *= 10;
				n += b - '0';
			} else if (b == -1 || !isPrintableChar(b)) {
				return minus ? -n : n;
			} else {
				throw new NumberFormatException();
			}
			b = readByte();
		}
	}

	public int nextInt() {
		return (int) nextLong();
	}

	public long[] nextLongList(int n) {
		return nextLongTable(1, n)[0];
	}

	public int[] nextIntList(int n) {
		return nextIntTable(1, n)[0];
	}

	public long[][] nextLongTable(int n, int m) {
		long[][] ret = new long[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextLong();
			}
		}
		return ret;
	}

	public int[][] nextIntTable(int n, int m) {
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextInt();
			}
		}
		return ret;
	}
}