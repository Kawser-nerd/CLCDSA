import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.io.BufferedWriter;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 *
 * @author @Ziklon
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    OutputWriter out = new OutputWriter(outputStream);
    BPowersOfTwo solver = new BPowersOfTwo();
    solver.solve(1, in, out);
    out.close();
  }

  static class BPowersOfTwo {
    public void solve(int testNumber, InputReader in, OutputWriter out) {

      int n = in.readInt();
      int[] seq = in.readIntArray(n);

      TreeMap<Integer, Integer> counters = new TreeMap<>();

      for (int e : seq) counters.put(e, counters.getOrDefault(e, 0) + 1);
      int ans = 0;

      while (!counters.isEmpty()) {
        int lastKey = counters.lastKey();
        int cnt = counters.get(lastKey);
        if (cnt == 1) counters.remove(lastKey);
        else {
          counters.put(lastKey, cnt - 1);
        }
        int p1 = 1;
        while (p1 <= lastKey) p1 *= 2;
        int need = p1 - lastKey;

        Integer needCount = counters.get(need);
        if (needCount != null) {
          ans++;
          if (needCount == 1) counters.remove(need);
          else counters.put(need, needCount - 1);
        }
      }
      out.printLine(ans);
    }
  }

  static class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private InputReader.SpaceCharFilter filter;

    public InputReader(InputStream stream) {
      this.stream = stream;
    }

    public int[] readIntArray(int size) {
      int[] array = new int[size];
      for (int i = 0; i < size; i++) {
        array[i] = readInt();
      }
      return array;
    }

    public int read() {
      if (numChars == -1) {
        throw new InputMismatchException();
      }
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (numChars <= 0) {
          return -1;
        }
      }
      return buf[curChar++];
    }

    public int readInt() {
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
        if (c < '0' || c > '9') {
          throw new InputMismatchException();
        }
        res *= 10;
        res += c - '0';
        c = read();
      } while (!isSpaceChar(c));
      return res * sgn;
    }

    public boolean isSpaceChar(int c) {
      if (filter != null) {
        return filter.isSpaceChar(c);
      }
      return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
      return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
      public boolean isSpaceChar(int ch);
    }
  }

  static class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
      writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
      this.writer = new PrintWriter(writer);
    }

    public void close() {
      writer.close();
    }

    public void printLine(int i) {
      writer.println(i);
    }
  }
}