import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.TreeSet;

public class Main {

  private TreeSet<Integer>[] tree;
  private int[] depth;

  private void depthDfs(int v, int p) {
    for (int u : tree[v]) {
      if (u == p) {
        continue;
      }
      depth[u] = depth[v] + 1;
      depthDfs(u, v);
    }
  }

  private boolean ok(int leaf, boolean[] removed) {
    int parent = -1;
    for (int u : tree[leaf]) {
      if (depth[leaf] > depth[u]) {
        parent = u;
        break;
      }
    }

    if (parent < 0) {
      return false;
    }

    int count = 0;
    for (int u : tree[parent]) {
      if (removed[u]) {
        continue;
      }
      if (tree[u].size() == 1) {
        count++;
      }
    }

    if (count >= 2) {
      return true;
    }
    removed[leaf] = true;
    removed[parent] = true;

    for (int u : tree[parent]) {
      if (depth[u] < depth[parent]) {
        tree[u].remove(parent);
        break;
      }
    }

    return false;
  }

  private void solve(FastScanner in, PrintWriter out) {
    int N = in.nextInt();
    tree = new TreeSet[N];
    for (int i = 0; i < N; i++) {
      tree[i] = new TreeSet<>();
    }

    for (int i = 0; i < N - 1; i++) {
      int a = in.nextInt() - 1;
      int b = in.nextInt() - 1;
      tree[a].add(b);
      tree[b].add(a);
    }

    depth = new int[N];
    depthDfs(0, -1);

    int[][] depthSort = new int[N][2];
    for (int i = 0; i < N; i++) {
      depthSort[i][0] = depth[i];
      depthSort[i][1] = i;
    }
    Arrays.sort(depthSort, (o1, o2) -> -o1[0] + o2[0]);
    boolean[] removed = new boolean[N];
    for (int i = 0; i < N; i++) {
      int leaf = depthSort[i][1];
      if (removed[leaf]) {
        continue;
      }

      if (ok(leaf, removed)) {
        out.println("First");
        return;
      }
    }
    out.println("Second");
  }

  public static void main(String[] args) {
    PrintWriter out = new PrintWriter(System.out);
    new Main().solve(new FastScanner(), out);
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
      if (hasNextByte()) {
        return buffer[ptr++];
      } else {
        return -1;
      }
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
        ptr++;
      }
    }

    boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    long nextLong() {
      if (!hasNext()) {
        throw new NoSuchElementException();
      }
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

    public long[] nextLongArray(int n) {
      long[] array = new long[n];
      for (int i = 0; i < n; i++) {
        array[i] = nextLong();
      }
      return array;
    }

    public String[] nextStringArray(int n) {
      String[] array = new String[n];
      for (int i = 0; i < n; i++) {
        array[i] = next();
      }
      return array;
    }

    public char[][] nextCharMap(int n) {
      char[][] array = new char[n][];
      for (int i = 0; i < n; i++) {
        array[i] = next().toCharArray();
      }
      return array;
    }

    public int[][] nextIntMap(int n, int m) {
      int[][] map = new int[n][];
      for (int i = 0; i < n; i++) {
        map[i] = nextIntArray(m);
      }
      return map;
    }
  }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.