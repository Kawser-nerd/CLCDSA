import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
		int age = 0;

		age = Integer.parseInt(next());
		switch (age) {
		case 1:
			out.println("Hello World");
			break;
		case 2:
			int numA = nextInt();
			int numB = nextInt();
			out.println(numA + numB);
			break;
		}

	}

	private void solveB() {
		int numN = Integer.parseInt(next());
		int numT = Integer.parseInt(next());

		int[][] wk = new int[numN][2];

		for (int i = 0; i < wk.length; i++) {
			for (int j = 0; j < 2; j++) {
				wk[i][j] = nextInt();
			}
		}

		Arrays.sort(wk, (x, y) -> Integer.compare(x[1], y[1]));

		int cnt = 9999999;
		for (int i = 0; i < wk.length; i++) {
			if (wk[i][1] <= numT) {
				cnt = Math.min(wk[i][0], cnt);
			} else {
				break;
			}
		}

		out.println(cnt != 9999999 ? cnt : "TLE");
	}

	private void solveC2() {

		int numN = nextInt();
		int[] xA = new int[numN];
		int[] yA = new int[numN];
		long[] hA = new long[numN];
		for (int i = 0; i < numN; i++) {
			xA[i] = nextInt();
			yA[i] = nextInt();
			hA[i] = nextInt();
		}

		int candidateIndex = 0;
		while (hA[candidateIndex] == 0) {
			candidateIndex++;
		}

		long h = 0;
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++) {
				boolean isRes = true;
				h = hA[candidateIndex] + Math.abs(xA[candidateIndex] - i) + Math.abs(yA[candidateIndex] - j);
				for (int k = 0; k < numN; k++) {
					if (hA[k] != Math.max(h - Math.abs(xA[k] - i) - Math.abs(yA[k] - j), 0)) {
						isRes = false;
						break;
					}
				}
				if (isRes) {
					out.println(i + " " + j + " " + h);
					return;
				}
			}
		}
	}

	private void solveC() {
		int numN = Integer.parseInt(next());

		long[][] wk = new long[numN][3];

		for (int i = 0; i < numN; i++) {
			for (int j = 0; j < 3; j++) {
				wk[i][j] = nextLong();
			}
		}

		int candidateIndex = 0;
		while (wk[candidateIndex][2] == 0) {
			candidateIndex++;
		}

		long h = -1;
		for (long i = 0; i <= 100; i++) {
			for (long j = 0; j <= 100; j++) {
				boolean isRes = true;
				h = Math.abs(wk[candidateIndex][0] - i) + Math.abs(wk[candidateIndex][1] - j) + wk[candidateIndex][2];
				for (int k = 0; k < numN; k++) {
					if (wk[k][2] != Math.max(h - Math.abs(wk[k][0] - i) - Math.abs(wk[k][1] - j), 0)) {
						isRes = false;
						break;
					}
				}
				if (isRes) {
					System.out.println(i + " " + j + " " + h);
					return;
				}
			}
		}

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