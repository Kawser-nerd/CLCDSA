import java.io.*;
import java.util.*;

public class Main {
	InputReader scn;
	PrintWriter out;
	String INPUT = "";

	void solve() {
		int n = scn.nextInt();
		String str = scn.next();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) {
			if(str.charAt(i) == 'E') {
				arr[i] = 1;
			} else {
				arr[i] = -1;
			}
		}
		
		int[] view = new int[n];
		int right = 0;
		if(arr[0] == 1) {
			right++;
		}
		for(int i = 1; i < n; i++) {
			view[i] += right;
			if(arr[i] == 1) {
				right++;
			}
		}
		
		int left = 0;
		if(arr[n - 1] == -1) {
			left++;
		}
		for(int i = n - 2; i >= 0; i--) {
			view[i] += left;
			if(arr[i] == -1) {
				left++;
			}
		}
		
		int min = n;
		for(int i = 0; i < n; i++) {
			min = Math.min(n - view[i] - 1, min);
		}
		
		out.println(min);
	}

	void run() throws Exception {
//		boolean onlineJudge = System.getProperty("ONLINE_JUDGE") != null;
		out = new PrintWriter(System.out);
		scn = new InputReader(true);
		long time = System.currentTimeMillis();
		solve();
		out.flush();
//		if (!onlineJudge) {
//			System.out.println(Arrays.deepToString(new Object[] { System.currentTimeMillis() - time + " ms" }));
//		}
	}

	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	class InputReader {
		InputStream is;

		public InputReader(boolean onlineJudge) {
			is = onlineJudge ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		}

		byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;

		int readByte() {
			if (lenbuf == -1)
				throw new InputMismatchException();
			if (ptrbuf >= lenbuf) {
				ptrbuf = 0;
				try {
					lenbuf = is.read(inbuf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}

		boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}

		int skip() {
			int b;
			while ((b = readByte()) != -1 && isSpaceChar(b))
				;
			return b;
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		char nextChar() {
			return (char) skip();
		}

		String next() {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}

		char[] next(int n) {
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(isSpaceChar(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}

		int nextInt() {
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}

		long nextLong() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}

			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}

		char[][] nextMatrix(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = next(m);
			return map;
		}

		int[] nextArray(int n, boolean isOneInd) {
			int k = isOneInd ? 1 : 0;
			int[] a = new int[n + k];
			for (int i = k; i < n + k; i++)
				a[i] = nextInt();
			return a;
		}

		int[] shuffle(int[] arr) {
			Random r = new Random();
			for (int i = 1, j; i < arr.length; i++) {
				j = r.nextInt(i);
				arr[i] = arr[i] ^ arr[j];
				arr[j] = arr[i] ^ arr[j];
				arr[i] = arr[i] ^ arr[j];
			}
			return arr;
		}
	}
}