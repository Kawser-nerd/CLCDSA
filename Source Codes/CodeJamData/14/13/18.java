import java.util.*;
import java.io.*;

public class shuffle {
  private static Reader in;
  private static PrintWriter out;
  public static final String NAME = "C-small-attempt0";
  public static int count = 0, numgood = 0;
  public static boolean ans;
  public static int[][] agg;

  private static void main2() throws IOException {
    int N = in.nextInt();
    int[] arr = new int[N];
    for (int i = 0; i < N; i++) {
      arr[i] = in.nextInt();
    }
//    int[] arr = null;
//    ans = false;
//    if (Math.random() < .5) {
//      arr = makeGood(1000);
//      ans = true;
//      numgood++;
//    } else {
//      arr = makeBad(1000);
//      ans = false;
//    }
    
//    if (ans == good(arr)) {
//      count++;
//    }
    out.println (good(arr) ? "GOOD" : "BAD");
  }
  
  private static int[] makeGood(int N) {
    int[] ret = new int[N];
    for (int i = 0; i < N; i++) {
      ret[i] = i;
    }
    for (int k = 0; k < N; k++) {
      int p = (int)(Math.random() * (N - k)) + k;
      int t = ret[p]; ret[p] = ret[k]; ret[k] = t;
    }
    return ret;
  }
  
  private static int[] makeBad(int N) {
    int[] ret = new int[N];
    for (int i = 0; i < N; i++) {
      ret[i] = i;
    }
    for (int k = 0; k < N; k++) {
      int p = (int)(Math.random() * N);
      int t = ret[p]; ret[p] = ret[k]; ret[k] = t;
    }
    return ret;
  }
  
  private static boolean good (int[] arr) {
    int N = arr.length;
    
    int[] pos = new int[N];
    for (int i = 0; i < N; i++)
      pos[arr[i]] = i;
    
    int gcount = 0;
    for (int i = 0; i < N; i++) {
      if (pos[i] > i) gcount++;
    }
    
    return gcount > 485; // magic
  }

  public static void main(String[] args) throws IOException {
    in = new Reader(NAME + ".in");
    out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

    int numCases = in.nextInt();
//    agg = new int[2][3];
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ": ");
      main2();
    }
//    System.out.println(count + " " + numCases + " " + (count / (double)numCases));
//    double[][] ret = new double[2][3];
//    for (int i = 0; i < 3; i++) {
//      ret[0][i] = agg[0][i] / (double)numgood;
//      ret[1][i] = agg[1][i] / (double)(numCases - numgood);
//    }
//    System.out.println (Arrays.deepToString(agg));
//    System.out.println(Arrays.deepToString(ret));

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
