import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.NoSuchElementException;

public class Main implements Runnable {

	public static void main(String[] args) {
		new Thread(null, new Main(), "", Runtime.getRuntime().maxMemory()).start();
	}

	public void run() {
		Scanner sc = new Scanner();
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();
		String str = sc.next();
		String[] h1 = hash(str.substring(0, n));
		String[] h2 = hash(reverse(str).substring(0, n));
		Arrays.sort(h1);
		Arrays.sort(h2);
		HashMap<String, Integer> m1 = new HashMap<>();
		for (int i = 0; i < h1.length; ++i) {
			int j = i;
			while (j + 1 < 1 << n && h1[i].equals(h1[j + 1]))
				++j;
			m1.put(h1[i], j - i + 1);
			i = j;
		}
		long ans = 0;
		for (int i = 0; i < h2.length; ++i) {
			int j = i;
			while (j + 1 < 1 << n && h2[i].equals(h2[j + 1]))
				++j;
			if (m1.containsKey(h2[i]))
				ans += (long) (j - i + 1) * m1.get(h2[i]);
			i = j;
		}
		pw.println(ans);
		pw.close();
	}

	String[] hash(String str) {
		int n = str.length();
		String[] ret = new String[1 << n];
		for (int s = 0; s < 1 << n; ++s) {
			for (int i = 0; i < n; ++i) {
				if (((1 << i) & s) > 0) {
					ret[s] = ret[s] + str.charAt(i);
				}
			}
			ret[s] += " ";
			for (int i = n - 1; i >= 0; --i) {
				if (((1 << i) & s) == 0) {
					ret[s] = ret[s] + str.charAt(i);
				}
			}
		}
		return ret;
	}

	String reverse(String str) {
		return new StringBuilder(str).reverse().toString();
	}

	class Scanner {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;

		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
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

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		private void skipUnprintable() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr]))
				ptr++;
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

		int nextInt() {
			return (int) nextLong();
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}