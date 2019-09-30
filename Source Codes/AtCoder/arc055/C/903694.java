import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";

	void solver(String S) {
		int[] z1 = zalgo(S);
		int[] z2 = zalgo(reverse(S));
		long ret = 0;
		int L = S.length();
		// A B C | A(??i) C
		for (int i = 0; i < L; i++) {
			if (L - i < i) {
				int a = Math.min(z1[i], L - i - 1);
				int c = Math.min(z2[L - i], L - i - 1);
				if (a <= 0 || c <= 0)
					continue;
				int sup = a + c - (L - i);
				if (sup < 0)
					continue;
				ret += sup + 1;
			}
		}
		out.println(ret);
	}

	String reverse(String s) {
		char[] ori = s.toCharArray();
		char[] rev = new char[ori.length];
		for (int i = 0; i < ori.length; i++) {
			rev[i] = ori[ori.length - 1 - i];
		}
		return String.valueOf(rev);
	}

	int[] reverse(int[] a) {
		int[] ret = new int[a.length];
		for (int i = 0; i < a.length; i++) {
			ret[a.length - 1 - i] = a[i];
		}
		return ret;
	}

	int[] zalgo(String s) {
		int[] ret = new int[s.length()];
		ret[0] = s.length();
		int i = 1, j = 0;
		while (i < s.length()) {
			while (i + j < s.length() && s.charAt(j) == s.charAt(i + j))
				j++;
			ret[i] = j;
			if (j == 0) {
				i++;
				continue;
			}
			int k = 1;
			while (i + k < s.length() && k + ret[k] < j) {
				ret[i + k] = ret[k];
				k++;
			}
			i += k;
			j -= k;
		}
		return ret;
	}

	void run() {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		solver(ns());
		out.flush();

	}

	public static void main(String[] args) throws Exception {
		new Main().run();
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
		System.out.println(Arrays.deepToString(o));
	}
}