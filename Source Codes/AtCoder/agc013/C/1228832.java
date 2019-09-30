import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int L = sc.nextInt();
    long T = sc.nextLong();
    
    long[][] ari = sc.nextLongTable(N, 2);
    
    long[] cl = new long[N];
    long[] ccl = new long[N];

    int p = 0, q = 0;
    for (int i = 0; i < N; i ++) {
      if (ari[i][1] == 1) {
        cl[p ++] = L - ari[i][0];
      } else {
        ccl[q ++] = ari[i][0];
      }
    }
    cl = Arrays.copyOf(cl, p);
    ccl = Arrays.copyOf(ccl, q);
    Arrays.sort(cl);

    long[] rets = new long[N];
    for (int i = 0; i < N ;i ++) {
      if (ari[i][1] == 1) {
        int count = (int)(count(ccl, ari[i][0], ari[i][0] + 2L * T, L) % N);
        rets[(i + count) % N] = (ari[i][0] + T) % L;
      } else {
        int count = (int)(count(cl, L - ari[i][0], L - ari[i][0] + 2L * T, L) % N);
        rets[(i + N - count) % N] = (ari[i][0] + L - T % L) % L;
      }
    }
    
    for (int i = 0; i < N; i ++) {
      System.out.println(rets[i]);
    }
  }
  
  private static long count(long[] xs, long f, long t, int L) {
    long ret = 0;
    int n = xs.length;
    {
      ret += t / L * n;
      int ind = Arrays.binarySearch(xs, (int)(t % L));
      if (ind < 0)  ind = -ind - 2;
      ind ++;
      ret += ind;
    }
    {
      ret -= f / L * n;
      int ind = Arrays.binarySearch(xs, (int)(f % L));
      if (ind < 0)  ind = -ind - 2;
      ind ++;
      ret -= ind;
    }
    return ret;
  }
}




class FastScanner {
	public static String debug = null;

	private final InputStream in = System.in;
	private int ptr = 0;
	private int buflen = 0;
	private byte[] buffer = new byte[1024];
	private boolean eos = false;

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