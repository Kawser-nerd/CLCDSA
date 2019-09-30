import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int M = sc.nextInt();
    int Q = sc.nextInt();
    
    int[][] map = new int[N + 2][M + 2];
    for (int i = 1; i <= N; i ++) {
      char[] s = sc.next().toCharArray();
      for (int j = 1; j <= M; j ++) {
        map[i][j] = s[j - 1] - '0';
      }
    }
    
    int[][] e = new int[N + 2][M + 2];
    int[][] v = new int[N + 2][M + 2];

    int[][] dir = {{-1, 0}, {0, -1}};
    for (int i = 1; i <= N; i ++) {
      for (int j = 1; j <= M; j ++) {
        v[i][j] = v[i][j - 1];
        e[i][j] = e[i][j - 1];
        if (map[i][j] == 1) {
          v[i][j] ++;
          
          for (int[] d : dir) {
            if (map[i + d[0]][j + d[1]] == 1) {
              e[i][j] ++;
            }
          }
        }
      }
      for (int j = 1; j <= M; j ++) {
        v[i][j] += v[i - 1][j];
        e[i][j] += e[i - 1][j];
      }
    }
    
    int[][][] ex = new int[2][N + 1][M + 1];
    for (int i = 1; i <= N; i ++) {
      for (int j = 1; j <= M; j ++) {
        ex[0][i][j] = ex[0][i][j - 1];
        if (map[i][j] == 1 && map[i - 1][j] == 1) {
          ex[0][i][j] ++;
        }
      }
    }
    for (int j = 1; j <= M; j ++) {
      for (int i = 1; i <= N; i ++) {
        ex[1][i][j] = ex[1][i - 1][j];
        if (map[i][j] == 1 && map[i][j - 1] == 1) {
          ex[1][i][j] ++;
        }
      }
    }
    
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < Q; i ++) {
      int x1 = sc.nextInt();
      int y1 = sc.nextInt();
      int x2 = sc.nextInt();
      int y2 = sc.nextInt();
      
      int v1 = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1];
      int e1 = e[x2][y2] - e[x1 - 1][y2] - e[x2][y1 - 1] + e[x1 - 1][y1 - 1];
      
      int et = ex[0][x1][y2] - ex[0][x1][y1 - 1];
      int el = ex[1][x2][y1] - ex[1][x1 - 1][y1];

      
      sb.append(v1 - (e1 - et - el));
      sb.append("\n");
    }
    System.out.println(sb);
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