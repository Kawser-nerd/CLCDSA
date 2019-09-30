import java.util.Scanner;

class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[] a = new int[m];
    int[] b = new int[m];
    for (int i = 0; i < m; i++) {
      a[i] = scanner.nextInt() - 1;
      b[i] = scanner.nextInt() - 1;
    }
    scanner.close();

    long[] ans = new long[m];
    ans[m - 1] = (long) n * (n - 1) / 2;

    UnionFind uni = new UnionFind(n);

    for (int i = m - 1; i >= 1; i--) {
      ans[i - 1] = ans[i];

      if (uni.root(a[i]) != uni.root(b[i])) {
        ans[i - 1] -= (long) uni.size(a[i]) * uni.size(b[i]);
        uni.connect(a[i], b[i]);
      }
    }
    for (int i = 0; i < m; i++) {
      System.out.println(ans[i]);
    }
  }

  static class UnionFind {

    private int[] parent;

    public UnionFind(int n) {
      // ??????????
      // ????????????-(????????)??????
      parent = new int[n];

      for (int i = 0; i < n; i++) {
        // ?????????????
        // ????????
        parent[i] = -1;
      }
    }

    // a??????????????????
    public int root(int a) {
      if (parent[a] < 0) {
        return a;
      } else {
        // ??????????
        return parent[a] = root(parent[a]);
      }
    }

    // a??????????
    public int size(int a) {
      return -parent[root(a)];
    }

    // a?b?????
    // ????(a)?????(b)???????
    public boolean connect(int a, int b) {
      // ????????
      a = root(a);
      b = root(b);

      // ????????????
      if (a == b) {
        return false;
      }

      if (size(a) < size(b)) {
        int r = a;
        a = b;
        b = r;
      }

      parent[a] += parent[b];
      parent[b] = a;

      return true;
    }
  }

}