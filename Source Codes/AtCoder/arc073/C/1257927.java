import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    
    long[][] v = sc.nextLongTable(N, 2);
    long max = 0;
    long min = Integer.MAX_VALUE;

    long max2 = 0;
    long min2 = Integer.MAX_VALUE;

    for (int i = 0; i < N; i ++) {
      if (v[i][0] > v[i][1]) {
        long tmp = v[i][0];
        v[i][0] = v[i][1];
        v[i][1] = tmp;
      }
      max = Math.max(max, v[i][1]);
      min = Math.min(min, v[i][0]);
      
      max2 = Math.max(max2, v[i][0]);
      min2 = Math.min(min2, v[i][1]);
    }
    
    long ans = (max - min2) * (max2 - min);
    
    long[][] es = new long[N * 2][3];
    for (int i = 0; i < N; i ++) {
      es[i * 2 + 0] = new long[]{v[i][0], i, 0};
      es[i * 2 + 1] = new long[]{v[i][1], i, 1};
    }
    Arrays.sort(es, (a, b) -> a[0] == b[0] ? Long.compare(a[2], b[2]) : Long.compare(a[0], b[0]));
    long h = max2;  
    
    for (long[] e : es) {
      ans = Math.min(ans, (max - min) * (h - e[0]));
      h = Math.max(h,  v[(int)e[1]][1]);
      if (e[2] == 1) {
        break;
      }

    }
    System.out.println(ans);
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