import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.NoSuchElementException;

public class Main {
  private static class Task {
    void solve(FastScanner in, PrintWriter out) {
      int N = in.nextInt();
      int M = in.nextInt();
      int[] A = in.nextIntArray(M);
      if (M == 1) {
        if (A[0] == 1) {
          out.println(1);
          out.println(1);
          out.println(1);
          return;
        }
        out.println(A[0]);
        out.println(2);
        out.println(1 + " " + (A[0] - 1));
        return;
      }

      ArrayList<Integer> odd = new ArrayList<>();
      ArrayList<Integer> even = new ArrayList<>();
      for (int a : A)
        if (a % 2 == 0) even.add(a);
        else odd.add(a);
      if (odd.size() > 2) {
        out.println("Impossible");
        return;
      }
      Collections.sort(odd);
      if (!odd.isEmpty()) {
        even.add(odd.get(0));
        if (odd.size() == 2) even.add(0, odd.get(1));
      }
      for (int e : even) out.print(e + " ");
      out.println();
      if (even.get(0) == 1) {
        out.println(even.size() - 1);
        for (int i = 1; i < even.size() - 1; i++) out.print(even.get(i) + " ");
        out.print(even.get(M - 1) + 1);
        out.println();
      } else {
        out.println(even.size());
        out.print(even.get(0) - 1);
        out.print(" ");
        for (int i = 1; i < even.size() - 1; i++) out.print(even.get(i) + " ");
        out.print(even.get(M - 1) + 1);
        out.println();
      }
    }
  }

  // Template
  public static void main(String[] args) {
    OutputStream outputStream = System.out;
    FastScanner in = new FastScanner();
    PrintWriter out = new PrintWriter(outputStream);
    Task solver = new Task();
    solver.solve(in, out);
    out.close();
  }
  private static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int bufferLength = 0;

    private boolean hasNextByte() {
      if (ptr < bufferLength) {
        return true;
      } else {
        ptr = 0;
        try {
          bufferLength = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (bufferLength <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    long nextLong() {
      if (!hasNext()) throw new NoSuchElementException();
      long n = 0;
      boolean minus = false;
      int b = readByte();
      if (b == '-') {
        minus = true;
        b = readByte();
      }
      if (b < '0' || '9' < b) {
        throw new NumberFormatException();
      }
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10;
          n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
          return minus ? -n : n;
        } else {
          throw new NumberFormatException();
        }
        b = readByte();
      }
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }

    double[] nextDoubleArray(int n) {
      double[] array = new double[n];
      for (int i = 0; i < n; i++) {
        array[i] = nextDouble();
      }
      return array;
    }

    double[][] nextDoubleMap(int n, int m) {
      double[][] map = new double[n][];
      for (int i = 0; i < n; i++) {
        map[i] = nextDoubleArray(m);
      }
      return map;
    }

    public int nextInt() {
      return (int) nextLong();
    }

    public int[] nextIntArray(int n) {
      int[] array = new int[n];
      for (int i = 0; i < n; i++) {
        array[i] = nextInt();
      }
      return array;
    }
  }
}