import java.io.*;
import java.util.*;


public class Main {

  static int N, T, E;
  static int x[];

  public static void main(String[] args) {
    InputReader in = new InputReader(System.in);
    PrintWriter W = new PrintWriter(System.out);

    N = in.nextInt();
    E = in.nextInt();
    T = in.nextInt();

    x = new int[N + 1];
    for (int i = 1; i <= N; i++)
      x[i] = in.nextInt();
    
    //W.println(brute() + E);
    W.println(solve1D1D() + E);

    /*
    int x[] = new int[1000];
    for (int i = 0; i < x.length; i++)
      x[i] = new Random().nextInt(10000);
    
    int T = new Random().nextInt(250);
    
    Arrays.sort(x);
    
    for (int i = 2; i + 2 < x.length; i++) {
      for (int j = i + 2; j + 2 < x.length; j++) {
        int L = w(i, j, x, T) + w(i + 1, j + 1,x, T);
        int R = w(i + 1, j, x, T) + w(i, j + 1, x, T);
        if (L > R) {
          System.out.println("Rekt " + x[i] + " " + x[j] + " " + x[i + 1] + " " + x[j + 1] + " " + L + " " + R);
        }
      }
    }
    */

    W.close();
  }
  
  public static long brute(){
    
    long dp[] = new long[N + 1];
    for(int i = 1; i <= N; i++){
      dp[i] = Long.MAX_VALUE;
      for(int j = 0; j < i; j++)
        dp[i] = Math.min(dp[i], dp[j] + cost(j + 1, i));
    }
    
    System.out.println(Arrays.toString(dp));
    return dp[N];
  }

  public static long solve1D1D() {
    MyStack stack = new MyStack(N + 5);
    long[] dp = new long[N + 1];
    dp[0] = 0;
    stack.push(new Pair(0, 1)); //(l,w) = (idx, segment start)

    for (int i = 1; i <= N; i++) {
      { //find last segment such that stack.p[mid].w <= i
        int start = 0, end = stack.top + 1, mid, ret = -1;
        while (start < end) {
          mid = (start + end) >> 1;
          if (stack.p[mid].w > i)
            end = mid;
          else {
            ret = mid;
            start = mid + 1;
          }
        }
        dp[i] = dp[stack.p[ret].l] + cost(stack.p[ret].l + 1, i);
      }
      if (i == N)
        break;
      while (!stack.isEmpty()) {
        Pair top = stack.peek();
        if (top.w > i && dp[i] + cost(i + 1, top.w) < dp[top.l] + cost(top.l + 1, top.w))
          stack.pop();
        else {
          int start = top.w, end = N + 1;
          int ret = -1;
          while (start < end) {
            int mid = (start + end) >> 1;
            if (dp[i] + cost(i + 1, mid) < dp[top.l] + cost(top.l + 1, mid))
              ret = end = mid;
            else
              start = mid + 1;
          }
          if (ret != -1)
            stack.push(new Pair(i, ret));
          break;
        }
      }
      if (stack.isEmpty())
        stack.push(new Pair(i, 1));
    }

    return dp[N];
  }

  static int cost(int i, int j) {
    int X = x[j] - x[i];
    if (2 * X >= T)
      return 2 * X;
    else
      return T;
  }

  static class MyStack {
    int top;
    Pair p[];

    MyStack(int n) {
      p = new Pair[n];
      top = -1;
    }

    void push(Pair x) {
      p[++top] = x;
    }

    Pair pop() {
      return p[top--];
    }

    Pair peek() {
      return p[top];
    }

    boolean isEmpty() {
      return top == -1;
    }

    void print() {
      for (int i = 0; i <= top; i++)
        System.out.print(p[i] + " ");
      System.out.println();
    }
  }

  static class Pair implements Comparable<Pair> {
    int l, w;

    Pair(int l, int w) {
      this.l = l;
      this.w = w;
    }

    public int compareTo(Pair o) {
      if (w != o.w)
        return Integer.compare(o.w, w);
      return Integer.compare(o.l, l);
    }

    public String toString() {
      return l + " " + w;
    }
  }

  static class InputReader {

    private final InputStream stream;
    private final byte[] buf = new byte[8192];
    private int curChar, snumChars;
    private SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int snext() {
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
      int c = snext();
      while (isSpaceChar(c)) {
        c = snext();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = snext();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res *= 10;
        res += c - '0';
        c = snext();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public long nextLong() {
      int c = snext();
      while (isSpaceChar(c)) {
        c = snext();
      }
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = snext();
      }
      long res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res *= 10;
        res += c - '0';
        c = snext();
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
      int c = snext();
      while (isSpaceChar(c)) {
        c = snext();
      }
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = snext();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public String nextLine() {
      int c = snext();
      while (isSpaceChar(c))
        c = snext();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = snext();
      } while (!isEndOfLine(c));
      return res.toString();
    }

    public boolean isSpaceChar(int c) {
      if (filter != null)
        return filter.isSpaceChar(c);
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private boolean isEndOfLine(int c) {
      return c == '\n' || c == '\r' || c == -1;
    }

    public interface SpaceCharFilter {
      public boolean isSpaceChar(int ch);
    }
  }
}