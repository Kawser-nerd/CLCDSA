import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {

  FastScanner sc;

  Main() {
    sc = new FastScanner();
  }

  int ni() {
    return Integer.parseInt(sc.next());
  }

  public static void main(String[] args) {
    new Main().run();
  }

  void run() {
    int n = ni();
    int m = ni();
    int s = ni();

    List<List<Integer>> adj = new ArrayList<>();
    for (int i = 0; i <= n; ++i) {
      adj.add(new LinkedList<>());
    }
    for (int i = 0; i < m; ++i) {
      int u = ni();
      int v = ni();
      adj.get(u).add(v);
      adj.get(v).add(u);
    }

    PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> b - a);
    int[] d = new int[n + 1];
    boolean[] done = new boolean[n + 1];
    queue.add(s);
    d[s] = s;
    while (queue.size() > 0) {
      int e = queue.poll();
      if (done[e]) {
        continue;
      }
      done[e] = true;
//      debug(e);
      for (Integer i : adj.get(e)) {
        int c = Math.min(d[e], i);
        if (c > d[i]) {
          d[i] = c;
          queue.add(i);
        }
      }
    }

//    debug(d);
    PrintWriter pw = new PrintWriter(System.out);
    for (int i = 1; i <= n; ++i) {
      if (d[i] >= i) {
        pw.println(i);
      }
    }
    pw.flush();
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }

  class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
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

    public long nextLong() {
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
  }
}