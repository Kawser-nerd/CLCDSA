import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().solve();
	}

	private void solve() throws IOException {
		try {
			//			solveA();
			solveB();
			//			solveC();
			//			solveD();
			//			solveE();
			//			solveF();
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
		int numX = nextInt();
		int numY = nextInt();

		Map<Integer, Integer> wk = new HashMap<Integer, Integer>();
		wk.put(1, 1);
		wk.put(3, 1);
		wk.put(5, 1);
		wk.put(7, 1);
		wk.put(8, 1);
		wk.put(10, 1);
		wk.put(12, 1);
		wk.put(4, 2);
		wk.put(6, 2);
		wk.put(9, 2);
		wk.put(11, 2);
		wk.put(2, 3);
		out.println(wk.get(numX) == wk.get(numY) ? "Yes" : "No");
	}

	private void solveB() {
		int numH = nextInt();
		int numW = nextInt();

		IntStream.range(0, numH + 2).forEach(i -> {
			StringBuilder builder = new StringBuilder();

			char[] wk = new char[numW];
			if (i != 0 && i != numH + 1) {
				wk = next().toCharArray();
			}
			for (int j = 0; j < numW + 2; j++) {
				if (i == 0 || i == numH + 1) {
					builder.append("#");
					continue;
				}
				if (j == 0 || j == numW + 1) {
					builder.append("#");
				} else {
					builder.append(wk[j - 1]);
				}
			}

			out.println(builder.toString());
		});

		//		char[][] wk = new char[numH][numW];
		//
		//		for (int i = 0; i < numH; i++) {
		//			wk[i] = next().toCharArray();
		//		}
		//
		//		for (int i = 0; i < numH + 2; i++) {
		//			StringBuilder builder = new StringBuilder();
		//
		//			for (int j = 0; j < numW + 2; j++) {
		//				if (i == 0 || i == numH + 1) {
		//					builder.append("#");
		//					continue;
		//				}
		//				if (j == 0 || j == numW + 1) {
		//					builder.append("#");
		//				} else {
		//					builder.append(wk[i - 1][j - 1]);
		//				}
		//			}
		//
		//			out.println(builder.toString());
		//		}

	}

	private void solveC() {
		int numN = nextInt();

		out.println("");
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