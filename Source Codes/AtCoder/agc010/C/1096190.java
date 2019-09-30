import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {
  private static int N;
  private static int[][] g;
  private static long[] A;

  private static long[] last;

  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    N = sc.nextInt();
    A = sc.nextLongList(N);
    
    int[] from = new int[N - 1];
    int[] to = new int[N - 1];
    for (int i = 0; i < N - 1; i ++) {
      from[i] = sc.nextInt() - 1;
      to[i] = sc.nextInt() - 1;
    }
    g = packU(N, from, to);
  
    last = new long[N];

    int s = -1;
    for (int i = 0; i < N; i ++) {
      if (g[i].length > 1) {
        s = i;
        break;
      }
    }
    if (s >= 0) {
      boolean ret = dfs(s, -1);
      if (ret && last[s] == 0) { 
        System.out.println("YES");
      } else {
        System.out.println("NO");
      }
    } else {
      System.out.println(A[0] == A[1] ? "YES" : "NO");
    }
  }

  private static boolean dfs(int now, int pre) {
    if (pre >= 0 && g[now].length == 1) {
      last[now] = A[now];
      return true;
    }

    long a = 0;
    long max = 0;
    for (int v : g[now]) {
      if (v != pre) {
        boolean ret = dfs(v, now);
        if (!ret) {
          return false;
        }
        a += last[v];
        max = Math.max(max, last[v]);
      }
    }

    if (pre >= 0 && g[now].length == 2) {
      last[now] = A[now];
      return a == A[now];
    } else {
      if (a <= A[now] * 2 && A[now] <= a) {
        last[now] = A[now] * 2 - a;
        
        if (A[now] < max) {
          return false;
        }
        return true;
      } else {
        return false;
      }
    }
  }
  
  public static int[][] packU(int n, int[] from, int[] to)
  {
      int[][] g = new int[n][];
      int[] p = new int[n];
      for(int f : from)p[f]++;
      for(int t : to)p[t]++;
      for(int i = 0;i < n;i++)g[i] = new int[p[i]];
      for(int i = 0;i < from.length;i++){
          g[from[i]][--p[from[i]]] = to[i];
          g[to[i]][--p[to[i]]] = from[i];
      }
      return g;
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