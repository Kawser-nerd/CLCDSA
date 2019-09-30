import java.awt.Point;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.NoSuchElementException;
import java.util.Queue;

public class Main {

	static final int[] dx = { 0, 1, 0, -1 };
	static final int[] dy = { 1, 0, -1, 0 };

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);

		int h = sc.nextInt();
		int w = sc.nextInt();
		int k = sc.nextInt();
		Point s = new Point();

		boolean[][] wall = new boolean[h][w];
		for (int i = 0; i < h; i++) {
			char[] cs = sc.next().toCharArray();
			for (int j = 0; j < w; j++) {
				switch (cs[j]) {
					case '#':
						wall[i][j] = true;
						break;
					case 'S':
						s.setLocation(j, i);
						break;
				}
			}
		}

		int[][] dist = new int[h][w];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				dist[i][j] = 1145141919;
			}
		}

		Queue<Point> q = new ArrayDeque<>();
		q.offer(s);
		dist[s.y][s.x] = 0;
		while(!q.isEmpty()) {
			Point p = q.poll();

			for (int i = 0; i < 4; i++) {
				int x = p.x + dx[i];
				int y = p.y + dy[i];
				if ((0 <= x && x < w && 0 <= y && y < h) && !wall[y][x] && dist[y][x] > dist[p.y][p.x] + 1) {
					dist[y][x] = dist[p.y][p.x] + 1;
					q.offer(new Point(x, y));
				}
			}
		}

		int min = 1145141919;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (dist[i][j] <= k) {
					min = Math.min(min, (Math.min(i, Math.min(j, Math.min(h - i - 1, w - j - 1))) + k - 1) / k + 1);
				}
			}
		}

		out.println(min);
		out.flush();
	}

}

class FastScanner {
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
			if (buflen <= 0) { return false; }
		}
		return true;
	}

	private byte readByte() {
		if (hasNextByte()) {
			return buffer[ptr++];
		} else {
			return -1;
		}
	}

	private boolean isPrintableChar(int c) {
		return '!' <= c && c <= '~';
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
			ptr++;
		}
	}

	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}

	public String next() {
		if (!hasNext()) { throw new NoSuchElementException(); }
		StringBuilder sb = new StringBuilder();
		byte b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public int nextInt() {
		if (!hasNext()) { throw new NoSuchElementException(); }
		int n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) { throw new NumberFormatException(); }
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

	public long nextLong() {
		if (!hasNext()) { throw new NoSuchElementException(); }
		long n = 0;
		boolean minus = false;
		byte b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b) { throw new NumberFormatException(); }
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