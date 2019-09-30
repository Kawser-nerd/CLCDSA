import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int M = scanner.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = scanner.nextInt();
    }

    UnionFind uf = new UnionFind(N + 1);
    for (int i = 0; i < M; i++) {
      int x = scanner.nextInt();
      int y = scanner.nextInt();
      uf.union(x, y);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
      if (uf.find(i + 1) == uf.find(a[i])) count++;
    }
    System.out.println(count);
  }

  static class UnionFind {
    private final int[] table;
    private final int[] ranks;
    private final int[] sizes;

    public UnionFind(int size) {
      this.table = new int[size];
      this.ranks = new int[size];
      this.sizes = new int[size];
      for (int i = 0; i < size; i++) {
        table[i] = i;
        sizes[i] = 1;
      }
    }

    public int find(int x) {
      if (table[x] != x) {
        table[x] = find(table[x]);
      }
      return table[x];
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