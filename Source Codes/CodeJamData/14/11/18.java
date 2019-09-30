import java.util.*;
import java.io.*;

public class charging {
  private static Reader in;
  private static PrintWriter out;
  public static final String NAME = "A-small-attempt6";
  public static int N, L;

  private static void main2() throws IOException {
    N = in.nextInt();
    L = in.nextInt();
    long[] start = new long[N];
    for (int i = 0; i < N; i++) {
      start[i] = in.nextLong(2);
    }
    Arrays.sort(start);
    long[] end =  new long[N];
    for (int i = 0; i < N; i++) {
      end[i] = in.nextLong(2);
    }
    Arrays.sort(end);
    int count = 0;
    ArrayList<Integer> eqrow = new ArrayList<Integer> ();
    int best = -1;
    for (int i = L - 1; i >= 0; i--) {
      int[] c1 = new int[2];
      int[] c2 = new int[2];
      for (int j = 0; j < N; j++) {
        int d1 = (int)((start[j] >> i) & 1);
        int d2 = (int)((end[j] >> i) & 1);
        c1[d1]++;
        c2[d2]++;
      }
      if (c1[0] == c2[1] && c1[1] == c2[0]) {
        eqrow.add(i);
      }
    }
    for (int i = 0; i < 1 << eqrow.size(); i++) {
      long[] st = new long[N], et = new long[N];
      System.arraycopy (start, 0, st, 0, N);
      System.arraycopy (end, 0, et, 0, N);
      int add = 0;
      for (int j = 0; j < eqrow.size(); j++) {
        if ((i & (1 << j)) != 0) {
          add++;
          flipBit(st, eqrow.get(j));
        }
      }
      int score = getMin(st, et);
      if (score == -1) continue;
      if (best == -1 || score + add < best)
        best = score + add;
    }
    
    out.println (best != -1 ? best : "NOT POSSIBLE");
  }
  
  private static void flipBit(long[] start, int bit) {
    for (int i = 0; i < start.length; i++) {
      start[i] ^= (1l << bit);
    }
    Arrays.sort(start);
  }
  
  public static int getMin(long[] start, long[] end) {
    int count = 0;
    boolean ok = true;
    outer : for (int i = L - 1; i >= 0; i--) {
      int[] c1 = new int[2];
      int[] c2 = new int[2];
      for (int j = 0; j < N; j++) {
        int d1 = (int)((start[j] >> i) & 1);
        int d2 = (int)((end[j] >> i) & 1);
        c1[d1]++;
        c2[d2]++;
      }
      boolean c = true;
      for (int j = 0; j < N; j++) {
        if ((start[j] >> i) != (end[j] >> i)) {
          c = false;
          break;
        }
      }
      if (c1[0] == c2[0]) {
        
      } else if (c1[0] == c2[1]) {
        for (int j = 0; j < N; j++)
          start[j] ^= (1l << i);
        count++;
        Arrays.sort(start);
      } else {
        ok = false;
        break outer;
      }
      for (int j = 0; j < N; j++) {
        if ((start[j] >> i) != (end[j] >> i)) {
          ok = false;
          break outer;
        }
      }
    }
    return ok ? count : -1;
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
    
    public long nextLong(int radix) throws IOException {
      long ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * radix + c - '0';
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
