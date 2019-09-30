import java.util.*;
import java.io.*;

public class minesweeper {
  private static Reader in;
  private static PrintWriter out;
  public static final String NAME = "C-large";

  private static void main2() throws IOException {
    int R = in.nextInt(), C = in.nextInt(), M = in.nextInt();
    boolean rev = false;
    if (R > C) {
      int t = R;
      R = C;
      C = t;
      rev = true;
    }

    int space = R * C - M;
    boolean possible = false;
    char[][] ans = new char[R + 1][C + 1];
    if (R == 1) {
      possible = true;
      ans[1][1] = 'c';
      for (int i = C; i >= C - M + 1; i--)
        ans[1][i] = '*';
      for (int i = C - M; i >= 2; i--)
        ans[1][i] = '.';
    } else if (space == 1) {
      possible = true;
      for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++)
          ans[i][j] = '*';
      }
      ans[1][1] = 'c';
    } else if (space == R * C) {
      possible = true;
      for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
          ans[i][j] = '.';
      ans[1][1] = 'c';
    } else {
      // knapsack
      boolean[][][] can = new boolean[R + 1][C + 1][space + 1]; // rows used, cur row num used,
                                                                // space used
      int[][][] prev = new int[R + 1][C + 1][space + 1];
      for (int i = 0; i <= R; i++)
        for (int j = 0; j <= C; j++)
          Arrays.fill(prev[i][j], -1);
      for (int i = 0; 2 * i <= space && i <= C; i++) {
        if (i == 1)
          continue;
        can[2][i][2 * i] = true;
      }

      for (int i = 3; i <= R; i++) { // current row
        for (int j = 0; j <= C; j++) { // current space in this row
          if (j == 1)
            continue; // can't use 1 space
          for (int k = j; k <= space; k++) { // current space used overall
            for (int q = j; q <= C; q++) { // space used in previous row
              if (can[i - 1][q][k - j]) {
                can[i][j][k] = true;
                prev[i][j][k] = q;
              }
            }
          }
        }
      }

      int st = -1;
      for (int i = 0; i <= C; i++) {
        if (i == 1)
          continue;
        if (can[R][i][space]) {
          possible = true;
          st = i;
        }
      }
      if (possible) {
        // backtrack
        int[] rownums = new int[R + 1];
        int left = space;
        for (int i = R; i >= 2; i--) {
          rownums[i] = st;
          int sub = st;
          st = prev[i][st][left];
          left -= sub;
        }
        rownums[1] = rownums[2];
        for (int i = 1; i <= R; i++) {
          Arrays.fill(ans[i], '.');
        }
        for (int i = 1; i <= R; i++) {
          for (int j = rownums[i] + 1; j <= C; j++) {
            ans[i][j] = '*';
          }
        }
        ans[1][1] = 'c';
      }
    }

    out.println();//R + " " + C + " " + M);
    if (possible) {
      if (!rev) {
        for (int i = 1; i <= R; i++) {
          for (int j = 1; j <= C; j++)
            out.print(ans[i][j]);
          out.println();
        }
      } else {
        for (int j = 1; j <= C; j++) {
          for (int i = 1; i <= R; i++)
            out.print(ans[i][j]);
          out.println();
        }
      }
    } else {
      out.println("Impossible");
    }
  }

  public static void main(String[] args) throws IOException {
    in = new Reader(NAME + ".in");
    out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ":");
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
