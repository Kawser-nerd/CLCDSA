package con2017.con2017R1C;


import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.Locale;

public class B {

  static final String islarge = "-large";
  private static final String[] packages = B.class.getPackage().getName().split("\\.");
  private static final String fileLoc = "src/" + packages[0] + "/" + packages[1] + "/files/";
  private static final String fileName = fileLoc + B.class.getSimpleName().toLowerCase() + islarge;
  private static final String inputFileName = fileName + ".in";
  private static final String outputFileName = fileName + ".out";
  private static InputReader in;
  private static OutputWriter out;

  static class Pair implements Comparable<Pair> {
    private final int from, to, p, range;

    public Pair(int from, int to, boolean isA) {
      this.from = from;
      this.to = to;
      this.p = isA ? 0 : 1;
      this.range = from > to ? DAY + to - from : to - from;
    }

    @Override
    public int compareTo(Pair oth) {
      if (this.from == oth.from) {
        return Integer.signum(this.to - oth.to);
      }
      return this.from < oth.from ? -1 : 1;
    }
  }

  static final int DAY = 1440;

  @SuppressWarnings("unchecked")
  private void solve() {
    int A = in.readInt(), B = in.readInt();
    Pair[] ps = new Pair[A + B];
    int[] left = new int[2];
    left[0] = left[1] = 720;
    for (int i = 0; i < A + B; i++) {
      ps[i] = new Pair(in.readInt(), in.readInt(), i < A);
      left[ps[i].p] -= ps[i].range;
    }
    Arrays.sort(ps);
    int tot = 0;
    ArrayList<Pair>[] ll = new ArrayList[2];
    ll[0] = new ArrayList<>();
    ll[1] = new ArrayList<>();
    for (int i = 0; i < ps.length; i++) {
      int prev = (i == 0 ? ps.length - 1 : i - 1);
      if (ps[prev].p != ps[i].p) {
        tot++;
      } else {
        Pair newp = new Pair(ps[prev].to, ps[i].from, ps[i].p == 0);
        if (newp.range == 0) {
          continue;
        }
        ll[newp.p].add(newp);
        left[newp.p] -= newp.range;
      }
    }
    Collections.sort(ll[0]);
    Collections.sort(ll[1]);
    if (left[1] < 0) {
      left[0] = left[1];
      ll[0] = ll[1];
    }
    if (left[0] < 0) {
      Collections.sort(ll[0], (Pair a, Pair b) -> Integer.signum(a.range - b.range));
      while (left[0] < 0) {
        tot += 2;
        Pair p = ll[0].get(ll[0].size() - 1);
        left[0] += (p.range);
        ll[0].remove(p);
      }
    }
    out.printLine(tot);
  }

  /*
   * START OF BOILERPLATE
   */
  private static void printCase(int t) {
    out.print("Case #" + t + ": ");
  }

  public static void main(String[] args) throws IOException {
    long start = System.currentTimeMillis();
    System.out.println("Contest: " + packages[1] + " problem: " + B.class.getSimpleName());
    System.out.println("Solving " + (fileName.endsWith(islarge) ? "LARGE" : "SMALL") + " dataset");
    System.out.println("------------------------------");
    Locale.setDefault(Locale.US);
    try (InputReader closeIn = new InputReader(new FileInputStream(inputFileName));
        OutputWriter closeOut = new OutputWriter(new FileOutputStream(outputFileName))) {
      in = closeIn;
      out = closeOut;
      int tests = in.readInt();
      for (int t = 1; t <= tests; t++) {
        printCase(t);
        new B().solve();
        System.out.println("Case #" + t + ": solved");
      }
    } finally {
      System.out.println("------------------------------");
      long stop = System.currentTimeMillis();
      System.out.println("Time: " + (stop - start) + " ms");
    }
  }


  static class InputReader implements AutoCloseable {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int read() {
      if (numChars == -1)
        throw new InputMismatchException();
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (numChars <= 0)
          return -1;
      }
      return buf[curChar++];
    }

    public String readLine() {
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

    public String readString() {
      int c = read();
      while (isSpaceChar(c))
        c = read();
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = read();
      } while (!isSpaceChar(c));
      return res.toString();
    }

    public long readLong() {
      int c = read();
      while (isSpaceChar(c))
        c = read();
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      long res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public int readInt() {
      int c = read();
      while (isSpaceChar(c))
        c = read();
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = read();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public boolean isSpaceChar(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public boolean isEndOfLine(int c) {
      return c == '\n' || c == '\r' || c == -1;
    }

    public void close() throws IOException {
      stream.close();
    }
  }

  static class OutputWriter implements AutoCloseable {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
      for (int i = 0; i < objects.length; i++) {
        if (i != 0)
          writer.print(' ');
        writer.print(objects[i]);
      }
    }

    public void printLine(Object... objects) {
      print(objects);
      writer.println();
    }

    public void close() {
      writer.close();
    }
  }
}
