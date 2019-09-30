import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/*
 public class at_arc083_b {

 }

 */
public class Main {

  public void solve() throws Throwable {
    Reader in = new Reader();

    Writer out = new Writer();

    // actual code
    int n = in.nextInt();

    int[][] a = new int[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = in.nextInt();
      }
    }

    boolean[][] imp = new boolean[n][n];

    int[][] sd = new int[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        imp[i][j] = true;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        sd[i][j] = a[i][j];
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (sd[i][k] + sd[k][j] < sd[i][j]) {
            System.out.println("-1");
            return;
          } else if (sd[i][k] + sd[k][j] == sd[i][j] && k != i && k != j) {
            imp[i][j] = false;
          }
        }
      }
    }

    long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (imp[i][j]) {
          ans += a[i][j];
        }
      }
    }

    System.out.println(ans);
    // end here
  }

  static class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader() {
      din = new DataInputStream(System.in);
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException {
      din = new DataInputStream(new FileInputStream(file_name));
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException {
      byte[] buf = new byte[64]; // line length
      int cnt = 0, c;
      while ((c = read()) != -1) {
        if (c == '\n')
          break;
        buf[cnt++] = (byte) c;
      }
      return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException {
      int ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');

      if (neg)
        return -ret;
      return ret;
    }

    public long nextLong() throws IOException {
      long ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }

    public double nextDouble() throws IOException {
      double ret = 0, div = 1;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();

      do {
        ret = ret * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');

      if (c == '.') {
        while ((c = read()) >= '0' && c <= '9') {
          ret += (c - '0') / (div *= 10);
        }
      }

      if (neg)
        return -ret;
      return ret;
    }

    private void fillBuffer() throws IOException {
      bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
      if (bytesRead == -1)
        buffer[0] = -1;
    }

    private byte read() throws IOException {
      if (bufferPointer == bytesRead)
        fillBuffer();
      return buffer[bufferPointer++];
    }

    public void close() throws IOException {
      if (din == null)
        return;
      din.close();
    }
  }

  static class Writer {
    StringBuilder sb = new StringBuilder();

    public void out(String s) {
      sb.append(s);
    }

    public void outAndSpace(String s) {
      sb.append(s);
      sb.append(' ');
    }

    public void outAndNewLine(String s) {
      sb.append(s);
      sb.append('\n');
    }

    public void flush() {
      System.out.println(sb.toString());
      sb.setLength(0);
    }

    public void realFlush() {
      flush();
      System.out.flush();
    }
  }

  public static void main(String[] args) throws Throwable {
    int t = 1;

    while (t-- > 0) {
      (new Main()).solve();
    }

  }
}