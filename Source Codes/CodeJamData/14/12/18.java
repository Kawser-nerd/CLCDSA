import java.util.*;
import java.io.*;

public class bintree {
  private static Reader in;
  private static PrintWriter out;
  public static final String NAME = "B-large";
  
  public static int[] eadj, eprev, elast, deg;
  public static int eidx, N;
  
  public static void addEdge (int a, int b) {
    deg[a]++; deg[b]++;
    eadj[eidx] = b; eprev[eidx] = elast[a]; elast[a] = eidx++;
    eadj[eidx] = a; eprev[eidx] = elast[b]; elast[b] = eidx++;
  }

  private static void main2() throws IOException {
    N = in.nextInt();
    eadj = new int[2 * N];
    eprev = new int [2 * N];
    elast = new int[N];
    deg = new int[N];
    eidx = 0;
    Arrays.fill (elast, -1);
    for (int i = 0; i < N - 1; i++) {
      addEdge(in.nextInt() - 1, in.nextInt() - 1);
    }
    
    cost = new int[N];
    int min = N - 1;
    for (int i = 0; i < N; i++) {
      int t = solve(i);
      if (t < min) {
        min = t;
      }
    }
    out.println (min);
  }
  
  private static int[] cost;
  private static int[] size;
  private static int solve(int node) {
    Arrays.fill (cost, -1);
    size = new int[N];
    dfs1(node, -1);
    return dfs(node, -1);
  }
  
  private static void dfs1(int node, int par) {
    size[node] = 1;
    for (int e = elast[node]; e != -1; e = eprev[e]) {
      if (eadj[e] == par) continue;
      dfs1(eadj[e], node);
      size[node] += size[eadj[e]];
    }
  }
  
  private static int dfs(int node, int par) {
    if (cost[node] != -1) return cost[node];
    int ccount = deg[node] - (par == -1 ? 0 : 1);
    int sz = size[node] - 1;
    int[] pr = new int[ccount];
    int idx = 0;
    for (int e = elast[node]; e != -1; e = eprev[e]) {
      if (eadj[e] == par) continue;
      pr[idx++] = dfs(eadj[e], node) - size[eadj[e]];
    }
    Arrays.sort(pr);
    int min = sz;
    if (pr.length >= 2) {
      min = Math.min (min, pr[0] + pr[1] + sz);
    }
    return cost[node] = min;
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
