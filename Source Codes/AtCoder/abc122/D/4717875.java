import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.regex.Pattern;

public class Main {

	static final Pattern p = Pattern.compile("(?:A.GC|AG.C)");

	static boolean ok(String last4) {
		return !(last4.contains("AGC") || last4.contains("GAC")
				|| last4.contains("ACG") || p.matcher(last4).matches());
	}

	static final String[] AGCT = {"A", "G", "C", "T"};
	static final int MOD = 1_000_000_007;

	static int recursive(int N, Map<Integer, Map<String, Integer>> memo,
			int current, String last3) {
		if (current == N) {
			return 1;
		}
		if (memo.getOrDefault(current, Collections.emptyMap())
				.get(last3) != null) {
			return memo.get(current).get(last3);
		}
		int result = 0;
		for (String c : AGCT) {
			String last4 = last3.concat(c);
			if (ok(last4)) {
				result = (result
						+ recursive(N, memo, current + 1, last4.substring(1)))
						% MOD;
			}
		}
		memo.computeIfAbsent(current, k -> new HashMap<>()).put(last3, result);
		return result;
	}

	static void exec(MyScanner in, PrintWriter out) {
		int N = in.nextInt();
		Map<Integer, Map<String, Integer>> memo = new HashMap<>();
		out.println(recursive(N, memo, 0, "TTT"));
	}

	public static void main(String[] args) {
		PrintWriter w = new PrintWriter(System.out);
		exec(new MyScanner(System.in), w);
		w.flush();
	}

	static class MyScanner {
		static final int BUFFER_SIZE = 1024;
		private final InputStream in;
		private final byte[] buffer = new byte[BUFFER_SIZE];
		private int point;
		private int readLength;
		MyScanner(InputStream in) {
			this.in = in;
		}
		private int readByte() {
			if (point < readLength) {
				int result = buffer[point];
				point += 1;
				return result;
			}
			try {
				readLength = in.read(buffer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (readLength == -1) {
				return -1;
			}
			point = 1;
			return buffer[0];
		}
		static boolean isPrintableCharExceptSpace(int c) {
			return 33 <= c && c <= 126;
		}
		String next() {
			StringBuilder b = new StringBuilder();
			int c = readByte();
			while (!(c == -1 || isPrintableCharExceptSpace(c))) {
				c = readByte();
			}
			if (c == -1) {
				throw new NoSuchElementException();
			}
			do {
				b.appendCodePoint(c);
				c = readByte();
			} while (c != -1 && isPrintableCharExceptSpace(c));
			return b.toString();
		}
		long nextLong() {
			int c = readByte();
			while (!(c == -1 || isPrintableCharExceptSpace(c))) {
				c = readByte();
			}
			if (c == -1) {
				throw new NoSuchElementException();
			}
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long result = 0L;
			do {
				if (!('0' <= c && c <= '9')) {
					throw new InputMismatchException();
				}
				result = result * 10L + (c - '0');
				c = readByte();
			} while (c != -1 && isPrintableCharExceptSpace(c));
			return minus ? -result : result;
		}
		int nextInt() {
			long n = nextLong();
			if (Integer.MIN_VALUE <= n && n <= Integer.MAX_VALUE) {
				return (int) n;
			}
			throw new InputMismatchException();
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}