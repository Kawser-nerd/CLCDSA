import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[][] bridges = new int[m][2];
    for (int i = 0; i < m; i++) {
      bridges[i][0] = scanner.nextInt() - 1;
      bridges[i][1] = scanner.nextInt() - 1;
    }

    UnionFind uf = new UnionFind(n);
    long[] result = new long[m + 1];
    result[m] = (long) n * (n - 1) / 2;
    for (int i = m - 1; i >= 0; i--) {
      int a = bridges[i][0];
      int b = bridges[i][1];
      result[i] = result[i + 1];
      if (uf.find(a) == uf.find(b)) continue;
      result[i] -= (long) uf.size(a) * uf.size(b);
      uf.union(a, b);
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= m; i++) sb.append(result[i]).append('\n');
    System.out.println(sb.toString());
  }

  private static class UnionFind {
    private final int[] table;
    private final int[] ranks;
    private final int[] sizes;

    public UnionFind(int size) {
      this.table = new int[size];
      this.ranks = new int[size];
      this.sizes = new int[size];
      for (int i = 0; i < size; i++) {
        this.table[i] = i;
        this.sizes[i] = 1;
      }
    }

    public int size(int n) {
      return sizes[find(n)];
    }

    public int find(int n) {
      if (table[n] != n) {
        table[n] = find(table[n]);
      }
      return table[n];
    }

    public void union(int x, int y) {
      int xRoot = find(x);
      int yRoot = find(y);
      if (xRoot == yRoot) return;

      if (ranks[xRoot] < ranks[yRoot]) {
        int tmp = xRoot;
        xRoot = yRoot;
        yRoot = tmp;
      }
      table[yRoot] = xRoot;
      sizes[xRoot] += sizes[yRoot];
      if (ranks[xRoot] == ranks[yRoot]) ranks[xRoot]++;
    }
  }
}