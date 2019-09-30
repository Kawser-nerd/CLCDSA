import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int W = sc.nextInt();
    
    int[][] e = sc.nextIntTable(N, 2);
    int base = e[0][0];
    Arrays.sort(e, (a, b) -> b[1] - a[1]);

    int[][] v = new int[4][100];
    int[] ptr = new int[4];

    for (int i = 0; i < N; i ++) {
      int k = e[i][0] - base;
      v[k][ptr[k]] = e[i][1];
      ptr[k] ++;
    }
    for (int i = 0; i < 4; i ++) {
      v[i] = Arrays.copyOf(v[i], ptr[i]);
    }
    
    long[][] sv = new long[4][];
    for (int i = 0; i < 4; i ++) {
      sv[i] = new long[v[i].length + 1];
      for (int j = 0; j < v[i].length; j ++) {
        sv[i][j + 1] = sv[i][j] + v[i][j];
      }
    }
    

    long ret = 0;
    for (int i = 0; i <= v[0].length; i ++) {
      for (int j = 0; j <= v[1].length; j ++) {
        for (int k = 0; k <= v[2].length; k ++) {
          long nowW = (long)i * base + (long)j * (base + 1) + (long)k * (base + 2);
          if (nowW > W) {
            continue;
          }
          
          int last = (int)((W - nowW) / (base + 3));
          long nowV = sv[0][i] + sv[1][j] + sv[2][k] + sv[3][Math.min(last, v[3].length)];
          ret = Math.max(nowV, ret);
        }
      }
    }
    System.out.println(ret);
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