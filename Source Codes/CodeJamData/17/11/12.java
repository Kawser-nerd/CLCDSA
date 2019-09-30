import java.io.*;
import java.util.*;

public class _2017Round1AqA {

  public static void main(String args[]) throws Exception {
    InputReader in;
    PrintWriter w;
    boolean online = true;
    String fileName = "A-large";

    if (online) {
      in = new InputReader(new FileInputStream(new File(fileName + ".in")));
      w = new PrintWriter(new FileWriter(fileName + "out.txt"));
    } else {
      in = new InputReader(System.in);
      w = new PrintWriter(System.out);
    }

    int T = in.nextInt();

    for (int t = 1; t <= T; t++) {
      int r = in.nextInt();
      int c = in.nextInt();
      
      char s[][] = new char[r][c];
      for (int i = 0; i < r; i++)
        s[i] = in.readString().toCharArray();
      
      int prevRow = -1;
      char ans[][] = new char[r][c];
      
      for (int i = 0; i < r; i++) {
        boolean f = false;
        for (int j = 0; j < c; j++)
          f |= s[i][j] != '?';
        if (f) {
          int prevCol = -1;
          for (int j = 0; j < c; j++) {
            if (s[i][j] != '?') {
              for (int k = prevCol + 1; k <= j; k++)
                ans[i][k] = s[i][j];
              prevCol = j;
            }
          }
          for (int j = prevCol + 1; j < c; j++) {
            ans[i][j] = ans[i][prevCol];
          }
          for (int j = prevRow + 1; j < i; j++)
            ans[j] = new String(ans[i]).toCharArray();
          prevRow = i;
        }
      }
      
      for (int i = prevRow + 1; i < r; i++)
        ans[i] = new String(ans[i - 1]).toCharArray();
      
      w.println("Case #" + t + ": ");
      for (int i = 0; i < r; i++)
        w.println(new String(ans[i]));
    }

    w.close();
  }
  
  static class InputReader {

    private final InputStream stream;
    private final byte[] buf = new byte[8192];
    private int curChar, snumChars;

    public InputReader(InputStream st) {
      this.stream = st;
    }

    public int read() {
      if (snumChars == -1)
        throw new InputMismatchException();
      if (curChar >= snumChars) {
        curChar = 0;
        try {
          snumChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (snumChars <= 0)
          return -1;
      }
      return buf[curChar++];
    }

    public int nextInt() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public long nextLong() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
      do {
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public int[] nextIntArray(int n) {
      int a[] = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = nextInt();
      }
      return a;
    }

    public String readString() {
      int c = read();
      while (isSpaceChar(c)) {
        c = read();
      }
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = read();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public String nextLine() {
      int c = read();
      while (isSpaceChar(c))
        c = read();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = read();
      } while (!isEndOfLine(c));
      return res.toString();
    }

    public boolean isSpaceChar(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean isEndOfLine(int c) {
      return c == '\n' || c == '\r' || c == -1;
    }

  }

}
