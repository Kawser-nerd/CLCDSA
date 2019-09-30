import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.util.NoSuchElementException;
import java.util.Collections;
import java.util.ArrayList;
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
		Task9 solver = new Task9();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task9 {
		public void solve(int testNumber, Scanner sc, PrintWriter out) {

			int n = sc.nextInt();
			int k = sc.nextInt();
			Salt[] salts = new Salt[n];
			for (int i = 0; i < n; i++) {
				salts[i] = new Salt(sc.nextInt(), sc.nextInt());
			}

			double ok = 0;
			double ng = 100;
			while (Math.abs(ok - ng) > 0.00000000001) {
				double mid = (ok + ng) / 2;
				List<Double> list = new ArrayList<>();

				for (int i = 0; i < n; i++) {
					list.add(salts[i].w * (salts[i].p - mid) / 100);
				}
				Collections.sort(list);
				Collections.reverse(list);

				double sum = 0;
				for (int i = 0; i < k; i++) {
					sum += list.get(i);
				}

				if (sum >= 0) ok = mid;
				else ng = mid;
			}

			out.println(ok);

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

	static class Salt {
		int w;
		int p;

		Salt(int w, int p) {
			this.w = w;
			this.p = p;
		}

	}
}