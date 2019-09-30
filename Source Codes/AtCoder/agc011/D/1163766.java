import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.NoSuchElementException;

public class Main {
  private static int N;
  private static Deque<Integer> queue = new ArrayDeque<Integer>();
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    N = sc.nextInt();
    long K = sc.nextLong();
    String s = sc.next();
    
    for (int i = 0; i < N; i ++) {
      int v = s.charAt(i) - 'A';
      if (i % 2 == 1) {
        v = v == 0 ? 1 : 0;
      }
      queue.add(v);
    }
    

    
    if (2 * N < K) {
      for (int i = 0; i < 2 * N; i ++) {
        next();
      }
      String s1 = build();
      next();
      String s2 = build();

      System.out.println(K % 2 == 0 ? s1 : s2);
    } else {
      for (int i = 0; i < K; i ++) {
        next();
      }
      System.out.println(build());
    }

  }
  
  private static void next() {
    if (queue.pollFirst() == 0) {
      queue.addFirst(1);
    } else {
      queue.addLast(N % 2 == 0 ? 1 : 0);
    }
  }

  private static String build() {
    StringBuilder sb = new StringBuilder();
    int ptr = 0;
    for (int v : queue) {
      if (ptr % 2 == 1) {
        v = v == 0 ? 1 : 0;
      }
      sb.append((char)('A' + v));
      ptr ++;
    }
    return sb.toString();
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