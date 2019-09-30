import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().solve();
	}

	private void solve() throws IOException {
		try {
			//			solveA();
			//			solveB();
			solveC();
			//			 solveD();
			//			 solveE();
			//			 solveF();
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
		String numN = next();

		out.println(numN.equals(new StringBuilder(numN).reverse().toString()) ? "Yes" : "No");
	}

	private void solveB() {
		int numA = nextInt();
		int numB = nextInt();
		int numC = nextInt();
		int numD = nextInt();

		int wkRes = Math.min(numB, numD) - Math.max(numA, numC);
		//wkRe?0?????????????????????????????
		out.println(wkRes >= 0 ? wkRes : 0);
	}

	private void solveC() {
		int numN = nextInt();

		BigDecimal[] times = new BigDecimal[numN];
		for (int i = 0; i < numN; i++) {
			times[i] = new BigDecimal(next());
		}

		/*
		 * ?????????
		 */
		if (times.length == 1) {
			out.println(times[0]);
			return;
		}

		BigDecimal res = BigDecimal.ZERO;
		for (int i = 1; i < times.length; i++) {
			if (i == 1) {
				res = getMinKoubaisu(times[i - 1], times[i]);
			} else {
				res = getMinKoubaisu(res, times[i]);
			}
		}

		out.println(res.longValue());
	}

	private BigDecimal getMinKoubaisu(BigDecimal val1, BigDecimal val2) {
		BigDecimal wk = getMaxKouyaku(val1, val2);
		return (val1.multiply(val2).divide(wk));
	}

	private BigDecimal getMaxKouyaku(BigDecimal val1, BigDecimal val2) {

		BigDecimal wkVal1 = val1.compareTo(val2) <= 0 ? val1 : val2;
		BigDecimal wkVal2 = val1.compareTo(val2) > 0 ? val1 : val2;
		BigDecimal amari = wkVal2.remainder(wkVal1);
		while (!amari.equals(BigDecimal.ZERO)) {
			wkVal2 = wkVal1;
			wkVal1 = amari;
			amari = wkVal2.remainder(wkVal1);
		}

		return wkVal1;
	}

	private void solveD() {
		int numN = nextInt();

		out.println("");
	}

	private void solveE() {
		int numN = nextInt();

		out.println("");
	}

	private void solveF() {
		int numN = nextInt();

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