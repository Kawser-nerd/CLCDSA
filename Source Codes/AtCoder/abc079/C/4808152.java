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
		int numN = nextInt();

		out.println(chkA(numN) ? "Yes" : "No");
	}

	private boolean chkA(int num) {

		boolean isGoodnum = false;
		int cnt = 0;
		int previous = 0;
		for (int i = 0; num != 0; i++) {
			if (i == 0) {
				//???
				previous = num % 10;
				num /= 10;
				cnt = 1;
			} else {
				int current = num % 10;
				if (previous == current) {
					cnt++;
				} else {
					//count????
					cnt = 1;
				}
				previous = current;
				num /= 10;
			}
			if (cnt == 3) {
				isGoodnum = true;
			}
		}
		return isGoodnum;
	}

	private void solveB() {
		int numN = nextInt();

		if (numN == 1) {
			out.println(1);
			return;
		}

		long val1 = 2;
		long val2 = 1;
		long res = 0;
		for (int i = 0; i < numN - 1; i++) {
			res = val1 + val2;
			long temp = val1;
			val1 = val2;
			val2 = val2 + temp;
		}

		out.println(res);
	}

	private int[] convC(int num) {
		int[] wk = new int[4];
		for (int i = wk.length - 1; i >= 0; i--) {
			wk[i] = num % 10;
			num /= 10;
		}
		return wk;
	}

	private void solveC() {

		int num = nextInt();

		int[] args = convC(num);

		int[] wk = new int[4];

		int res = chkC(args, 0, wk, 0, 0);

		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < wk.length; i++) {
			if (i == 0) {
				builder.append(args[i]);
			} else {
				switch (wk[i]) {
				case 1:
					builder.append("+");
					break;
				case 2:
					builder.append("-");
					break;
				}
				builder.append(args[i]);
			}
		}

		builder.append("=7");
		out.println(builder.toString());
	}

	private int chkC(int[] args, int total, int[] wk, int currentI, int operand) {

		if (currentI >= 4) {
			return total;
		}
		if (currentI == 0) {
			total += args[0];
		} else {
			switch (operand) {
			case 1:
				total += args[currentI];
				wk[currentI] = operand;
				break;
			case 2:
				total -= args[currentI];
				wk[currentI] = operand;
				break;
			}
		}

		int val1 = chkC(args, total, wk, currentI + 1, 1);
		if (val1 == 7) {
			return 7;
		}
		int val2 = chkC(args, total, wk, currentI + 1, 2);
		if (val2 == 7) {
			return 7;
		}

		return -1;

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