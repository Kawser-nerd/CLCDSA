import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task7 solver = new Task7();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task7 {
		public void solve(int testNumber, Scanner sc, PrintWriter out) {

			int n = sc.nextInt();

			Point[] a = new Point[n];
			Point[] b = new Point[n];
			for (int i = 0; i < n; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				a[i] = new Point(x, y);
			}
			for (int i = 0; i < n; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				b[i] = new Point(x, y);
			}

			Point aCenter = new Point(0, 0), bCenter = new Point(0, 0);
			for (int i = 0; i < n; i++) {
				aCenter.x += a[i].x;
				aCenter.y += a[i].y;
				bCenter.x += b[i].x;
				bCenter.y += b[i].y;
			}
			aCenter.x /= n;
			aCenter.y /= n;
			bCenter.x /= n;
			bCenter.y /= n;

			double aMax = 0, bMax = 0;
			for (int i = 0; i < n; i++) {
				aMax = Math.max(aMax, a[i].distance(aCenter));
				bMax = Math.max(bMax, b[i].distance(bCenter));
			}

			out.println(bMax / aMax);
		}

	}

	static class Scanner {
		private final InputStream in;
		private final byte[] buffer;
		private int ptr;
		private int buflen;

		public Scanner(InputStream in) {
			this.in = in;
			this.buffer = new byte[1024];
			this.ptr = 0;
			this.buflen = 0;
		}

		private boolean hasNextByte() {
			if (ptr < buflen) return true;
			else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) return false;
			}
			return true;
		}

		private byte readByte() {
			if (hasNextByte()) return buffer[ptr++];
			return -1;
		}

		private boolean isPrintableChar(byte c) {
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

		public int nextInt() {
			if (!hasNext()) throw new NoSuchElementException();
			int n = 0;
			boolean minus = false;
			byte b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) throw new NumberFormatException();
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

	static class Point {
		double x;
		double y;

		Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		double distance(Point p) {
			return Math.sqrt(Math.pow(this.x - p.x, 2) + Math.pow(this.y - p.y, 2));
		}

	}
}