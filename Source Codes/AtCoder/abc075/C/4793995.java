import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.stream.IntStream;
import java.util.stream.Stream;

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
		int numA = nextInt();
		int numB = nextInt();
		int numC = nextInt();

		if (numA == numB) {
			out.println(numC);
		} else if (numA == numC) {
			out.println(numB);
		} else if (numB == numC) {
			out.println(numA);
		}
	}

	private void solveB() {
		int numH = nextInt();
		int numW = nextInt();

		char[][] wk = IntStream.range(0, numH).map(i -> i).collect(() -> new char[numH][numW],
				(t, i) -> {
					t[i] = next().toCharArray();
				},
				(t, u) -> {
					Stream.concat(Arrays.stream(t), Arrays.stream(u));
				});

		StringBuilder builder = new StringBuilder();
		for (int j = 0; j < numH; j++) {
			builder.setLength(0);
			for (int k = 0; k < numW; k++) {
				if (wk[j][k] == '.') {
					int res = chkB(wk, j, k, numH, numW);
					builder.append(res);
				} else {
					builder.append(wk[j][k]);
				}
			}
			out.println(builder.toString());
		}

	}

	private int chkB(char[][] wk, int h, int w, int maxH, int maxW) {
		int[] CONST_H = new int[] { 1, 0, -1 };
		int[] CONST_W = new int[] { 1, 0, -1 };
		int res = 0;
		for (int i : CONST_H) {
			for (int j : CONST_W) {
				if (i == 0 && j == 0) {
					continue;
				}
				if (h + i >= 0 && h + i < maxH
						&& w + j >= 0 && w + j < maxW) {
					res += wk[h + i][w + j] == '#' ? 1 : 0;
				}
			}
		}
		wk[h][w] = (char) res;
		return res;
	}

	private void solveC() {
		int numN = nextInt();
		int numM = nextInt();

		int[][] wk = IntStream.range(0, numM).collect(() -> new int[numN][numN],
				(t, i) -> {
					int startN = nextInt();
					int endN = nextInt();
					t[startN - 1][endN - 1] = 1;
					t[endN - 1][startN - 1] = 1;
				}, (t, u) -> {
					Stream.concat(Arrays.stream(t), Arrays.stream(u)).toArray();
				});

		out.println(chkC(numN, wk, 0, 0));
	}

	private int chkC(int numN, int[][] wk, int i, int totalCnt) {
		if (i >= numN) {
			return totalCnt;
		}
		int[] wkArray = wk[i];
		int wkCnt = 0;
		int res = 0;
		int targetIndex = 0;
		for (int j = 0; j < wkArray.length; j++) {
			if (wkArray[j] != 0) {
				wkCnt++;
				targetIndex = j;
			}
		}
		if (wkCnt == 1) {
			wk[targetIndex][i] = 0;
			wk[i] = new int[numN];
			if (targetIndex < i) {
				res = chkC(numN, wk, targetIndex, totalCnt + 1);
			} else {
				res = chkC(numN, wk, i + 1, totalCnt + 1);
			}
			return res;
		} else {
			return chkC(numN, wk, i + 1, totalCnt);
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