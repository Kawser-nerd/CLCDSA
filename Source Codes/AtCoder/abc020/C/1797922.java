import java.util.*;
import java.io.*;

public class Main {
    private static IO io = new IO();
    
    public static void main(String[] args) {

    	int yy = io.nextInt();
    	int xx = io.nextInt();
    	int t = io.nextInt();
    	char map[][] = new char[xx][yy];
    	int sx = 0, sy = 0, gx = 0, gy = 0;
		for (int j = 0; j < yy; j++) {
			for (int i = 0; i < xx; i++) {
				map[i][j] = io.nextChar();
				if (map[i][j]=='S') {
					sx = i;
					sy = j;
					map[i][j] = '.';
				} else if (map[i][j]=='G') {
					gx = i;
					gy = j;
					map[i][j] = '.';
				}
			}
		}

		// (i,j)??????
		long d[][] = new long[xx][yy];
		// x, y, ????
		Deque<int[]> que = new ArrayDeque<>();
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};

		int upp = t;
		int low = 1;

		while (upp-low>1) {
			int mid = (upp+low)/2;
			for (int i = 0; i < xx; i++) Arrays.fill(d[i], 1145141919);
			d[sx][sy] = 0;
			que.offer(new int[] {sx, sy, 0});

			while (!que.isEmpty()) {
				int poll[] = que.poll();
				int x = poll[0];
				int y = poll[1];
				int dis = poll[2];
				if (d[x][y]<dis) continue;
				for (int i = 0; i < 4; i++) {
					int mx = x + dx[i];
					int my = y + dy[i];
					if (0<=mx && mx<xx && 0<=my && my<yy) {
						int cost = (map[mx][my]=='.') ? 1 : mid;
						if (d[mx][my]>dis+cost) {
							d[mx][my] = dis + cost;
							que.offer(new int[] {mx, my, dis+cost});
						}
					}
				}
			}

			if (d[gx][gy]<=t) low = mid;
			else upp = mid;
		}

		System.out.println(low);

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