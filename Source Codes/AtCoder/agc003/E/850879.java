import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		int Q = sc.nextInt();
		long[] q = sc.nextLongList(Q);
		
		int ptr = 0;
		long[] nq = new long[Q + 1];
		for (long v : q) {
			while (ptr > 0 && nq[ptr] >= v) {
				ptr --;
			}
			nq[++ ptr] = v;
		}
		q = Arrays.copyOf(nq, ptr + 1);
		Q = ptr;
		
		long[] ans = solve(N, Q, q);
		
		StringBuilder sb = new StringBuilder();
		for (long v : ans) {
			sb.append(v);
			sb.append("\n");
		}
		System.out.println(sb);
		
	}

	private static long[] solve(int N, int Q, long[] B) {
		int L = B.length - 1;
		long[] a = new long[N + 1];
		long[] t = new long[L + 1];
		t[L] = 1;
		for (int i = L; i >= 1; i --) {
			long k = B[i];

			int j = i - 1;
			while (true) {
				int left = 0;
				int right = j;
				while (left <= right) {
					int mid = (left + right) / 2;
					if (k < B[mid]) {
						right = mid - 1;
					} else {
						left = mid + 1;
					}
				}
				j = right;
				if (j <= 0) break;
				
				t[j] += t[i] * (k / B[j]);
				k %= B[j];
			}
			
			a[0] += t[i] * (k / N + 1);
			a[(int)(k % N)] -= t[i];
		}
		
		if (L == 0) {
			a[0] = 1;
		}
		
		long now = 0;
		long[] ans = new long[N];
		for (int i = 0; i < N; i ++) {
			now += a[i];
			ans[i] = now;
		}
		
		return ans;
	}
}



class FastScanner {
	public static String debug = null;

	private InputStream in;
	private int ptr = 0;
	private int buflen = 0;
	private byte[] buffer = new byte[1024];
	private boolean eos = false;

	public FastScanner() {
		try {
			this.in = System.in;
		} catch (Exception e) {
		}
	}

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				if (debug != null) {
					buflen = debug.length();
					buffer = debug.getBytes();
					debug = "";
					eos = true;
				} else {
					buflen = in.read(buffer);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen < 0) {
				eos = true;
				return false;
			} else if (buflen == 0) {
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

	public boolean isEOS() {
		return this.eos;
	}

	public boolean hasNext() {
		skipUnprintable();
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
		return (int) nextLong();
	}

	public long[] nextLongList(int n) {
		return nextLongTable(1, n)[0];
	}

	public int[] nextIntList(int n) {
		return nextIntTable(1, n)[0];
	}

	public long[][] nextLongTable(int n, int m) {
		long[][] ret = new long[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextLong();
			}
		}
		return ret;
	}

	public int[][] nextIntTable(int n, int m) {
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextInt();
			}
		}
		return ret;
	}
}