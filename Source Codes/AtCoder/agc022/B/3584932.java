import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main {

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() {
		PrintWriter pw = new PrintWriter(System.out);
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		if (N == 3) {
			System.out.println(2 + " " + 5 + " " + 63);
			return;
		}
		N -= 4;
		System.out.print(2 + " " + 4 + " " + 3 + " " + 9 + (N == 0 ? "\n" : " "));
		int MAX = 30000;
		for (int i = 8; i <= MAX && N >= 2; i += 6) {
			System.out.print(i + " " + (i + 2));
			N -= 2;
			System.out.print(N == 0 ? "\n" : " ");
		}
		for (int i = 15; i <= MAX && N >= 2; i += 12) {
			System.out.print(i + " " + (i + 6));
			N -= 2;
			System.out.print(N == 0 ? "\n" : " ");
		}
		for (int i = 6; i <= MAX && N >= 1; i += 6) {
			System.out.print(i);
			N -= 1;
			System.out.print(N == 0 ? "\n" : " ");
		}
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

	class Scanner {
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

		private boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}

		public boolean hasNext() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr]))
				ptr++;
			return hasNextByte();
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

		public int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
				throw new NumberFormatException();
			return (int) nl;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}

}