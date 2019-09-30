import java.util.Random;
import java.util.Scanner;

public class TheGardenerOfSevilleSmall {

  static class DSU {
    static Random rnd = new Random(3);
    final int n;
    int[] p;

    DSU(int n) {
      this.n = n;
      p = new int[n];
      for (int i = 0; i < n; i++) {
        p[i] = i;
      }
    }

    int get(int v) {
      return v == p[v] ? v : (p[v] = get(p[v]));
    }

    void unite(int v1, int v2) {
      if (rnd.nextBoolean()) {
        p[get(v1)] = get(v2);
      } else {
        p[get(v2)] = get(v1);
      }
    }
  }

  static int toVertex(int r, int c, int[][] byRow, int[][] byCol, int x) {
    x--;
    if (x < c) {
      return byCol[x][0];
    }
    x -= c;
    if (x < r) {
      return byRow[x][byRow[x].length - 1];
    }
    x -= r;
    if (x < c) {
      return byCol[c - x - 1][byCol[c - x - 1].length - 1];
    }
    x -= c;
    return byRow[r - x - 1][0];
  }

  static String solve(int r, int c, int[] a) {
    int n = r * c;
    int[][] byRow = new int[r][c + 1];
    int[][] byCol = new int[c][r + 1];
    int total = 0;
    for (int i = 0; i < byRow.length; i++) {
      for (int j = 0; j < byRow[i].length; j++) {
        byRow[i][j] = total++;
      }
    }
    for (int i = 0; i < byCol.length; i++) {
      for (int j = 0; j < byCol[i].length; j++) {
        byCol[i][j] = total++;
      }
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      DSU dsu = new DSU(total);
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          int index = i * c + j;
          if ((mask & (1 << index)) == 0) {
            dsu.unite(byCol[j][i], byRow[i][j]);
            dsu.unite(byCol[j][i + 1], byRow[i][j + 1]);
          } else {
            dsu.unite(byCol[j][i], byRow[i][j + 1]);
            dsu.unite(byCol[j][i + 1], byRow[i][j]);
          }
        }
      }
      boolean ok = true;
      for (int i = 0; i < a.length; i += 2) {
        int v1 = toVertex(r, c, byRow, byCol, a[i]);
        int v2 = toVertex(r, c, byRow, byCol, a[i + 1]);
        ok &= dsu.get(v1) == dsu.get(v2);
      }
      if (ok) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
            int index = i * c + j;
            if ((mask & (1 << index)) == 0) {
              sb.append("/");
            } else {
              sb.append("\\");
            }

          }
          sb.append(i == r - 1 ? "" : "\n");
        }
        return sb.toString();
      }
    }
    return "IMPOSSIBLE";
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      int r = in.nextInt();
      int c = in.nextInt();
      int[] a = new int[2 * (r + c)];
      for (int i = 0; i < a.length; i++) {
        a[i] = in.nextInt();
      }
      String ans = solve(r, c, a);
      System.out.println("Case #" + t + ": \n" + ans);
    }
  }
}
