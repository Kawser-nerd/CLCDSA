import java.io.*;
import java.util.*;

public class _2017Round1AqB {

  public static void main(String args[]) throws Exception {
    InputReader in;
    PrintWriter w;
    boolean online = true;
    String fileName = "B-large";

    if (online) {
      in = new InputReader(new FileInputStream(new File(fileName + ".in")));
      w = new PrintWriter(new FileWriter(fileName + "out.txt"));
    } else {
      in = new InputReader(System.in);
      w = new PrintWriter(System.out);
    }

    int T = in.nextInt();

    for (int t = 1; t <= T; t++) {

      int ans = 0;

      int n = in.nextInt();
      int p = in.nextInt();

      int r[] = in.nextIntArray(n);

      int q[][] = new int[n][p];
      int minn[][] = new int[n][p];
      int maxx[][] = new int[n][p];

      for (int i = 0; i < n; i++) {
        q[i] = in.nextIntArray(p);
        Arrays.sort(q[i]);
        for (int j = 0; j < p; j++) {
          {
            int start = 0, end = (int) 1e7 + 1;
            minn[i][j] = -1;
            while (start < end) {
              int mid = (start + end) >> 1;
              double lowval = mid * 0.9 * r[i];
              double higval = mid * 1.1 * r[i];;
              if (q[i][j] < lowval) {
                end = mid;
              } else if (q[i][j] > higval) {
                start = mid + 1;
              } else {
                minn[i][j] = mid;
                end = mid;
              }
            }
          }
          
          {
            int start = 0, end = (int) 1e7 + 1;
            maxx[i][j] = -1;
            while (start < end) {
              int mid = (start + end) >> 1;
            double lowval = mid * 0.9 * r[i];
            double higval = mid * 1.1 * r[i]; 
              if (q[i][j] < lowval) {
                end = mid;
              } else if (q[i][j] > higval) {
                start = mid + 1;
              } else {
                maxx[i][j] = mid;
                start = mid + 1;
              }
            }
          }
        }
      }
      
      //System.out.println(Arrays.deepToString(minn));
      //System.out.println(Arrays.deepToString(maxx));

      int ptr[] = new int[n];

      while (true) {
        //System.out.println(Arrays.toString(ptr));
        
        int MIN = -1, MAX = -1;
        int leftMost = -1;
        for (int i = 0; i < n; i++) {
          int min = minn[i][ptr[i]];
          int max = maxx[i][ptr[i]];
          if (min == -1 || max == -1) {
            leftMost = i;
            MIN = Integer.MAX_VALUE;
            MAX = Integer.MIN_VALUE;
          }
          if (MIN != -1) {
            MIN = Math.max(MIN, min);
            MAX = Math.min(MAX, max);
            if (MAX == max)
              leftMost = i;
          } else {
            MIN = min;
            MAX = max;
            leftMost = i;
          }
        }
        
        if (MIN <= MAX) {
          ans++;
          boolean f = false;
          for (int i = 0; i < n; i++) {
            ptr[i]++;
            if (ptr[i] == p) {
              f = true;
              break;
            }
          }
          if (f)
            break;
        } else {
          ptr[leftMost]++;
          if (ptr[leftMost] == p)
            break;
        }
      }

      w.println("Case #" + t + ": " + ans);
    }

    w.close();
  }

  static public int getMin(int base, int value) {
    double r = value * 1.0 / base;
    double d = r / 0.9;
    for (int i = (int) Math.max(d - 5, 1); i < d + 6; i++) {
      if (value >= 0.9 * i * base && value <= 1.1 * i * base)
        return i;
    }
    return -1;
  }

  static public int getMax(int base, int value) {
    double r = value * 1.0 / base;
    double d = r / 1.1;
    for (int i = (int) d + 5; i >= 1; i--) {
      if (value >= 0.9 * i * base && value <= 1.1 * i * base)
        return i;
    }
    return -1;
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
