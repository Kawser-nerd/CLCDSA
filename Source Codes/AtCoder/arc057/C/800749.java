import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.NoSuchElementException;

public class Main {
	private static void solve() {
		String k = next();
		BigInteger a1 = new BigInteger(k);
		BigInteger a2 = a1.add(BigInteger.ONE);
		BigInteger hd = BigInteger.valueOf(100);
		a1 = a1.pow(2);
		a2 = a2.pow(2).subtract(BigInteger.ONE);
		boolean flg = false;
		while (true) {
			boolean flg2 = flg || !a1.mod(hd).equals(BigInteger.ZERO);
			if (a1.divide(hd).compareTo(BigInteger.ZERO) == 0 || a1.divide(hd).compareTo(a2.divide(hd)) == 0 && flg2)
				break;
			flg = flg2;
			a1 = a1.divide(hd);
			a2 = a2.divide(hd);
		}
		BigInteger res = flg ? a1.add(BigInteger.ONE) : a1;
		out(res.toString());
	}

	static int abs(int x) {
		return x < 0 ? -x : x;
	}

	static int gcd(int x, int y) {
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

	static int clamp(int a, int min, int max) {
		return a < min ? min : a > max ? max : a;
	}

	static int max(int a, int b) {
		return a > b ? a : b;
	}

	static int min(int a, int b) {
		return a < b ? a : b;
	}

	static long max(long a, long b) {
		return a > b ? a : b;
	}

	static long min(long a, long b) {
		return a < b ? a : b;
	}

	static void out(String val) {
		IO.out(val);
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

	static String next() {
		return IO.next();
	}

	static int nextInt() {
		return IO.nextInt();
	}

	static long nextLong() {
		return IO.nextLong();
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

final class UnionFind {
	int[] data;

	UnionFind(int n) {
		data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = -1;
		}
	}

	boolean union(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y)
			return false;
		if (data[y] < data[x]) {
			x ^= y;
			y ^= x;
			x ^= y;
		}
		data[x] += data[y];
		data[y] = x;
		return true;
	}

	boolean find(int x, int y) {
		return root(x) == root(y);
	}

	int root(int x) {
		return data[x] < 0 ? x : (data[x] = root(data[x]));
	}

	int size(int x) {
		return -data[root(x)];
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