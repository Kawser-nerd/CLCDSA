import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;
import java.util.TreeSet;

public class Main {

  private ArrayList<Integer> getOneCycle(ArrayList<ArrayList<Integer>> tree) {
    int N = tree.size();
    int[] scc = decompose(tree);
    int[] count = new int[N];
    ArrayList<Integer> cycle = new ArrayList<>();
    for (int s : scc) {
      count[s]++;
    }
    for (int i = 0; i < N; i++) {
      if (count[scc[i]] > 1) {
        cycle.add(i);
      }
    }

    return cycle;
  }

  private void solve(FastScanner in, PrintWriter out) {
    int N = in.nextInt();
    ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      tree.add(new ArrayList<>());
    }

    int[] parent = new int[N];
    for (int i = 0; i < N; i++) {
      int p = in.nextInt() - 1;
      parent[i] = p;
      tree.get(p).add(i);
    }

    ArrayList<Integer> cycle = getOneCycle(tree);
    if (cycle.isEmpty()) {
      out.println("POSSIBLE");
      return;
    }

    TreeSet<Integer>[] children = new TreeSet[N];
    for (int i = 0; i < N; i++) {
      children[i] = new TreeSet<>();
    }

    ArrayDeque<Integer> bfs = new ArrayDeque<>();
    int[] vis = new int[N];
    int[] grundy = new int[N];
    Arrays.fill(grundy, -1);
    for (int i = 0; i < N; i++) {
      if (tree.get(i).isEmpty()) {
        bfs.add(i);
        grundy[i] = 0;
      }
    }
    while (!bfs.isEmpty()) {
      int v = bfs.poll();
      int p = parent[v];
      vis[p]++;
      if (vis[p] == tree.get(p).size()) {
        bfs.add(p);
      }
      if (tree.get(v).isEmpty()) {
        continue;
      }
      TreeSet<Integer> set = children[v];
      for (int u : tree.get(v)) {
        set.add(grundy[u]);
      }
      grundy[v] = getGrundy(set);
    }

    for (int c : cycle) {
      for (int u : tree.get(c)) {
        if (grundy[u] >= 0) {
          children[c].add(grundy[u]);
        }
      }
    }

    int x = cycle.get(0);
    int g1 = getGrundy(children[x]);
    grundy[x] = g1;
    {
      int M = cycle.size();
      int cur = x;
      TreeSet<Integer>[] copy = copy(children);
      for (int i = 0; i < M; i++) {
        int p = parent[cur];
        copy[p].add(grundy[cur]);
        grundy[p] = getGrundy(copy[p]);
        cur = p;
      }
      if (g1 == grundy[x]) {
        out.println("POSSIBLE");
        return;
      }
    }
    children[x].add(g1);
    int g2 = getGrundy(children[x]);
    children[x].remove(g1);
    grundy[x] = g2;
    {
      int M = cycle.size();
      int cur = x;
      TreeSet<Integer>[] copy = copy(children);
      for (int i = 0; i < M; i++) {
        int p = parent[cur];
        copy[p].add(grundy[cur]);
        grundy[p] = getGrundy(copy[p]);
        cur = p;
      }
      if (g2 == grundy[x]) {
        out.println("POSSIBLE");
        return;
      }
    }
    out.println("IMPOSSIBLE");

  }

  private TreeSet<Integer>[] copy(TreeSet<Integer>[] children) {
    TreeSet<Integer>[] array = new TreeSet[children.length];
    for (int i = 0; i < children.length; i++) {
      array[i] = new TreeSet<>(children[i]);
    }
    return array;
  }

  private int getGrundy(TreeSet<Integer> set) {
    int grundy = 0;
    for (int s : set) {
      if (s == grundy) {
        grundy++;
      } else {
        return grundy;
      }
    }
    return grundy;
  }

  public static int[] decompose(ArrayList<ArrayList<Integer>> G) {
    ArrayList<Integer> vs = new ArrayList<>();
    int V = G.size();
    int[] cmp = new int[V];

    ArrayList<ArrayList<Integer>> rG = new ArrayList<>(V);
    for (int i = 0; i < V; i++) {
      rG.add(new ArrayList<>());
    }
    for (int i = 0; i < V; i++) {
      for (int v : G.get(i)) {
        rG.get(v).add(i);
      }
    }
    boolean[] used = new boolean[V];

    ArrayDeque<Integer> stack = new ArrayDeque<>();
    boolean[] added = new boolean[V];
    for (int i = 0; i < V; i++) {
      if (!used[i]) {
        stack.addFirst(i);
        while (!stack.isEmpty()) {
          int v = stack.peekFirst();
          used[v] = true;
          boolean pushed = false;
          for (int j = G.get(v).size() - 1; j >= 0; j--) {
            int u = G.get(v).get(j);
            if (!used[u]) {
              stack.addFirst(u);
              pushed = true;
            }
          }
          if (!pushed) {
            stack.pollFirst();
            if (!added[v]) {
              vs.add(v);
              added[v] = true;
            }
          }
        }
      }
    }

    Arrays.fill(used, false);
    int k = 0;
    Collections.reverse(vs);
    for (int i : vs) {
      if (!used[i]) {
        stack.push(i);
        used[i] = true;
        cmp[i] = k;
        while (!stack.isEmpty()) {
          int v = stack.peek();
          boolean pushed = false;
          for (int u : rG.get(v)) {
            if (!used[u]) {
              used[u] = true;
              cmp[u] = k;
              stack.push(u);
              pushed = true;
            }
          }
          if (!pushed) {
            stack.pop();
          }
        }
        k++;
      }
    }
    return cmp;
  }

  public static void main(String[] args) {
    FastScanner in = new FastScanner();
    PrintWriter out = new PrintWriter(System.out);
    new Main().solve(in, out);
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