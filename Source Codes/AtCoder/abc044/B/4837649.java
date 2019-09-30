import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().solve();
	}

	private void solve() throws IOException {
		try {
			//			solveA();
			solveB();
			//			 solveC();
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
		int numN = nextInt();
		int numK = nextInt();
		int numX = nextInt();
		int numY = nextInt();

		long res = 0;
		if (numN < numK) {
			res += numN * numX;
		} else {
			res += numK * numX + (numN - numK) * numY;
		}

		out.println(res);
	}

	private void solveA2() {
		int numN = nextInt();
		int numK = nextInt();
		int numX = nextInt();
		int numY = nextInt();

		long res = 0;
		for (int i = 1; i <= Math.min(numN, numK); i++) {
			res += numX;
		}
		for (int i = numK + 1; i <= numN; i++) {
			res += numY;
		}

		out.println(res);
	}

	private void solveB() {
		String[] wk = next().split("");
		Map<String, Integer> res = Arrays.stream(wk).collect(() -> new HashMap<String, Integer>(),
				(t, i) -> {
					t.merge(i, 1, (oldV, newV) -> oldV + newV);
				},
				(t, u) -> {
					t.putAll(u);
				});

		boolean isJudge = true;
		for (Integer resV : res.values()) {
			if (resV % 2 != 0) {
				isJudge = false;
			}
		}

		out.println(isJudge ? "Yes" : "No");
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