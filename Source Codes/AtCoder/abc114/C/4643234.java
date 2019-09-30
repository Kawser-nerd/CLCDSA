import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().solve();
	}

	private void solve() throws IOException {
		try {
			//			solveA();
			//			solveB();
			//			solveC();
			solveC2();
			// solveD();
			// solveE();
			// solveF();
		} finally {
			if (in != null) {
				in.close();
			}
			if (out != null) {
				out.flush();
				out.close();
			}
		}

	}

	private void solveA() {
		int numN = Integer.parseInt(next());

		switch (numN) {
		case 7:
		case 5:
		case 3:
			out.print("YES");
			break;
		default:
			out.print("NO");
			break;
		}

		out.println("");
	}

	private void solveB() {
		String strN = next();

		int res = 99999999;
		for (int i = 0; i < strN.length() - 2; i++) {
			String wk = strN.substring(i, i + 3);
			int wkNum = Integer.parseInt(wk);
			res = Math.min(res, Math.abs(wkNum - 753));
		}

		out.println(res);
	}

	private boolean isOk(int x) {
		return hasX(x, 3) && hasX(x, 5) && hasX(x, 7);
	}

	private boolean hasX(int x, int num) {
		while (x != 0) {
			if (x % 10 == num) {
				return true;
			}
			x /= 10;
		}
		return false;
	}

	private void solveC() {
		int numN = Integer.parseInt(next());

		int res = 0;
		for (int i = 357; i <= numN; i++) {
			if (i % 2 == 0) {
				continue;
			} else {
				String wk = Integer.toString(i);
				int num7 = 0;
				int num5 = 0;
				int num3 = 0;
				if (wk.contains("9") || wk.contains("8") || wk.contains("6") || wk.contains("4") || wk.contains("2")
						|| wk.contains("1")) {
					continue;
				} else {
					if (wk.contains("7")) {
						num7++;
					}
					if (wk.contains("5")) {
						num5++;
					}
					if (wk.contains("3")) {
						num3++;
					}
				}
				if (num3 > 0 && num5 > 0 && num7 > 0) {
					res++;
				}
			}
		}

		out.println(res);
	}

	private void dfsSolveC2(long numN, long current) {
		if (current <= numN) {
			char[] wk = Long.toString(current).toCharArray();

			int num7 = 0;
			int num5 = 0;
			int num3 = 0;
			for (int i = 0; i < wk.length; i++) {
				if (wk[i] == '7') {
					num7++;
				} else if (wk[i] == '5') {
					num5++;
				} else if (wk[i] == '3') {
					num3++;
				}
			}
			if (num7 > 0 && num5 > 0 && num3 > 0) {
				resC2++;
			}
			dfsSolveC2(numN, 10 * current + 3);
			dfsSolveC2(numN, 10 * current + 5);
			dfsSolveC2(numN, 10 * current + 7);
		}
	}

	long resC2 = 0;

	private void solveC2() {
		long numN = Integer.parseInt(next());
		dfsSolveC2(numN, 0);

		out.println(resC2);
	}

	private void solveD() {
		int numN = Integer.parseInt(next());

		out.println("");
	}

	private void solveE() {
		int numN = Integer.parseInt(next());

		out.println("");
	}

	private void solveF() {
		int numN = Integer.parseInt(next());

		out.println("");
	}

	private final PrintWriter out = new PrintWriter(System.out);
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

	private static boolean isPrintableChar(int c) {
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

	public int nextInt() {
		return Integer.parseInt(next());
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
}