import java.util.*;
import java.io.*;

public class Main {
    private static IO io = new IO();
    
    public static void main(String[] args) {

    	long Ax = io.nextLong();
    	long Ay = io.nextLong();
    	long Bx = io.nextLong();
    	long By = io.nextLong();
		int n = io.nextInt();

		long x[] = new long[n+1];
		long y[] = new long[n+1];
		for (int i = 0; i < n; i++) {
			x[i] = io.nextLong();
			y[i] = io.nextLong();
		}
		x[n] = x[0];
		y[n] = y[0];

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			Long Sa = (Bx-Ax)*(y[i]-Ay) - (By-Ay)*(x[i]-Ax);
			Long Sb = (Bx-Ax)*(y[i-1]-Ay) - (By-Ay)*(x[i-1]-Ax);
			Long Sc = (Ax-x[i])*(y[i-1]-y[i]) - (Ay-y[i])*(x[i-1]-x[i]);
			Long Sd = (Bx-x[i])*(y[i-1]-y[i]) - (By-y[i])*(x[i-1]-x[i]);
			if (Sa*Sb<0 && Sc*Sd<0) ans++;
		}

		System.out.println(ans/2 + 1);

    }

    private static class IO extends PrintWriter {
		private final InputStream in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;
		IO() {
			this(System.in);
		}
		IO(InputStream source) {
			super(System.out);
			this.in = source;
		}
		boolean hasNextByte() {
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
		int readByte() {
			if (hasNextByte()) return buffer[ptr++];
			else return -1;
		}
		boolean isPrintableChar(int c) {
			return 33 <= c && c <= 126;
		}
		boolean isNewLine(int c) {
			return c == '\n' || c == '\r';
		}
		void skipUnprintable() {
			while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
		}
		void skipNewLine() {
			while (hasNextByte() && isNewLine(buffer[ptr])) ptr++;
		}
		boolean hasNext() {
			skipUnprintable();
			return hasNextByte();
		}
		boolean hasNextLine() {
			skipNewLine();
			return hasNextByte();
		}
		String next() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		char[] nextCharArray(int len) {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			char[] s = new char[len];
			int i = 0;
			int b = readByte();
			while (isPrintableChar(b)) {
				if (i == len) {
					throw new InputMismatchException();
				}
				s[i++] = (char) b;
				b = readByte();
			}
			return s;
		}
		String nextLine() {
			if (!hasNextLine()) {
				throw new NoSuchElementException();
			}
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isNewLine(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		long nextLong() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
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
		int nextInt() {
			long nl = nextLong();
			if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
				throw new NumberFormatException();
			}
			return (int) nl;
		}
		char nextChar() {
			if (!hasNext()) {
				throw new NoSuchElementException();
			}
			return (char) readByte();
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		int[] arrayInt(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = nextInt();
			return a;
		}
		long[] arrayLong(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) a[i] = nextLong();
			return a;
		}
		double[] arrayDouble(int n) {
			double[] a = new double[n];
			for (int i = 0; i < n; i++) a[i] = nextDouble();
			return a;
		}
		void arrayInt(int[]... a) {
			for (int i = 0; i < a[0].length; i++) for (int j = 0; j < a.length; j++) a[j][i] = nextInt();
		}
		int[][] matrixInt(int n, int m) {
			int[][] a = new int[n][];
			for (int i = 0; i < n; i++) a[i] = arrayInt(m);
			return a;
		}
		char[][] charMap(int n, int m) {
			char[][] a = new char[n][];
			for (int i = 0; i < n; i++) a[i] = nextCharArray(m);
			return a;
		}
		public void close() {
			super.close();
			try {
				in.close();
			} catch (IOException ignored) {
			}
		}
	}
}