import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.OptionalLong;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().solve();
	}

	private void solve() throws IOException {
		try {
			//			solveA();
			//			solveB();
			//			solveC();
			solveC2();
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

		out.println((numA + numB) % 24);
	}

	private void solveB() {
		int numN = nextInt();
		int numM = nextInt();

		int[][] ab = new int[numN][2];

		IntStream.range(0, numN).forEach(i -> {
			ab[i][0] = nextInt();
			ab[i][1] = nextInt();
		});

		int[][] cd = new int[numM][2];

		IntStream.range(0, numM).forEach(i -> {
			cd[i][0] = nextInt();
			cd[i][1] = nextInt();
		});

		for (int[] js : ab) {
			int res = Integer.MAX_VALUE;
			int index = -1;
			for (int j = 0; j < cd.length; j++) {
				int wk = Math.abs(js[0] - cd[j][0]) + Math.abs(js[1] - cd[j][1]);
				if (wk < res) {
					res = wk;
					index = j;
				}
			}
			out.println(index + 1);
		}

	}

	/**
	 * numN = A * B
	 * numN???????
	 */
	private void solveC() {
		long numN = nextLong();

		//		Map<Long, Long> wk = new HashMap<Long, Long>();
		//		for (long i = 1; i < numN; i++) {
		//			if (numN % i == 0) {
		//				wk.put((long) i, numN / i);
		//			}
		//		}

		Map<Long, Long> wk = LongStream.range(1, numN).filter(i -> numN % i == 0)
				.collect(
						() -> new HashMap<Long, Long>(),
						(t, i) -> t.put((long) i, numN / i),
						(t, u) -> t.putAll(u));

		//		long res = Long.MAX_VALUE;
		//		for (Entry<Long, Long> en : wk.entrySet()) {
		//			res = Math.min(res, chkDigit(Math.max(en.getKey(), en.getValue())));
		//		}

		OptionalLong hoge = wk.entrySet().stream().mapToLong(entryS -> chkDigit(Math.max(entryS.getKey(), entryS.getValue()))).min();

		out.println(hoge.getAsLong());
	}

	/**
	 * ????????
	 * numN = A * B = B * A
	 * ???????
	 * digits(A) <= digits(B)????????????????
	 */
	private void solveC2() {
		long numN = nextLong();

		long res = Long.MAX_VALUE;
		/*
		 * ??????????????????????????
		 * ?????A*B=B*A?????????wkA???????
		 *  1* 16 ??????? 16*1???????????
		 */
		long wkA = 1;
		long wkB = numN / 1;
		while (wkA <= wkB) {
			if (numN % wkA == 0) {
				res = Math.min(res, Math.max(chkDigit(wkA), chkDigit(wkB)));
			}
			wkA++;
			wkB = numN / wkA;
		}

		//		for (long i = 1; i < numN; i++) {
		//			long wkA = i;
		//			long wkB = numN / i;
		//
		//			/*
		//			 * ??????????????????????????
		//			 * ?????A*B=B*A?????????i???????
		//			 *  1* 16 ??????? 16*1???????????
		//			 */
		//
		//			if (wkA > wkB) {
		//				break;
		//			}
		//			if (numN % i == 0) {
		//				res = Math.min(res, Math.max(chkDigit(wkA), chkDigit(wkB)));
		//			}
		//		}

		out.println(res);
	}

	private int chkDigit(double num) {
		int cnt = 0;
		long wk = (long) num;
		while (wk != 0) {
			cnt++;
			wk /= 10;
		}
		return cnt;
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