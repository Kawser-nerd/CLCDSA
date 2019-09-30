import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) throws IOException {
		//		new Main().solveA();
		//		new Main().solveB();
		//		new Main().solveC();
		//		new Main().solveD();
		new Main().solveD2();
		//		new Main().solveE();
		//		new Main().solveF();
	}

	private void solveA() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println(numN / 3);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			Set<String> wkSet = new HashSet<String>();
			for (int i = 0; i < numN; i++) {
				wkSet.add(scanner.next());
			}

			System.out.println(wkSet.size() == 3 ? "Three" : "Four");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			String[] wk = new String[numN];

			Map<String, Long> wkMap = new HashMap<String, Long>();
			wkMap.put("M", (long) 0);
			wkMap.put("A", (long) 0);
			wkMap.put("R", (long) 0);
			wkMap.put("C", (long) 0);
			wkMap.put("H", (long) 0);
			for (int i = 0; i < wk.length; i++) {
				wk[i] = scanner.next();
				if (wk[i].startsWith("M")) {
					wkMap.put("M", wkMap.get("M") + 1);
				} else if (wk[i].startsWith("A")) {
					wkMap.put("A", wkMap.get("A") + 1);
				} else if (wk[i].startsWith("R")) {
					wkMap.put("R", wkMap.get("R") + 1);
				} else if (wk[i].startsWith("C")) {
					wkMap.put("C", wkMap.get("C") + 1);
				} else if (wk[i].startsWith("H")) {
					wkMap.put("H", wkMap.get("H") + 1);
				}
			}

			long res = 0;
			res += wkMap.get("M") * wkMap.get("A") * wkMap.get("R");
			res += wkMap.get("M") * wkMap.get("A") * wkMap.get("C");
			res += wkMap.get("M") * wkMap.get("A") * wkMap.get("H");

			res += wkMap.get("M") * wkMap.get("R") * wkMap.get("C");
			res += wkMap.get("M") * wkMap.get("R") * wkMap.get("H");

			res += wkMap.get("M") * wkMap.get("C") * wkMap.get("H");

			res += wkMap.get("A") * wkMap.get("R") * wkMap.get("C");
			res += wkMap.get("A") * wkMap.get("R") * wkMap.get("H");

			res += wkMap.get("A") * wkMap.get("C") * wkMap.get("H");

			res += wkMap.get("R") * wkMap.get("C") * wkMap.get("H");

			System.out.println(res);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private int examD(int[] pre, int start, int end, Map<Integer, int[]> wkMap, int numD) {

		int res = 0;

		int[] wk = wkMap.get(start);

		if (start == end) {
			res = (Math.abs(wk[0] - pre[0]) + Math.abs(wk[1] - pre[1]));
		} else {
			res = examD(wk, start + numD, end, wkMap, numD) + (Math.abs(wk[0] - pre[0]) + Math.abs(wk[1] - pre[1]));
		}
		return res;
	}

	private void solveD() throws IOException {
		//		Scanner scanner = null;
		int numH = 0;
		int numW = 0;
		int numD = 0;

		try {
			numH = Integer.parseInt(next());
			numW = Integer.parseInt(next());
			numD = Integer.parseInt(next());

			Map<Integer, int[]> wkMap = new HashMap<Integer, int[]>(1000000);
			for (int i = 0; i < numH; i++) {
				for (int j = 0; j < numW; j++) {
					wkMap.put(Integer.parseInt(next()), new int[] { i, j });
				}
			}

			int numQ = Integer.parseInt(next());

			int[] res = new int[numQ];
			/**
			 * ??version
			 */
			//			for (int i = 0; i < numQ; i++) {
			//				int numL = scanner.nextInt();
			//				int numR = scanner.nextInt();
			//				res[i] = examD(wkMap.get(numL), numL, numR, wkMap, numD);
			//			}

			/**
			 * ????????version
			 */
			int[] pre = null;
			int[] wk = null;
			int numL = 0;
			int numR = 0;
			int numRes = 0;

			int start = 0;
			int end = 0;
			for (int i = 0; i < numQ; i++) {
				numL = Integer.parseInt(next());
				numR = Integer.parseInt(next());
				numRes = 0;

				start = numL;
				end = numR;
				pre = wkMap.get(start);
				wk = wkMap.get(start);
				while (true) {

					numRes += (Math.abs(wk[0] - pre[0]) + Math.abs(wk[1] - pre[1]));
					if (start < end) {
						pre = wkMap.get(start);
						start = start + numD;
					} else {
						break;
					}
					wk = wkMap.get(start);
				}

				res[i] = numRes;
			}

			for (int i = 0; i < res.length; i++) {
				out.println(res[i]);
			}

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

	private void solveD2() throws IOException {
		//		Scanner scanner = null;
		int numH = 0;
		int numW = 0;
		int numD = 0;

		try {
			numH = Integer.parseInt(next());
			numW = Integer.parseInt(next());
			numD = Integer.parseInt(next());

			Map<Integer, int[]> wkMap = new HashMap<Integer, int[]>(1000000);
			for (int i = 0; i < numH; i++) {
				for (int j = 0; j < numW; j++) {
					wkMap.put(Integer.parseInt(next()), new int[] { i, j });
				}
			}

			int[] wkArray = new int[(numH * numW) + 1];
			Arrays.fill(wkArray, 0);
			for (int i = 1; i <= (numH * numW) - numD; i++) {
				int[] pre = wkMap.get(i);
				int[] aft = wkMap.get(i + numD);
				int numRes = (Math.abs(aft[0] - pre[0]) + Math.abs(aft[1] - pre[1])) + wkArray[i];
				wkArray[i + numD] = numRes;
			}

			int numQ = Integer.parseInt(next());

			int[] res = new int[numQ];

			int numL = 0;
			int numR = 0;

			for (int i = 0; i < numQ; i++) {
				numL = Integer.parseInt(next());
				numR = Integer.parseInt(next());

				res[i] = wkArray[numR] - wkArray[numL];
			}

			for (int i = 0; i < res.length; i++) {
				out.println(res[i]);
			}

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

	private void solveE() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveF() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
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