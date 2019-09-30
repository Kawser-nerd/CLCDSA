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
			solveB();
			// solveC();
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
		int numX = Integer.parseInt(next());
		int numY = Integer.parseInt(next());

		out.print(numX + numY / 2);

		out.println("");
	}

	private void solveB() {
		int numN = Integer.parseInt(next());
		int numT = Integer.parseInt(next());
		int numA = Integer.parseInt(next());

		double[][] wk = new double[numN][2];

		int index = 0;
		double sabun = 999999999;
		for (int i = 0; i < wk.length; i++) {
			wk[i][0] = nextInt();
			wk[i][1] = numT - wk[i][0] * 0.006;
			if (Math.abs(numA - wk[i][1]) < sabun) {
				sabun = Math.abs(numA - wk[i][1]);
				index = i;
			}

		}

		out.println(index + 1);
	}

	private void solveC() {
		int numN = Integer.parseInt(next());

		out.println("");
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