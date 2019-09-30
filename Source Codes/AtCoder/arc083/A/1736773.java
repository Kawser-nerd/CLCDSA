import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/*
 public class at_arc083_a {

 }

 */
public class Main {
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


  public void solve() throws Throwable {
    Reader in = new Reader();

    Writer out = new Writer();

    // actual code
    int a = in.nextInt();
    int b = in.nextInt();
    int c = in.nextInt();
    int d = in.nextInt();

    int e = in.nextInt();
    int f = in.nextInt();


    int[] sugar = new int[f + 1];
    int[] water = new int[f + 1];

    if (c == 1) {
      for (int i = 0; i <= f; i++) {
        sugar[i] = i;
      }
    } else {
      for (int i = 0; i <= f / c; i++) {
        for (int j = 0; j <= f / d; j++) {
          int sum = i * c + j * d;
          if (sum <= f) {
            sugar[sum] = sum;
          }
        }
      }
    }

    for (int i = 1; i <= f; i++) {
      sugar[i] = Math.max(sugar[i], sugar[i - 1]);
    }

    for (int i = 0; i <= f / (100 * a); i++) {
      for (int j = 0; j <= f / (100 * b); j++) {
        int sum = i * a * 100 + j * b * 100;
        if (sum <= f) {
          water[sum] = sum;
        }
      }
    }

    for (int i = 1; i <= f; i++) {
      water[i] = Math.max(water[i], water[i - 1]);
    }

    double ans = -1;
    int sw = 0;
    int sd = 0;
    for (int i = 0; i <= f; i++) {


      int cw = water[i];

      for (int j = f - cw; j >= 0; j--) {
        int cs = sugar[j];

        int mxs = (cw / 100) * e;

        if (cs <= mxs && (cs + cw) > 0 && (cs + cw) <= f) {
          double newans = (100.0 * (double) cs) / ((double)cs + cw);

          if (newans > ans) {
            ans = newans;
            sw = cs + cw;
            sd = cs;
          }
        }
      }
    }

    System.out.println(sw + " " + sd);
    // end here
  }

  public static void main(String[] args) throws Throwable {
    int t = 1;

    while (t-- > 0) {
      (new Main()).solve();
    }

  }
}