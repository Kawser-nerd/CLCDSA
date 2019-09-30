import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Set;
import java.util.TreeMap;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.IntStream;

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
		int numR = nextInt();
		int numG = nextInt();
		int numB = nextInt();

		int num = (numR * 100 + numG * 10 + numB);

		out.println(num % 4 == 0 ? "YES" : "NO");
	}

	private void solveB() {
		int numN = nextInt();
		Map<Integer, Integer> wk = new TreeMap<Integer, Integer>();
		IntStream.range(0, numN).forEach(i -> wk.merge(nextInt(), 1, (oldV, newV) -> oldV + newV));

		AtomicInteger min = new AtomicInteger(Integer.MAX_VALUE);
		AtomicInteger max = new AtomicInteger(0);
		wk.keySet().stream().forEach(key -> {
			min.set(Math.min(min.intValue(), key));
			max.set(Math.max(max.intValue(), key));
		});

		out.println(max.intValue() - min.intValue());
	}

	private void solveC() {
		int numN = nextInt();

		//		Map<Integer, Integer> wk = new HashMap<Integer, Integer>();
		Set<Integer> set = new HashSet<>();
		int cnt = 0;
		for (int i = 0; i < numN; i++) {
			int key = nextInt();
			if (key < 400) {
				//				wk.merge(1, 1, (oldV, newV) -> oldV + newV);
				set.add(1);
			} else if (key < 800) {
				//				wk.merge(2, 1, (oldV, newV) -> oldV + newV);
				set.add(2);
			} else if (key < 1200) {
				//				wk.merge(3, 1, (oldV, newV) -> oldV + newV);
				set.add(3);
			} else if (key < 1600) {
				//				wk.merge(4, 1, (oldV, newV) -> oldV + newV);
				set.add(4);
			} else if (key < 2000) {
				//				wk.merge(5, 1, (oldV, newV) -> oldV + newV);
				set.add(5);
			} else if (key < 2400) {
				//				wk.merge(6, 1, (oldV, newV) -> oldV + newV);
				set.add(6);
			} else if (key < 2800) {
				//				wk.merge(7, 1, (oldV, newV) -> oldV + newV);
				set.add(7);
			} else if (key < 3200) {
				//				wk.merge(8, 1, (oldV, newV) -> oldV + newV);
				set.add(8);
			} else {
				cnt++;
			}

		}

		//		int min = wk.size() == 0 ? 1 : cnt;
		//		int max = wk.size() + cnt;
		//		int min = set.size() == 0 ? 1 : cnt;
		//		int max = set.size() + cnt;
		//		out.println(min + " " + max);
		if (set.size() == 0) {
			System.out.println("1 " + cnt);
		} else {
			System.out.println(set.size() + " " + (set.size() + cnt));
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