import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;


public class Main {
  public static void main(String[] args) {
    solve();
  }
  
  private static void solve() {
    FastScanner sc = new FastScanner();
    int N = sc.nextInt();
    int K = sc.nextInt();

    long[] sum = new long[N + 1];
    for (int i = 0; i < N; i ++) {
      int a = sc.nextInt();
      sum[i + 1] = sum[i] + (a - K);
    }
    
    int[] s = (int[])(shrinkXI(sum)[0]);
    long[] ft = buildFenwick(N + 1, 0);
    long count = 0;
    for (int i = 0; i <= N; i ++) {
      count += sumFenwick(ft, s[i]);
      addFenwick(ft, s[i], 1);
    }
    System.out.println(count);
  }

  public static Object[] shrinkXI(final long[] a)
  {
      int n = a.length;
      Integer[] b = new Integer[n];
      for(int i = 0;i < n;i++)b[i] = i;
      Arrays.sort(b, new Comparator<Integer>(){
          public int compare(Integer x, Integer y){
              return Long.signum(a[x] - a[y]);
          }
      });
      int[] ret = new int[n];
      long[] interval = new long[n];
      int p = 0;
      for(int i = 0;i < n;i++){
          if(i > 0 && a[b[i]] > a[b[i-1]]){
              interval[p] = a[b[i]]-a[b[i-1]];
              p++;
          }
          ret[b[i]] = p;
      }
      
      return new Object[]{ret, Arrays.copyOf(interval, p)};
  }

  public static long[] buildFenwick(int n, int v)
  {
      long[] ft = new long[n+1];
      Arrays.fill(ft, 1, n+1, v);
      for(int k = 2, h = 1;k <= n;k*=2, h*=2){
          for(int i = k;i <= n;i+=k){
              ft[i] += ft[i-h];
          }
      }
      return ft;
  }
  public static void addFenwick(long[] ft, int i, int v)
  {
      if(v == 0 || i < 0)return;
      int n = ft.length;
      for(i++;i < n;i += i&-i)ft[i] += v;
  }
  public static long sumFenwick(long[] ft, int i)
  {
      long sum = 0;
      for(i++;i > 0;i -= i&-i)sum += ft[i];
      return sum;
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