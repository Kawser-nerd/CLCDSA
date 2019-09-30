import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;
 
public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
 
	void run() {
		Scanner sc = new Scanner();
		PrintWriter pw = new PrintWriter(System.out);
		int N = sc.nextInt();
		int L = sc.nextInt();
		double totSalt = 0;
		double totV = 0;
		double[] t = new double[N];
		double[] v = new double[N];
		ArrayDeque<double[]> dq = new ArrayDeque<>();
		for (int i = 0; i < N; ++i) {
			t[i] = sc.nextDouble();
			v[i] = sc.nextDouble();
			double nextSalt = t[i] * v[i];
			double nextV = v[i];
			long sum = 0;
			while (nextV > sum && i != 0) {
				double[] state = dq.pollLast();
				if (nextV - (sum + state[1]) >= 0) {
					totSalt -= state[0];
					totV -= state[1];
					sum += state[1];
				} else {
					double r = (state[1] - (nextV - sum)) / state[1];
					sum += (1 - r) * state[1];
					totSalt -= (1 - r) * state[0];
					totV -= (1 - r) * state[1];
					state[0] *= r;
					state[1] *= r;
					dq.addLast(state);
					break;
				}
			}
			while (!dq.isEmpty()) {
				double[] state = dq.peekFirst();
				if (state[0] / state[1] >= nextSalt / nextV) {
					totSalt -= state[0];
					totV -= state[1];
					nextSalt += state[0];
					nextV += state[1];
					dq.pollFirst();
				} else {
					break;
				}
			}
			dq.addFirst(new double[] { nextSalt, nextV });
			totSalt += nextSalt;
			totV += nextV;
			if(i%20000==0)System.gc();
			pw.println(String.format("%.20f", totSalt / totV));
		}
		pw.close();
	}
 
	static void tr(Object... objects) {
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