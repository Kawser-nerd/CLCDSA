import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	private static void solve() {
		int r = nei();
		int g = nei();
		int b = nei();
		int min = 0x7fffffff;
		if (r / 2 + 1 + g / 2 + 1 < 100 && g / 2 + 1 + b / 2 + 1 < 100) {
			for (int i = -101 - r / 2; i <= -99 - r / 2; i++) {
				int r1 = i;
				int r2 = i + r - 1;
				for (int j = -1 - g / 2; j <= 1 - g / 2; j++) {
					int g1 = j;
					int g2 = j + g - 1;
					for (int k = 99 - b / 2; k <= 101 - b / 2; k++) {
						int b1 = k;
						int b2 = k + b - 1;
						int c = cnt(r1, r2, -100) + cnt(g1, g2, 0) + cnt(b1, b2, 100);
						if (c < min)
							min = c;
					}
				}
			}
			kil(min);
		}
		for (int i = -500; i <= 500; i++) {
			int r1 = i;
			int r2 = i + r - 1;
			for (int j = r2 + 1; j <= 500; j++) {
				int g1 = j;
				int g2 = j + g - 1;
				for (int k = g2 + 1; k <= 500; k++) {
					int b1 = k;
					int b2 = k + b - 1;
					int c = cnt(r1, r2, -100) + cnt(g1, g2, 0) + cnt(b1, b2, 100);
					if (c < min)
						min = c;
				}
			}
		}
		out(min);
	}

	static int cnt(int min, int max, int center) {
		min -= center;
		max -= center;
		if (min <= 0 && max >= 0) {
			min = -min;
			return min * (min + 1) + max * (max + 1) >> 1;
		}
		if (min < 0)
			min = -min;
		if (max < 0)
			max = -max;
		if (min > max) {
			min ^= max;
			max ^= min;
			min ^= max;
		}
		return max * (max + 1) - min * (min - 1) >> 1;
	}

	static int gcd(int x, int y) {
		x = (x ^ x >> 31) - (x >> 31);
		y = (y ^ y >> 31) - (y >> 31);
		if (x < y) {
			x ^= y;
			y ^= x;
			x ^= y;
		}
		int z = x % y;
		if (z == 0)
			return y;
		return gcd(y, z);
	}

	static long gcd(long x, long y) {
		x = (x ^ x >> 63) - (x >> 63);
		y = (y ^ y >> 63) - (y >> 63);
		if (x < y) {
			x ^= y;
			y ^= x;
			x ^= y;
		}
		long z = x % y;
		if (z == 0)
			return y;
		return gcd(y, z);
	}

	static int lcm(int x, int y) {
		x = (x ^ x >> 31) - (x >> 31);
		y = (y ^ y >> 31) - (y >> 31);
		return x / gcd(x, y) * y;
	}

	static long lcm(long x, long y) {
		x = (x ^ x >> 63) - (x >> 63);
		y = (y ^ y >> 63) - (y >> 63);
		return x / gcd(x, y) * y;
	}

	static int abs(int x) {
		return x < 0 ? -x : x;
	}

	static long abs(long x) {
		return x < 0 ? -x : x;
	}

	static int min(int a, int b) {
		return a < b ? a : b;
	}

	static long min(long a, long b) {
		return a < b ? a : b;
	}

	static int max(int a, int b) {
		return a > b ? a : b;
	}

	static long max(long a, long b) {
		return a > b ? a : b;
	}

	static int clamp(int a, int min, int max) {
		return a < min ? min : a > max ? max : a;
	}

	static long clamp(long a, long min, long max) {
		return a < min ? min : a > max ? max : a;
	}

	static void out(String val) {
		IO.out(val);
	}

	static void out(Object val) {
		IO.out(String.valueOf(val));
	}

	static void out(int val) {
		IO.out(String.valueOf(val));
	}

	static void out(long val) {
		IO.out(String.valueOf(val));
	}

	static void out(char val) {
		IO.out(String.valueOf(val));
	}

	static void out(float val) {
		IO.out(String.valueOf(val));
	}

	static void out(double val) {
		IO.out(String.valueOf(val));
	}

	static void out(boolean val) {
		IO.out(String.valueOf(val));
	}

	static void kil(String val) {
		IO.out(val);
		IO.flush();
		System.exit(0);
	}

	static void kil(Object val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(int val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(long val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(char val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(float val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(double val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static void kil(boolean val) {
		IO.out(String.valueOf(val));
		IO.flush();
		System.exit(0);
	}

	static String nes() {
		return IO.next();
	}

	static int nei() {
		return IO.nextInt();
	}

	static long nel() {
		return IO.nextLong();
	}

	static String[] nss(int n) {
		String[] as = new String[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.next();
		}
		return as;
	}

	static int[] nis(int n) {
		int[] as = new int[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextInt();
		}
		return as;
	}

	static long[] nls(int n) {
		long[] as = new long[n];
		for (int i = 0; i < n; i++) {
			as[i] = IO.nextLong();
		}
		return as;
	}

	static String[][] nss2(int n, int m) {
		String[][] as = new String[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.next();
			}
		}
		return as;
	}

	static int[][] nis2(int n, int m) {
		int[][] as = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextInt();
			}
		}
		return as;
	}

	static long[][] nls2(int n, int m) {
		long[][] as = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				as[i][j] = IO.nextLong();
			}
		}
		return as;
	}

	static int parseInt(String val) {
		return Integer.parseInt(val);
	}

	static int parseInt(char val) {
		return Integer.parseInt(String.valueOf(val));
	}

	static long parseLong(String val) {
		return Long.parseLong(val);
	}

	public static void main(String[] args) {
		solve();
		IO.flush();
	}
}

final class IO {
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out, false);
	private static final byte[] buffer = new byte[1024];
	private static int ptr = 0;
	private static int len = 0;

	private static boolean hasNextByte() {
		if (ptr < len)
			return true;
		ptr = 0;
		try {
			len = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return len > 0;
	}

	private static int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	static boolean hasNext() {
		byte c;
		while (hasNextByte() && ((c = buffer[ptr]) < '!' || c > '~'))
			ptr++;
		return hasNextByte();
	}

	static String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (b >= '!' && b <= '~') {
			sb.append((char) b);
			b = readByte();
		}
		return sb.toString();
	}

	static long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		int sign = 1;
		int b = readByte();
		if (b == '-') {
			sign = -1;
			b = readByte();
		}
		if (b < '0' || '9' < b)
			throw new NumberFormatException();
		while (true) {
			if ('0' <= b && b <= '9')
				n = n * 10 + b - '0';
			else if (b == -1 || b < '!' || b > '~')
				return n * sign;
			else
				throw new NumberFormatException();
			b = readByte();
		}
	}

	static int nextInt() {
		if (!hasNext())
			throw new NoSuchElementException();
		int n = 0;
		int sign = 1;
		int b = readByte();
		if (b == '-') {
			sign = -1;
			b = readByte();
		}
		if (b < '0' || '9' < b)
			throw new NumberFormatException();
		while (true) {
			if ('0' <= b && b <= '9')
				n = n * 10 + b - '0';
			else if (b == -1 || b < '!' || b > '~')
				return n * sign;
			else
				throw new NumberFormatException();
			b = readByte();
		}
	}

	static void out(String val) {
		out.println(val);
	}

	static void flush() {
		out.flush();
	}
}