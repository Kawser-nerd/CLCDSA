import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class deceitfulwar {
  private static Reader in;
  private static PrintWriter out;
  public static final String NAME = "D-large";

  private static void main2() throws IOException {
    int N = in.nextInt();
    double[] n = new double[N];
    double[] k = new double[N];
    for (int i = 0; i < N; i++)
      n[i] = in.nextDouble();
    for (int i = 0; i < N; i++)
      k[i] = in.nextDouble();
    Arrays.sort(n);
    
    
    int win2 = 0;
    boolean[] mark = new boolean[N];
    for (int i = 0; i < N; i++) {
      // play in increasing order
      double best = 1l << 50;
      int idx = -1;
     
      // find smallest one that can beat chosen
      for (int j = 0; j < N; j++) {
        if (!mark[j] && k[j] > n[i] && k[j] < best) {
          best = k[j];
          idx = j;
        }
      }
      if (idx == -1) {
        // can't beat it, find smallest thing to give up
        win2++;
        for (int j = 0; j < N; j++) {
          if (!mark[j] && k[j] < best) {
            best = k[j];
            idx = j;
         }
        }
      }
      mark[idx] = true;
    }
    
    
    int win = 0;
    mark = new boolean[N];
    for (int i = 0; i < N; i++) {
      double min = 1l << 60;
      int idx = -1;
      for (int j = 0; j < N; j++) {
        if (!mark[j] && k[j] < min) {
          min = k[j];
          idx = j;
        }
      }
      // able to cheat this win
      if (min < n[i]) {
        win++;
      } else {
        idx = -1;
        double max = -1;
        for (int j = 0; j < N; j++) {
          if (!mark[j] && k[j] > max) {
            max = k[j];
            idx = j;
          }
        }
      }

      mark[idx] = true;
    }
    
    
    out.printf ("%d %d\n", win, win2);
  }

  public static void main(String[] args) throws IOException {
    in = new Reader(NAME + ".in");
    out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ": ");
      main2();
    }

    out.close();
    System.exit(0);
  }

  /** Faster input **/
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
      byte[] buf = new byte[1024];
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
      else
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
      else
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
        while ((c = read()) >= '0' && c <= '9')
          ret += (c - '0') / (div *= 10);
      }
      if (neg)
        return -ret;
      else
        return ret;
    }

    public char nextChar() throws IOException {
      char ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      return (char) c;
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
}
