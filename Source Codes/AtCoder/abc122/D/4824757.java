import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.regex.Pattern;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().solve();
	}

	private void solve() throws IOException {
		try {
			//			solveA();
			//			solveB();
			//			solveC();
			//			solveC3();
			solveD();
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
		String wk = next();
		if (wk.equals("A")) {
			out.println("T");
		} else if (wk.equals("T")) {
			out.println("A");
		} else if (wk.equals("G")) {
			out.println("C");
		} else if (wk.equals("C")) {
			out.println("G");
		}

	}

	private int getLength(String wk, int currentI, int total) {
		if (currentI >= wk.length()) {
			return total;
		}
		String wkS = wk.substring(currentI, currentI + 1);
		if (wkS.equals("A") || wkS.equals("T") || wkS.equals("G") || wkS.equals("C")) {
			return getLength(wk, currentI + 1, total) + 1;
		} else {
			return total;
		}
	}

	private void solveB() {
		String s = next();
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			int wkRes = getLength(s, i, 0);
			res = Math.max(wkRes, res);
		}

		out.println(res);
	}

	private int getLengthC(String wk, int currentI, int total) {
		if (currentI >= wk.length() - 1) {
			return total;
		}
		String wkS = wk.substring(currentI, currentI + 2);
		if (wkS.equals("AC")) {
			return getLengthC(wk, currentI + 2, total) + 1;
		} else {
			return getLengthC(wk, currentI + 1, total);
		}
	}

	Pattern p = Pattern.compile("AC");

	/**
	 * ????
	 * @param original
	 * @param old
	 * @param replace
	 * @return
	 */
	private String replaceByHand(final String original, final String old, final String replace) {
		int offset = 0;
		StringBuilder builder = new StringBuilder(original.length());
		int index;
		while (0 <= (index = original.indexOf(old, offset))) {
			builder.append(original, offset, index);
			builder.append(replace);
			offset = index + old.length();
		}
		builder.append(original, offset, original.length());
		return builder.toString();
	}

	/**
	 * ????
	 * @param wk
	 * @param start
	 * @param last
	 * @return
	 */
	private int getLengthC2(String wk, int start, int last) {
		int total = 0;
		//		wk = wk.substring(start, last);

		/**
		 * p8
		 */
		char[] wkL = wk.toCharArray();
		for (int i = start + 1; i < last;) {
			if (wkL[i] == 'C' && wkL[i - 1] == 'A') {
				total++;
				i += 2;
			} else {
				i++;
			}
		}

		/**
		 * p7
		 */
		//		total = (wk.length() - replaceByHand(wk, "AC", "").length()) / 2;

		/**
		 * p6
		 */
		//		String[] wkL = wk.split("");
		//		for (int i = start + 1; i < last;) {
		//			if (wkL[i].equals("C") && wkL[i - 1].equals("A")) {
		//				total++;
		//				i += 2;
		//			} else {
		//				i++;
		//			}
		//		}

		/**
		 * p5
		 */
		//		total = (wk.length() - wk.replaceAll("AC", "").length()) / 2;

		/**
		 * 4
		 */
		//		Matcher m = p.matcher(wk);
		//		int s = 0;
		//		while (m.find(s)) {
		//			total++;
		//			s = m.end();
		//		}

		/**
		 * p2
		 */
		//		if (wk.lastIndexOf("AC") == 3) {
		//			total = wk.split("AC").length;
		//		} else {
		//			total = wk.split("AC").length - 1;
		//		}

		/**
		 * p1
		 */
		//		total = (wk.length() - wk.replace("AC", "").length()) / 2;

		/**
		 * p1
		 */
		//		int num = 0;
		//		while (num != -1) {
		//			num = wk.indexOf("AC");
		//			if (num != -1) {
		//				total++;
		//				wk = wk.substring(2, wk.length());
		//			}
		//		}
		return total;
	}

	private void solveC() {
		int numN = nextInt();
		int numQ = nextInt();
		String strS = next();
		int[][] wk = new int[numQ][2];

		for (int i = 0; i < wk.length; i++) {
			wk[i][0] = nextInt();
			wk[i][1] = nextInt();
		}

		for (int[] is : wk) {
			//			String wkS = strS.substring(is[0] - 1, is[1]);
			int res = 0;
			//			for (int i = 0; i < wkS.length(); i++) {
			//				String firstS = wkS.substring(i, i + 1);
			//				boolean isNextA = firstS.equals("A");
			//				int wkRes = 0;
			//				if (isNextA) {
			//					wkRes = getLengthC(wkS, i, 0);
			//				}
			//				res = Math.max(wkRes, res);
			//			}
			res = getLengthC2(strS, is[0] - 1, is[1]);
			out.println(res);
		}

	}

	private void solveC3() {
		int numN = nextInt();
		int numQ = nextInt();
		String strS = next();
		int[][] wk = new int[numQ][2];

		for (int i = 0; i < wk.length; i++) {
			wk[i][0] = nextInt();
			wk[i][1] = nextInt();
		}

		/*
		 * ??????????????
		 * ???????????????A?C????????????
		 * A  C  A  C  T  A  C  G
		 * 0, 1, 1, 2, 2, 2, 3, 3
		 *
		 *
		 * ???????????
		 * ?????C????????????????A????????????????
		 * A  C  A  C  T  A  C  G
		 * 1, 1, 2, 2, 2, 3, 3, 3
		 */
		int[] wkA = new int[strS.length()];

		char[] wkL = strS.toCharArray();
		int cnt = 0;
		for (int i = 1; i < strS.length(); i++) {
			/*
			 * "AC"?????????????
			 * A?C????????????????"AC"?????????????????????????
			 * ?????A?????????????AC???????
			 * ?????C?????????????AC??????
			 * ?????A?????????????AC??????????????????????+????????-?????
			 * ?????C?????????????AC???????????????????-????
			 */

			if (wkL[i] == 'C' && wkL[i - 1] == 'A') {
				cnt++;
			}
			wkA[i] = cnt;

		}
		for (int[] is : wk) {
			int start = is[0];
			int last = is[1];

			int total = wkA[last - 1] - wkA[start - 1];

			out.println(total);
		}

	}

	/**
	 * A G C T  -
	 * 0 1 2 3 newC
	 *
	 * 012
	 * 021
	 * 102
	 * 0?12
	 * 01?2
	 *
	 * S + c3 + c2 + c1 + newC
	 */
	private void solveD() {
		int numN = nextInt();

		final long CONST_RES = (long) (Math.pow(10, 9) + 7);

		int[][][][] wk = new int[101][4][4][4];
		wk[0][3][3][3] = 1;

		for (int strLength = 0; strLength < numN; strLength++) {
			for (int c3 = 0; c3 < 4; c3++) {
				for (int c2 = 0; c2 < 4; c2++) {
					for (int c1 = 0; c1 < 4; c1++) {

						if (wk[strLength][c3][c2][c1] == 0)
							continue;

						for (int c0 = 0; c0 < 4; c0++) {

							if (c0 == 2 && c1 == 1 && c2 == 0)
								continue;
							if (c0 == 1 && c1 == 2 && c2 == 0)
								continue;
							if (c0 == 2 && c1 == 0 && c2 == 1)
								continue;
							if (c0 == 2 && c1 == 1 && c3 == 0)
								continue;
							if (c0 == 2 && c2 == 1 && c3 == 0)
								continue;

							wk[strLength + 1][c2][c1][c0] += wk[strLength][c3][c2][c1];
							wk[strLength + 1][c2][c1][c0] %= CONST_RES;
						}
					}
				}
			}
		}
		long res = 0;
		for (int c3 = 0; c3 < 4; c3++) {
			for (int c2 = 0; c2 < 4; c2++) {
				for (int c1 = 0; c1 < 4; c1++) {
					res += wk[numN][c3][c2][c1];
					res %= CONST_RES;
				}
			}
		}

		out.println(res);
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