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
			//			solveC();
			//			solveD();
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
		String res = next().substring(0, 1) + next().substring(0, 1) + next().substring(0, 1);

		out.println(res);
	}

	private void solveB() {
		long numA = nextLong();
		long numB = nextLong();
		long numX = nextLong();

		//		long max1 = numB % numX;
		//		long res1 = (numB - max1) / numX;
		long res1 = numB / numX;

		if (numA == 0) {
			out.println(res1 + 1);
		} else {
			//			long max2 = (numA - 1) % numX;
			//			long res2 = ((numA - 1) - max2) / numX;
			long res2 = (numA - 1) / numX;
			out.println(res1 - res2);
		}

	}

	private void solveB2() {
		long numA = nextLong();
		long numB = nextLong();
		long numX = nextLong();

		long cnt = 0;
		long wk = 1;
		long addC = 0;
		while (true) {
			wk = numX * addC;
			if (numA <= wk && wk <= numB) {
				cnt++;
			} else if (wk > numB) {
				break;
			}
			addC++;
		}

		out.println(cnt);
	}

	private void solveC() {
		int numN = nextInt();
		long numX = nextInt();
		long[] wk = new long[numN];
		long cnt = 0;
		for (int i = 0; i < numN; i++) {
			wk[i] = nextInt();
			if (i != 0) {
				if (wk[i] + wk[i - 1] > numX) {
					long diff = (wk[i] + wk[i - 1]) - numX;
					/*
					 * diff?wk[i]?????????????????
					 * numX=100
					 * wk[i]=10,wk[i-1]=99
					 */
					if (diff <= wk[i]) {
						wk[i] = wk[i] - diff;
					} else {
						/*
						 * wk[i]?0
						 * wk[i+1]????????????????wk[i-1]???????????
						 * wk[i-1]??????wk[i-2]+wk[i-1]?X???????????
						 */
						wk[i] = 0;
						wk[i - 1] = wk[i - 1] - (diff - wk[i]);
					}
					cnt += diff;
				}
			}
		}

		out.println(cnt);
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