import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main{
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	static long MOD = 1_000_000_000 + 7;

	static void solver() {
		int h = ni();
		int w = ni();
		int a = ni();
		int b = ni();

		fact = new long[2 * 1_000_001];
		fact[0] = 1;
		fact[1] = 1;
		for (int i = 2; i < fact.length; i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}

		long m = nCk(h + w - 2, h - 1);
		long ans = m;
		for (int i = 0; i < b; i++) {
			ans -= nCk((h - a - 1) + i, i) % MOD * nCk(a - 1 + (w - 1 - i), a - 1) % MOD;
			while (ans < 0)
				ans += MOD;
		}

		out.println(ans % MOD);
	}

	static long[] fact;

	// 1~n?????k???????
	static long nCk(int n, int k) {
		if (n < k)
			return 0;
		else {
			return (fact[n] * inv(fact[n - k], MOD) % MOD * inv(fact[k], MOD) % MOD);
		}
	}

	static long inv(long a, long mod) {
		// if (gcd(a, mod) != 1)
		// throw new ArithmeticException("ax=1 mod m?gcd(a,x)!=1??????");
		a = a % mod;
		long b = mod;
		long p = 1, q = 0;
		// ? + qa = b
		// ? + pa = a (b>a)

		while (b > 1) {
			long c = b / a;
			b = b % a;
			q = q - p * c;
			long d = b;
			b = a;
			a = d;
			d = p;
			p = q;
			q = d;
		}
		while (q < 0)
			q += mod;
		return q;
	}

	public static void main(String[] args) throws Exception {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		solver();
		out.flush();
	}

	static long nl() {
		try {
			long num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}

	static char nc() {
		try {
			int b = skip();
			if (b == -1)
				return 0;
			return (char) b;
		} catch (IOException e) {
		}
		return 0;
	}

	static double nd() {
		try {
			return Double.parseDouble(ns());
		} catch (Exception e) {
		}
		return 0;
	}

	static String ns() {
		try {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			if (b == -1)
				return "";
			sb.append((char) b);
			while (true) {
				b = is.read();
				if (b == -1)
					return sb.toString();
				if (b <= ' ')
					return sb.toString();
				sb.append((char) b);
			}
		} catch (IOException e) {
		}
		return "";
	}

	public static char[] ns(int n) {
		char[] buf = new char[n];
		try {
			int b = skip(), p = 0;
			if (b == -1)
				return null;
			buf[p++] = (char) b;
			while (p < n) {
				b = is.read();
				if (b == -1 || b <= ' ')
					break;
				buf[p++] = (char) b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}

	public static byte[] nse(int n) {
		byte[] buf = new byte[n];
		try {
			int b = skip();
			if (b == -1)
				return null;
			is.read(buf);
			return buf;
		} catch (IOException e) {
		}
		return null;
	}

	static int skip() throws IOException {
		int b;
		while ((b = is.read()) != -1 && !(b >= 33 && b <= 126))
			;
		return b;
	}

	static boolean eof() {
		try {
			is.mark(1000);
			int b = skip();
			is.reset();
			return b == -1;
		} catch (IOException e) {
			return true;
		}
	}

	static int ni() {
		try {
			int num = 0;
			boolean minus = false;
			while ((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'))
				;
			if (num == '-') {
				num = 0;
				minus = true;
			} else {
				num -= '0';
			}

			while (true) {
				int b = is.read();
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}

	static void tr(Object... o) {
		if (INPUT.length() != 0)
			System.out.println(Arrays.deepToString(o));
	}

}