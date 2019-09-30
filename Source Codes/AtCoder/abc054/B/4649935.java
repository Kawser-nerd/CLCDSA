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
		int alice = nextInt();
		int bob = nextInt();

		if (alice == bob) {
			out.println("Draw");
		} else if (alice == 1) {
			out.println("Alice");
		} else if (bob == 1) {
			out.println("Bob");
		} else if (alice != bob) {
			out.println(alice > bob ? "Alice" : "Bob");
		}

		out.println("");
	}

	private boolean chkB(String[] wkA, int currentA, String[] wkB, int aPos) {
		boolean res = false;

		if (wkA.length - currentA < wkB.length) {
//			memoB.put(currentA + ":" + aPos, false);
			return false;
		}
		if (wkA[currentA].length() - aPos < wkB[0].length()) {
//			memoB.put(currentA + ":" + aPos, false);
			return false;
		}
		//		if (memoB.getOrDefault(currentA + ":" + aPos, false)) {
		//			return memoB.get(currentA + ":" + aPos);
		//		}
		//???A???????
		//??????B?currentB???A?currentA?????????????
		//A????????-A??????????????????
		//B?currentB???A?currentA?????????????
		boolean aPosWk = wkA[currentA].startsWith(wkB[0], aPos);
		if (aPosWk) {
			//A????????currentA+1????????B??currentB+1?????????

			for (int i = 0; i < wkB.length; i++) {
				res = wkA[currentA + i].startsWith(wkB[0 + i], aPos);
				if (!res) {
					break;
				}
			}

		}
		//A?????????????aPos+1?????
		//??aPos??????????aPos?+1?????
		if (!res) {
			//B??currentB+1???????????????A??????
			int len = wkA[currentA].indexOf(wkB[0], aPos + 1);
			//???????????????
			if (len >= 0) {
				res = chkB(wkA, currentA, wkB, len);
			}

		}

		//aPos?0????????currentId?
		if (!res && aPos == 0) {
			//A?????????????currentA+1?????
			res = chkB(wkA, currentA + 1, wkB, 0);
		}
//		memoB.put(currentA + ":" + aPos, res);
		return res;
	}

//	Map<String, Boolean> memoB = new HashMap<String, Boolean>();

	private void solveB() {
		int numN = nextInt();
		int numM = nextInt();
		String[] wkA = new String[numN];
		String[] wkB = new String[numM];

		for (int i = 0; i < wkA.length; i++) {
			wkA[i] = next();
		}
		for (int i = 0; i < wkB.length; i++) {
			wkB[i] = next();
		}

		boolean res = chkB(wkA, 0, wkB, 0);
		out.println(res ? "Yes" : "No");
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