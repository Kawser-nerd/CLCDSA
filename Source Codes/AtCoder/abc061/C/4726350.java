import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Arrays;
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
			//			solveC2();
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
		int numA = nextInt();
		int numB = nextInt();
		int numC = nextInt();

		out.println(numC >= numA && numC <= numB ? "Yes" : "No");

	}

	private void solveB() {
		int numN = nextInt();
		int numM = nextInt();

		int[] wk = new int[numN];

		for (int i = 0; i < numM; i++) {
			int a = nextInt();
			int b = nextInt();
			wk[a - 1]++;
			wk[b - 1]++;
		}

		Arrays.stream(wk).forEach(i -> out.println(i));
	}

	private void solveC() {
		int numN = nextInt();
		long numK = nextLong();

		int[][] wk = new int[numN][2];
		for (int i = 0; i < numN; i++) {
			wk[i][0] = nextInt();
			wk[i][1] = nextInt();
		}

		Arrays.sort(wk, (a, b) -> Integer.compare(a[0], b[0]));

		long sum = 0;
		for (int i = 0; i < wk.length; i++) {
			sum += wk[i][1];
			if (sum >= numK) {
				out.println(wk[i][0]);
				return;
			}
		}

	}

	private void solveC2() {
		int numN = nextInt();
		BigDecimal numK = new BigDecimal(next());

		String[][] wk = new String[numN][2];
		for (int i = 0; i < numN; i++) {
			wk[i][0] = next();
			wk[i][1] = next();
		}

		BigDecimal cnt = BigDecimal.ZERO;
		for (int i = 0; i < numN; i++) {
			cnt = cnt.add(new BigDecimal(wk[i][1]));
			if (cnt.compareTo(numK) >= 0) {
				out.println(wk[i][0]);
				return;
			}
		}
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